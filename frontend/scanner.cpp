/**
 * @file scanner.cpp
 * @author Marek Sedlacek
 * @brief Scanner and parsing driver (semantics)
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
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

using namespace ptc;

// Helper functions

std::string ptc::encodeFunction(std::string name, std::vector<ir::FormalParamDecl *> params) {
    assert(name.size() > 0 && "Function name cannot be empty");
    std::string paramStr;
    for(auto p : params) {
        paramStr += p->getType()->getName()+"_";
    }
    return name+"_"+std::to_string(params.size())+paramStr;
}

std::string ptc::encodeFunction(std::string name, std::vector<ir::Expr *> params) {
    assert(name.size() > 0 && "Function name cannot be empty");
    std::string paramStr;
    for(auto p : params) {
        paramStr += p->getType()->getName()+"_";
    }
    return name+"_"+std::to_string(params.size())+paramStr;
}

Scanner::Scanner(Diagnostics &diags, std::string moduleName) : currentIR(nullptr), diags(diags), moduleName(moduleName) {
    loc = new Parser::location_type();
    init();
}

Scanner::~Scanner() {
    delete globalScope;
}

void Scanner::init() {
    currScope = new Scope();
    globalScope = currScope; // This will be overriden by module scope

    llvmloc = llvm::SMLoc();

    mainModule = new ir::ModuleDecl(nullptr, llvm::SMLoc(), moduleName);
    currentIR = mainModule;

    intType = new ir::TypeDecl(currentIR, llvm::SMLoc(), INT_CSTR);
    floatType = new ir::TypeDecl(currentIR, llvm::SMLoc(), FLOAT_CSTR);
    stringType = new ir::TypeDecl(currentIR, llvm::SMLoc(), STRING_CSTR);
    boolType = new ir::TypeDecl(currentIR, llvm::SMLoc(), BOOL_CSTR);
    voidType = new ir::TypeDecl(currentIR, llvm::SMLoc(), VOID_CSTR);

    unknownType = new ir::TypeDecl(currentIR, llvm::SMLoc(), UNKNOWN_CSTR);

    currScope->insert(intType);
    currScope->insert(boolType);
    currScope->insert(floatType);
    currScope->insert(stringType);
    currScope->insert(voidType);

    {
        auto printParams = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc, "v", this->stringType, false)
        };
        auto printBody = std::vector<ir::IR *> {};
        auto printFun = new ir::FunctionDecl(currentIR,
                                                llvm::SMLoc(),
                                                "print_string",
                                                "print",
                                                this->voidType,
                                                printParams,
                                                printBody);
        currScope->insert(printFun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc, "v", this->intType, false)
        };
        auto body = std::vector<ir::IR *> {};
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvm::SMLoc(),
                                                "to_string_int",
                                                "to_string",
                                                this->stringType,
                                                params,
                                                body);
        currScope->insert(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc, "v", this->floatType, false)
        };
        auto body = std::vector<ir::IR *> {};
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvm::SMLoc(),
                                                "to_string_float",
                                                "to_string",
                                                this->stringType,
                                                params,
                                                body);
        currScope->insert(fun);
    }

    {
        auto params = std::vector<ir::FormalParamDecl *>{
            new ir::FormalParamDecl(currentIR, llvmloc, "v", this->boolType, false)
        };
        auto body = std::vector<ir::IR *> {};
        auto fun = new ir::FunctionDecl(currentIR,
                                                llvm::SMLoc(),
                                                "to_string_bool",
                                                "to_string",
                                                this->stringType,
                                                params,
                                                body);
        currScope->insert(fun);
    }
}

void Scanner::parse(std::istream *code) {
    this->switch_streams(code);
    loc = new Parser::location_type();
    auto parser = new Parser(this);

    enterScope(mainModule);
    globalScope = currScope;
    if(parser->parse() != 0) {
        // TODO: ERROR
        log::error("Could not parse the source code.");
        exit(1);
    }
    leaveScope();

    mainModule->setDecls(this->decls);

    LOG1("\n-----\nIR generated:\n");
    LOG1(mainModule->debug());
    /*for(auto a : this->decls) {
        std::cout << a->debug() << "\n";
    }*/
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
                diags.report(llvmloc, diag::ERR_INTERNAL, "Hexadecimal escape sequences are not yet implemented");
            break;
            case 'o':
                diags.report(llvmloc, diag::ERR_INTERNAL, "Octal escape sequences are not yet implemented");
            break;
            case 'u':
                diags.report(llvmloc, diag::ERR_INTERNAL, "Unicode escape sequences are not yet implemented");
            break;
            case 'U':
                diags.report(llvmloc, diag::ERR_INTERNAL, "Unicode escape sequences are not yet implemented");
            break;
            case 'N':
                diags.report(llvmloc, diag::ERR_INTERNAL, "Unicode escape sequences are not yet implemented");
            break;
            default:
                diags.report(llvmloc, diag::ERR_UNKNOWN_ESC_SEQ, std::string("\\")+c);
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
    diags.report(llvm::SMLoc(), d, msg);
}

