/**
 * @file ir.hpp
 * @author Marek Sedlacek
 * @brief IR handling and code representation
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * Internal Representation of the code
 */

#ifndef _IR_HPP_
#define _IR_HPP_

#include "codegen.hpp"
#include "llvm/Support/SMLoc.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/APSInt.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/IRBuilder.h"
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

#define INT_CSTR "int"
#define FLOAT_CSTR "float"
#define BOOL_CSTR "bool"
#define STRING_CSTR "string"
#define VOID_CSTR "void"
#define ANY_CSTR "any"
#define RANGE_CSTR "range"
#define NONETYPE_CSTR "noneType"
#define MATRIX_CSTR "matrix"
#define VARARGS_CSTR "varargs"
#define UNKNOWN_CSTR "*unknowntype*"

namespace ptc {

namespace cg {
    class CGModule;
}

namespace ir {

class Expr;
class VarAccess;

/**
 * Types of IR
 */
enum IRKind {
    IR_VAR_DECL,
    IR_TYPE_DECL,
    IR_FUN_TYPE_DECL,
    IR_STRUCT_DECL,
    IR_EXPR_STMT,
    IR_FORMAL_PARAM_DECL,
    IR_FUNCTION_DECL,
    IR_IF,
    IR_WHILE,
    IR_FOREACH,
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
    EX_UN_PRE,
    EX_INT,
    EX_BOOL,
    EX_FLOAT,
    EX_STRING,
    EX_MATRIX,
    EX_STRUCT,
    EX_NONE,
    EX_VAR,
    EX_FUN_CALL,
    EX_FUN_PTR,
    EX_EXT_SYMB,
    EX_MEMBER_ACCESS,
    EX_RANGE,
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
    OP_SUBSCR,
    OP_LNOT,
    OP_BNOT,
    OP_AS,
    OP_SLICE,
    OP_UNKNOWN
};

struct SourceInfo {
    int l_start;
    int c_start;
    int l_end;
    int c_end;
    std::string filename;
    std::string snippet;
    int snip_start;
    int snip_end;
    SourceInfo(std::string filename, int line, int start, int line_end, int c_end, std::string snippet, int snip_start, int snip_end) 
        : l_start(line), c_start(start), l_end(line_end), c_end(c_end), filename(filename), snippet(snippet), snip_start(snip_start), snip_end(snip_end) {}
    SourceInfo() {}

    int getLStartCEnd() {
        if(snip_end < snip_start) {
            return snippet.size();
        }
        return snip_end;
    }

    // Needed to use set on this type
    bool operator< (const SourceInfo b) const {
        if(l_start == b.l_start) {
            return c_start < b.c_start;
        }
        return l_start < b.l_start;
    }
};

/**
 * Parent class for all IR objects - declarations
 */
class IR {
private:
    const IRKind kind;
protected:
    IR *enclosing_ir;
    std::string name;
    SourceInfo loc;
public:
    IR(IRKind kind, IR *enclosing_ir, SourceInfo loc, std::string name) : kind(kind),
                                                                            enclosing_ir(enclosing_ir),
                                                                            name(name),
                                                                            loc(loc) {
    }

    IRKind getKind() const { return kind; }
    std::string getName() { return name; }
    virtual std::string debug() const { return "IR"; }
    IR *getEnclosingIR() { return enclosing_ir; }
    void setEnclosingIR(ir::IR *parent) { enclosing_ir = parent; }
    void setLocation(SourceInfo srcInfo) { this->loc = srcInfo; }
    SourceInfo getLocation() { return loc; }
};

/**
 * @brief Converts a block of IRs to a debug string
 * 
 * @param block Block of IRs
 * @return Block as a debug string
 */
std::string block2String(std::vector<ir::IR *> block);

class Expr;
class FormalParamDecl;
class ExternalSymbolAccess;

// TODO: Dont be lazy and template this
std::string block2List(std::vector<ir::Expr *> block);
std::string block2List(std::vector<ir::IR *> block);
std::string block2List(std::vector<std::string> block);
std::string block2List(std::vector<ir::FormalParamDecl *> block);

/**
 * Declaration of a type
 */
class TypeDecl : public IR {
private:
    IR *decl;
    std::vector<Expr *> matrixSize;
    bool maybe;
    bool unresolved;
    ExternalSymbolAccess *externalIR;
    bool structType;

