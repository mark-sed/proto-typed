/**
 * @file ir.hpp
 * @author Marek Sedlacek
 * @brief IR handling and code representation
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _IR_HPP_
#define _IR_HPP_

#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/IRBuilder.h"
#include <vector>
#include <sstream>

#define INT_CSTR "int"
#define FLOAT_CSTR "float"
#define BOOL_CSTR "bool"
#define STRING_CSTR "string"
#define MATRIX_CSTR "matrix"
#define VOID_CSTR "void"
#define UNKNOWN_CSTR "*unknowntype*"

namespace ptc {

namespace ir {

class Expr;
class VarAccess;

/**
 * Types of IR
 */
enum IRKind {
    IR_VAR_DECL,
    IR_TYPE_DECL,
    IR_STRUCT_DECL,
    IR_EXPR_STMT,
    IR_FORMAL_PARAM_DECL,
    IR_FUNCTION_DECL,
    IR_IF,
    IR_WHILE,
    IR_RETURN,
    IR_MODULE_DECL,
    IR_IMPORT,
    IR_BREAK,
    IR_CONTINUE
};

/**
 * Types of expressions
 */
enum ExprKind {
    EX_BIN_INF,
    EX_BIN_PRE,
    EX_INT,
    EX_BOOL,
    EX_FLOAT,
    EX_STRING,
    EX_MATRIX,
    EX_NONE,
    EX_VAR,
    EX_FUN_CALL,
    EX_FUN_PTR,
    EX_EXT_SYMB,
    EX_MEMBER_ACCESS,
    EX_UNRESOLVED_SYMB
};

/**
 * Types of operators
 */
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
    OP_ACCESS,
    OP_UNKNOWN
};

/**
 * Parent class for all IR objects - declarations
 */
class IR {
private:
    const IRKind kind;
protected:
    IR *enclosing_ir;
    llvm::SMLoc loc;
    std::string name;
public:
    IR(IRKind kind, IR *enclosing_ir, llvm::SMLoc loc, std::string name) : kind(kind),
                                                                               enclosing_ir(enclosing_ir),
                                                                               loc(loc),
                                                                               name(name) {
    }

    IRKind getKind() const { return kind; }
    llvm::SMLoc getLocation() { return loc; }
    std::string getName() { return name; }
    virtual std::string debug() const { return "IR"; }
    IR *getEnclosingIR() { return enclosing_ir; }
    void setEnclosingIR(ir::IR *parent) { enclosing_ir = parent; }
};

/**
 * @brief Converts a block of IRs to a debug string
 * 
 * @param block Block of IRs
 * @return Block as a debug string
 */
std::string block2String(std::vector<ir::IR *> block);

class Expr;

std::string block2List(std::vector<ir::Expr *> block);

/**
 * Declaration of a type
 */
class TypeDecl : public IR {
private:
    IR *decl;
    bool is_maybe;
    std::vector<Expr *> matrixSize;
public:
    TypeDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name, IR *decl=nullptr)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name),
              decl(decl),
              matrixSize{} {}
    TypeDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name, std::vector<Expr *> matsize, IR *decl=nullptr)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name),
              decl(decl),
              matrixSize(matsize) {}

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_TYPE_DECL;
    }
    bool isMatrix() { return !matrixSize.empty(); }
    std::vector<Expr *> getMatrixSize() { return matrixSize; }
    IR *getDecl() { return decl; }
    std::string debug() const override { 
        if(!matrixSize.empty()) {
            return name + "<" + block2List(matrixSize) + ">";
        }
        return name; 
    }
};

/**
 * Declaration of a variable
 */
class VarDecl : public IR {
private:
    TypeDecl *td;
    Expr *initValue;
public:
    VarDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name, TypeDecl *td, Expr *initValue=nullptr)
           : IR(IRKind::IR_VAR_DECL, enclosing_ir, loc, name),
             td(td),
             initValue(initValue) {}
    
    TypeDecl *getType() { return td; }
    Expr *getInitValue() { return initValue; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_VAR_DECL;
    }
    virtual std::string debug() const override;
};