void Scanner::enterScope(ir::IR *decl) {
    LOGMAX("Creating new scope");
    currScope = new Scope(currScope);
    currentIR = decl;
}

void Scanner::enterFunScope() {
    LOGMAX("Creating new function scope");
    currScope = new Scope(currScope);
    currentIR = new ir::FunctionDecl(currentIR);
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
        LOGMAX("Type for vardecl is nullptr");
        return nullptr;
    }
    LOGMAX(type->getName()+" "+name);
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(t) {
        auto v = new ir::VarDecl(currentIR, type->getLocation(), name, t, value);
        if(currScope->insert(v)) {
            //this->decls.push_back(v);
        }
        else {
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
    auto v = new ir::ExprStmt(currentIR, llvmloc, "Expression", e);
    //this->decls.push_back(v);
    return v;
}

ir::IR *Scanner::parseReturn(ir::Expr *e) {
    LOGMAX("Parsing return");
    return new ir::ReturnStmt(e, currentIR, llvmloc, "Return");
}

ir::IR *Scanner::parseBreak() {
    LOGMAX("Parsing break");
    return new ir::BreakStmt(currentIR, llvmloc);
}

ir::IR *Scanner::parseContinue() {
    LOGMAX("Parsing break");
    return new ir::ContinueStmt(currentIR, llvmloc);
}

ir::Expr *Scanner::parseInt(long v) {
    LOGMAX("Parsing int "+std::to_string(v));
    llvm::APInt vInt(64, v, true);
    llvm::APSInt vsInt(vInt);
    return new ir::IntLiteral(llvmloc, vsInt, intType);
}

ir::Expr *Scanner::parseFloat(double v) {
    LOGMAX("Parsing float "+std::to_string(v));
    llvm::APFloat vFloat(v);
    return new ir::FloatLiteral(llvmloc, vFloat, floatType);
}

ir::Expr *Scanner::parseBool(bool v) {
    LOGMAX("Parsing bool "+std::string(v ? "true" : "false"));
    return new ir::BoolLiteral(llvmloc, v, boolType);
}

ir::Expr *Scanner::parseString(std::string v) {
    LOGMAX("Parsing string "+v);
    return new ir::StringLiteral(llvmloc, v, stringType);
}

ir::Expr *Scanner::parseVar(std::string v, bool external) {
    LOGMAX("Parsing a variable "+v);
    if(!external) {
        auto var = currScope->lookup(v);
        if(!var) {
            var = currScope->lookupPossibleFun(v);
        }
        if(var) {
            if(llvm::isa<ir::VarDecl>(var)) {
                return new ir::VarAccess(llvm::dyn_cast<ir::VarDecl>(var));
            }
            else if(llvm::isa<ir::FunctionDecl>(var)) {
                return new ir::VarAccess(llvm::dyn_cast<ir::FunctionDecl>(var), this->intType);
            }
            else if(llvm::isa<ir::FormalParamDecl>(var)) {
                return new ir::VarAccess(llvm::dyn_cast<ir::FormalParamDecl>(var));
            }
            else {
                diags.report(llvmloc, diag::ERR_INTERNAL, "Only variable and function access is just yet implemented");
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
                if((tl->getName() == FLOAT_CSTR && tr->getName() == INT_CSTR)
                || (tl->getName() == INT_CSTR && tr->getName() == FLOAT_CSTR)) {
                    type = tl;
                }
                else {
                    diags.report(llvmloc, diag::ERR_INVALID_CONVERSION, tr->getName(), tl->getName());
                }
            }
        break;
        case ir::OperatorKind::OP_ADD:
            // FIXME: Handle matrices
        case ir::OperatorKind::OP_SUB:
        case ir::OperatorKind::OP_MUL:
        case ir::OperatorKind::OP_DIV:
        case ir::OperatorKind::OP_MOD:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR}) || !utils::isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR})) {
                diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            else {
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
            if(!utils::isOneOf(tl->getName(), {FLOAT_CSTR}) || !utils::isOneOf(tr->getName(), {FLOAT_CSTR})) {
                diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->floatType;
        break;
        case ir::OperatorKind::OP_BLSHFT:
        case ir::OperatorKind::OP_BRSHFT:
        case ir::OperatorKind::OP_BAND:
        case ir::OperatorKind::OP_BXOR:
        case ir::OperatorKind::OP_BOR:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR}) || !utils::isOneOf(tr->getName(), {INT_CSTR})) {
                diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->intType;
        break;
        case ir::OperatorKind::OP_BT:
        case ir::OperatorKind::OP_BEQ:
        case ir::OperatorKind::OP_LT:
        case ir::OperatorKind::OP_LEQ:
            if(!utils::isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR}) ||
                !utils::isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR})) {
                diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            if(tl->getName() == STRING_CSTR || tr->getName() == STRING_CSTR) {
                if(tl->getName() != tr->getName()) {
                    diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
                }
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_EQ:
        case ir::OperatorKind::OP_NEQ:
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_LAND:
        case ir::OperatorKind::OP_LOR:
            if(!utils::isOneOf(tl->getName(), {BOOL_CSTR}) || !utils::isOneOf(tr->getName(), {BOOL_CSTR})) {
                diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
            }
            type = this->boolType;
        break;
        case ir::OperatorKind::OP_IN:
            // TODO: check that tr is a matrix
            type = this->boolType;
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
                diags.report(llvmloc, diag::ERR_BAD_STRUCT_ELEM);
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
                            diags.report(llvmloc, diag::ERR_INTERNAL, "NOT YET IMPLEMENTED Structs inside of structs access");
                        }
                        else {
                            diags.report(llvmloc, diag::ERR_INTERNAL, "unknown element type in a struct");
                        }
                    }
                    else {
                        diags.report(llvmloc, diag::ERR_HAS_NO_MEMBER, "struct "+struDecl->getName(), elemName);
                    }
                }
                else {
                    diags.report(llvmloc, diag::ERR_TYPE_NOT_STRUCT, struType->getName());
                }
            }
            /*else if(auto lmem = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(l)) {
                
            }*/
            else {
                // TODO: this can be also an expr (nested access) or a function call
                // TODO: Allow also structLiteral?
                // Split access into var assignments
                diags.report(llvmloc, diag::ERR_TYPE_NOT_STRUCT, struType->getName());
            }
        }
        break;
        default: diags.report(llvmloc, diag::ERR_INTERNAL, "Unknown operator in an expression");
        break;
        }
    }
    return new ir::BinaryInfixExpr(l, r, op, type, is_const);
}

