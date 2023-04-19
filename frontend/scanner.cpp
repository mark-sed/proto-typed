#include "scanner.hpp"
#include "logging.hpp"
#include "llvm/Support/Casting.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/APSInt.h"
#include <cstring>
#include <initializer_list>
#include <algorithm>

using namespace ptc;

Scanner::Scanner(Diagnostics &diags) : currentIR(nullptr), diags(diags) {
    loc = new Parser::location_type();
    init();
}

void Scanner::init() {
    currScope = new Scope();
    currentIR = nullptr;

    llvmloc = llvm::SMLoc();
    
    intType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "int");
    floatType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "float");
    stringType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "string");
    boolType = new ir::TypeDecl(currentIR, llvm::SMLoc(), "bool");

    currScope->insert(intType);
    currScope->insert(boolType);
    currScope->insert(floatType);
    currScope->insert(stringType);
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
}

void Scanner::removeQuotes(char **str) {
    // Remove first quote
    *str = &(*str)[1];
    // Remove last quote
    (*str)[std::strlen(*str)-1] = '\0';
}

ir::IR *Scanner::parseVarDecl(ir::IR *type, std::string name) {
    LOGMAX(type->getName().str()+" "+name);
    ir::TypeDecl *t = llvm::dyn_cast<ir::TypeDecl>(type);
    if(t) {
        auto v = new ir::VarDecl(currentIR, type->getLocation(), name, t);
        if(currScope->insert(v)) {
            this->decls.push_back(v);
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
    this->decls.push_back(v);
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
    auto var = currScope->lookup(v);
    if(var) {
        return new ir::VarAccess(llvm::dyn_cast<ir::VarDecl>(var));
    }
    else {
        diags.report(llvmloc, diag::ERR_UNDEFINED_VAR, v);
        return nullptr;
    }
}

ir::Expr *Scanner::parseInfixExpr(ir::Expr *l, ir::Expr *r, ir::Operator op, bool is_const) {
    LOGMAX("Creating expression: "+l->debug()+" "+op.debug()+" "+r->debug())
    auto tl = l->getType();
    auto tr = r->getType();
    auto type = tl;
    switch(op.getKind()) {
    case ir::OperatorKind::OP_ASSIGN:
        if(tl->getName() != tr->getName()) {
            if((tl->getName() == "float" && tr->getName() == "int")
              || (tl->getName() == "int" && tr->getName() == "float")) {
                type = tl;
            }
            else {
                diags.report(llvmloc, diag::ERR_INVALID_CONVERSION, tl->getName(), tr->getName());
            }
        }
    break;
    case ir::OperatorKind::OP_ADD:
        // FIXME: Handle matrices
    case ir::OperatorKind::OP_SUB:
    case ir::OperatorKind::OP_MUL:
    case ir::OperatorKind::OP_DIV:
    case ir::OperatorKind::OP_MOD:
        // Int or Float
        if(tl->getName() != tr->getName()) {
            // One is float
            type = this->floatType;
        }
    break;
    case ir::OperatorKind::OP_CONCAT:
        type = this->stringType;
    break;
    case ir::OperatorKind::OP_POW:
        type = this->floatType;
    break;
    case ir::OperatorKind::OP_BLSHFT:
    case ir::OperatorKind::OP_BRSHFT:
    case ir::OperatorKind::OP_BAND:
    case ir::OperatorKind::OP_BXOR:
    case ir::OperatorKind::OP_BOR:
        type = this->intType;
    break;
    case ir::OperatorKind::OP_BT:
    case ir::OperatorKind::OP_BEQ:
    case ir::OperatorKind::OP_LT:
    case ir::OperatorKind::OP_LEQ:
    case ir::OperatorKind::OP_EQ:
    case ir::OperatorKind::OP_NEQ:
    case ir::OperatorKind::OP_LAND:
    case ir::OperatorKind::OP_LOR:
    case ir::OperatorKind::OP_IN:
        type = this->boolType;
    break;
    default: diags.report(llvmloc, diag::ERR_INTERNAL, "Unknown operator in an expression");
    break;
    }
    return new ir::BinaryInfixExpr(l, r, op, type, is_const);
}