/**
 * Declaration of a struct type
 */
class StructDecl : public IR {
private:
    std::vector<ir::IR *> elements;
    bool zero_init;
public:
    StructDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name, std::vector<ir::IR *> elements)
            : IR(IRKind::IR_STRUCT_DECL, enclosing_ir, loc, name),
              elements(elements),
              zero_init(true) {
        for(auto v: elements) {
            // zero_init is set only if no element has assigned value
            // and all the struct elements are also zero_init
            // String have implicit initvalue
            if(llvm::dyn_cast<VarDecl>(v)->getInitValue() ||
                llvm::dyn_cast<VarDecl>(v)->getType()->getName() == STRING_CSTR ||
                (llvm::dyn_cast<VarDecl>(v)->getType()->getDecl() && 
                !llvm::dyn_cast<StructDecl>(llvm::dyn_cast<VarDecl>(v)->getType()->getDecl())->is_zero_init())) {
                zero_init = false;
                break;
            }
        }
    }

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_STRUCT_DECL;
    }
    std::string debug() const override { return "struct "+name+" {\n"+block2String(elements)+"}"; }
    std::vector<ir::IR *> getElements() { return elements; }
    bool is_zero_init() { return zero_init; }
};

/**
 * List of modules to import
 */
class Import : public IR {
private:
    std::vector<std::string> names;
public:
    Import(IR *enclosing_ir, llvm::SMLoc loc, std::vector<std::string>& names)
        : IR(IRKind::IR_IMPORT, enclosing_ir, loc, "import"),
          names(names) {}

    std::vector<std::string> getNames() { return names; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_IMPORT;
    }
    virtual std::string debug() const override { return "import ...TODO"; }
};

/**
 * Declaration of a formal parameter
 */
class FormalParamDecl : public IR {
private:
    TypeDecl *td;
    bool byReference;
public:
    FormalParamDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name, TypeDecl *td, bool byReference=false)
           : IR(IRKind::IR_FORMAL_PARAM_DECL, enclosing_ir, loc, name),
             td(td),
             byReference(byReference) {}
    
    TypeDecl *getType() { return td; }
    bool isByReference() { return byReference; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_FORMAL_PARAM_DECL;
    }
    virtual std::string debug() const override { return "("+td->debug()+(byReference ? "&" : "")+")"+name; }
};

/**
 * Declaration of a function
 */
class FunctionDecl : public IR {
private:
    std::string og_name;
    TypeDecl *returnType;
    std::vector<FormalParamDecl *> params;
    std::vector<ir::IR *> decls;
    bool prototype;
public:
    FunctionDecl(IR *enclosing_ir, 
                 llvm::SMLoc loc,
                 std::string name,
                 std::string og_name,
                 TypeDecl *returnType,
                 std::vector<FormalParamDecl *> params,
                 std::vector<ir::IR *> decls)
           : IR(IRKind::IR_FUNCTION_DECL, enclosing_ir, loc, name),
             og_name(og_name),
             returnType(returnType),
             params(params),
             decls(decls),
             prototype(false) {}
    FunctionDecl(IR *enclosing_ir) : IR(IRKind::IR_FUNCTION_DECL, enclosing_ir, llvm::SMLoc(), "unknownfunc"),
                                     returnType(nullptr),
                                     prototype(true) {}

    void resolveFunction(llvm::SMLoc loc,
                         std::string name,
                         std::string og_name,
                         TypeDecl *returnType,
                         std::vector<FormalParamDecl *> params,
                         std::vector<ir::IR *> decls) {
        this->loc = loc;
        this->name = name;
        this->og_name = og_name;
        this->returnType = returnType;
        this->params = params;
        this->decls = decls;
        this->prototype = false;
    }
    