ir::IR *Scanner::parseVarDef(ir::IR *type, std::string name, ir::Expr *value) {
    LOGMAX("Variable definition");
    auto vdecl = this->parseVarDecl(type, name, value);
    this->decls.push_back(vdecl);
    auto e = this->parseInfixExpr(this->parseVar(name), value, ir::Operator(ir::OperatorKind::OP_ASSIGN));
    return this->parseExprStmt(e);
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

ir::IR *Scanner::parseMatrixType(std::string name, std::vector<ir::Expr *> &matsize) {
    LOGMAX("Creating matrix type "+name+"[...]");
    auto rootType = sym_lookup(name, true);
    if(auto rootDecl = llvm::dyn_cast<ir::TypeDecl>(rootType)) {
        return new ir::TypeDecl(currentIR, llvmloc, name, matsize, rootDecl->getDecl());
    }
    diags.report(llvmloc, diag::ERR_NOT_A_TYPE, name);
    return nullptr;
}

ir::IR *Scanner::parseImports(std::vector<std::string> names) {
    LOGMAX("Parsing import list");
    for(auto n: names) {
        addModuleToCompile(n);
    }
    return new ir::Import(currentIR, llvmloc, names);
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
    LOGMAX("Creating new function param list with "+name);
    // TODO: Handle by reference
    auto fp = new ir::FormalParamDecl(currentIR, llvmloc, name, llvm::dyn_cast<ir::TypeDecl>(type));
    std::vector<ir::FormalParamDecl *> list{fp};
    currScope->insert(fp);
    //this->decls.push_back(fp);
    return list;
}

std::vector<ir::FormalParamDecl *> Scanner::parseAddFunParam(std::vector<ir::FormalParamDecl *> &list, ir::IR *type, std::string name) {
    LOGMAX("Pushing new argument into function param list: "+name);
    // TODO: Handle by reference
    auto fp = new ir::FormalParamDecl(currentIR, llvmloc, name, llvm::dyn_cast<ir::TypeDecl>(type));
    list.push_back(fp);
    currScope->insert(fp);
    //this->decls.push_back(fp);
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

ir::IR *Scanner::parseStruct(std::string name, std::vector<ir::IR *> body) {
    LOGMAX("Parsing struct "+name);
    auto structDecl = new ir::StructDecl(currentIR, llvmloc, name, body);
    auto structType = new ir::TypeDecl(currentIR, llvm::SMLoc(), name, structDecl);
    for(auto b = body.begin(), end = body.end(); b != end; ++b) {
        auto e = *b;
        if(ir::VarDecl *elem = llvm::dyn_cast<ir::VarDecl>(e)) {
            if(std::count_if(b, body.end(), 
                [elem](ir::IR *i) { 
                    return llvm::isa<ir::VarDecl>(i) && 
                    (llvm::dyn_cast<ir::VarDecl>(i)->getName() == elem->getName()); 
                }) != 1) {
                diags.report(llvmloc, diag::ERR_DUPL_STRUCT_MEMBER, elem->getName(), name);
            }
        }
        else {
            diags.report(llvmloc, diag::ERR_SYNTAX, "Unknown construct inside of struct declaration");
        }
    }
    if(!currScope->insert(structType)) {
        diags.report(llvmloc, diag::ERR_SYM_ALREADY_DECLARED, name);
    }
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
            // The function chosen in parseVar could have different parameters
            std::string properName = encodeFunction(f->getOGName(), params);
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
                diags.report(llvmloc, diag::ERR_INCORRECT_ARGS, f->getOGName());
            }
            auto propF = llvm::dyn_cast<ir::FunctionDecl>(propFIR);

            auto fc = new ir::FunctionCall(propF, params);
            return fc;
        }
        else {
            diags.report(llvmloc, diag::ERR_NOT_CALLABLE, var->getVar()->getName());
        }
    }
    else {
        if(auto symb = llvm::dyn_cast<ir::UnresolvedSymbolAccess>(fun)) {
            return new ir::FunctionCall(symb, params);
        }
        else {
            diags.report(llvmloc, diag::ERR_INTERNAL, "Function call is not implemented for expressions");
        }
    }
    return nullptr;
}

