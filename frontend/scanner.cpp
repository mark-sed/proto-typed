/**
 * @file scanner.cpp
 * @author Marek Sedlacek
 * @brief Scanner and parsing driver (semantics)
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2024
 * Takes care of scanning, parsing and creating
 * IR from parsed code.
 */

#include "scanner.hpp"
#include "logging.hpp"
#include "utils.hpp"
#include "ptc.hpp"
#include "llvm/Support/Casting.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/APSInt.h"
#include <cstring>
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace ptc;

// Helper functions

std::string ptc::encodeFunction(std::string name, std::vector<ir::FormalParamDecl *> params, bool lib) {
    assert(name.size() > 0 && "Function name cannot be empty");
    if (!lib) {
        std::string paramStr;
        for(auto p : params) {
            paramStr += p->getType()->getName()+"_";
        }
        return name+"_"+std::to_string(params.size())+paramStr;
    }
    else {
        std::string paramStr;
        for(auto p : params) {
            paramStr += "_"+p->getType()->getName();
        }
        return name+paramStr;
    }
}

std::string ptc::encodeFunction(std::string name, std::vector<ir::Expr *> params, bool lib) {
    assert(name.size() > 0 && "Function name cannot be empty");
    if (!lib) {
        std::string paramStr;
        for(auto p : params) {
            paramStr += p->getType()->getName()+"_";
        }
        return name+"_"+std::to_string(params.size())+paramStr;
    }
    else {
        std::string paramStr;
        for(auto p : params) {
            paramStr += "_"+p->getType()->getName();
        }
        return name+paramStr;
    }
}

ir::SourceInfo Scanner::llvmloc2Src() {
    const long LINE_LEN_PRE = 100; // Max length of line to be displayed, but will be cut at first
    const long LINE_LEN_POST = 20;

    std::string currLine = srcCode[llvmloc->begin.line-1];
    if(currLine.size() > LINE_LEN_PRE+LINE_LEN_POST) {
        size_t start = 0;
        if(llvmloc->begin.column > LINE_LEN_PRE) {
            start = llvmloc->begin.column - LINE_LEN_PRE;
        }
        size_t end = llvmloc->begin.column + LINE_LEN_POST;
        if(end > currLine.size()-1)
            end = currLine.size()-1;
        currLine = currLine.substr(start, end-start);

        unsigned int end_c = llvmloc->end.column - start;
        if(end_c > end) {
            end_c = end;
        }
        return ir::SourceInfo(fileName, llvmloc->begin.line, llvmloc->begin.column, llvmloc->end.line, llvmloc->end.column, currLine, llvmloc->begin.column-start, end_c);
    }

    return ir::SourceInfo(fileName, llvmloc->begin.line, llvmloc->begin.column, llvmloc->end.line, llvmloc->end.column, currLine, llvmloc->begin.column, llvmloc->end.column);
}

Scanner::Scanner(Diagnostics &diags, std::vector<std::string> srcCode, std::string moduleName, std::string fileName, ir::ModuleDecl *ptlibMod, bool lib)
        : currentIR(nullptr), diags(diags), moduleName(moduleName), fileName(fileName), ptlibMod(ptlibMod), srcCode(srcCode), lib(lib), parseByte(0), lastNl(0), preLastNl(0) {
    llvmloc = new Parser::location_type();
    init();
}

Scanner::~Scanner() {
    delete globalScope;
}

void Scanner::init() {
    currScope = new Scope();
    globalScope = currScope; // This will be overriden by module scope

    mainModule = new ir::ModuleDecl(nullptr, llvmloc2Src(), moduleName);
    currentIR = mainModule;
    parseByte = 0;
    lastNl = 0;
    preLastNl = 0;

    intType = new ir::TypeDecl(currentIR, llvmloc2Src(), INT_CSTR);
    floatType = new ir::TypeDecl(currentIR, llvmloc2Src(), FLOAT_CSTR);
    stringType = new ir::TypeDecl(currentIR, llvmloc2Src(), STRING_CSTR);
    boolType = new ir::TypeDecl(currentIR, llvmloc2Src(), BOOL_CSTR);
    voidType = new ir::TypeDecl(currentIR, llvmloc2Src(), VOID_CSTR);
    anyType = new ir::TypeDecl(currentIR, llvmloc2Src(), ANY_CSTR);
    anyType->setMaybe(true);
    rangeType = new ir::TypeDecl(currentIR, llvmloc2Src(), RANGE_CSTR);
    noneType = new ir::TypeDecl(currentIR, llvmloc2Src(), NONETYPE_CSTR);
    varargsType = new ir::TypeDecl(currentIR, llvmloc2Src(), VARARGS_CSTR);

    unknownType = new ir::TypeDecl(currentIR, llvmloc2Src(), UNKNOWN_CSTR);

    currScope->insert(intType);
    currScope->insert(boolType);
    currScope->insert(floatType);
    currScope->insert(stringType);
    currScope->insert(anyType);
    currScope->insert(voidType);
    currScope->insert(rangeType);
    currScope->insert(noneType);
    currScope->insert(varargsType);

    auto mintType = intType->clone();
    mintType->setMaybe(true);
    auto mfloatType = floatType->clone();
    mfloatType->setMaybe(true);

    // _entry
    defineFun(_ENTRY_NAME, _ENTRY_NAME, voidType, {});
    // print
    defineFun("print_string", "print", voidType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->stringType, false)
    });
    // String function
    // to_string
    defineFun("to_string_int", "to_string", stringType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->intType, false)
    });
    defineFun("to_string_float", "to_string", stringType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("to_string_bool", "to_string", stringType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->boolType, false)
    });
    // From string
    defineFun("to_int_base_string_int", "to_int_base", mintType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "str", this->stringType, false),
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "base", this->intType, false)
    });
    defineFun("to_float_string", "to_float", mfloatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "str", this->stringType, false)
    });
    // length
    defineFun("length_string", "length", intType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->stringType, false)
    });
    defineFun("ord_string", "ord", intType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->stringType, false)
    });
    defineFun("chr_int", "chr", stringType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->intType, false)
    });

    // Math functions
    // Trigonometry
    defineFun("sin_float", "sin", floatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("cos_float", "cos", floatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("tan_float", "tan", floatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("is_nan_float", "is_nan", boolType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("ln_float", "ln", floatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });
    defineFun("log10_float", "log10", floatType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", this->floatType, false)
    });

    // Environment
    defineFun("system_string", "system", intType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "cmd", this->stringType, false)
    });
    defineFun("getenv_string", "getenv", stringType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "name", this->stringType, false)
    });
    defineFun("setenv_string_string_bool", "setenv", boolType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "name", this->stringType, false),
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "value", this->stringType, false),
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "overwrite", this->boolType, false)
    });
    defineFun("exit_int", "exit", voidType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "status", this->intType, false)
    });
    defineFun("set_seed_int", "set_seed", voidType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "seed", this->intType, false)
    });
    defineFun("rand_uint", "rand_uint", intType, {
    });
    defineFun("timestamp", "timestamp", intType, {
    });

    if(!lib) {
        for(auto d: ptlibMod->getDecls()) {
            if(auto v = llvm::dyn_cast<ir::FunctionDecl>(d)) {
                currScope->insert(v);
            }
            else if(auto v = llvm::dyn_cast<ir::VarDecl>(d)) {
                currScope->insert(v);
            }
            else if(auto v = llvm::dyn_cast<ir::StructDecl>(d)) {
                auto t = new ir::TypeDecl(v->getEnclosingIR(), v->getLocation(), v->getName(), v);
                currScope->insert(t);
            }
        }
    }

    // IO
    std::vector<ir::IR *> elements {
        new ir::VarDecl(currentIR, llvmloc2Src(), "path", stringType),
        new ir::VarDecl(currentIR, llvmloc2Src(), "mode", stringType),
        new ir::VarDecl(currentIR, llvmloc2Src(), "handle", intType),
    };
    auto fileTypeDecl = new ir::StructDecl(currentIR, llvmloc2Src(), "File", elements);
    fileType = new ir::TypeDecl(currentIR, llvmloc2Src(), "File", fileTypeDecl);
    defineFun("fopen_string_string", "fopen", intType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "path", this->stringType, false),
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "mode", this->stringType, false)
    });
    defineFun("fclose_int", "fclose", boolType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "handle", intType, false)
    });
    defineFun("fgetbyte_File", "fgetbyte", intType, {
        new ir::FormalParamDecl(currentIR, llvmloc2Src(), "f", fileType, false)
    });
}