    std::string getOGName() { return og_name; }
    TypeDecl *getReturnType() { return returnType; }
    std::vector<FormalParamDecl *> getParams() { return params; }
    std::vector<ir::IR *> getDecl() { return decls; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_FUNCTION_DECL;
    }
    virtual std::string debug() const override {
        if(!prototype)
            return returnType->getName()+" "+name+"(...) {\n" + block2String(decls) +"}\n";
        else
            return "unknwon-type unknown-function(?) { ... }";
    }
};

/**
 * Operator in an expression
 */
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
        case OP_ACCESS: return ".";
        case OP_UNKNOWN: return "unknown";
        default: return "not-listed-op";
        }
    } 
    bool isUnspecified() const { return unspecified; }
};

/**
 * Parent class for any expression
 */
class Expr {
private:
    const ExprKind kind;
    bool is_const;
protected:
    TypeDecl *type;
    Expr(ExprKind kind, TypeDecl *type, bool is_const) : kind(kind), is_const(is_const), type(type) {}
    virtual ~Expr() {}
public:
    ExprKind getKind() const { return kind; }
    TypeDecl *getType() { return type; }
    virtual std::string debug() const { return "Expr"; }
    void setType(TypeDecl *t) { type = t; }
    bool isConst() { return is_const; }
};

std::string block2String(std::vector<ir::Expr *> block);

/**
 * Expression containing 2 arguments and an operator
 */
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

/**
 * Unary expression with prefixed operator
 */
class UnaryPrefixExpr : public Expr {
private:
    Expr *e;
    const Operator op;
public:
    UnaryPrefixExpr(Expr *e, Operator op, TypeDecl *type, bool is_const)
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

/**
 * Integer value
 */
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

/**
 * Float value
 */
class FloatLiteral : public Expr {
private:
    llvm::SMLoc loc;
    llvm::APFloat value;
public:
    FloatLiteral(llvm::SMLoc loc, const llvm::APFloat &value, TypeDecl *type)
              : Expr(ExprKind::EX_FLOAT, type, true),
                loc(loc),
                value(value) {
    }

    llvm::APFloat &getValue() { return value; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_FLOAT;
    }
    std::string debug() const override { return std::to_string(value.convertToDouble()); }
};

/**
 * Boolean value
 */
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

/**
 * Constant string value
 */
class StringLiteral : public Expr {
private:
    llvm::SMLoc loc;
    std::string value;
public:
    StringLiteral(llvm::SMLoc loc, std::string &value, TypeDecl *type)
              : Expr(ExprKind::EX_STRING, type, true),
                loc(loc),
                value(value) {
    }

    std::string &getValue() { return value; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_STRING;
    }
    std::string debug() const override { return value; }
};

/**
 * Homogeneus matrix of any type
 */
class MatrixLiteral : public Expr {
private:
    llvm::SMLoc loc;
    std::vector<Expr *> value;
public:
    MatrixLiteral(llvm::SMLoc loc, std::vector<Expr *> &value, TypeDecl *type)
              : Expr(ExprKind::EX_MATRIX, type, true),
                loc(loc),
                value(value) {
    }

    std::vector<Expr *> &getValue() { return value; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_MATRIX;
    }
    std::string debug() const override { return "("+type->getName()+")["+block2List(value)+"]"; }
};

/**
 * Access to a variable (as a variable in an expression)
 */
class VarAccess : public Expr {
private:
    IR *var;
public:
    VarAccess(VarDecl *var) : Expr(ExprKind::EX_VAR, var->getType(), false), var(var) {}
    VarAccess(FormalParamDecl *var) : Expr(ExprKind::EX_VAR, var->getType(), false), var(var) {}
    VarAccess(FunctionDecl *var, TypeDecl *type) : Expr(ExprKind::EX_VAR, type, false), var(var) {}
    
