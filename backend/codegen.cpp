#include "codegen.hpp"
#include "llvm/ADT/StringExtras.h"

using namespace ptc;

cg::CodeGenerator *cg::CodeGenerator::create(llvm::LLVMContext &ctx, llvm::TargetMachine *target) {
    return new CodeGenerator(ctx, target);
}

std::unique_ptr<llvm::Module> cg::CodeGenerator::run(ir::ModuleDecl *module, std::string fileName) {
    std::unique_ptr<llvm::Module> m = std::make_unique<llvm::Module>(fileName, ctx);
    m->setTargetTriple(target->getTargetTriple().getTriple());
    m->setDataLayout(target->createDataLayout());
    cg::CGModule cgm(m.get());
    cgm.run(module);
    return m;
}

void cg::CGModule::init() {
    voidT = llvm::Type::getVoidTy(getLLVMCtx());
    int1T = llvm::Type::getInt1Ty(getLLVMCtx());
    int64T = llvm::Type::getInt64Ty(getLLVMCtx());
    doubleT = llvm::Type::getDoubleTy(getLLVMCtx());
}

llvm::Type *cg::CGModule::convertType(ir::TypeDecl *t) {
    if(t->getName() == INT_CSTR) {
        return int64T;
    }
    if(t->getName() == BOOL_CSTR) {
        return int1T;
    }
    if(t->getName() == VOID_CSTR) {
        return voidT;
    }
    if(t->getName() == FLOAT_CSTR) {
        return doubleT;
    }
    llvm::report_fatal_error("Unsupported type");
    return nullptr;
}

void cg::CGModule::run(ir::ModuleDecl *mod) {
    for(auto *decl: mod->getDecls()) {
        auto kind = decl->getKind();
        switch(kind) {
        case ir::IRKind::IR_VAR_DECL:
            { // new variable needs its own scope
            auto var = llvm::dyn_cast<ir::VarDecl>(decl);
            llvm::GlobalVariable *v = new llvm::GlobalVariable(*llvmMod, 
                                                               convertType(var->getType()),
                                                               false,
                                                               llvm::GlobalValue::PrivateLinkage,
                                                               nullptr,
                                                               mangleName(var));
            globals[var] = v;
            }
        break;
        default: llvm::report_fatal_error("Code generation invoked for not yet implemented IR");
        break;
        }
    }
}