ir::IR *Scanner::parseIfStmt(ir::Expr *cond, std::vector<ir::IR *> &ifBranch, std::vector<ir::IR *> &elseBranch) {
    LOGMAX("Parsing if statement");
    if(cond->getType() != boolType) {
        diags.report(llvmloc, diag::ERR_IF_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto ifstmt = new ir::IfStatement(currentIR, llvmloc, "if", cond, ifBranch, elseBranch);
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
    if(cond->getType() != boolType) {
        diags.report(llvmloc, diag::ERR_WHILE_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto whl = new ir::WhileStmt(currentIR, llvmloc, "while", cond, body);
    // Set enclosing IR for all statements in the body to this
    for(auto i : body) {
        i->setEnclosingIR(whl);
    }
    return whl;
}

ir::IR *Scanner::parseFun(ir::IR *type, std::string name, std::vector<ir::FormalParamDecl *> params, std::vector<ir::IR *> body) {
    LOGMAX("Parsing a function "+name);
    auto ctype = llvm::dyn_cast<ir::TypeDecl>(type);
    auto f = llvm::dyn_cast<ir::FunctionDecl>(currentIR);
    f->resolveFunction(llvmloc, encodeFunction(name, params), name, ctype, params, body);
    leaveScope();
    currScope->insert(f);

    return f;
}

void Scanner::parseEntry(std::vector<ir::IR *> body) {
    LOGMAX("Parsing entry");
    std::vector<ir::IR *> entryBody;
    for(auto i: body) {
        if(llvm::isa<ir::VarDecl>(i) ||
            llvm::isa<ir::TypeDecl>(i) ||
            llvm::isa<ir::FunctionDecl>(i) ||
            llvm::isa<ir::TypeDecl>(i) ||
            llvm::isa<ir::StructDecl>(i)) {
            this->decls.push_back(i);
        }
        else {
            entryBody.push_back(i);
        }
    }
    std::vector<ir::FormalParamDecl *> params{};
    this->decls.push_back(new ir::FunctionDecl(mainModule,
                                                llvmloc,
                                                "_entry",
                                                "_entry",
                                                voidType,
                                                params,
                                                entryBody));
}