    IR *getVar() { return var; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_VAR;
    }
    std::string debug() const override { return var->debug(); }
};

/**
 * Access to a variable (as a variable in an expression)
 */
class ExternalSymbolAccess : public Expr {
private:
    std::string moduleName;
    std::string symbolName;
public:
    ExternalSymbolAccess(std::string moduleName, std::string symbolName, TypeDecl *type) 
        : Expr(ExprKind::EX_EXT_SYMB, type, false), 
          moduleName(moduleName), 
          symbolName(symbolName) {}

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_EXT_SYMB;
    }
    std::string debug() const override { return moduleName+"::"+symbolName; }
};

/**
 * Access to a not yet resolved symbol (as a variable in an expression)
 */
class UnresolvedSymbolAccess : public Expr {
private:
    std::string symbolName;
public:
    UnresolvedSymbolAccess(std::string symbolName, TypeDecl *type) 
        : Expr(ExprKind::EX_UNRESOLVED_SYMB, type, false),
          symbolName(symbolName) {}

    std::string getName() { return symbolName; }

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_UNRESOLVED_SYMB;
    }
    std::string debug() const override { return "(unresolved)"+symbolName; }
};

/**
 * Access a memeber of a struct
 */
class MemberAccess : public Expr {
private:
    IR *decl;
    int index;
public:
    MemberAccess(IR *decl, int index, TypeDecl *type) 
        : Expr(ExprKind::EX_MEMBER_ACCESS, type, false),
          decl(decl),
          index(index) {}

    IR *getDecl() { return decl; }
    int getIndex() { return index; }

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_MEMBER_ACCESS;
    }
    std::string debug() const override { return decl->debug(); }
};

/**
 * Standalone expression (statement)
 */
class ExprStmt : public IR {
private:
    Expr *e;
public:
    ExprStmt(IR *enclosing_ir, llvm::SMLoc loc, std::string name, Expr *e)
           : IR(IRKind::IR_EXPR_STMT, enclosing_ir, loc, name),
             e(e) {}
    
    Expr *getExpr() { return e; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_EXPR_STMT;
    }
    virtual std::string debug() const override { return e->debug(); }
};

/**
 * Function call
 */
class FunctionCall : public Expr {
private:
    FunctionDecl *fun;
    UnresolvedSymbolAccess *unresF;
    std::vector<Expr *> params;
    bool unresolved;
public:
    FunctionCall(FunctionDecl *fun, std::vector<Expr *> params) 
                : Expr(ExprKind::EX_FUN_CALL, fun->getReturnType(), false),
                  fun(fun),
                  unresF(nullptr),
                  params(params),
                  unresolved(false) {}
    FunctionCall(UnresolvedSymbolAccess *unresF, std::vector<Expr *> params)
                : Expr(ExprKind::EX_FUN_CALL, unresF->getType(), false),
                  fun(nullptr),
                  unresF(unresF),
                  params(params),
                  unresolved(true) {}
    
    FunctionDecl *getFun() { return fun; }
    void setFun(FunctionDecl *f) { fun = f; }
    bool isUnresolved() { return unresolved; }
    void setUnresolved(bool s) { unresolved = s; }
    UnresolvedSymbolAccess *getUnresolvedFun() { return unresF; }
    std::vector<Expr *> getParams() { return params; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_FUN_CALL;
    }
    std::string debug() const override {
        if(!unresolved)
            return "("+fun->getReturnType()->getName()+")"+fun->getName()+"(...)";
        return "(unresolved)"+unresF->getName()+"(...)";
    }
};

/**
 * If statement
 */
class IfStatement : public IR {
private:
    Expr *cond;
    std::vector<ir::IR *> ifBranch;
    std::vector<ir::IR *> elseBranch;
public:
    IfStatement(IR *enclosing_ir, 
                llvm::SMLoc loc,
                std::string name,
                Expr *cond,
                std::vector<ir::IR *> &ifBranch,
                std::vector<ir::IR *> &elseBranch)
           : IR(IRKind::IR_IF, enclosing_ir, loc, name),
             cond(cond),
             ifBranch(ifBranch),
             elseBranch(elseBranch) {}
    
