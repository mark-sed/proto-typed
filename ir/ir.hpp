#ifndef _IR_HPP_
#define _IR_HPP_

#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/APSInt.h"

namespace ptc {

namespace ir {

class Expr;
class VarAccess;

enum IRKind {
    IR_VAR_DECL,
    IR_TYPE_DECL,
    IR_EXPR_STMT,
    IR_ASSIGNMENT
};

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

enum DataType {
    INT,
    BOOL,
    FLOAT,
    STRING
};

enum OperatorKind {
    OP_ADD,
    OP_SUB,
    OP_POW,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_BLSHFT,
    OP_BRSHFT,
    OP_BT,
    OP_BEQ,
    OP_LT,
    OP_LEQ,
    OP_EQ,
    OP_NEQ,
    OP_BAND,
    OP_BXOR,
    OP_BOR,
    OP_IN,
    OP_LAND,
    OP_LOR,
    OP_CONCAT,
    OP_ASSIGN,
    OP_UNKNOWN
};


class IR {
private:
    const IRKind kind;
protected:
    IR *enclosing_ir;
    llvm::SMLoc loc;
    llvm::StringRef name;
public:
    IR(IRKind kind, IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name) : kind(kind),
                                                                               enclosing_ir(enclosing_ir),
                                                                               loc(loc),
                                                                               name(name) {
    }

    IRKind getKind() const { return kind; }
    llvm::SMLoc getLocation() { return loc; }
    llvm::StringRef getName() { return name; }
    virtual std::string debug() const { return "IR"; }
    IR *getEnclosingIR() { return enclosing_ir; }
};


class TypeDecl : public IR {
private:
    bool is_maybe;
public:
    TypeDecl(IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name) {}

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_TYPE_DECL;
    }
    std::string debug() const override { return name.str(); }
};


class VarDecl : public IR {
private:
    TypeDecl *td;
public:
    VarDecl(IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name, TypeDecl *td)
           : IR(IRKind::IR_VAR_DECL, enclosing_ir, loc, name),
             td(td) {}
    
    TypeDecl *getType() { return td; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_VAR_DECL;
    }
    virtual std::string debug() const override { return "("+td->debug()+")"+name.str(); }
};



class Operator {
private:
    //llvm::SMLoc loc;
    OperatorKind kind;
    bool unspecified;
public:
    Operator() : kind(OperatorKind::OP_UNKNOWN), unspecified(true) {}
    Operator(OperatorKind kind, bool unspecified=false) : kind(kind),
                                                          unspecified(unspecified) {
    }

    //llvm::SMLoc getLocation() const { return loc; }
    OperatorKind getKind() const { return kind; }
    std::string debug() const { 
        switch(kind) {
        case OP_ADD: return "+";
        case OP_SUB: return "-";
        case OP_POW: return "**";
        case OP_MUL: return "*";
        case OP_DIV: return "/";
        case OP_MOD: return "%";
        case OP_BLSHFT: return "<<";
        case OP_BRSHFT: return ">>";
        case OP_BT: return ">";
        case OP_BEQ: return ">=";
        case OP_LT: return "<";
        case OP_LEQ: return "<=";
        case OP_EQ: return "==";
        case OP_NEQ: return "!=";
        case OP_BAND: return "&";
        case OP_BXOR: return "^";
        case OP_BOR: return "|";
        case OP_IN: return "in";
        case OP_LAND: return "and";
        case OP_LOR: return "or";
        case OP_CONCAT: return "++";
        case OP_ASSIGN: return "=";
        case OP_UNKNOWN: return "unknown";
        default: return "not-listed-op";
        }
    } 
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
    virtual std::string debug() const { return "Expr"; }
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
    std::string debug() const override { return left->debug() + op.debug() + right->debug(); } 
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
    std::string debug() const override { return op.debug() + e->debug(); }
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
    std::string debug() const override { return std::to_string(value.getExtValue()); }
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
    std::string debug() const override { return value ? "true" : "false"; }
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
    std::string debug() const override { return var->debug(); }
};

class ExprStmt : public IR {
private:
    Expr *e;
public:
    ExprStmt(IR *enclosing_ir, llvm::SMLoc loc, llvm::StringRef name, Expr *e)
           : IR(IRKind::IR_EXPR_STMT, enclosing_ir, loc, name),
             e(e) {}
    
    Expr *getExpr() { return e; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_VAR_DECL;
    }
    virtual std::string debug() const override { return e->debug(); }
};

}

}

#endif//_IR_HPP_