    IR *getBaseIr(IR *d) {
        if(auto t = llvm::dyn_cast<TypeDecl>(d)) {
            if(t->getDecl()) return getBaseIr(t->getDecl());
        }
        return d;
    }
public:
    TypeDecl(IR *enclosing_ir, SourceInfo loc, std::string name, IR *decl=nullptr)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name),
              decl(decl),
              matrixSize{},
              maybe(false),
              unresolved(false),
              externalIR(nullptr) {}
    TypeDecl(IR *enclosing_ir, SourceInfo loc, std::string name, std::vector<Expr *> matsize, IR *decl=nullptr)
            : IR(IRKind::IR_TYPE_DECL, enclosing_ir, loc, name),
              decl(decl),
              matrixSize(matsize),
              maybe(false),
              unresolved(false),
              externalIR(nullptr) {}
    TypeDecl(IR *enclosing_ir, SourceInfo loc, std::string name, IRKind kind)
            : IR(kind, enclosing_ir, loc, name),
              decl(nullptr),
              matrixSize{},
              maybe(false),
              unresolved(false),
              externalIR(nullptr) {}

    TypeDecl *clone() {
        return new TypeDecl(*this);
    }

    IR *getBaseDecl() {
        if(!decl) return this;
        return getBaseIr(decl);
    }

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_TYPE_DECL || ir->getKind() == IRKind::IR_FUN_TYPE_DECL;
    }
    std::string getBaseName() { 
        auto bn = getName(); 
        bn.erase(std::remove(bn.begin(), bn.end(), '['), bn.end());
        bn.erase(std::remove(bn.begin(), bn.end(), ']'), bn.end());
        return bn;
    }
    int getDimensions() {
        return std::count_if(name.begin(), name.end(), [](char c) { return c == '['; });
    }
    bool isMatrix() { return !matrixSize.empty(); }
    bool isMaybe() { return maybe; }
    void setMaybe(bool m) { maybe = m; }
    ExternalSymbolAccess *getExternalIR() { return externalIR; }
    void setExternalIR(ExternalSymbolAccess *e) { externalIR = e; }
    std::vector<Expr *> getMatrixSize() { return matrixSize; }
    IR *getDecl() { return decl; }
    bool isUnresolved() { return unresolved; }
    void setUnresolved(bool r) { unresolved = r; }
    std::string debug() const override {
        std::string n = "";
        if(unresolved) {
            n += "(unresolved type)";
        }
        if(!matrixSize.empty()) {
            n += name + "<" + block2List(matrixSize) + ">";
        }
        else {
            n += name;
        }
        if(maybe) {
            n+="?";
        }
        return n;
    }
};

/** Function type declaration */
class FunTypeDecl : public TypeDecl {
private:
    TypeDecl *retType;
    std::vector<TypeDecl *> argTypes;
public:
    FunTypeDecl(IR *enclosing_ir, SourceInfo loc, std::string name, TypeDecl *retType, std::vector<ir::IR *> argTypesIR)
        : TypeDecl(enclosing_ir, loc, name, IRKind::IR_FUN_TYPE_DECL), retType(retType) {
        for(auto i : argTypesIR) {
            argTypes.push_back(llvm::dyn_cast<TypeDecl>(i));
        }
        setMaybe(true);
    }

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_FUN_TYPE_DECL;
    }

    std::vector<TypeDecl *> getArgTypes() { return argTypes; }
    TypeDecl *getReturnType() { return retType; }
};

/**
 * Declaration of a variable
 */
class VarDecl : public IR {
private:
    TypeDecl *td;
    Expr *initValue;
public:
    VarDecl(IR *enclosing_ir, SourceInfo loc, std::string name, TypeDecl *td, Expr *initValue=nullptr)
           : IR(IRKind::IR_VAR_DECL, enclosing_ir, loc, name),
             td(td),
             initValue(initValue) {}
    