void Scanner::parse(std::istream *code) {
    this->switch_streams(code);
    llvmloc = new Parser::location_type();
    auto parser = new Parser(this);

    enterScope(mainModule);
    globalScope = currScope;
    if(parser->parse() != 0) {
        // Fail
    }
    leaveScope();

    mainModule->setDecls(this->decls);

    LOG1("\n-----\nIR generated:\n");
    LOG1(mainModule->debug());
}

bool Scanner::defineFun(std::string name, std::string ogName, ir::TypeDecl *retType, std::initializer_list<ir::FormalParamDecl*> params) {
    auto body = std::vector<ir::IR *> {};
    auto fun = new ir::FunctionDecl(currentIR,
                                    llvmloc2Src(),
                                    name,
                                    ogName,
                                    retType,
                                    params,
                                    body);
    return currScope->insert(fun);
}


std::string Scanner::escapeString(std::string str) {
    std::stringstream res;
    bool backslash = false;
    for(int i = 0; str[i] != '\0'; ++i) {
        char c = str[i];
        if(backslash) {
            switch(c) {
            case '\"': 
                res << '\"';
            break;
            case '\\': 
                res << '\\';
            break;
            case 'a': 
                res << '\a';
            break;
            case 'b': 
                res << '\b';
            break;
            case 'f': 
                res << '\f';
            break;
            case 'n': 
                res << '\n';
            break;
            case 'r': 
                res << '\r';
            break;
            case 't': 
                res << '\t';
            break;
            case 'v': 
                res << '\v';
            break;
            // TODO: https://en.cppreference.com/w/cpp/language/escape
            case 'x':
            case 'X':
                diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Hexadecimal escape sequences are not yet implemented");
            break;
            case 'q':
            case 'Q':
                diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Octal escape sequences are not yet implemented");
            break;
            case 'u':
            case 'U':
                diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Unicode escape sequences are not yet implemented");
            break;
            case 'N': // TODO: Should this be kept?
                diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Named unicode escape sequences are not yet implemented");
            break;
            default:
                diags.report(llvmloc2Src(), diag::ERR_UNKNOWN_ESC_SEQ, std::string("\\")+c);
            }
            backslash = false;
            continue;
        }
        if(c == '\\') {
            backslash = true;
            continue;
        }
        res << c;
    }
    return res.str();
}

void Scanner::fatal_error(diag::diagmsg d, std::string msg) {
    diags.report(llvmloc2Src(), d, msg);
}

void Scanner::enterScope(ir::IR *decl) {
    LOGMAX("Creating new scope");
    currScope = new Scope(currScope);
    currentIR = decl;
}

void Scanner::enterFunScope() {
    LOGMAX("Creating new function scope");
    currScope = new Scope(currScope);
    currentIR = new ir::FunctionDecl(currentIR, llvmloc2Src());
}

void Scanner::enterBlockScope() {
    LOGMAX("Creating new block scope");
    currScope = new Scope(currScope);
    // PlaceHolder IR
    currentIR = new ir::FunctionDecl(currentIR, llvmloc2Src());
}

void Scanner::leaveScope() {
    LOGMAX("Leaving current scope");
    Scope *parent = currScope->getParent();
    if(currScope != globalScope)
        delete currScope;
    currScope = parent;
    currentIR = currentIR->getEnclosingIR();
}

ir::IR *Scanner::parseVarDecl(ir::IR *type, const std::string name, ir::Expr *value) {
    if(!type) {
        // var used
        type = value->getType();
    }
    LOGMAX(type->debug()+" "+name);
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(t) {
        if(value && value->getType()->getName() != UNKNOWN_CSTR) {
            if(value && type->getName() != value->getType()->getName() && type->getName() != ANY_CSTR && value->getType()->getName() != ANY_CSTR) {
                if(!(t->isMaybe() && value->getType()->getName() == NONETYPE_CSTR))
                    diags.report(type->getLocation(), diag::ERR_INCORRECT_ASSIGNMENT, value->getType()->getName(), type->getName());
            }
            if(value && value->getType()->getName() == ANY_CSTR && t->getName() != ANY_CSTR) {
                diags.report(llvmloc2Src(), diag::ERR_USE_CAST_FOR_ANY, value->getType()->getName(), t->getName());
            }
        }
        auto v = new ir::VarDecl(currentIR, type->getLocation(), name, t, value);
        if(!currScope->insert(v)) {
            diags.report(type->getLocation(), diag::ERR_SYM_ALREADY_DECLARED, name);
        }
        return v;
    }
    else {
        diags.report(type->getLocation(), diag::ERR_VARDECL_REQUIRES_TYPE);
    }
    return nullptr;
}

ir::IR *Scanner::parseExprStmt(ir::Expr *e) {
    LOGMAX("Parsing expression '"+e->debug()+"' into a statement");
    auto v = new ir::ExprStmt(currentIR, llvmloc2Src(), "Expression", e);
    //this->decls.push_back(v);
    return v;
}

ir::IR *Scanner::parseReturn(ir::Expr *e) {
    LOGMAX("Parsing return");
    return new ir::ReturnStmt(e, currentIR, llvmloc2Src(), "Return");
}

ir::IR *Scanner::parseBreak() {
    LOGMAX("Parsing break");
    return new ir::BreakStmt(currentIR, llvmloc2Src());
}

ir::IR *Scanner::parseContinue() {
    LOGMAX("Parsing break");
    return new ir::ContinueStmt(currentIR, llvmloc2Src());
}

