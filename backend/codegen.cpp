#include "codegen.hpp"
#include "logging.hpp"
#include "llvm/ADT/StringExtras.h"

using namespace ptc;

cg::CodeGenHandler *cg::CodeGenHandler::create(llvm::LLVMContext &ctx, llvm::TargetMachine *target) {
    return new CodeGenHandler(ctx, target);
}

std::unique_ptr<llvm::Module> cg::CodeGenHandler::run(ir::ModuleDecl *module, std::string fileName) {
    std::unique_ptr<llvm::Module> m = std::make_unique<llvm::Module>(fileName, ctx);
    m->setTargetTriple(target->getTargetTriple().getTriple());
    m->setDataLayout(target->createDataLayout());
    cg::CGModule cgm(m.get());
    cgm.run(module);
    return m;
}

void cg::CodeGen::init() {
    voidT = llvm::Type::getVoidTy(ctx);
    int1T = llvm::Type::getInt1Ty(ctx);
    int64T = llvm::Type::getInt64Ty(ctx);
    doubleT = llvm::Type::getDoubleTy(ctx);
}

llvm::Type *cg::CodeGen::convertType(ir::TypeDecl *t) {
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

std::string cg::CodeGen::mangleName(ir::IR *ir) {
    // TODO
    std::string mangled;
    LOG1("MANGLING NOT IMPLEMENTED!");
    return mangled;
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

llvm::FunctionType *cg::CGFunction::createFunctionType(ir::FunctionDecl *fun) {
    // TODO:
    return nullptr;
}

llvm::Function *cg::CGFunction::createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType) {
    // TODO:
    return nullptr;
}

void cg::CGFunction::run(ir::FunctionDecl *fun) {
    this->fun = fun;
    // TODO:
}

//void cg::CGFunction::run() { }