    TypeDecl *getType() { return td; }
    void setType(TypeDecl *t) { this->td = t; }
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
    bool libType;
public:
    StructDecl(IR *enclosing_ir, SourceInfo loc, std::string name, std::vector<ir::IR *> elements)
            : IR(IRKind::IR_STRUCT_DECL, enclosing_ir, loc, name),
              elements(elements),
              zero_init(true),
              libType(false) {
        for(auto v: elements) {
            // zero_init is set only if no element has assigned value
            // and all the struct elements are also zero_init
            // String have implicit initvalue
            if(llvm::dyn_cast<VarDecl>(v)->getInitValue() ||
                llvm::dyn_cast<VarDecl>(v)->getType()->getName() == STRING_CSTR ||
                (llvm::dyn_cast<VarDecl>(v)->getType()->getDecl() && 
                llvm::isa<StructDecl>(llvm::dyn_cast<VarDecl>(v)->getType()->getDecl()) &&
                !llvm::dyn_cast<StructDecl>(llvm::dyn_cast<VarDecl>(v)->getType()->getDecl())->is_zero_init())) {
                zero_init = false;
                break;
            }
        }
    }

    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_STRUCT_DECL;
    }
    std::string debug() const override { 
        std::string l = "";
        if(libType)
            l = "(lib type)";
        return "struct "+l+name+" {\n"+block2String(elements)+"}";
    }
    std::vector<ir::IR *> getElements() { return elements; }
    bool is_zero_init() { return zero_init; }
    bool isLibType() { return libType; }
    void setLibType(bool b) { libType = b; }
};

/**
 * List of modules to import
 */
class Import : public IR {
private:
    std::vector<std::string> names;
public:
    Import(IR *enclosing_ir, SourceInfo loc, std::vector<std::string>& names)
        : IR(IRKind::IR_IMPORT, enclosing_ir, loc, "import"),
          names(names) {}

    std::vector<std::string> getNames() { return names; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_IMPORT;
    }
    virtual std::string debug() const override { return "import "+block2List(names); }
};

/**
 * Declaration of a formal parameter
 */
class FormalParamDecl : public IR {
private:
    TypeDecl *td;
    bool byReference;
public:
    FormalParamDecl(IR *enclosing_ir, SourceInfo loc, std::string name, TypeDecl *td, bool byReference=false)
           : IR(IRKind::IR_FORMAL_PARAM_DECL, enclosing_ir, loc, name),
             td(td),
             byReference(byReference) {}
    
    TypeDecl *getType() { return td; }
    void setType(TypeDecl *t) { td = t; }
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
                 SourceInfo loc,
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
    FunctionDecl(IR *enclosing_ir, SourceInfo loc) : IR(IRKind::IR_FUNCTION_DECL, enclosing_ir, loc, "unknownfunc"),
                                     returnType(nullptr),
                                     prototype(true) {}

    void resolveFunction(SourceInfo loc,
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
    void setReturnType(TypeDecl *t) { returnType = t; }
    std::vector<FormalParamDecl *> getParams() { return params; }
    std::vector<ir::IR *> getDecl() { return decls; }
    void setDecl(std::vector<ir::IR *> d) { decls = d; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_FUNCTION_DECL;
    }
    virtual std::string debug() const override {
        if(!prototype)
            return returnType->getName()+" "+name+"("+ block2List(params) +") {\n" + block2String(decls) +"}\n";
        else
            return "unknwon-type unknown-function(?) { ... }";
    }
};

/**
 * Operator in an expression
 */
class Operator {
private:
    //SourceInfo loc;
    OperatorKind kind;
    bool unspecified;
public:
    Operator() : kind(OperatorKind::OP_UNKNOWN), unspecified(true) {}
    Operator(OperatorKind kind, bool unspecified=false) : kind(kind),
                                                          unspecified(unspecified) {
    }

    //SourceInfo getLocation() const { return loc; }
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
        case OP_SUBSCR: return "[]";
        case OP_LNOT: return "!";
        case OP_BNOT: return "~";
        case OP_AS: return "as";
        case OP_SLICE: return "[..]";
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
    void setLeft(Expr *l) { this->left = l; }
    void setRight(Expr *r) { this->right = r; } 
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
                    : Expr(ExprKind::EX_UN_PRE, type, is_const),
                      e(e),
                      op(op) {
    }

    Expr *getExpr() { return e; }
    const Operator &getOperator() { return op; }
    std::string debug() const override { return op.debug() + e->debug(); }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_UN_PRE;
    }
};

/**
 * Integer value
 */