ir::Expr *Scanner::parseInt(long v) {
    LOGMAX("Parsing int "+std::to_string(v));
    llvm::APInt vInt(64, v, true);
    llvm::APSInt vsInt(vInt);
    return new ir::IntLiteral(llvmloc2Src(), vsInt, intType);
}

ir::Expr *Scanner::parseFloat(double v) {
    LOGMAX("Parsing float "+std::to_string(v));
    llvm::APFloat vFloat(v);
    return new ir::FloatLiteral(llvmloc2Src(), vFloat, floatType);
}

ir::Expr *Scanner::parseBool(bool v) {
    LOGMAX("Parsing bool "+std::string(v ? "true" : "false"));
    return new ir::BoolLiteral(llvmloc2Src(), v, boolType);
}

ir::Expr *Scanner::parseString(std::string v) {
    LOGMAX("Parsing string "+v);
    return new ir::StringLiteral(llvmloc2Src(), v, stringType);
}

ir::Expr *Scanner::parseNone() {
    LOGMAX("Parsing none");
    return new ir::NoneLiteral(llvmloc2Src(), noneType);
}

static std::string getFunTypeName(ir::TypeDecl *retType, std::vector<ir::IR *> argTypes) {
    std::string tName = retType->getName() + "(";
    bool first = true;
    for(auto i : argTypes) {
        if(!first) {
            tName += ",";
        }
        first = false;
        tName += i->getName();
    }
    tName += ")";
    return tName;
}

ir::Expr *Scanner::parseVar(std::string v, bool external, bool maybe_type) {
    LOGMAX("Parsing a variable "+v);
    if(!external) {
        auto var = currScope->lookup(v, maybe_type);
        if(!var) {
            var = currScope->lookupPossibleFun(v);
        }
        if(var) {
            if(llvm::isa<ir::VarDecl>(var)) {
                return new ir::VarAccess(llvm::dyn_cast<ir::VarDecl>(var));
            }
            else if(auto fun = llvm::dyn_cast<ir::FunctionDecl>(var)) {
                std::vector<ir::IR *> paramTypes;
                for(auto i : fun->getParams()) {
                    paramTypes.push_back(llvm::dyn_cast<ir::IR>(i->getType()));
                }
                auto ft = new ir::FunTypeDecl(currentIR, llvmloc2Src(), getFunTypeName(fun->getReturnType(), paramTypes), fun->getReturnType(), paramTypes);
                return new ir::VarAccess(fun, ft);
            }
            else if(llvm::isa<ir::FormalParamDecl>(var)) {
                return new ir::VarAccess(llvm::dyn_cast<ir::FormalParamDecl>(var));
            }
            else if(auto t = llvm::dyn_cast<ir::TypeDecl>(var)) {
                return new ir::VarAccess(t);
            }
            else {
                diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Only variable and function access is just yet implemented");
            }
        }
        else {
            return new ir::UnresolvedSymbolAccess(v, this->unknownType);
        }
        return nullptr;
    }
    else {
        size_t delPos = v.find(':');
        std::string modName = v.substr(0, delPos);
        std::string symbolName = v.substr(delPos+2, v.size()-2-delPos);
        LOGMAX("Parsing external symbol "+symbolName+" from module "+modName);
        return new ir::ExternalSymbolAccess(modName, symbolName, this->unknownType);
    }
}

ir::Expr *Scanner::parseUnaryPrefixExpr(ir::Expr *l, ir::Operator op, bool is_const) {
    LOGMAX("Creating expression: "+op.debug()+l->debug())
    auto tl = l->getType();
    auto type = tl;

    if(tl == unknownType) {
        type = unknownType;
    }
    else {
        switch(op.getKind()) {
            case ir::OperatorKind::OP_LNOT:
                if(tl->getName() != BOOL_CSTR) {
                    diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE_UNARY, op.debug(), tl->getName());
                }
            break;
            case ir::OperatorKind::OP_BNOT:
                if(tl->getName() != INT_CSTR) {
                    diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE_UNARY, op.debug(), tl->getName());
                }
            break;
            default: diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Unknown operator in an expression");
            break;
        }
    }

    return new ir::UnaryPrefixExpr(l, op, type, is_const);
}

