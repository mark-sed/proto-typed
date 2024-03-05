/**
 * @file codegen.hpp
 * @author Marek Sedlacek
 * @brief Code generation
 * 
 * @copyright Copyright (c) 2024
 * Code generation from IR to LLVM assembly
 */

#ifndef _CODE_GEN_HPP_
#define _CODE_GEN_HPP_

#include "ir.hpp"
#include "ptlib.hpp"
#include "llvm/Target/TargetMachine.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/ADT/StringMap.h"
#include <map>
#include <set>
#include <vector>

namespace ptc{
    namespace ir {
        class ModuleDecl;
        class IR;
        class Expr;
        class TypeDecl;
        class FunTypeDecl;
        class MatrixLiteral;
        class StructLiteral;
        class StructDecl;
        class FunctionDecl;
        class BinaryInfixExpr;
        class UnaryPrefixExpr;
        class FunctionCall;
        class ExprStmt;
        class ReturnStmt;
        class BreakStmt;
        class ContinueStmt;
        class IfStatement;
        class WhileStmt;
        class ForeachStmt;
        class Import;
        class VarDecl;
        class FormalParamDecl;
    }
}

namespace ptc {

namespace cg {

class PTLib;

/**
 * General codegeneration handler
 * Runs code generation pipeline
 */
class CodeGenHandler {
private:
    llvm::LLVMContext &ctx;
    llvm::TargetMachine *target;
protected:
    CodeGenHandler(llvm::LLVMContext &ctx, llvm::TargetMachine *target)
                 : ctx(ctx), target(target) {}

public:
    cg::CGModule *cgm;
    /**
     * Creates new CodeGenHandler instance
     * @param ctx LLVM context
     * @param target Target architecture
     * @return new CodeGenHandler instance
     */
    static CodeGenHandler *create(llvm::LLVMContext &ctx, llvm::TargetMachine *target);

    /**
     * Runs codegeneration for a given module
     * @param module IR module
     * @param fileName Module file name (for error reporting)
     * @return LLVM module with code generated for passed in module
     */
    std::unique_ptr<llvm::Module> run(ir::ModuleDecl *module, ir::ModuleDecl *ptlibMod, std::string fileName, bool isMainMod);
};

class CGModule;

/**
 * General code generation class used by specific code generators
 */
class CodeGen {
protected:
    llvm::LLVMContext &ctx;

    CodeGen(llvm::LLVMContext &ctx, CGModule &currModule, ir::ModuleDecl *ptlibMod) : ctx(ctx), builder(ctx), currBB(nullptr), currModule(currModule), ptlibMod(ptlibMod) {
        init();
    }

    llvm::IRBuilder<> builder;
    llvm::BasicBlock *currBB;
    CGModule &currModule;
    ir::ModuleDecl *ptlibMod;

    void setCurrBB(llvm::BasicBlock *BB) {
        currBB = BB;
        builder.SetInsertPoint(currBB);
    }

    struct BasicBlockDef {
        // Maps the variable (or formal parameter) to its definition.
        llvm::DenseMap<ir::IR *, llvm::TrackingVH<llvm::Value>> defs;
        // Set of incompleted phi instructions.
        llvm::DenseMap<llvm::PHINode *, ir::IR *> incompletePhis;
        // Block is sealed, that is, no more predecessors will be added.
        bool sealed;

        BasicBlockDef() : sealed(true) {}
    };

    llvm::DenseMap<llvm::BasicBlock *, BasicBlockDef> currDef;
    llvm::DenseMap<ir::IR *, llvm::Value *> locals;

    llvm::StructType *getStringIR();

    llvm::FunctionType *createFunctionType(ir::FunctionDecl *fun);
    llvm::FunctionType *createFunctionType(ir::FunTypeDecl *fun);

public:
    // LLVM versions of PT types
    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *floatT;
    llvm::Type *anyT;
    llvm::StructType *stringT;
    llvm::PointerType *stringTPtr;
    llvm::StructType *matrixT;
    llvm::PointerType *matrixTPtr;
    llvm::StructType *fileT;

    llvm::Value *getReadValuePtr(llvm::Value *v);

    /**
     * Maps PT type to llvm type
     * Unlike convertType, this can also accept variable declarations
     * @param decl PT type declaration
     * @return llvm type for passed in type
     * @note calls convertType
     */
    llvm::Type *mapType(ir::IR *decl);
    /**
     * Converts PT type to llvm type
     * @param type PT type declaration
     * @return llvm type for passed in type
     */
    llvm::Type *convertType(ir::TypeDecl *type);
    /**
     * Generates mangled name for given IR
     * @param ir IR for which to generate name
     * @return mangled name for given IR
     */
    std::string mangleName(ir::IR *ir);

    /**
     * Holds all the user defined types (structs)
     */
    static llvm::StringMap<std::pair<llvm::Type *, llvm::Constant *>> userTypes;