class IntLiteral : public Expr {
private:
    SourceInfo loc;
    llvm::APSInt value;
public:
    IntLiteral(SourceInfo loc, const llvm::APSInt &value, TypeDecl *type)
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
    SourceInfo loc;
    llvm::APFloat value;
public:
    FloatLiteral(SourceInfo loc, const llvm::APFloat &value, TypeDecl *type)
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
    SourceInfo loc;
    bool value;
public:
    BoolLiteral(SourceInfo loc, const bool &value, TypeDecl *type)
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
    SourceInfo loc;
    std::string value;
public:
    StringLiteral(SourceInfo loc, std::string &value, TypeDecl *type)
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
    SourceInfo loc;
    std::vector<Expr *> value;
public:
    MatrixLiteral(SourceInfo loc, std::vector<Expr *> &value, TypeDecl *type)
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
 * Struct literal
 */
class StructLiteral : public Expr {
private:
    SourceInfo loc;
    std::map<std::string, ir::Expr *> values;
public:
    StructLiteral(SourceInfo loc, TypeDecl *type, std::map<std::string, ir::Expr *> &values)
              : Expr(ExprKind::EX_STRUCT, type, true),
                loc(loc),
                values(values) {
    }

    std::map<std::string, ir::Expr *> getValues() { return values; }
    StructDecl *getDecl() { 
        if(auto stdc = llvm::dyn_cast<ir::StructDecl>(type->getDecl()))
            return stdc; 
        return nullptr;
    }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_STRUCT;
    }
    std::string debug() const override {
        std::stringstream ss;
        for(auto [k, v] : values) {
            ss << "." << k << "=" << v->debug() << ", ";
        }
        return type->getName()+"{"+ss.str()+"}";
    }
};

/**
 * None value
 */
class NoneLiteral : public Expr {
private:
    SourceInfo loc;
public:
    NoneLiteral(SourceInfo loc, TypeDecl *type)
              : Expr(ExprKind::EX_NONE, type, true),
                loc(loc) {
    }

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_NONE;
    }
    std::string debug() const override { return "none"; }
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
    VarAccess(TypeDecl *var) : Expr(ExprKind::EX_VAR, var, false), var(var) {}
    
    IR *getVar() { return var; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_VAR;
    }
    std::string debug() const override { return var->debug(); }
};

class ModuleDecl;

/**
 * Access to a variable (as a variable in an expression)
 */
class ExternalSymbolAccess : public Expr {
private:
    std::string moduleName;
    std::string symbolName;
    IR *extIR;
    ModuleDecl *modDecl;
public:
    ExternalSymbolAccess(std::string moduleName, std::string symbolName, TypeDecl *type) 
        : Expr(ExprKind::EX_EXT_SYMB, type, false), 
          moduleName(moduleName), 
          symbolName(symbolName),
          extIR(nullptr),
          modDecl(nullptr) {}

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_EXT_SYMB;
    }
    IR *getExtIR() { return extIR; }
    void setExtIR(IR *e) { this->extIR = e; }
    ModuleDecl *getModDecl() { return modDecl; }
    void setModDecl(ModuleDecl *mod) { modDecl = mod; }
    std::string getModuleName() { return moduleName; }
    std::string getSymbolName() { return symbolName; }
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
    std::string debug() const override { return "(unresolved symbol)"+symbolName; }
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
 * Integer sequence (range)
 */
class Range : public Expr {
private:
    Expr *start;
    Expr *step;
    Expr *end;
public:
    Range(Expr *start, Expr *step, Expr *end, TypeDecl *type) 
        : Expr(ExprKind::EX_RANGE, type, false),
          start(start),
          step(step),
          end(end) {}

    Expr *getStart() { return start; }
    Expr *getStep() { return step; }
    Expr *getEnd() { return end; }

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_RANGE;
    }
    std::string debug() const override { 
        if(!step)
            return start->debug()+" .. "+end->debug();
        return start->debug()+" step: "+step->debug()+" .. "+end->debug(); 
    }
};

/**
 * Slice for a string or matrix
 */
/*class Slice : public Expr {
private:
    Range *range;
public:
    Slice(Range *range, TypeDecl *type) 
        : Expr(ExprKind::EX_SLICE, type, false),
          range(range) {}

    Range *getRange() { return range; }

    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_SLICE;
    }
    std::string debug() const override { 
        return "["+range->debug()+"]"; 
    }
};*/

/**
 * Standalone expression (statement)
 */