ir::Expr *Scanner::parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const) {
    LOGMAX("Creating expression: "+l->debug()+" "+op.debug()+" "+r->debug())
    auto tl = l->getType();
    auto tr = r->getType();
    auto type = tl;
    if(op.getKind() != ir::OperatorKind::OP_ACCESS && (tl == unknownType || tr == unknownType)) {
        type = unknownType;
    }
    else {
        switch(op.getKind()) {
        case ir::OperatorKind::OP_ASSIGN:
            if(tl->getName() != tr->getName()) {
                if(tr->getName() == NONETYPE_CSTR) {
                    if(!tl->isMaybe()) {
                        diags.report(llvmloc2Src(), diag::ERR_CANNOT_ASSIGN_NONE);
                    }
                    type = tl;
                }
                else if(tl->isMaybe() && tr->getName() == ANY_CSTR) {
                    diags.report(llvmloc2Src(), diag::ERR_USE_CAST_FOR_ANY, tr->getName(), tl->getName());
                    type = tl;
                }
                else if(tl->getName() == ANY_CSTR) {
                    type = tl;
                }
                else if(tr->isUnresolved() || tr->getBaseName() == UNKNOWN_CSTR) {
                    type = tl;
                }
                else if(tl->isUnresolved() || tl->getBaseName() == UNKNOWN_CSTR) {
                    type = tr;
                }
                else {
                    diags.report(llvmloc2Src(), diag::ERR_INCORRECT_ASSIGNMENT, tr->getName(), tl->getName());
                }
            }
        break;
        case ir::OperatorKind::OP_ADD:
            if(tl->getName() == tr->getName() && tl->isMatrix()) {
                type = tl;
            }
            else {
                if(!utils::isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR}) || !utils::isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR})) {
                    diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
                }
                else {
                    // TODO: Kepp this implicit conversion?
                    // Int or Float
                    if(tl->getName() != tr->getName()) {
                        // One is float
                        type = this->floatType;
                    }
                }
            }
            break;
        case ir::OperatorKind::OP_SUB:
        case ir::OperatorKind::OP_MUL:
        case ir::OperatorKind::OP_DIV:
        case ir::OperatorKind::OP_MOD:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR}) || !utils::isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            else {
                // TODO: Kepp this implicit conversion?
                // Int or Float
                if(tl->getName() != tr->getName()) {
                    // One is float
                    type = this->floatType;
                }
            }
        break;
        case ir::OperatorKind::OP_CONCAT:
            type = this->stringType;
        break;
        case ir::OperatorKind::OP_POW:
            if(!utils::isOneOf(tl->getName(), {FLOAT_CSTR, INT_CSTR}) || !utils::isOneOf(tr->getName(), {FLOAT_CSTR, INT_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->floatType;
        break;
        case ir::OperatorKind::OP_BLSHFT:
        case ir::OperatorKind::OP_BRSHFT:
        case ir::OperatorKind::OP_BAND:
        case ir::OperatorKind::OP_BXOR:
        case ir::OperatorKind::OP_BOR:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR}) || !utils::isOneOf(tr->getName(), {INT_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->intType;
        break;
        case ir::OperatorKind::OP_BT:
        case ir::OperatorKind::OP_BEQ:
        case ir::OperatorKind::OP_LT:
        case ir::OperatorKind::OP_LEQ:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR}) ||
                !utils::isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            if(tl->getName() == STRING_CSTR || tr->getName() == STRING_CSTR) {
                if(tl->getName() != tr->getName()) {
                    diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
                }
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_EQ:
        case ir::OperatorKind::OP_NEQ:
            if(tl->isMatrix()) {
                if(tl->getName() != tr->getName()) {
                    if(!tl->isMaybe() || (tl->isMaybe() && tl->getName() != NONETYPE_CSTR && tr->getName() != NONETYPE_CSTR)) {
                        diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
                    }
                }
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_LAND:
        case ir::OperatorKind::OP_LOR:
            if(!utils::isOneOf(tl->getName(), {BOOL_CSTR}) || !utils::isOneOf(tr->getName(), {BOOL_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_IN:
            if(tr->isMatrix()) {
                // TODO: Handle maybe elements, its possible to check for none
                if(tl->getName() == NONETYPE_CSTR) {
                    // TODO: Check if ELEMENT IS Maybe (not array)
                    diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "IN for maybe (none) is not yet implemented");
                }
                else if(tr->getMatrixSize().size() != tl->getMatrixSize().size()+1 || tr->getBaseName() != tl->getBaseName()) {
                    // TODO: Possibly specify that the left side has to have one less dimension that the right one
                    diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
                }
            }
            else if(tr->getName() != STRING_CSTR || tl->getName() != STRING_CSTR) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_SUBSCR:
            if((!tl->isMatrix() && !utils::isOneOf(tl->getName(), {STRING_CSTR})) || !utils::isOneOf(tr->getName(), {INT_CSTR})) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }

            if(tl->isMatrix()) {
                if(!tl->getDecl()) {
                    diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Somehow root type for matrix was not set");
                }
                type = llvm::dyn_cast<ir::TypeDecl>(tl->getDecl());
                if(!type) {
                    diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Somehow root type for matrix is incorrect");
                }
            }
            else {
                type = tl;
            }
        break;
        case ir::OperatorKind::OP_AS:
            // TODO: Add checks for compatible conversions
            if(tr->isMaybe() && tl->getName() != ANY_CSTR) {
                diags.report(llvmloc2Src(), diag::ERR_CANNOT_CAST_TO_MAYBE);
            }
            type = tr;
        break;
        case ir::OperatorKind::OP_ACCESS:
        {
            std::string elemName;
            if(auto elem = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(r)) {
                elemName = elem->getName();
            }
            else if(auto elem = llvm::dyn_cast<ir::VarAccess>(r)) { 
                elemName = elem->getVar()->getName();
            }
            else if(auto elem = llvm::dyn_cast<ir::MemberAccess>(r)) { 
                elemName = elem->getDecl()->getName();
            }
            else {
                diags.report(llvmloc2Src(), diag::ERR_BAD_STRUCT_ELEM);
            }
            ir::TypeDecl *struType = l->getType();
            if(struType->getDecl()) {
                auto struDecl = llvm::dyn_cast<ir::StructDecl>(struType->getDecl());
                if(struDecl) {
                    // Check if the element is present in the struct
                    ir::IR *found = nullptr;
                    int index = 0;
                    for(index = 0; static_cast<size_t>(index) < struDecl->getElements().size(); ++index) {
                        if(struDecl->getElements()[index]->getName() == elemName) {
                            found = struDecl->getElements()[index];
                            break;
                        }
                    }
                    if(found) {
                        if(auto fvar = llvm::dyn_cast<ir::VarDecl>(found)) {
                            type = fvar->getType();
                            //auto oldR = r;
                            r = new ir::MemberAccess(found, index, type);
                            // FIXME: delete oldR
                            //delete oldR;
                        }
                        else if(auto fvar = llvm::dyn_cast<ir::StructDecl>(found)) {
                            //TODO: Handle and set r correctly
                            (void)fvar;
                            diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "NOT YET IMPLEMENTED Structs inside of structs access");
                        }
                        else {
                            diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "unknown element type in a struct");
                        }
                    }
                    else {
                        diags.report(llvmloc2Src(), diag::ERR_HAS_NO_MEMBER, "struct "+struDecl->getName(), elemName);
                    }
                }
                else {
                    diags.report(llvmloc2Src(), diag::ERR_TYPE_NOT_STRUCT, struType->getName());
                }
            }
            /*else if(auto lmem = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(l)) {
                
            }*/
            else {
                // TODO: this can be also an expr (nested access) or a function call
                // TODO: Allow also structLiteral?
                // Split access into var assignments
                if(!struType->isUnresolved()) {
                    diags.report(llvmloc2Src(), diag::ERR_TYPE_NOT_STRUCT, struType->getName());
                }
            }
        }
        break;
        case ir::OperatorKind::OP_SLICE:
        {
            if((!tl->isMatrix() && !utils::isOneOf(tl->getName(), {STRING_CSTR})) || !llvm::isa<ir::Range>(r)) {
                diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = tl;
        }
        break;
        default: diags.report(llvmloc2Src(), diag::ERR_INTERNAL, "Unknown operator in an expression");
        break;
        }
    }
    return new ir::BinaryInfixExpr(l, r, op, type, is_const);
}

std::vector<ir::Expr *> Scanner::parseFunCallArg(ir::Expr *e) {
    LOGMAX("Creating new function call list with "+e->debug());
    std::vector<ir::Expr *> list{e};
    return list;    
}

std::vector<ir::Expr *> Scanner::parseAddFunCallArg(std::vector<ir::Expr *> &list, ir::Expr *e) {
    LOGMAX("Pushing new argument into call list: "+e->debug());
    list.push_back(e);
    return list;
}

std::vector<ir::Expr *> Scanner::parseMatrixSize(ir::Expr *e) {
    LOGMAX("Creating new matrix size list with "+e->debug());
    std::vector<ir::Expr *> list{e};
    return list;    
}

std::vector<ir::Expr *> Scanner::parseAddMatrixSize(std::vector<ir::Expr *> &list, ir::Expr *e) {
    LOGMAX("Pushing new matrix size "+e->debug());
    list.push_back(e);
    return list;
}

void Scanner::addStructTemplatedFunction(ir::TypeDecl *t) {
    ir::TypeDecl *tPtr = t->clone();
    tPtr->setMaybe(true);
    //auto stDecl = llvm::dyn_cast<ir::StructDecl>(t->getDecl());
    auto body = std::vector<ir::IR *> {};
    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "s", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "s", t, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "equals_"+t->getName()+"_"+t->getName(),
                                                "equals",
                                                this->boolType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }
}

