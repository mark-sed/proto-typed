#include "constant_folder.hpp"
#include "llvm/ADT/APSInt.h"
#include <functional>

using namespace ptc;

bool is_const_expr(ir::Expr *e) {
    return llvm::isa<ir::IntLiteral>(e) ||
            llvm::isa<ir::FloatLiteral>(e) ||
            llvm::isa<ir::BoolLiteral>(e) ||
            llvm::isa<ir::StringLiteral>(e) ||
            llvm::isa<ir::NoneLiteral>(e);
}

ir::Expr *transformIntExpr(ir::IntLiteral *a, ir::IntLiteral *b, std::function<long(long, long)> f) {
    llvm::APInt nvI(64, f(a->getValue().getExtValue(), b->getValue().getExtValue()), true);
    llvm::APSInt nv(nvI);
    return new ir::IntLiteral(a->getLocation(), nv, a->getType());
}

ir::Expr *foldExpr(ir::Expr *e) {
    if(is_const_expr(e)) {
        return e;
    }

    if(auto va = llvm::dyn_cast<ir::VarAccess>(e)) {
        if(auto vd = llvm::dyn_cast<ir::VarDecl>(va->getVar())) {
            if(vd->getInitValue() && is_const_expr(vd->getInitValue())) {
                return vd->getInitValue();
            }
        }
    }
    else if(auto bie = llvm::dyn_cast<ir::BinaryInfixExpr>(e)) {
        auto lv = foldExpr(bie->getLeft());
        if(!lv) return nullptr;
        auto rv = foldExpr(bie->getRight());
        if(!rv) return nullptr;

        auto lvInt = llvm::dyn_cast<ir::IntLiteral>(lv);
        auto lvFloat = llvm::dyn_cast<ir::FloatLiteral>(lv);
        auto lvBool = llvm::dyn_cast<ir::BoolLiteral>(lv);
        auto lvString = llvm::dyn_cast<ir::StringLiteral>(lv);
        auto lvNone = llvm::dyn_cast<ir::NoneLiteral>(lv);

        auto rvInt = llvm::dyn_cast<ir::IntLiteral>(rv);
        auto rvFloat = llvm::dyn_cast<ir::FloatLiteral>(rv);
        auto rvBool = llvm::dyn_cast<ir::BoolLiteral>(rv);
        auto rvString = llvm::dyn_cast<ir::StringLiteral>(rv);
        auto rvNone = llvm::dyn_cast<ir::NoneLiteral>(rv);

        ir::Expr *newExpr = nullptr;
        switch(bie->getOperator().getKind()) {
            case ir::OperatorKind::OP_ADD: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::plus<long>());
            }
            break;
            case ir::OperatorKind::OP_SUB: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::minus<long>());
            }
            break;
            case ir::OperatorKind::OP_MUL: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::multiplies<long>());
            }
            break;
            /*case ir::OperatorKind::OP_POW: return "**";
            case ir::OperatorKind::OP_DIV: return "/";
            case ir::OperatorKind::OP_MOD: return "%";
            case ir::OperatorKind::OP_BLSHFT: return "<<";
            case ir::OperatorKind::OP_BRSHFT: return ">>";
            case ir::OperatorKind::OP_BT: return ">";
            case ir::OperatorKind::OP_BEQ: return ">=";
            case ir::OperatorKind::OP_LT: return "<";
            case ir::OperatorKind::OP_LEQ: return "<=";
            case ir::OperatorKind::OP_EQ: return "==";
            case ir::OperatorKind::OP_NEQ: return "!=";
            case ir::OperatorKind::OP_BAND: return "&";
            case ir::OperatorKind::OP_BXOR: return "^";
            case ir::OperatorKind::OP_BOR: return "|";
            case ir::OperatorKind::OP_IN: return "in";
            case ir::OperatorKind::OP_LAND: return "and";
            case ir::OperatorKind::OP_LOR: return "or";
            case ir::OperatorKind::OP_CONCAT: return "++";
            case ir::OperatorKind::OP_ASSIGN: return "=";
            case ir::OperatorKind::OP_ACCESS: return ".";
            case ir::OperatorKind::OP_SUBSCR: return "[]";
            case ir::OperatorKind::OP_LNOT: return "!";
            case ir::OperatorKind::OP_BNOT: return "~";
            case ir::OperatorKind::OP_AS: return "as";
            case ir::OperatorKind::OP_SLICE: return "[..]";*/
        }
        return newExpr;
    }

    return nullptr;
}

void ConstantFolder::run() {
    for(auto decl: mod->getDecls()) {
        if(auto vd = llvm::dyn_cast<ir::VarDecl>(decl)) {
            if(vd->getInitValue() && !is_const_expr(vd->getInitValue())) {
                auto folded = foldExpr(vd->getInitValue());
                if(folded)
                    vd->setInitValue(folded);
            }
        }
    }
}