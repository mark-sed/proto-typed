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
#include "llvm/Support/Casting.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/APSInt.h"
#include <cstring>
#include <initializer_list>
#include <algorithm>

using namespace ptc;

// Helper functions

/**
 * @param v Value to check if is in accepted
 * @param accepted Accepted values
 * @return true if v is in accepted
 * @return false if v is not in accepted
 */
template<typename T>
bool isOneOf(T v, std::initializer_list<T> accepted) {
    return std::find(begin(accepted), end(accepted), v) != std::end(accepted);
}
bool isOneOf(llvm::StringRef v, std::initializer_list<std::string> accepted) {
    return std::find(begin(accepted), end(accepted), v.str().c_str()) != std::end(accepted);
}

std::string encodeFunction(std::string name, ir::TypeDecl *retType, std::vector<ir::FormalParamDecl *> params) {
    std::string paramStr;
    for(auto p : params) {
        paramStr += p->getType()->getName()+p->getName()+"_";
    }
    return name+"_"+retType->getName()+std::to_string(params.size())+paramStr;
}

Scanner::Scanner(Diagnostics &diags) : currentIR(nullptr), diags(diags) {
    loc = new Parser::location_type();
    init();
}

void Scanner::init() {
    currScope = new Scope();
    

    llvmloc = llvm::SMLoc();

    // TODO: Maybe set the name to the module's correct name?
    mainModule = new ir::ModuleDecl(nullptr, llvm::SMLoc(), "mainModule");
    currentIR = mainModule;

    intType = new ir::TypeDecl(currentIR, llvm::SMLoc(), INT_CSTR);
    floatType = new ir::TypeDecl(currentIR, llvm::SMLoc(), FLOAT_CSTR);
    stringType = new ir::TypeDecl(currentIR, llvm::SMLoc(), STRING_CSTR);
    boolType = new ir::TypeDecl(currentIR, llvm::SMLoc(), BOOL_CSTR);
    voidType = new ir::TypeDecl(currentIR, llvm::SMLoc(), VOID_CSTR);

    currScope->insert(intType);
    currScope->insert(boolType);
    currScope->insert(floatType);
    currScope->insert(stringType);
    currScope->insert(voidType);

    auto printParams = std::vector<ir::FormalParamDecl *>{
        new ir::FormalParamDecl(currentIR, llvmloc, "v", this->intType, false)
    };
    auto printBody = std::vector<ir::IR *> {
        // TODO
    };
    auto printIntFun = new ir::FunctionDecl(currentIR,
                                            llvm::SMLoc(),
                                            encodeFunction("print", this->voidType, printParams),
                                            this->voidType,
                                            printParams,
                                            printBody);
    currScope->insert(printIntFun);
}

void Scanner::parse(std::istream *code) {
    this->switch_streams(code);
    loc = new Parser::location_type();
    auto parser = new Parser(this);

    if(parser->parse() != 0) {
        // TODO: ERROR
        log::error("Could not parse the source code.");
        exit(1);
    }

    mainModule->setDecls(this->decls);

    LOG1("\n-----\nIR generated:\n");
    LOG1(mainModule->debug());
    /*for(auto a : this->decls) {
        std::cout << a->debug() << "\n";
    }*/
}

void Scanner::removeQuotes(char **str) {
    // Remove first quote
    *str = &(*str)[1];
    // Remove last quote
    (*str)[std::strlen(*str)-1] = '\0';
}