void Scanner::addMatrixTemplatedFunction(ir::TypeDecl *t, ir::TypeDecl *elemTOG) {
    if(t->getBaseName() == UNKNOWN_CSTR)
        return;
    ir::TypeDecl *tPtr = t->clone();
    tPtr->setMaybe(true);
    auto elemT = elemTOG->clone();
    auto elemTPtr = elemT->clone();
    elemTPtr->setMaybe(true);
    if(elemT->isMaybe()) {
        elemT->setMaybe(false);
    }
    auto body = std::vector<ir::IR *> {};
    
    // Append cannot be generated for non-maybe function type
    if(!llvm::isa<ir::FunTypeDecl>(elemTOG)) {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemT, false)
        };
        auto funAppend = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "append_"+t->getName()+"_"+elemT->getName(),
                                                "append",
                                                this->voidType,
                                                params,
                                                body);
        globalScope->insert(funAppend);
        mainModule->addLibFunction(funAppend);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemTPtr, true)
        };
        auto funAppend = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "mappend_"+t->getName()+"_"+elemTPtr->getName(),
                                                "mappend",
                                                this->voidType,
                                                params,
                                                body);
        globalScope->insert(funAppend);
        mainModule->addLibFunction(funAppend);
    }

    {
        auto paramsMat = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false)
        };
        auto funLength = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "length_"+t->getName(),
                                                "length",
                                                this->intType,
                                                paramsMat,
                                                body);
        globalScope->insert(funLength);
        mainModule->addLibFunction(funLength);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m1", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m2", t, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "equals_"+t->getName()+"_"+t->getName(),
                                                "equals",
                                                this->boolType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemT, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "find_"+t->getName()+"_"+elemT->getName(),
                                                "find",
                                                this->intType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemT, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "contains_"+t->getName()+"_"+elemT->getName(),
                                                "contains",
                                                this->boolType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "start", intType, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "next", intType, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "end", intType, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "slice_"+t->getName()+"_int_int_int",
                                                "slice",
                                                t,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "start", intType, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "end", intType, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "slice_"+t->getName()+"_int_int",
                                                "slice",
                                                t,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", t, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "reverse_"+t->getName(),
                                                "reverse",
                                                t,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m1", t, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m2", t, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "join_"+t->getName()+"_"+t->getName(),
                                                "join",
                                                t,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "index", intType, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "remove_"+t->getName()+"_"+intType->getName(),
                                                "remove",
                                                voidType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    if(!llvm::isa<ir::FunTypeDecl>(elemTOG)) {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemT, false),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "index", intType, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "insert_"+t->getName()+"_"+elemT->getName()+"_int",
                                                "insert",
                                                voidType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "v", elemTPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "index", intType, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "minsert_"+t->getName()+"_"+elemTPtr->getName()+"_int",
                                                "minsert",
                                                voidType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }

    {
        std::vector<ir::IR *> cmpparams{elemT, elemT};
        auto cmpfun = new ir::FunTypeDecl(tPtr->getEnclosingIR(), llvmloc2Src(), getFunTypeName(boolType, cmpparams), boolType, cmpparams);

        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "m", tPtr, true),
            new ir::FormalParamDecl(currentIR, llvmloc2Src(), "cmp", cmpfun, false)
        };
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvmloc2Src(),
                                                "sort_"+t->getName()+"_"+cmpfun->getName(),
                                                "sort",
                                                voidType,
                                                params,
                                                body);
        globalScope->insert(fun);
        mainModule->addLibFunction(fun);
    }
}

std::map<std::string, ir::Expr *> Scanner::parseStructVals(std::string name, ir::Expr *e) {
    LOGMAX("Creating new stuct value "+e->debug());
    std::map<std::string, ir::Expr *> list;
    list[name] = e;
    return list;
}

std::map<std::string, ir::Expr *> Scanner::parseStructVals(std::map<std::string, ir::Expr *> &list, std::string name, ir::Expr *e) {
    LOGMAX("Adding new stuct value "+e->debug());
    list[name] = e;
    return list;
}

ir::Expr *Scanner::parseExternalStructLiteral(ir::IR *type, std::map<std::string, ir::Expr *> values) {
    LOGMAX("Parsing external struct literal");
    auto t = llvm::dyn_cast<ir::TypeDecl>(type);
    return new ir::StructLiteral(llvmloc2Src(), t, values);
}

ir::Expr *Scanner::parseStructLiteral(ir::IR *type, std::map<std::string, ir::Expr *> values) {
    LOGMAX("Parsing struct literal");
    auto t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(!t) {
        diags.report(llvmloc2Src(), diag::ERR_TYPE_NOT_STRUCT, type->getName());
    }
    if(!t->getDecl() || !llvm::isa<ir::StructDecl>(t->getDecl())) {
        diags.report(llvmloc2Src(), diag::ERR_TYPE_NOT_STRUCT, type->getName());
    }
    // This cast is checked above
    auto sdt = llvm::dyn_cast<ir::StructDecl>(t->getDecl());
    // Check key correctness
    for(auto [k, v] : values) {
        ir::VarDecl *elemD = nullptr;
        for(auto e : sdt->getElements()) {
            if(e->getName() == k) {
                elemD = llvm::dyn_cast<ir::VarDecl>(e);
                break;
            }
        }
        if(!elemD) {
            diags.report(llvmloc2Src(), diag::ERR_HAS_NO_MEMBER, "struct "+sdt->getName(), k);
            continue;
        } else if(elemD->getType()->getName() != v->getType()->getName()) {
            diags.report(llvmloc2Src(), diag::ERR_INCORRECT_ASSIGNMENT, elemD->getType()->getName(), v->getType()->getName());
        }
    }
    return new ir::StructLiteral(llvmloc2Src(), t, values);
}

ir::IR *Scanner::parseExtType(std::string name, bool isMaybe) {
    LOGMAX("Parsing external type");
    auto t = new ir::TypeDecl(currentIR, llvmloc2Src(), name);
    t->setMaybe(isMaybe);
    t->setUnresolved(true);
    t->setExternalIR(llvm::dyn_cast<ir::ExternalSymbolAccess>(parseVar(name, true)));
    return t;
}

ir::IR *Scanner::parseMaybeMatrixType(ir::IR *type) {
    LOGMAX("Parsing maybe matrix type");
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    auto tm = t->clone();
    tm->setMaybe(true);
    return tm;
}

