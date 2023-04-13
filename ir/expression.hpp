#ifndef _EXPRESSION_HPP_
#define _EXPRESSION_HPP_

#include "ir.hpp"
#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/APSInt.h"

namespace ptc {

namespace ir {

enum ExprKind {
    EX_BIN_INF,
    EX_BIN_PRE,
    EX_INT,
    EX_BOOL,
    EX_FLOAT,
    EX_STRING,
    EX_NONE,
    EX_VAR
};

enum OperatorKind {
    OP_ADD,
    OP_SUB,
    OP_UNKNOWN
};


class Operator {
private:
    llvm::SMLoc loc;
    OperatorKind kind;
    bool unspecified;
public:
    Operator() : loc(), kind(OperatorKind::OP_UNKNOWN), unspecified(true) {}
    Operator(llvm::SMLoc loc, OperatorKind kind, bool unspecified=false) : loc(loc),
                                                                           kind(kind),
                                                                           unspecified(unspecified) {
    }

    llvm::SMLoc getLocation() const { return loc; }
    OperatorKind getKind() const { return kind; }
    bool isUnspecified() const { return unspecified; }
};


class Expr {
private:
    const ExprKind kind;
    TypeDecl *type;
    bool is_const;
protected:
    Expr(ExprKind kind, TypeDecl *type, bool is_const) : kind(kind), type(type), is_const(is_const) {}

public:
    ExprKind getKind() const { return kind; }
    TypeDecl *getType() { return type; }
    void setType(TypeDecl *t) { type = t; }
    bool isConst() { return is_const; }
};


class BinaryInfixExpr : public Expr {
private:
    Expr *left;
    Expr *right;
    const Operator op;
public:
    BinaryInfixExpr(Expr *left, Expr *right, Operator op, TypeDecl *type, bool is_const) 
                   : Expr(ExprKind::EX_BIN_INF, type, is_const),
                     left(left),
                     right(right),
                     op(op) {
    }

    Expr *getLeft() { return left; }
    Expr *getRight() { return right; }
    const Operator &getOperator() { return op; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_BIN_INF;
    }
};


class BinaryPrefixExpr : public Expr {
private:
    Expr *e;
    const Operator op;
public:
    BinaryPrefixExpr(Expr *e, Operator op, TypeDecl *type, bool is_const)
                    : Expr(ExprKind::EX_BIN_PRE, type, is_const),
                      e(e),
                      op(op) {
    }

    Expr *getExpr() { return e; }
    const Operator &getOperator() { return op; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_BIN_PRE;
    }
};


class IntLiteral : public Expr {
private:
    llvm::SMLoc loc;
    llvm::APSInt value;
public:
    IntLiteral(llvm::SMLoc loc, const llvm::APSInt &value, TypeDecl *type)
              : Expr(ExprKind::EX_INT, type, true),
                loc(loc),
                value(value) {
    }

    llvm::APSInt &getValue() { return value; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_INT;
    }
};


class BoolLiteral : public Expr {
private:
    llvm::SMLoc loc;
    bool value;
public:
    BoolLiteral(llvm::SMLoc loc, const bool &value, TypeDecl *type)
              : Expr(ExprKind::EX_BOOL, type, true),
                loc(loc),
                value(value) {
    }

    bool &getValue() { return value; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_BOOL;
    }
};


class VarAccess : public Expr {
private:
    IR *var;
public:
    VarAccess(VarDecl *var) : Expr(ExprKind::EX_VAR, var->getType(), false), var(var) {}
    
    IR *getVar() { return var; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_VAR;
    }
};

}

}

#endif//_EXPRESSION_HPP_