class ExprStmt : public IR {
private:
    Expr *e;
public:
    ExprStmt(IR *enclosing_ir, SourceInfo loc, std::string name, Expr *e)
           : IR(IRKind::IR_EXPR_STMT, enclosing_ir, loc, name),
             e(e) {}
    
    Expr *getExpr() { return e; }
    void setExpr(ir::Expr *e) { this->e = e; }
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
    VarDecl *var;
    Expr *expr;
    FormalParamDecl *param;
    UnresolvedSymbolAccess *unresF;
    ExternalSymbolAccess *extF;
    std::vector<Expr *> params;
    bool unresolved;
    bool external;
public:
    FunctionCall(FunctionDecl *fun, std::vector<Expr *> params) 
                : Expr(ExprKind::EX_FUN_CALL, fun->getReturnType(), false),
                  fun(fun),
                  var(nullptr),
                  expr(nullptr),
                  param(nullptr),
                  unresF(nullptr),
                  extF(nullptr),
                  params(params),
                  unresolved(false),
                  external(false) {}
    FunctionCall(VarDecl *var, std::vector<Expr *> params) 
                : Expr(ExprKind::EX_FUN_CALL, llvm::dyn_cast<ir::FunTypeDecl>(var->getType())->getReturnType(), false),
                  fun(nullptr),
                  var(var),
                  expr(nullptr),
                  param(nullptr),
                  unresF(nullptr),
                  extF(nullptr),
                  params(params),
                  unresolved(false),
                  external(false) {}
    FunctionCall(Expr *expr, std::vector<Expr *> params) 
                : Expr(ExprKind::EX_FUN_CALL, expr->getType(), false),
                  fun(nullptr),
                  var(nullptr),
                  expr(expr),
                  param(nullptr),
                  unresF(nullptr),
                  extF(nullptr),
                  params(params),
                  unresolved(false),
                  external(false) {}
    FunctionCall(FormalParamDecl *param, std::vector<Expr *> params) 
                : Expr(ExprKind::EX_FUN_CALL, llvm::dyn_cast<ir::FunTypeDecl>(param->getType())->getReturnType(), false),
                  fun(nullptr),
                  var(nullptr),
                  expr(nullptr),
                  param(param),
                  unresF(nullptr),
                  extF(nullptr),
                  params(params),
                  unresolved(false),
                  external(false) {}
    FunctionCall(UnresolvedSymbolAccess *unresF, std::vector<Expr *> params)
                : Expr(ExprKind::EX_FUN_CALL, unresF->getType(), false),
                  fun(nullptr),
                  var(nullptr),
                  expr(nullptr),
                  param(nullptr),
                  unresF(unresF),
                  extF(nullptr),
                  params(params),
                  unresolved(true),
                  external(false) {}
    FunctionCall(ExternalSymbolAccess *extF, std::vector<Expr *> params)
                : Expr(ExprKind::EX_FUN_CALL, extF->getType(), false),
                  fun(nullptr),
                  var(nullptr),
                  expr(nullptr),
                  param(nullptr),
                  unresF(nullptr),
                  extF(extF),
                  params(params),
                  unresolved(false),
                  external(true) {}
    