    Expr *getCond() { return cond; }
    std::vector<ir::IR *> getIfBranch() { return ifBranch; }
    std::vector<ir::IR *> getElseBranch() { return elseBranch; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_IF;
    }
    virtual std::string debug() const override {
        return "if("+cond->debug()+") {\n" + block2String(ifBranch) + "}\nelse {\n" + block2String(elseBranch) + "}\n";
    }
};

class WhileStmt : public IR {
private:
    Expr *cond;
    std::vector<ir::IR *> body;
    llvm::BasicBlock *afterBB;
    llvm::BasicBlock *condBB;
    bool doWhile;
public:
    WhileStmt(IR *enclosing_ir, 
              llvm::SMLoc loc,
              std::string name,
              Expr *cond,
              std::vector<ir::IR *> body,
              bool doWhile=false)
        : IR(IRKind::IR_WHILE, enclosing_ir, loc, name),
          cond(cond),
          body(body),
          doWhile(doWhile) {}

    Expr *getCond() { return cond; }
    bool isDoWhile() { return doWhile; }
    std::vector<ir::IR *> getBody() { return body; }
    void setAfterBB(llvm::BasicBlock *bb) { afterBB = bb; }
    void setCondBB(llvm::BasicBlock *bb) { condBB = bb; }
    llvm::BasicBlock *getAfterBB() { return afterBB; }
    llvm::BasicBlock *getCondBB() { return condBB; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_WHILE;
    }
    virtual std::string debug() const override {
        return "while("+cond->debug()+") {\n"+ block2String(body) +"}\n";
    }
};

/**
 * Function return statement 
 */
class ReturnStmt: public IR {
private:
    Expr *val;
public:
    ReturnStmt(Expr *val, IR *enclosing_ir, llvm::SMLoc loc, std::string name)
        : IR(IRKind::IR_RETURN, enclosing_ir, loc, name), val(val) {}

    Expr *getValue() { return val; }

    static bool classof(const IR *s) {
        return s->getKind() == IRKind::IR_RETURN;
    }

    virtual std::string debug() const override {
        if(val)
            return "return "+val->debug();
        else
            return "return void";
    }
};

/**
 * Break statement 
 */
class BreakStmt: public IR {
public:
    BreakStmt(IR *enclosing_ir, llvm::SMLoc loc)
        : IR(IRKind::IR_BREAK, enclosing_ir, loc, "break") {}

    static bool classof(const IR *s) {
        return s->getKind() == IRKind::IR_BREAK;
    }

    virtual std::string debug() const override {
        return "break";
    }
};

/**
 * Continue statement 
 */
class ContinueStmt: public IR {
public:
    ContinueStmt(IR *enclosing_ir, llvm::SMLoc loc)
        : IR(IRKind::IR_CONTINUE, enclosing_ir, loc, "continue") {}

    static bool classof(const IR *s) {
        return s->getKind() == IRKind::IR_CONTINUE;
    }

    virtual std::string debug() const override {
        return "continue";
    }
};

/**
 * Module declaration 
 */
class ModuleDecl : public IR {
private:
    std::vector<IR *> decls;
    bool main;
public:
    ModuleDecl(IR *enclosing_ir, llvm::SMLoc loc, std::string name)
              : IR(IRKind::IR_MODULE_DECL, enclosing_ir, loc, name), main(false) {}
    ModuleDecl(IR *enclosing_ir, 
               llvm::SMLoc loc,
               std::string name,
               std::vector<ir::IR *> &decls)
              : IR(IRKind::IR_MODULE_DECL, enclosing_ir, loc, name), decls(decls), main(false) {}
    
    std::vector<ir::IR *> getDecls() { return decls; }
    void setDecls(std::vector<ir::IR *> &decls) { this->decls = decls; }
    void setMain(bool m) { this->main = m; }
    bool isMain() { return this->main; }

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_MODULE_DECL;
    }

    virtual std::string debug() const override {
        std::string dbg = "module "+name+" {\n";
        dbg += block2String(decls);
        dbg+="}\n";
        return dbg;
    }
};

}

}

#endif//_IR_HPP_