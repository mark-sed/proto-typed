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

namespace ptc {

namespace cg {

class PTLib;

class CodeGenHandler {
private:
    llvm::LLVMContext &ctx;
    llvm::TargetMachine *target;
    ir::ModuleDecl *module;
protected:
    CodeGenHandler(llvm::LLVMContext &ctx, llvm::TargetMachine *target)
                 : ctx(ctx), target(target), module(nullptr) {}

public:
    static CodeGenHandler *create(llvm::LLVMContext &ctx, llvm::TargetMachine *target);

    std::unique_ptr<llvm::Module> run(ir::ModuleDecl *module, std::string fileName);
};

class CGModule;

class CodeGen {
protected:
    llvm::LLVMContext &ctx;

    CodeGen(llvm::LLVMContext &ctx, CGModule &currModule) : ctx(ctx), builder(ctx), currBB(nullptr), currModule(currModule) {
        init();
    }

    llvm::IRBuilder<> builder;
    llvm::BasicBlock *currBB;
    CGModule &currModule;

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

    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) = 0;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe=false) = 0;

    llvm::StructType *getStringIR();

public:
    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *floatT;
    llvm::StructType *stringT;
    llvm::PointerType *stringTPtr;
    llvm::StructType *matrixT;
    llvm::PointerType *matrixTPtr;

    llvm::Type *mapType(ir::IR *decl);
    llvm::Type *convertType(ir::TypeDecl *type);
    std::string mangleName(ir::IR *ir);

    static llvm::StringMap<std::pair<llvm::Type *, llvm::Constant *>> userTypes;

    void init();
};


class CGModule : public CodeGen {
private:
    llvm::Module *llvmMod;
    ir::ModuleDecl *mod;
    llvm::DenseMap<ir::IR *, llvm::GlobalObject *> globals;
    llvm::GlobalVariable *str_empty;
    std::vector<std::pair<llvm::Value *, llvm::GlobalVariable *>> stringsToInit;
    std::vector<std::pair<llvm::Value *, ir::MatrixLiteral *>> matricesToInit;
    //std::vector<std::pair<llvm::GlobalVariable *, llvm::GlobalVariable *>> maybesToInit;

    PTLib *ptlibLoader;
protected:
    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) override;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe=false) override;

public:
    CGModule(llvm::Module *llvmMod);
    ~CGModule();

    llvm::LLVMContext &getLLVMCtx() { return llvmMod->getContext(); }
    llvm::Module *getLLVMMod() { return llvmMod; }
    ir::ModuleDecl *getModuleDecl() { return mod; }

    void defineStruct(ir::StructDecl *decl);
    llvm::GlobalObject *getGlobals(ir::IR *ir) { return globals[ir]; }
    void run(ir::ModuleDecl *module);
    llvm::GlobalVariable *nonePtr;
};

class CGFunction : public CodeGen {
private:
    CGModule &cgm;
    ir::FunctionDecl *fun;
    llvm::FunctionType *funType;
    llvm::Function *llvmFun;
    llvm::DenseMap<ir::FormalParamDecl *, llvm::Value *> formalParams;

    llvm::Value *readLocalVar(llvm::BasicBlock *BB, ir::IR *decl);
    llvm::Value *readLocalVarRecursive(llvm::BasicBlock *BB, ir::IR *decl);
    void writeLocalVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val);
    void sealBlock(llvm::BasicBlock *BB);
    llvm::PHINode *addEmptyPhi(llvm::BasicBlock *BB, ir::IR *decl);
    void addPhiOperands(llvm::BasicBlock *BB, ir::IR *decl, llvm::PHINode *phi);
    void optimizePhi(llvm::PHINode *phi);

    llvm::FunctionType *createFunctionType(ir::FunctionDecl *fun);
    llvm::Function *createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType);
protected:
    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) override;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe=false) override;

    llvm::Value *emitInfixExpr(ir::BinaryInfixExpr *e);
    llvm::Value *emitFunCall(ir::FunctionCall *e);
    llvm::Value *emitExpr(ir::Expr *e);

    void emitMemberAssignment(ir::BinaryInfixExpr *l, llvm::Value *r);
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
    CGFunction(CGModule &cgm, ir::FunctionDecl *fun) : CodeGen(cgm.getLLVMCtx(), cgm), cgm(cgm), fun(fun) {
        funType = createFunctionType(fun);
        this->llvmFun = createFunction(fun, funType);
    } 

    void run();
};

}

} // namespace ptc


#endif//_CODE_GEN_HPP_