ir::IR *Scanner::parseMatrixType(std::string name, std::vector<ir::Expr *> &matsize, bool isMaybe) {
    auto ogName = name;
    for(size_t i = 0; i < matsize.size(); ++i) {
        name += "[]";
    }
    LOGMAX("Creating matrix type "+name+(isMaybe ? "(maybe type)" : ""));
    auto rootType = sym_lookup(name, isMaybe, true);
    if(auto rootDecl = llvm::dyn_cast<ir::TypeDecl>(rootType)) {
        if(isMaybe) {
            rootDecl = rootDecl->clone();
            rootDecl->setMaybe(true);
        }
        auto elemT = rootDecl;
        auto elemName = ogName;
        auto prevElemT = rootDecl;
        for(size_t i = 0; i < matsize.size()-1; ++i) {
            elemName += "[]";
            std::vector<ir::Expr *> elemSize;
            for(size_t j = 0; j <= i; ++j) {
                elemSize.push_back(matsize[j]);
            }
            elemT = new ir::TypeDecl(currentIR, llvmloc2Src(), elemName, elemSize, elemT);
            addMatrixTemplatedFunction(elemT, prevElemT);
            prevElemT = elemT;
        }
        auto t = new ir::TypeDecl(currentIR, llvmloc2Src(), name, matsize, elemT);

        addMatrixTemplatedFunction(t, elemT);

        return t;
    }
    diags.report(llvmloc2Src(), diag::ERR_NOT_A_TYPE, name);
    return nullptr;
}

ir::IR *Scanner::parseMatrixType(ir::IR *rootType, std::vector<ir::Expr *> &matsize) {
    auto ogName = rootType->getName();
    std::string name = rootType->getName();
    for(size_t i = 0; i < matsize.size(); ++i) {
        name += "[]";
    }
    LOGMAX("Creating matrix function type "+name);
    if(auto rootDecl = llvm::dyn_cast<ir::TypeDecl>(rootType)) {
        auto elemT = rootDecl;
        auto elemName = ogName;
        auto prevElemT = rootDecl;
        for(size_t i = 0; i < matsize.size()-1; ++i) {
            elemName += "[]";
            std::vector<ir::Expr *> elemSize;
            for(size_t j = 0; j <= i; ++j) {
                elemSize.push_back(matsize[j]);
            }
            elemT = new ir::TypeDecl(currentIR, llvmloc2Src(), elemName, elemSize, elemT);
            addMatrixTemplatedFunction(elemT, prevElemT);
            prevElemT = elemT;
        }
        auto t = new ir::TypeDecl(currentIR, llvmloc2Src(), name, matsize, elemT);

        addMatrixTemplatedFunction(t, elemT);

        return t;
    }
    diags.report(llvmloc2Src(), diag::ERR_NOT_A_TYPE, name);
    return nullptr;
}

std::vector<ir::Expr *> Scanner::parseMatrixValue(ir::Expr *e) {
    LOGMAX("Creating new matrix with "+e->debug());
    std::vector<ir::Expr *> list{e};
    return list;
}

std::vector<ir::Expr *> Scanner::parseAddMatrixValue(std::vector<ir::Expr *> &list, ir::Expr *e) {
    LOGMAX("Pushing new matrix value "+e->debug());
    list.push_back(e);
    return list;
}

ir::Expr *Scanner::parseMatrix(std::vector<ir::Expr *> values) {
    LOGMAX("Creating new matrix literal");
    ir::TypeDecl *t = unknownType;
    if(!values.empty()) {
        ir::TypeDecl *elT = values[0]->getType();
        t = new ir::TypeDecl(elT->getEnclosingIR(), elT->getLocation(), elT->getName()+"[]", values, elT);
        addMatrixTemplatedFunction(t, elT);
    }
    return new ir::MatrixLiteral(llvmloc2Src(), values, t);
}

static bool isIntvalExpr(ir::Expr *e) {
    if(e->getType()->getName() == UNKNOWN_CSTR) {
        return true;
    }
    if(e->getType()->getName() == INT_CSTR) {
        return true;
    }
    return false;
}

ir::Expr *Scanner::parseRange(ir::Expr *start, ir::Expr *second, ir::Expr *end) {
    LOGMAX("Parsing range "+start->debug()+","+second->debug()+".."+end->debug());
    if(!isIntvalExpr(start)) {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_RANGE_TYPE, "first", start->getType()->getName());
    }
    if(!isIntvalExpr(second)) {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_RANGE_TYPE, "second", second->getType()->getName());
    }
    if(!isIntvalExpr(end)) {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_RANGE_TYPE, "last", end->getType()->getName());
    }
    return new ir::Range(start, parseInfixExpr(second, start, ir::Operator(ir::OperatorKind::OP_SUB), false), end, rangeType);
}

ir::Expr *Scanner::parseRange(ir::Expr *start, ir::Expr *end) {
    LOGMAX("Parsing range "+start->debug()+".."+end->debug());
    if(!isIntvalExpr(start)) {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_RANGE_TYPE, "first", start->getType()->getName());
    }
    if(!isIntvalExpr(end)) {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_RANGE_TYPE, "last", end->getType()->getName());
    }
    return new ir::Range(start, nullptr, end, rangeType);
}

ir::IR *Scanner::parseImports(std::vector<std::string> names) {
    LOGMAX("Parsing import list");
    for(auto n: names) {
        addModuleToCompile(n);
    }
    return new ir::Import(currentIR, llvmloc2Src(), names);
}

std::vector<std::string> Scanner::parseImportName(std::string name) {
    LOGMAX("Parsing import name "+name);
    std::vector<std::string> list{name};
    return list;
}

std::vector<std::string> Scanner::parseAddImportName(std::vector<std::string> &list, std::string name) {
    LOGMAX("Parsing import name "+name);
    list.push_back(name);
    return list;
}

std::vector<ir::FormalParamDecl *> Scanner::parseFunParam(ir::IR *type, std::string name) {
    LOGMAX("Creating new function param list with "+type->getName()+" "+name);
    auto t = llvm::dyn_cast<ir::TypeDecl>(type);
    auto fp = new ir::FormalParamDecl(currentIR, llvmloc2Src(), name, t, t->isMaybe());
    std::vector<ir::FormalParamDecl *> list{fp};
    currScope->insert(fp);
    return list;
}

std::vector<ir::FormalParamDecl *> Scanner::parseAddFunParam(std::vector<ir::FormalParamDecl *> &list, ir::IR *type, std::string name) {
    LOGMAX("Pushing new argument into function param list: "+name);
    auto t = llvm::dyn_cast<ir::TypeDecl>(type);
    auto fp = new ir::FormalParamDecl(currentIR, llvmloc2Src(), name, t, t->isMaybe());
    list.push_back(fp);
    currScope->insert(fp);
    return list;
}

std::vector<ir::IR *> Scanner::parseStmtBody(ir::IR *stmt) {
    if(!stmt) {
        LOGMAX("Creating empty statement body");
        std::vector<ir::IR *> body{};
        return body;
    }
    else {
        LOGMAX("Creating statement body "+stmt->debug());
        std::vector<ir::IR *> body{stmt};
        return body;
    }
}

std::vector<ir::IR *> Scanner::parseStmtBodyAdd(std::vector<ir::IR *> &body, ir::IR *stmt) {
    if(!stmt) {
        LOGMAX("Nullptr was to be added to statement body");
        return body;
    }
    LOGMAX("Adding to a statement body "+stmt->debug());
    body.push_back(stmt);
    return body;
}

