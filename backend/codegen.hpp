#ifndef _CODE_GEN_HPP_
#define _CODE_GEN_HPP_

#include "ir.hpp"
#include "llvm/Target/TargetMachine.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"

namespace ptc {

namespace cg {

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

    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) = 0;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl) = 0;

    llvm::Value *emitInfixExpr(ir::BinaryInfixExpr *e);
    llvm::Value *emitExpr(ir::Expr *e);

    void emitStmt(ir::ExprStmt *stmt);

public:
    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *doubleT;

    llvm::Type *mapType(ir::IR *decl);
    llvm::Type *convertType(ir::TypeDecl *type);
    std::string mangleName(ir::IR *ir);

    void init();
};


class CGModule : public CodeGen {
private:
    llvm::Module *llvmMod;
    ir::ModuleDecl *mod;
    llvm::DenseMap<ir::IR *, llvm::GlobalObject *> globals;
protected:
    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) override;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl) override;

public:
    CGModule(llvm::Module *llvmMod) : CodeGen(llvmMod->getContext(), *this), llvmMod(llvmMod) {}

    llvm::LLVMContext &getLLVMCtx() { return llvmMod->getContext(); }
    llvm::Module *getLLVMMod() { return llvmMod; }
    ir::ModuleDecl *getModuleDecl() { return mod; }

    llvm::GlobalObject *getGlobals(ir::IR *ir) { return globals[ir]; }
    void run(ir::ModuleDecl *module);
};

class CGFunction : public CodeGen {
private:
    CGModule &cgm;
    ir::FunctionDecl *fun;
    llvm::FunctionType *funType;
    llvm::Function *llvmFun;
    llvm::DenseMap<ir::FormalParamDecl *, llvm::Argument *> formalParams;

    llvm::Value *readLocalVar(llvm::BasicBlock *BB, ir::IR *decl);

    llvm::FunctionType *createFunctionType(ir::FunctionDecl *fun);
    llvm::Function *createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType);
protected:
    virtual void writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) override;
    virtual llvm::Value *readVar(llvm::BasicBlock *BB, ir::IR *decl) override;

    virtual void emit(std::vector<ir::IR *> stmts);
public:
    CGFunction(CGModule &cgm) : CodeGen(cgm.getLLVMCtx(), cgm), cgm(cgm) {} 

    void run(ir::FunctionDecl *fun);
    //void run();
};

}

} // namespace ptc


#endif//_CODE_GEN_HPP_