    /**
     * Initializer, has to be called before any other method
     * Initializes types and internal structures
     */
    void init();
};

/**
 * Code generator for PT module
 */
class CGModule : public CodeGen {
private:
    llvm::Module *llvmMod;
    llvm::DenseMap<ir::IR *, llvm::GlobalObject *> globals;
    llvm::GlobalVariable *str_empty;
    std::vector<std::pair<llvm::Value *, llvm::GlobalVariable *>> stringsToInit;
    std::vector<std::pair<llvm::Value *, ir::MatrixLiteral *>> matricesToInit;
    std::vector<std::pair<llvm::Value *, ir::StructLiteral *>> structsToInit;
    std::vector<std::pair<llvm::Value *, llvm::GlobalVariable *>> maybesToInit;
    std::set<ir::Import *> modulesToInit;
    bool mainMod;

    PTLib *ptlibLoader;

    llvm::SmallVector<llvm::Constant *> getStructValsInit(ir::StructDecl *decl, std::map<std::string, ir::Expr *> inits);

public:
    ir::ModuleDecl *mod;
    
    /**
     * @param llvmMod module which to which the code will be generated
     */
    CGModule(llvm::Module *llvmMod, ir::ModuleDecl *ptlibMod);
    ~CGModule();

    llvm::LLVMContext &getLLVMCtx() { return llvmMod->getContext(); }
    llvm::Module *getLLVMMod() { return llvmMod; }
    ir::ModuleDecl *getModuleDecl() { return mod; }
    llvm::Constant *getTypeDefaultValue(ir::TypeDecl *t);

    /**
     * Generates llvm type for passed in structure and
     * adds it to the userTypes
     * @param decl Structure declaration
     */
    void defineStruct(ir::StructDecl *decl);
    /**
     * Getter for global objects
     * @param ir IR to get the GO for
     * @return llvm IR GlobalObject for passed in IR
     */
    llvm::GlobalObject *getGlobals(ir::IR *ir) { return globals[ir]; }

    /**
     * Runs the code generation for passed in module
     */
    void run(ir::ModuleDecl *module);

    void setMainMod(bool m) { this->mainMod = m; }
    bool isMainMod() { return this->mainMod; }
};

/**
 * Code generator for PT functions
 */
class CGFunction : public CodeGen {
private:
    CGModule &cgm;
    ir::FunctionDecl *fun;
    llvm::FunctionType *funType;
    llvm::Function *llvmFun;
    llvm::DenseMap<ir::FormalParamDecl *, llvm::Value *> formalParams;

    llvm::Value *readLocalVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe=false);
    void writeLocalVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val);

    llvm::Function *createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType);
protected:
    void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val);
    void writeExtVar(CGModule *mod, ir::IR *decl, llvm::Value *val);
    llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe=false);
    llvm::Value *readExtVar(CGModule *mod, ir::IR *decl, bool asMaybe=false);

    llvm::Value * getElementIndex(std::vector<llvm::Value *> &indices, ir::BinaryInfixExpr *acc);

    // Expression code generation
    llvm::Value *emitInfixExpr(ir::BinaryInfixExpr *e);
    llvm::Value *emitUnaryPrefixExpr(ir::UnaryPrefixExpr *e);
    llvm::Value *emitFunCall(ir::FunctionCall *e);
    llvm::Value *emitExpr(ir::Expr *e);
    llvm::Value *emitStructElem(ir::BinaryInfixExpr *acc);

    // IR code generation
    void emitMemberAssignment(ir::BinaryInfixExpr *l, llvm::Value *r);
    void emitArrayAssignment(ir::BinaryInfixExpr *l, llvm::Value *r);
    void emitStmt(ir::ExprStmt *stmt);
    void emitStmt(ir::ReturnStmt *stmt);
    void emitStmt(ir::BreakStmt *stmt);
    void emitStmt(ir::ContinueStmt *stmt);
    void emitStmt(ir::IfStatement *stmt);
    void emitStmt(ir::WhileStmt *stmt);
    void emitStmt(ir::ForeachStmt *stmt);
    void emitStmt(ir::Import *stmt);
    void emitStmt(ir::VarDecl *stmt);
    virtual void emit(std::vector<ir::IR *> stmts);
public:
    /**
     * @param cgm Code generator for module in which this function resides
     * @param fun IR declaration of this function
     */
    CGFunction(CGModule &cgm, ir::FunctionDecl *fun, ir::ModuleDecl *ptlibMod) : CodeGen(cgm.getLLVMCtx(), cgm, ptlibMod), cgm(cgm), fun(fun) {
        funType = createFunctionType(fun);
        this->llvmFun = createFunction(fun, funType);
    } 

    /**
     * Runs code generation for this function
     */
    void run();
};

}

} // namespace ptc


#endif//_CODE_GEN_HPP_