ir::IR *Scanner::parseFunType(ir::IR *retType, std::vector<ir::IR *> argTypes) {
    LOGMAX("Parsing function type");
    return new ir::FunTypeDecl(currentIR, llvmloc2Src(), getFunTypeName(llvm::dyn_cast<ir::TypeDecl>(retType), argTypes), llvm::dyn_cast<ir::TypeDecl>(retType), argTypes);
}

std::vector<ir::IR *> Scanner::parseFunTypeList(ir::IR *type) {
    LOGMAX("Creating list of function types");
    std::vector<ir::IR *> list{type};
    return list;
}

std::vector<ir::IR *> Scanner::parseFunTypeListAdd(std::vector<ir::IR *> &list, ir::IR *type) {
    LOGMAX("Adding type to function type list "+type->debug());
    list.push_back(type);
    return list;
}

ir::IR *Scanner::parseStruct(std::string name, std::vector<ir::IR *> body) {
    LOGMAX("Parsing struct "+name);
    auto structDecl = new ir::StructDecl(currentIR, llvmloc2Src(), name, body);
    structDecl->setLibType(lib);
    auto structType = new ir::TypeDecl(currentIR, llvmloc2Src(), name, structDecl);
    for(auto b = body.begin(), end = body.end(); b != end; ++b) {
        auto e = *b;
        if(ir::VarDecl *elem = llvm::dyn_cast<ir::VarDecl>(e)) {
            if(std::count_if(b, body.end(), 
                [elem](ir::IR *i) { 
                    return llvm::isa<ir::VarDecl>(i) && 
                    (llvm::dyn_cast<ir::VarDecl>(i)->getName() == elem->getName()); 
                }) != 1) {
                diags.report(llvmloc2Src(), diag::ERR_DUPL_STRUCT_MEMBER, elem->getName(), name);
            }
        }
        else {
            diags.report(llvmloc2Src(), diag::ERR_SYNTAX, "Unknown construct inside of struct declaration");
        }
    }
    if(!currScope->insert(structType)) {
        diags.report(llvmloc2Src(), diag::ERR_SYM_ALREADY_DECLARED, name);
    }
    addStructTemplatedFunction(structType);
    return structDecl;
}

ir::IR *Scanner::parseStructElement(ir::IR *type, const std::string name, ir::Expr *value) {
    if(!type) {
        LOGMAX("Type for vardecl is nullptr");
        return nullptr;
    }
    LOGMAX("struct element "+type->getName()+" "+name);
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(t) {
        auto v = new ir::VarDecl(currentIR, type->getLocation(), name, t, value);
        return v;
    }
    else {
        diags.report(type->getLocation(), diag::ERR_VARDECL_REQUIRES_TYPE);
    }
    return nullptr;
}

std::vector<ir::IR *> Scanner::parseAddStructElement(ir::IR *elem, std::vector<ir::IR *> body) {
    LOGMAX("Adding struct element to struct declaration list");
    body.insert(body.begin(), elem);
    return body;
}

static bool isUnknownType(ir::Expr *e) {
    if(e->getType()->getBaseName() == UNKNOWN_CSTR || llvm::isa<ir::UnresolvedSymbolAccess>(e) || llvm::isa<ir::ExternalSymbolAccess>(e)) {
        return true;
    }

    else if(auto s = llvm::dyn_cast<ir::FunctionCall>(e)) {
        return s->isUnresolved() || s->isExternal();
    }
    else if(auto s = llvm::dyn_cast<ir::BinaryInfixExpr>(e)) {
        return isUnknownType(s->getLeft()) || isUnknownType(s->getRight());
    }
    else if(auto s = llvm::dyn_cast<ir::UnaryPrefixExpr>(e)) {
        return isUnknownType(s->getExpr());
    }
    else if(auto s = llvm::dyn_cast<ir::MatrixLiteral>(e)) {
        if(s->getType()->getBaseName() == UNKNOWN_CSTR) {
            return false;
        }
        for(auto a : s->getValue()) {
            if(isUnknownType(a)) {
                return true;
            }
        }
        return false;
    }
    else if(auto s = llvm::dyn_cast<ir::StructLiteral>(e)) {
        for(auto [_, v] : s->getValues()) {
            if(isUnknownType(v)) {
                return true;
            }
        }
        return false;
    }
    else if(auto s = llvm::dyn_cast<ir::Range>(e)) {
        return isUnknownType(s->getStart()) || isUnknownType(s->getStep()) || isUnknownType(s->getEnd());
    }
    return false;
}

ir::Expr *Scanner::parseFunCall(ir::Expr *fun, std::vector<ir::Expr *> params) {
    if(!fun) {
        LOG1("Function call called with nullptr function");
        return nullptr;
    }
    LOGMAX("Parsing function call "+fun->debug());
    // TODO: Handle when calling on return value
    auto var = llvm::dyn_cast<ir::VarAccess>(fun);
    if(var) {
        if(auto f = llvm::dyn_cast<ir::FunctionDecl>(var->getVar())) {
            for(auto p: params) {
                if(isUnknownType(p)) {
                    LOGMAX("Unresolved or external parameter in a function call, returning as unresolved");
                    return new ir::FunctionCall(new ir::UnresolvedSymbolAccess(f->getOGName(), fun->getType()), params);
                }
            }

            // The function chosen in parseVar could have different parameters
            std::string properName = encodeFunction(f->getOGName(), params, lib);
            auto propFIR = currScope->lookup(properName);
            if(!propFIR) {
                // Lib functions
                // first try adding the arguments to the name
                std::string appendix = "";
                for(auto p: params) {
                    appendix+="_"+p->getType()->getName();
                }
                propFIR = currScope->lookup(f->getOGName()+appendix);
                /*if(!propFIR) {
                    propFIR = currScope->lookup(f->getName());
                }*/
            }
            if(!propFIR) {
                diags.report(llvmloc2Src(), diag::ERR_INCORRECT_ARGS_DET, f->getOGName(), ir::block2List(f->getParams()), ir::block2List(params));
                return nullptr;
            }
            auto propF = llvm::dyn_cast<ir::FunctionDecl>(propFIR);

            auto fc = new ir::FunctionCall(propF, params);
            return fc;
        } else if (auto v = llvm::dyn_cast<ir::VarDecl>(var->getVar())) {
            if(llvm::isa<ir::FunTypeDecl>(v->getType())) {
                auto fc = new ir::FunctionCall(v, params);
                return fc;
            }
            else {
                diags.report(llvmloc2Src(), diag::ERR_NOT_CALLABLE, var->getVar()->getName());
            }
        }else if (auto v = llvm::dyn_cast<ir::FormalParamDecl>(var->getVar())) {
            if(llvm::isa<ir::FunTypeDecl>(v->getType())) {
                auto fc = new ir::FunctionCall(v, params);
                return fc;
            }
            else {
                diags.report(llvmloc2Src(), diag::ERR_NOT_CALLABLE, var->getVar()->getName());
            }
        } else {
            diags.report(llvmloc2Src(), diag::ERR_NOT_CALLABLE, var->getVar()->getName());
        }
    }
    else {
        if(auto symb = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(fun)) {
            return new ir::FunctionCall(symb, params);
        }
        else if(auto symb = llvm::dyn_cast<ir::ExternalSymbolAccess>(fun)) {
            return new ir::FunctionCall(symb, params);
        }
        else if(llvm::isa<ir::FunTypeDecl>(fun->getType())) {
            return new ir::FunctionCall(fun, params);
        }
        else {
            diags.report(llvmloc2Src(), diag::ERR_NOT_CALLABLE, fun->debug());
        }
    }
    return nullptr;
}