ir::IR *Scanner::parseVarDecl(ir::IR *type, const std::string name) {
    LOGMAX(type->getName()+" "+name);
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(t) {
        auto v = new ir::VarDecl(currentIR, type->getLocation(), name, t);
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

ir::Expr *Scanner::parseInt(long v) {
    LOGMAX("Parsing int "+std::to_string(v));
    llvm::APInt vInt(64, v, true);
    llvm::APSInt vsInt(vInt);
    return new ir::IntLiteral(llvmloc, vsInt, intType);
}

ir::Expr *Scanner::parseFloat(double v) {
    LOGMAX("Parsing float "+std::to_string(v));
    llvm::APFloat vFloat(v);
    // TODO:
    return nullptr;
}

ir::Expr *Scanner::parseBool(bool v) {
    LOGMAX("Parsing bool "+std::string(v ? "true" : "false"));
    return new ir::BoolLiteral(llvmloc, v, boolType);
}

ir::Expr *Scanner::parseString(std::string v) {
    // TODO:
    return nullptr;
}

ir::Expr *Scanner::parseVar(std::string v) {
    LOGMAX("Parsing a variable "+v);
    auto var = currScope->lookup(v);
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
        diags.report(llvmloc, diag::ERR_UNDEFINED_VAR, v);
        return nullptr;
    }
    return nullptr;
}

ir::Expr *Scanner::parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const) {
    LOGMAX("Creating expression: "+l->debug()+" "+op.debug()+" "+r->debug())
    auto tl = l->getType();
    auto tr = r->getType();
    auto type = tl;
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
        if(!isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR}) || !isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR})) {
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
        if(!isOneOf(tl->getName(), {FLOAT_CSTR}) || !isOneOf(tr->getName(), {FLOAT_CSTR})) {
            diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
        }
        type = this->floatType;
    break;
    case ir::OperatorKind::OP_BLSHFT:
    case ir::OperatorKind::OP_BRSHFT:
    case ir::OperatorKind::OP_BAND:
    case ir::OperatorKind::OP_BXOR:
    case ir::OperatorKind::OP_BOR:
        if(!isOneOf(tl->getName(), {INT_CSTR}) || !isOneOf(tr->getName(), {INT_CSTR})) {
            diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
        }
        type = this->intType;
    break;
    case ir::OperatorKind::OP_BT:
    case ir::OperatorKind::OP_BEQ:
    case ir::OperatorKind::OP_LT:
    case ir::OperatorKind::OP_LEQ:
        if(!isOneOf(tl->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR}) ||
            !isOneOf(tr->getName(), {INT_CSTR, FLOAT_CSTR, STRING_CSTR})) {
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
        if(!isOneOf(tl->getName(), {BOOL_CSTR}) || !isOneOf(tr->getName(), {BOOL_CSTR})) {
            diags.report(llvmloc, diag::ERR_UNSUPPORTED_OP_TYPE, op.debug(), tl->getName(), tr->getName());
        }
        type = this->boolType;
    break;
    case ir::OperatorKind::OP_IN:
        // TODO: check that tr is a matrix
        type = this->boolType;
    break;
    default: diags.report(llvmloc, diag::ERR_INTERNAL, "Unknown operator in an expression");
    break;
    }
    return new ir::BinaryInfixExpr(l, r, op, type, is_const);
}

ir::IR *Scanner::parseVarDef(ir::IR *type, std::string name, ir::Expr *value) {
    this->parseVarDecl(type, name);
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

ir::Expr *Scanner::parseFunCall(ir::Expr *fun, std::vector<ir::Expr *> params) {
    if(!fun) {
        LOG1("Function call called with nullptr function");
        return nullptr;
    }
    LOGMAX("Parsing function call "+fun->debug());
    // TODO: Handle when calling on return value
    auto var = llvm::dyn_cast<ir::VarAccess>(fun);
    if(var) {
        auto fir = this->sym_lookup(var->getVar()->getName());
        if(fir) {
            auto f = llvm::dyn_cast<ir::FunctionDecl>(fir);
            if(f) {
                auto fc = new ir::FunctionCall(f, params);
                return fc;
            }
            else {
                diags.report(llvmloc, diag::ERR_NOT_CALLABLE, var->getVar()->getName());
            }
        }
        else {
            diags.report(llvmloc, diag::ERR_UNDEFINED_VAR, var->getVar()->getName());
        }
    }
    else {
        diags.report(llvmloc, diag::ERR_INTERNAL, "Function call is not implemented for expressions");
    }
    return nullptr;
}

ir::IR *Scanner::parseIfStmt(ir::Expr *cond, std::vector<ir::IR *> &ifBranch, std::vector<ir::IR *> &elseBranch) {
    LOGMAX("Parsing if statement");
    if(cond->getType() != boolType) {
        diags.report(llvmloc, diag::ERR_IF_COND_MUST_BE_BOOL, cond->getType()->getName());
    }
    auto ifstmt = new ir::IfStatement(currentIR, llvmloc, "if", cond, ifBranch, elseBranch);
    return ifstmt;
}

ir::IR *Scanner::parseFun(ir::IR *type, std::string name, std::vector<ir::Expr *> params, std::vector<ir::IR *> body) {
    LOGMAX("Parsing a function");
    
    std::vector<ir::FormalParamDecl *> formParams{};
    //for(auto p: params) {
        // TODO: convert
    //}

    auto ctype = llvm::dyn_cast<ir::TypeDecl>(type);
    return new ir::FunctionDecl(currentIR, llvmloc, encodeFunction(name, ctype, formParams), ctype, formParams, body);
}

void Scanner::parseMain(std::vector<ir::IR *> body) {
    LOGMAX("Parsing main");
    for(auto i: body) {
        this->decls.push_back(i);
    }
}