    FunctionDecl *getFun() { return fun; }
    VarDecl *getVar() { return var; }
    FormalParamDecl *getParam() { return param; }
    Expr *getExpr() { return expr; }
    void setFun(FunctionDecl *f) { fun = f; }
    bool isUnresolved() { return unresolved; }
    void setUnresolved(bool s) { unresolved = s; }
    bool isExternal() { return external; }
    void setExternal(bool e) { external = e; }
    ExternalSymbolAccess *getExternalFun() { return extF; }
    UnresolvedSymbolAccess *getUnresolvedFun() { return unresF; }
    std::vector<Expr *> getParams() { return params; }
    static bool classof(const Expr *e) {
        return e->getKind() == ExprKind::EX_FUN_CALL;
    }
    std::string debug() const override {
        if(var)
            return "("+var->debug()+")"+"("+block2List(params)+")";
        if(param)
            return "("+param->debug()+")"+"("+block2List(params)+")";
        if(expr)
            return "("+expr->debug()+")"+"("+block2List(params)+")";
        if(unresolved)
            return "(unresolved call)"+unresF->getName()+"("+block2List(params)+")";
        if(external)
            return "(external)"+extF->debug()+"("+block2List(params)+")";
        if(fun)
            return "("+fun->getReturnType()->getName()+")"+fun->getName()+"("+block2List(params)+")";
        return "TODO:SOME_FUN_CALL";
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
                SourceInfo loc,
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

/**
 * While or doWhile statement
 */
class WhileStmt : public IR {
private:
    Expr *cond;
    std::vector<ir::IR *> body;
    llvm::BasicBlock *afterBB;
    llvm::BasicBlock *condBB;
    bool doWhile;
public:
    WhileStmt(IR *enclosing_ir, 
              SourceInfo loc,
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
 * Foreach statement (for with collection or range)
 */
class ForeachStmt : public IR {
private:
    Expr *i;
    Expr *collection;
    std::vector<ir::IR *> body;
    bool defineI;
    llvm::BasicBlock *afterBB;
    llvm::BasicBlock *condBB;
    llvm::BasicBlock *nextIterBB;
public:
    ForeachStmt(IR *enclosing_ir,
                SourceInfo loc,
                std::string name,
                Expr *i,
                Expr *collection,
                std::vector<ir::IR *> body,
                bool defineI)
        : IR(IRKind::IR_FOREACH, enclosing_ir, loc, name),
          i(i),
          collection(collection),
          body(body),
          defineI(defineI) {}
    
    Expr *getI() { return i; }
    Expr *getCollection() { return collection; }
    std::vector<ir::IR *> getBody() { return body; }
    void setAfterBB(llvm::BasicBlock *bb) { afterBB = bb; }
    void setCondBB(llvm::BasicBlock *bb) { condBB = bb; }
    void setNextIterBB(llvm::BasicBlock *bb) { nextIterBB = bb; }
    llvm::BasicBlock *getAfterBB() { return afterBB; }
    llvm::BasicBlock *getCondBB() { return condBB; }
    llvm::BasicBlock *getNextIterBB() { return nextIterBB; }
    bool getDefineI() { return defineI; }
    static bool classof(const IR *ir) {
        return ir->getKind() == IRKind::IR_FOREACH;
    }
    virtual std::string debug() const override {
        return "for("+i->debug()+" : "+ collection->debug() +") {\n"+ block2String(body) +"}\n";
    }
};

/**
 * Function return statement 
 */
class ReturnStmt: public IR {
private:
    Expr *val;
    ir::FunctionDecl *parentFun;
public:
    ReturnStmt(Expr *val, IR *enclosing_ir, SourceInfo loc, std::string name)
        : IR(IRKind::IR_RETURN, enclosing_ir, loc, name), val(val), parentFun(nullptr) {}

    Expr *getValue() { return val; }
    ir::FunctionDecl *getParentFun() { return parentFun; }
    void setParentFun(ir::FunctionDecl *f) { parentFun = f; }

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
    BreakStmt(IR *enclosing_ir, SourceInfo loc)
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
    ContinueStmt(IR *enclosing_ir, SourceInfo loc)
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
    std::vector<FunctionDecl *> libFunctions;
    cg::CGModule *cgmodule;
public:
    ModuleDecl(IR *enclosing_ir, SourceInfo loc, std::string name)
              : IR(IRKind::IR_MODULE_DECL, enclosing_ir, loc, name), main(false), cgmodule(nullptr) {}
    ModuleDecl(IR *enclosing_ir, 
               SourceInfo loc,
               std::string name,
               std::vector<ir::IR *> &decls)
              : IR(IRKind::IR_MODULE_DECL, enclosing_ir, loc, name), decls(decls), main(false), cgmodule(nullptr) {}
    
    std::vector<ir::IR *> getDecls() { return decls; }
    void setDecls(std::vector<ir::IR *> &decls) { this->decls = decls; }
    void setMain(bool m) { this->main = m; }
    bool isMain() { return this->main; }
    ptc::cg::CGModule *getCGModule() { return cgmodule; }
    void setCGModule(cg::CGModule *cgm) { this->cgmodule = cgm; }
    void setLibFunctions(std::vector<FunctionDecl *> fs) { libFunctions = fs; }
    std::vector<FunctionDecl *> getLibFunctions() { return libFunctions; }
    void addLibFunction(FunctionDecl *f) { libFunctions.push_back(f); }
    void prependDecl(IR *d) { decls.insert(decls.begin(), d); }

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