ir::IR *Scanner::parseIfStmt(ir::Expr *cond, std::vector<ir::IR *> &ifBranch, std::vector<ir::IR *> &elseBranch) {
    LOGMAX("Parsing if statement");
    if(cond->getType() != boolType && cond->getType()->getName() != UNKNOWN_CSTR) {
        diags.report(llvmloc2Src(), diag::ERR_IF_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto ifstmt = new ir::IfStatement(currentIR, llvmloc2Src(), "if", cond, ifBranch, elseBranch);
    // Set enclosing IR for all statements in the body to this
    for(auto i : ifBranch) {
        i->setEnclosingIR(ifstmt);
    }
    for(auto i : elseBranch) {
        i->setEnclosingIR(ifstmt);
    }
    return ifstmt;
}

ir::IR *Scanner::parseWhile(ir::Expr *cond, std::vector<ir::IR *> &body) {
    LOGMAX("Parsing while");
    if(cond->getType() != boolType && cond->getType()->getName() != UNKNOWN_CSTR) {
        diags.report(llvmloc2Src(), diag::ERR_WHILE_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto whl = new ir::WhileStmt(currentIR, llvmloc2Src(), "while", cond, body);
    // Set enclosing IR for all statements in the body to this
    for(auto i : body) {
        i->setEnclosingIR(whl);
    }
    return whl;
}

ir::IR *Scanner::parseDoWhile(ir::Expr *cond, std::vector<ir::IR *> &body) {
    LOGMAX("Parsing do while");
    if(cond->getType() != boolType && cond->getType()->getName() != UNKNOWN_CSTR) {
        diags.report(llvmloc2Src(), diag::ERR_WHILE_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto whl = new ir::WhileStmt(currentIR, llvmloc2Src(), "do", cond, body, true);
    // Set enclosing IR for all statements in the body to this
    for(auto i : body) {
        i->setEnclosingIR(whl);
    }
    return whl;
}

ir::IR *Scanner::parseForeach(ir::Expr *i, ir::Expr *collection, std::vector<ir::IR *> &body, bool defineI) {
    LOGMAX("Parsing foreach");
    bool hasUnknown = collection->getType()->getName() == UNKNOWN_CSTR || i->getType()->getName() == UNKNOWN_CSTR;
    if(!hasUnknown && collection->getType()->getName() == STRING_CSTR && i->getType()->getName() != STRING_CSTR) {
        diags.report(llvmloc2Src(), diag::ERR_MISMATCHED_FOR_TYPES, i->getType()->getName(), collection->getType()->getName());
    }
    else if(!hasUnknown && collection->getType()->isMatrix()) {
        if(!collection->getType()->getDecl()) {
            diags.report(llvmloc2Src(), diag::ERR_MISMATCHED_FOR_TYPES, i->getType()->getName(), collection->getType()->getName());
        }
        else if(collection->getType()->getDecl()->getName() != i->getType()->getName()) {
            diags.report(llvmloc2Src(), diag::ERR_MISMATCHED_FOR_TYPES, i->getType()->getName(), collection->getType()->getName());
        }
    }
    else if(!hasUnknown && collection->getType()->getName() == RANGE_CSTR) {
        if(i->getType()->getName() != INT_CSTR) {
            diags.report(llvmloc2Src(), diag::ERR_MISMATCHED_RANGE_TYPE);
        }
    }
    else if(!hasUnknown && collection->getType()->getName() != STRING_CSTR && i->getType()->getName() != STRING_CSTR){
        diags.report(llvmloc2Src(), diag::ERR_UNSUPPORTED_FOR_TYPE, collection->getType()->getName());
    }
    auto freach = new ir::ForeachStmt(currentIR, llvmloc2Src(), "for", i, collection, body, defineI);
    // Set enclosing IR for all statements in the body to this
    for(auto i : body) {
        i->setEnclosingIR(freach);
    }
    if(defineI) {
        auto vracc = llvm::dyn_cast<ir::VarAccess>(i);
        vracc->getVar()->setEnclosingIR(freach);
    }
    return freach;
}

ir::IR *Scanner::parseForeach(ir::IR *i, ir::Expr *collection, std::vector<ir::IR *> &body) {
    if(auto ivd = llvm::dyn_cast<ir::VarDecl>(i)) {
        return parseForeach(new ir::VarAccess(ivd), collection, body, true);
    }
    else {
        diags.report(llvmloc2Src(), diag::ERR_INCORRECT_FOR_CONSTRUCT);
        return nullptr;
    }
}

ir::IR *Scanner::parseFun(ir::IR *type, std::string name, std::vector<ir::FormalParamDecl *> params, std::vector<ir::IR *> body) {
    LOGMAX("Parsing a function "+name);
    auto ctype = llvm::dyn_cast<ir::TypeDecl>(type);
    auto f = llvm::dyn_cast<ir::FunctionDecl>(currentIR);
    std::string encname = encodeFunction(name, params, lib);
    if(sym_lookup(encname)) {
        diags.report(llvmloc2Src(), diag::ERR_FUNCTION_REDEFINITION, name);
    }
    f->resolveFunction(llvmloc2Src(), encname, name, ctype, params, body);
    leaveScope();
    currScope->insert(f);

    return f;
}

void Scanner::parseEntry(std::vector<ir::IR *> body) {
    LOGMAX("Parsing entry");
    std::vector<ir::IR *> entryBody;
    for(auto i: body) {
        if(auto f = llvm::dyn_cast<ir::FunctionDecl>(i)) {
            if(f->getName() == _ENTRY_NAME) {
                continue;
            }
            this->decls.push_back(f);
        }
        else if(llvm::isa<ir::VarDecl>(i) ||
            llvm::isa<ir::TypeDecl>(i) ||
            llvm::isa<ir::StructDecl>(i) ||
            llvm::isa<ir::Import>(i)) {
            this->decls.push_back(i);
        }
        else {
            entryBody.push_back(i);
        }
    }
    
    std::vector<ir::FormalParamDecl *> params{};
    this->decls.push_back(new ir::FunctionDecl(mainModule,
                                                llvmloc2Src(),
                                                _ENTRY_NAME,
                                                _ENTRY_NAME,
                                                voidType,
                                                params,
                                                entryBody));
}
