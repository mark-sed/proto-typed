#include "constant_folder.hpp"
#include "llvm/ADT/APSInt.h"
#include "llvm/ADT/APFloat.h"
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

ir::Expr *transformFloatExpr(ir::FloatLiteral *a, ir::FloatLiteral *b, std::function<double(double, double)> f) {
    llvm::APFloat v(f(a->getValue().convertToDouble(), b->getValue().convertToDouble()));
    return new ir::FloatLiteral(a->getLocation(), v, a->getType());
}

double powd(double a, double b) {
    return pow(a, b);
}

double modd(double a, double b) {
    return fmod(a, b);
}

long blshift(long a, long b) {
    return a << b;
}

long brshift(long a, long b) {
    return a >> b;
}

long band(long a, long b) {
    return a & b;
}

long bor(long a, long b) {
    return a | b;
}

long bxor(long a, long b) {
    return a ^ b;
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
        //auto lvNone = llvm::dyn_cast<ir::NoneLiteral>(lv);

        auto rvInt = llvm::dyn_cast<ir::IntLiteral>(rv);
        auto rvFloat = llvm::dyn_cast<ir::FloatLiteral>(rv);
        auto rvBool = llvm::dyn_cast<ir::BoolLiteral>(rv);
        auto rvString = llvm::dyn_cast<ir::StringLiteral>(rv);
        //auto rvNone = llvm::dyn_cast<ir::NoneLiteral>(rv);

        switch(bie->getOperator().getKind()) {
            case ir::OperatorKind::OP_ADD: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::plus<long>());
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, std::plus<double>());
            }
            break;
            case ir::OperatorKind::OP_SUB: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::minus<long>());
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, std::minus<double>());
            }
            break;
            case ir::OperatorKind::OP_MUL: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::multiplies<long>());
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, std::multiplies<double>());
            }
            break;
            case ir::OperatorKind::OP_DIV: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::divides<long>());
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, std::divides<double>());
            }
            break;
            case ir::OperatorKind::OP_POW: {
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, powd);
            }
            break;
            case ir::OperatorKind::OP_MOD: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, std::modulus<long>());
                if(lvFloat && rvFloat) return transformFloatExpr(lvFloat, rvFloat, modd);
            }
            break;
            case ir::OperatorKind::OP_BLSHFT: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, blshift);
            }
            break;
            case ir::OperatorKind::OP_BRSHFT: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, brshift);
            }
            break;
            case ir::OperatorKind::OP_BT: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() > rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() > rvFloat->getValue().convertToDouble()), lvFloat->getType());
            }
            break;
            case ir::OperatorKind::OP_BEQ: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() >= rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() >= rvFloat->getValue().convertToDouble()), lvFloat->getType());
            }
            break;
            case ir::OperatorKind::OP_LT: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() < rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() < rvFloat->getValue().convertToDouble()), lvFloat->getType());
            }
            break;
            case ir::OperatorKind::OP_LEQ: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() <= rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() <= rvFloat->getValue().convertToDouble()), lvFloat->getType());
            }
            break;
            case ir::OperatorKind::OP_EQ: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() == rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() == rvFloat->getValue().convertToDouble()), lvFloat->getType());
                if(lvBool && rvBool) return new ir::BoolLiteral(lvBool->getLocation(), (lvBool->getValue() == rvBool->getValue()), lvBool->getType());
                if(lvString && rvString) return new ir::BoolLiteral(lvString->getLocation(), (lvString->getValue() == rvString->getValue()), lvString->getType());
            }
            break;
            case ir::OperatorKind::OP_NEQ: {
                if(lvInt && rvInt) return new ir::BoolLiteral(lvInt->getLocation(), (lvInt->getValue().getExtValue() != rvInt->getValue().getExtValue()), lvInt->getType());
                if(lvFloat && rvFloat) return new ir::BoolLiteral(lvFloat->getLocation(), (lvFloat->getValue().convertToDouble() != rvFloat->getValue().convertToDouble()), lvFloat->getType());
                if(lvBool && rvBool) return new ir::BoolLiteral(lvBool->getLocation(), (lvBool->getValue() != rvBool->getValue()), lvBool->getType());
                if(lvString && rvString) return new ir::BoolLiteral(lvString->getLocation(), (lvString->getValue() != rvString->getValue()), lvString->getType());
            }
            break;
            case ir::OperatorKind::OP_BAND: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, band);
            }
            break;
            case ir::OperatorKind::OP_BXOR: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, bxor);
            }
            break;
            case ir::OperatorKind::OP_BOR: {
                if(lvInt && rvInt) return transformIntExpr(lvInt, rvInt, bor);
            }
            break;
            case ir::OperatorKind::OP_LAND: {
                if(lvBool && rvBool) return new ir::BoolLiteral(lvBool->getLocation(), (lvBool->getValue() && rvBool->getValue()), lvBool->getType());
            }
            break;
            case ir::OperatorKind::OP_LOR: {
                if(lvBool && rvBool) return new ir::BoolLiteral(lvBool->getLocation(), (lvBool->getValue() || rvBool->getValue()), lvBool->getType());
            }
            break;
            case ir::OperatorKind::OP_CONCAT: {
                if(lvString && rvString) {
                    std::string conc = lvString->getValue() + rvString->getValue();
                    return new ir::StringLiteral(lvString->getLocation(), conc, lvString->getType());
                }
            }
            break;
            default: break;
            /*case ir::OperatorKind::OP_ACCESS: return ".";
            case ir::OperatorKind::OP_SUBSCR: return "[]";
            case ir::OperatorKind::OP_AS: return "as";
            case ir::OperatorKind::OP_SLICE: return "[..]";*/
        }
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