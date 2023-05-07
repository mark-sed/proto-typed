#ifndef _CODE_GEN_HPP_
#define _CODE_GEN_HPP_

#include "ir.hpp"
#include "llvm/Target/TargetMachine.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

namespace ptc {

namespace cg {

class CodeGenerator {
private:
    llvm::LLVMContext &ctx;
    llvm::TargetMachine *target;
    ir::ModuleDecl *module;
protected:
    CodeGenerator(llvm::LLVMContext &ctx, llvm::TargetMachine *target)
                 : ctx(ctx), target(target), module(nullptr) {}

public:
    static CodeGenerator *create(llvm::LLVMContext &ctx, llvm::TargetMachine *target);

    std::unique_ptr<llvm::Module> run(ir::ModuleDecl *module, std::string fileName);
}; 

class CGModule {
private:
    llvm::Module *llvmMod;

    ir::ModuleDecl *mod;

    llvm::DenseMap<ir::IR *, llvm::GlobalObject *> globals;

public:
    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *doubleT;
    
    CGModule(llvm::Module *llvmMod) : llvmMod(llvmMod) {
        init();
    }

    void init();

    llvm::LLVMContext &getLLVMCtx() { return llvmMod->getContext(); }
    llvm::Module *getLLVMMod() { return llvmMod; }
    ir::ModuleDecl *getModuleDecl() { return mod; }

    llvm::Type *convertType(ir::TypeDecl *type);
    std::string mangleName(ir::IR *ir);

    llvm::GlobalObject *getGlobals(ir::IR *ir) { return globals[ir]; }
    void run(ir::ModuleDecl *module);
};

}

} // namespace ptc


#endif//_CODE_GEN_HPP_