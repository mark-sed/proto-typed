/**
 * @file codegen.cpp
 * @author Marek Sedlacek
 * @brief Code generation
 * 
 * @copyright Copyright (c) 2023
 * Code generation from IR to LLVM assembly
 */

#include "codegen.hpp"
#include "parser.hpp"
#include "logging.hpp"
#include "utils.hpp"
#include "scanner.hpp"
#include "ir.hpp"
#include "llvm/ADT/StringExtras.h"
#include "llvm/IR/CFG.h"
#include "llvm/Support/Casting.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/Attributes.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/IR/DataLayout.h"
#include <vector>

using namespace ptc;
using namespace ptc::cg;

llvm::cl::OptionCategory CodeGenerationCat("Code Generation Options", "");
static llvm::cl::opt<bool> cgNoMain("no-main", llvm::cl::desc("Does not generate main function for passed in program"), llvm::cl::init(false), llvm::cl::cat(CodeGenerationCat));

bool isPrimitiveType(ir::TypeDecl *t) {
    auto tn = t->getName();
    return tn == INT_CSTR || tn == BOOL_CSTR || tn == FLOAT_CSTR;
}

cg::CGModule::CGModule(llvm::Module *llvmMod, ir::ModuleDecl *ptlibMod) : cg::CodeGen(llvmMod->getContext(), *this, ptlibMod), llvmMod(llvmMod), mainMod(false) {
    ptlibLoader = new PTLib(this, llvmMod, ctx);
}

CGModule::~CGModule() {
    delete ptlibLoader;
}

cg::CodeGenHandler *cg::CodeGenHandler::create(llvm::LLVMContext &ctx, llvm::TargetMachine *target) {
    return new CodeGenHandler(ctx, target);
}

llvm::StringMap<std::pair<llvm::Type *, llvm::Constant *>> cg::CodeGen::userTypes{};

std::unique_ptr<llvm::Module> cg::CodeGenHandler::run(ir::ModuleDecl *module, ir::ModuleDecl *ptlibMod, std::string fileName, bool isMainMod) {
    std::unique_ptr<llvm::Module> m = std::make_unique<llvm::Module>(fileName, ctx);
    m->setTargetTriple(target->getTargetTriple().getTriple());
    m->setDataLayout(target->createDataLayout());
    cgm = new cg::CGModule(m.get(), ptlibMod);
    cgm->setMainMod(isMainMod);
    cgm->run(module);
    return m;
}

void cg::CodeGen::init() {
    voidT = llvm::Type::getVoidTy(ctx);
    int1T = llvm::Type::getInt1Ty(ctx);
    int64T = llvm::Type::getInt64Ty(ctx);
    floatT = llvm::Type::getDoubleTy(ctx);
    // Any is maybe type so the pointer will be generated automatically
    anyT = builder.getInt8Ty();

    std::vector<llvm::Type*> structElements{
        builder.getInt8Ty()->getPointerTo(),
        builder.getInt32Ty(),
        builder.getInt32Ty(),
        builder.getInt32Ty()
    };
    stringT = llvm::StructType::create(ctx, structElements, STRING_CSTR);
    stringTPtr = stringT->getPointerTo();

    std::vector<llvm::Type*> matrixElements{
        builder.getInt8Ty()->getPointerTo(),
        builder.getInt32Ty(),
        builder.getInt32Ty(),
        builder.getInt32Ty()
    };
    matrixT = llvm::StructType::create(ctx, matrixElements, MATRIX_CSTR);
    matrixTPtr = matrixT->getPointerTo();

    stringSizeBytes = llvm::ConstantInt::get(builder.getInt64Ty(), 16, true);
}

llvm::Type *cg::CodeGen::convertType(ir::TypeDecl *t) {
    llvm::Type *llvmT = nullptr;
    if(t->isMatrix()) {
        llvmT = matrixT;
    }
    else if(t->getName() == INT_CSTR) {
        llvmT = int64T;
    }
    else if(t->getName() == BOOL_CSTR) {
        llvmT = int1T;
    }
    else if(t->getName() == VOID_CSTR) {
        llvmT = voidT;
    }
    else if(t->getName() == FLOAT_CSTR) {
        llvmT = floatT;
    }
    else if(t->getName() == STRING_CSTR) {
        llvmT = stringT;
    }
    else if(t->getName() == ANY_CSTR) {
        llvmT = anyT;
    }
    else if(t->getDecl()) {
        if(auto *v = llvm::dyn_cast<ir::StructDecl>(t->getDecl())) {
            if(!v->isLibType()) {
                std::string manName = mangleName(v);
                llvmT = userTypes[manName].first;
            }
            else {
                llvmT = userTypes[v->getName()].first;
            }
        }
    }

    if(!llvmT) {
        llvm::report_fatal_error("Unsupported type");
        return nullptr;
    }

    if(t->isMaybe())
        return llvmT->getPointerTo();
    return llvmT;
}

std::string cg::CodeGen::mangleName(ir::IR *ir) {
    if(currModule.mod == ptlibMod) {
        return ir->getName();
    }

    std::string mangled;
    while(ir) {
        mangled.insert(0, ir->getName()+"_");
        ir = ir->getEnclosingIR();
    }
    mangled.insert(0, "_ptc_");
    return mangled;
}

llvm::Type *cg::CodeGen::mapType(ir::IR *decl) {
    if(auto *fp = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        llvm::Type *t = convertType(fp->getType());
        // Maybe type handles this
        //if(fp->isByReference()) {
        //    t = t->getPointerTo();
        //}
        return t;
    }
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        return convertType(v->getType());
    }
    return convertType(llvm::cast<ir::TypeDecl>(decl));
}

void cg::CGModule::writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    /*if(llvm::dyn_cast<ir::VarDecl>(decl)) {
        LOGMAX("Writing variable in module");
        builder.CreateStore(val, getGlobals(decl));
    } else {
        llvm::report_fatal_error("Unsupported variable access");
    }*/
    llvm::report_fatal_error("UNIMPLEMENTED module var write");
}

void cg::CGFunction::writeLocalVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    assert(BB && "Basic block is nullptr");
    assert(
        (llvm::isa<ir::VarDecl>(decl) ||
        llvm::isa<ir::FormalParamDecl>(decl)) &&
        "Declaration must be variable or formal parameter");
    assert(val && "Value is nullptr");
    LOGMAX("Write local var: "+decl->debug());
    currDef[BB].defs[decl] = val;
    // Check if it is a parameter
    if (auto *fpd = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(formalParams.find(fpd) != formalParams.end()) {
            if(fpd->getType()->isMaybe() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
                auto ptrV = builder.CreateLoad(mapType(fpd->getType()), formalParams[fpd]);
                builder.CreateStore(val, ptrV);
            }
            else {
                builder.CreateStore(val, formalParams[fpd]);
            }
        }
        else {
            llvm::report_fatal_error("Write local var formal param not found");
        }
    }
    else if(auto *vrdec = llvm::dyn_cast<ir::VarDecl>(decl)){
        // Its a local variable
        if(locals.find(decl) != locals.end()) {
            if(vrdec->getType()->isMaybe() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
                llvm::BasicBlock *allocBB = llvm::BasicBlock::Create(ctx, "maybe.alloc", llvmFun);
                llvm::BasicBlock *assignBB = llvm::BasicBlock::Create(ctx, "maybe.assign", llvmFun);

                auto ptrVal = builder.CreateLoad(mapType(vrdec->getType()), locals[decl]);
                auto isNone = builder.CreateICmpEQ(ptrVal, llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(mapType(vrdec->getType()))));
                builder.CreateCondBr(isNone, allocBB, assignBB);

                setCurrBB(allocBB);
                auto mallocF = cgm.getLLVMMod()->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));
                llvm::DataLayout* dataLayout = new llvm::DataLayout(cgm.getLLVMMod());
                auto ts = dataLayout->getTypeAllocSize(val->getType());
                auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
                builder.CreateStore(mem, locals[decl]);

                builder.CreateBr(assignBB);
                setCurrBB(assignBB);

                auto ptrValNew = builder.CreateLoad(mapType(vrdec->getType()), locals[decl]);
                builder.CreateStore(val, ptrValNew);
            }
            else {
                // Check if any to bitcast //TODO: Remove once as is implemented 
                /*if(val->getType() == builder.getInt8Ty()) {
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(val)) {
                        auto emEx = li->getOperand(0);
                        auto casted = builder.CreateBitCast(emEx, mapType(decl)->getPointerTo());
                        auto loaded = builder.CreateLoad(mapType(decl), casted);
                        builder.CreateStore(loaded, locals[decl]);
                    }
                    else {
                        llvm::report_fatal_error("Cannot cast any type for parameter");
                    }
                }
                else {*/
                    builder.CreateStore(val, locals[decl]);
                //}
            }
        }
        else {
            llvm::Type *t;
            ir::TypeDecl *td;
            if(auto vrdcl = llvm::dyn_cast<ir::VarDecl>(decl)) {
                td = vrdcl->getType();
                t = mapType(vrdcl->getType());
            }
            else if(auto frmlp = llvm::dyn_cast<ir::FormalParamDecl>(decl)){
                td = frmlp->getType();
                t = mapType(frmlp->getType());
            }
            else {
                llvm::report_fatal_error("Unknown local variable type");
            }
            
            if(td->isMaybe() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
                auto mallocF = cgm.getLLVMMod()->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));
                llvm::DataLayout* dataLayout = new llvm::DataLayout(cgm.getLLVMMod());
                auto ts = dataLayout->getTypeAllocSize(val->getType());
                auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
                auto vPtrPtr = builder.CreateAlloca(t);
                builder.CreateStore(val, mem);
                builder.CreateStore(mem, vPtrPtr);
                locals[decl] = vPtrPtr;
            }
            else {
                auto vPtr = builder.CreateAlloca(t);
                // Check if any to bitcast //TODO: Remove once as is implemented 
                /*if(val->getType() == builder.getInt8Ty()) {
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(val)) {
                        auto emEx = li->getOperand(0);
                        auto casted = builder.CreateBitCast(emEx, mapType(decl)->getPointerTo());
                        val = builder.CreateLoad(mapType(decl), casted);
                    }
                    else {
                        llvm::report_fatal_error("Cannot cast any type for parameter");
                    }
                }*/
                builder.CreateStore(val, vPtr);
                locals[decl] = vPtr;
            }
        }
    }
}

void cg::CGFunction::writeVar(llvm::BasicBlock *BB, ir::IR *decl, llvm::Value *val) {
    LOGMAX("Write var: "+decl->debug());
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR() == cgm.getModuleDecl()) {
            if(v->getType()->isMaybe() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
                llvm::BasicBlock *allocBB = llvm::BasicBlock::Create(ctx, "maybe.alloc", llvmFun);
                llvm::BasicBlock *assignBB = llvm::BasicBlock::Create(ctx, "maybe.assign", llvmFun);
                
                auto ptrVal = builder.CreateLoad(mapType(v->getType()), cgm.getGlobals(decl));
                auto isNone = builder.CreateICmpEQ(ptrVal, llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(mapType(v->getType()))));
                builder.CreateCondBr(isNone, allocBB, assignBB);

                setCurrBB(allocBB);
                auto mallocF = cgm.getLLVMMod()->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));
                llvm::DataLayout* dataLayout = new llvm::DataLayout(cgm.getLLVMMod());
                auto ts = dataLayout->getTypeAllocSize(val->getType());
                auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
                builder.CreateStore(mem, cgm.getGlobals(decl));

                builder.CreateBr(assignBB);
                setCurrBB(assignBB);

                auto ptrValNew = builder.CreateLoad(mapType(v->getType()), cgm.getGlobals(decl));
                builder.CreateStore(val, ptrValNew);
            }
            else {
                // Check if any to bitcast
                /*if(val->getType() == builder.getInt8Ty()) {
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(val)) {
                        auto emEx = li->getOperand(0);
                        auto casted = builder.CreateBitCast(emEx, mapType(decl)->getPointerTo());
                        auto loaded = builder.CreateLoad(mapType(decl), casted);
                        builder.CreateStore(loaded, cgm.getGlobals(decl));
                    }
                    else {
                        llvm::report_fatal_error("Cannot cast any type for global value");
                    }
                }
                else {*/
                builder.CreateStore(val, cgm.getGlobals(decl));
                //}
            }
        }
        else {
            writeLocalVar(BB, decl, val);
        }
    } else if (auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
            llvm::BasicBlock *allocBB = llvm::BasicBlock::Create(ctx, "maybe.alloc", llvmFun);
            llvm::BasicBlock *assignBB = llvm::BasicBlock::Create(ctx, "maybe.assign", llvmFun);
            
            auto ptrVal = builder.CreateLoad(mapType(v->getType()), formalParams[v]);
            auto isNone = builder.CreateICmpEQ(ptrVal, llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(mapType(v->getType()))));
            builder.CreateCondBr(isNone, allocBB, assignBB);

            setCurrBB(allocBB);
            auto mallocF = cgm.getLLVMMod()->getOrInsertFunction("GC_malloc",
                                llvm::FunctionType::get(
                                builder.getInt8Ty()->getPointerTo(),
                                builder.getInt64Ty(),
                                false
                                ));
            llvm::DataLayout* dataLayout = new llvm::DataLayout(cgm.getLLVMMod());
            auto ts = dataLayout->getTypeAllocSize(val->getType());
            auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
            builder.CreateStore(mem, formalParams[v]);

            builder.CreateBr(assignBB);
            setCurrBB(assignBB);

            auto ptrValNew = builder.CreateLoad(mapType(v->getType()), formalParams[v]);
            builder.CreateStore(val, ptrValNew);
        }
        else {
            writeLocalVar(BB, decl, val);
        }
    } else {
        llvm::report_fatal_error("Unsupported variable access");
    }
}

void cg::CGFunction::writeExtVar(CGModule *mod, ir::IR *decl, llvm::Value *val) {
    LOGMAX("Write external var: "+decl->debug());
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR() == mod->getModuleDecl()) {
            if(!mod) {
                llvm::report_fatal_error("External value is from unparsed module");
            }
            // Check if already declared
            auto extVar = cgm.getLLVMMod()->getNamedGlobal(mangleName(decl));
            if(!extVar) {
                extVar = new llvm::GlobalVariable(*cgm.getLLVMMod(),
                                                mapType(v),
                                                false,
                                                llvm::GlobalValue::ExternalLinkage,
                                                nullptr,
                                                mangleName(decl));
            }

            if(v->getType()->isMaybe() && !llvm::isa<llvm::ConstantPointerNull>(val) && !llvm::isa<llvm::PointerType>(val->getType())) {
                llvm::BasicBlock *allocBB = llvm::BasicBlock::Create(ctx, "maybe.alloc", llvmFun);
                llvm::BasicBlock *assignBB = llvm::BasicBlock::Create(ctx, "maybe.assign", llvmFun);
                
                auto ptrVal = builder.CreateLoad(mapType(v->getType()), extVar);
                auto isNone = builder.CreateICmpEQ(ptrVal, llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(mapType(v->getType()))));
                builder.CreateCondBr(isNone, allocBB, assignBB);

                setCurrBB(allocBB);
                auto mallocF = cgm.getLLVMMod()->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));
                llvm::DataLayout* dataLayout = new llvm::DataLayout(cgm.getLLVMMod());
                auto ts = dataLayout->getTypeAllocSize(val->getType());
                auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
                builder.CreateStore(mem, extVar);

                builder.CreateBr(assignBB);
                setCurrBB(assignBB);

                auto ptrValNew = builder.CreateLoad(mapType(v->getType()), extVar);
                builder.CreateStore(val, ptrValNew);
            }
            else {
                // Check if any to bitcast
                /*if(val->getType() == builder.getInt8Ty()) {
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(val)) {
                        auto emEx = li->getOperand(0);
                        auto casted = builder.CreateBitCast(emEx, mapType(decl)->getPointerTo());
                        auto loaded = builder.CreateLoad(mapType(decl), casted);
                        builder.CreateStore(loaded, extVar);
                    }
                    else {
                        llvm::report_fatal_error("Cannot cast any type for global value");
                    }
                }
                else {*/
                    builder.CreateStore(val, extVar);
                //}
            }
        }
        else {
            llvm::report_fatal_error("Cannot write into local external variable");
        }
    }
    else {
        llvm::report_fatal_error("Only external variable can be written to");
    }
}

llvm::Value *cg::CGModule::readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe) {
    llvm::report_fatal_error("UNIMPLEMENTED module var read");
}

llvm::Value *cg::CGFunction::readLocalVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe) {
    LOGMAX("Read local var: "+decl->debug());
    // TODO: Checks for type
    LOGMAX("Read var "+decl->debug());
    auto val = locals.find(decl);
    if(val != locals.end()) {
        llvm::Type *t = nullptr;
        ir::TypeDecl *ptT = nullptr;
        if(auto vrdcl = llvm::dyn_cast<ir::VarDecl>(decl)) {
            ptT = vrdcl->getType();
            t = mapType(ptT);
        }
        else if(auto vrdcl = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
            ptT = vrdcl->getType();
            t = mapType(ptT);
        }
        if(ptT->isMaybe() && !asMaybe) {
            auto ptrV = builder.CreateLoad(t, val->second);
            return builder.CreateLoad(t->getPointerElementType(), ptrV);
        }
        return builder.CreateLoad(t, val->second);
    }
    else {
        if(auto fpd = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
            auto fval = formalParams.find(fpd);
            if(fval != formalParams.end()) {
                if(fpd->getType()->isMaybe() && !asMaybe) {
                    auto ptrV = builder.CreateLoad(mapType(fpd->getType()), fval->second);
                    return builder.CreateLoad(mapType(fpd->getType())->getPointerElementType(), ptrV);
                }
                return builder.CreateLoad(mapType(fpd->getType()), fval->second);
            }
            else {
                llvm::report_fatal_error("Somehow codegen did not have formal parameter created");
            }
        }
        else {
            llvm::report_fatal_error("Somehow codegen did not have variable created");
            
        }
    }
    return nullptr;
}

llvm::Value *cg::CGFunction::readVar(llvm::BasicBlock *BB, ir::IR *decl, bool asMaybe) {
    LOGMAX("Read var: "+decl->debug());
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR()->getKind() == ir::IRKind::IR_MODULE_DECL) {
            if(v->getType()->isMaybe() && !asMaybe) {
                auto ptrV = builder.CreateLoad(mapType(v), currModule.getGlobals(decl));
                return builder.CreateLoad(mapType(v)->getPointerElementType(), ptrV);
            }
            return builder.CreateLoad(mapType(v), currModule.getGlobals(decl));
        }
        else {
            return readLocalVar(BB, decl, asMaybe);
        }
        /*else {
            llvm::report_fatal_error("Nested functions are not supported");
        }*/
    } else if(auto *v = llvm::dyn_cast<ir::FormalParamDecl>(decl)) {
        if(v->isByReference()) {
            if(v->getType()->isMaybe() && !asMaybe) {
                auto fvPtr = builder.CreateLoad(mapType(v), formalParams[v]);
                return builder.CreateLoad(mapType(v)->getPointerElementType(), fvPtr);
            }
            return builder.CreateLoad(mapType(v)->getNonOpaquePointerElementType(), formalParams[v]);
        }
        else {
            return readLocalVar(BB, decl, asMaybe);
        }
    }
    llvm::report_fatal_error("Unsupported variable declaration");
    return nullptr;
}

llvm::Value *cg::CGFunction::readExtVar(cg::CGModule *mod, ir::IR *decl, bool asMaybe) {
    LOGMAX("Read external var: "+decl->debug());
    if(auto *v = llvm::dyn_cast<ir::VarDecl>(decl)) {
        if(v->getEnclosingIR()->getKind() == ir::IRKind::IR_MODULE_DECL) {
            if(!mod) {
                llvm::report_fatal_error("External value is from unparsed module");
            }
            auto vPtr = cgm.getLLVMMod()->getNamedGlobal(mangleName(decl));
            if(!vPtr) {
                vPtr = new llvm::GlobalVariable(*cgm.getLLVMMod(),
                                                mapType(v),
                                                false,
                                                llvm::GlobalValue::ExternalLinkage,
                                                nullptr,
                                                mangleName(decl));
            }
            if(v->getType()->isMaybe() && !asMaybe) {
                auto ptrV = builder.CreateLoad(mapType(v), vPtr);
                return builder.CreateLoad(mapType(v)->getPointerElementType(), ptrV);
            }
            return builder.CreateLoad(mapType(v), vPtr);
        }
        else {
            llvm::report_fatal_error("Only global variables are accessible from other modules");
        }
    }
    llvm::report_fatal_error("Unsupported variable declaration");
    return nullptr;
}

llvm::Value *cg::CGFunction::emitFunCall(ir::FunctionCall *e) {
    if(e->isUnresolved()) {
        llvm::report_fatal_error("Function call was not resolved by a resolver");
    }
    ir::FunctionDecl *f = e->getFun();
    std::vector<llvm::Value *> args{};
    int index = 0;
    for(auto a: e->getParams()) {
        llvm::Value *emEx = nullptr;
        if(f->getParams()[index]->isByReference()) {
            if(auto aa = llvm::dyn_cast<ir::VarAccess>(a)) {
                if(aa->getType()->isMaybe()) {
                    emEx = readVar(currBB, aa->getVar(), true);
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(emEx)) {
                        emEx = li->getOperand(0);
                    }
                    else {
                        llvm::report_fatal_error("Argument in a function call cannot be passed in by a reference");
                    }
                }
                else {
                    emEx = builder.CreateAlloca(mapType(f->getParams()[index]->getType()));
                    auto vLd = readVar(currBB, aa->getVar(), true);
                    if(auto li = llvm::dyn_cast<llvm::LoadInst>(vLd)) {
                        builder.CreateStore(li->getOperand(0), emEx);
                    }
                    else {
                        llvm::report_fatal_error("Argument in a function call cannot be passed in by a reference");
                    }
                }
            }
            else {
                // Constant was passed to a maybe argument
                // Alloca memory and forget about it as it cannot be used
                emEx = builder.CreateAlloca(mapType(f->getParams()[index]->getType()));
                auto emExValPtr = builder.CreateAlloca(mapType(f->getParams()[index]->getType())->getPointerElementType());
                builder.CreateStore(emitExpr(a), emExValPtr);
                builder.CreateStore(emExValPtr, emEx);
            }
        }
        else {
            emEx = emitExpr(a);
        }
        args.push_back(emEx);
        ++index;
    }
    // TODO: Set last arg to true is argvars
    if(!e->isExternal()) {
        llvm::Function *funDecl = cgm.getLLVMMod()->getFunction(mangleName(f));
        if(!funDecl) {
            // Lib functions
            funDecl = cgm.getLLVMMod()->getFunction(f->getName());
        }
        if(!funDecl) {
            auto msg = "Somehow function "+f->getOGName()+"('"+mangleName(f)+"') could not be found";
            llvm::report_fatal_error(msg.c_str());
        }
        return builder.CreateCall(funDecl, args);
    } else {
        auto funDecl = cgm.getLLVMMod()->getOrInsertFunction(mangleName(e->getFun()), createFunctionType(e->getFun()));
        return builder.CreateCall(funDecl, args);
    }
}

llvm::Value *cg::CGFunction::emitExpr(ir::Expr *e) {
    switch(e->getKind()) {
    case ir::ExprKind::EX_BIN_INF: return emitInfixExpr(llvm::dyn_cast<ir::BinaryInfixExpr>(e));
    case ir::ExprKind::EX_UN_PRE: return emitUnaryPrefixExpr(llvm::dyn_cast<ir::UnaryPrefixExpr>(e));
    case ir::ExprKind::EX_VAR:
    {
        auto *decl = llvm::dyn_cast<ir::VarAccess>(e)->getVar();
        // VarAccess might by type for as operator
        if(llvm::isa<ir::TypeDecl>(decl)) {
            return nullptr;
        }
        return readVar(currBB, decl);
    }
    case ir::ExprKind::EX_INT:
        return llvm::ConstantInt::get(int64T, llvm::dyn_cast<ir::IntLiteral>(e)->getValue());
    case ir::ExprKind::EX_NONE:
        return llvm::ConstantPointerNull::get(builder.getInt8Ty()->getPointerTo());
    case ir::ExprKind::EX_STRING: 
    {
        llvm::GlobalVariable *v = new llvm::GlobalVariable(*cgm.getLLVMMod(),
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr);
        v->setInitializer(builder.CreateGlobalStringPtr(llvm::dyn_cast<ir::StringLiteral>(e)->getValue().c_str(), "", 0, cgm.getLLVMMod()));
        
        auto strobj = builder.CreateAlloca(stringT);

        auto stringInitF = cgm.getLLVMMod()->getOrInsertFunction("string_Create_Init", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        {
                                                            stringTPtr,
                                                            builder.getInt8Ty()->getPointerTo()
                                                        },
                                                        false
                                                    ));
        // Init string
        auto vloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), v);
        builder.CreateCall(stringInitF, { strobj, vloaded });
        auto strval = builder.CreateLoad(stringT, strobj);
        
        return strval;

    }
    case ir::ExprKind::EX_BOOL: return llvm::ConstantInt::get(int1T, llvm::dyn_cast<ir::BoolLiteral>(e)->getValue());
    case ir::ExprKind::EX_FLOAT: return llvm::ConstantFP::get(floatT,llvm::dyn_cast<ir::FloatLiteral>(e)->getValue());
    case ir::ExprKind::EX_MATRIX:
    {
        auto matPtr = builder.CreateAlloca(matrixTPtr);
        auto matobj = builder.CreateAlloca(matrixT);
        builder.CreateStore(matobj, matPtr);
        auto matrixCreateF = cgm.getLLVMMod()->getOrInsertFunction("matrix_Create_Default", 
                                                      llvm::FunctionType::get(
                                                        voidT,
                                                        matrixTPtr,
                                                        false
                                                      ));
        builder.CreateCall(matrixCreateF, matobj);
        auto mex = llvm::dyn_cast<ir::MatrixLiteral>(e);
        // TODO: change to non cyclic call once add matrix is created or init matrix
        auto matrixAppend = cgm.getLLVMMod()->getFunction("append_"+mex->getType()->getName()+"_"+mex->getType()->getDecl()->getName());
        if(!matrixAppend) {
            llvm::report_fatal_error(("Somehow correctly templated append function was not generated: append_"+mex->getType()->getName()+"_"+mex->getType()->getDecl()->getName()).c_str());
        }
        for(auto v: mex->getValue()) {
            builder.CreateCall(matrixAppend, {matPtr, emitExpr(v)});
        }
        return builder.CreateLoad(matrixT, matobj);
    }
    case ir::ExprKind::EX_FUN_CALL: return emitFunCall(llvm::dyn_cast<ir::FunctionCall>(e));
    case ir::ExprKind::EX_MEMBER_ACCESS: return nullptr; // Member access is handeled by the left hand side
    case ir::ExprKind::EX_RANGE: return nullptr; // For loop handles this
    case ir::ExprKind::EX_EXT_SYMB: 
    {
        auto extS = llvm::dyn_cast<ir::ExternalSymbolAccess>(e);
        if(auto vd = llvm::dyn_cast<ir::VarDecl>(extS->getExtIR())) {
            if(!extS->getModDecl()) {
                llvm::report_fatal_error("External symbol module was not resolved");
            }
            auto v = readExtVar(extS->getModDecl()->getCGModule(), vd);
            return v;
        }

        llvm::report_fatal_error("Unknown external symbol IR");
        return nullptr;
    }
    case ir::ExprKind::EX_STRUCT:
    {
        auto *decl = llvm::dyn_cast<ir::StructLiteral>(e);
        auto struDecl = decl->getDecl();
        auto tp = decl->getType();

        auto sPtr = builder.CreateAlloca(mapType(tp));

        int i = 0;
        for(auto elem : struDecl->getElements()) {
            auto evar = llvm::dyn_cast<ir::VarDecl>(elem);
            if(evar->getType()->isMaybe()) {
                llvm::report_fatal_error("Struct literal maybe types are not yet implemented");
            }
            auto ival = evar->getInitValue();
            for(auto [k, v] : decl->getValues()) {
                if(k == evar->getName()) {
                    ival = v;
                    break;
                }
            }
            llvm::Value *emV = nullptr;
            if(!ival) {
                if(isPrimitiveType(evar->getType())) {
                    emV = cgm.getTypeDefaultValue(evar->getType());
                }
                else if(evar->getType()->getName() == STRING_CSTR) {
                    std::string s = "";
                    ir::StringLiteral *empt = new ir::StringLiteral(evar->getLocation(), s, evar->getType());
                    emV = emitExpr(empt);
                }
                else {
                    llvm::report_fatal_error("Struct nested intializer is not yet implemented");
                }
            } else {
                emV = emitExpr(ival);
            }
            llvm::Value *zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), 0);
            llvm::Value *index = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), i);
            auto elemPtr = builder.CreateGEP(mapType(tp), sPtr, {zero, index});
            builder.CreateStore(emV, elemPtr);
            ++i;
        }
        return builder.CreateLoad(mapType(tp), sPtr);
    }
    default:
        llvm::report_fatal_error(("Unimplemented expression kind in code generation "+e->debug()).c_str());
        return nullptr;
    }
}

llvm::Value *cg::CGFunction::getElementIndex(std::vector<llvm::Value *> &indices, ir::BinaryInfixExpr *acc) {
    auto left = acc->getLeft();
    auto right = acc->getRight();

    if(auto elem = llvm::dyn_cast<ir::MemberAccess>(right)) {
        auto strucType = left->getType();
        if(!strucType->getDecl() || !llvm::isa<ir::StructDecl>(strucType->getDecl())) {
            llvm::report_fatal_error("Assignment variable is not a struct");
        }
        
        llvm::Value *v = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), elem->getIndex());
        indices.insert(indices.begin(), v);
    }
    else {
        llvm::report_fatal_error("Left hand side is not assignable");
    }

    if(auto elleft = llvm::dyn_cast<ir::BinaryInfixExpr>(left)) {
        return getElementIndex(indices, elleft);
    }
    else if(auto var = llvm::dyn_cast<ir::VarAccess>(left)){
        llvm::Value *llvar = nullptr;
        auto strucType = left->getType();
        if(auto v = llvm::dyn_cast<ir::VarDecl>(var->getVar())) {
            if(v->getEnclosingIR() == cgm.getModuleDecl()) {
                llvar = cgm.getGlobals(var->getVar());
            }
            else if(v->getEnclosingIR() == fun) {
                llvar = readVar(currBB, var->getVar());
                if(auto r = llvm::dyn_cast<llvm::LoadInst>(llvar))
                    llvar = r->getOperand(0);
            }
            else {
                llvm::report_fatal_error("Unknown variable scope");
            }
        }
        else if(auto v = llvm::dyn_cast<ir::FormalParamDecl>(var->getVar())) {
            if(v->isByReference()) {
                llvar = formalParams[v];
                if(auto r = llvm::dyn_cast<llvm::LoadInst>(llvar))
                    llvar = r->getOperand(0);
            }
            else {
                auto llvarval = readVar(currBB, var->getVar());
                if(auto r = llvm::dyn_cast<llvm::LoadInst>(llvarval))
                    llvar = r->getOperand(0);
            }
        }
        else {
            llvm::report_fatal_error("Unknown variable type for assignment");
        }
        llvm::Value *zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(cgm.getLLVMCtx()), 0);
        indices.insert(indices.begin(), zero);
        return builder.CreateGEP(mapType(strucType), llvar, indices);
    }
    llvm::report_fatal_error("Unknown construct in element access");
    return nullptr;
}

llvm::Value *cg::CGFunction::emitStructElem(ir::BinaryInfixExpr *acc) {
    std::vector<llvm::Value *> indices;
    return getElementIndex(indices, acc);
}

void cg::CGFunction::emitMemberAssignment(ir::BinaryInfixExpr *l, llvm::Value *r) {
    builder.CreateStore(r, emitStructElem(l));
}

llvm::Value *cg::CGFunction::emitUnaryPrefixExpr(ir::UnaryPrefixExpr *e) {
    llvm::Value *left = emitExpr(e->getExpr());
    llvm::Value *result = nullptr;
    switch(e->getOperator().getKind()) {
    case ir::OperatorKind::OP_LNOT:
        LOGMAX("Creating LNOT instruction");
        if(left->getType() == int1T) {
            result = builder.CreateNot(left);
        }
        else {
            llvm::report_fatal_error("LNOT does not supported given type");
        }
    break;
    case ir::OperatorKind::OP_BNOT:
        LOGMAX("Creating BNOT instruction");
        if(left->getType() == int64T) {
            result = builder.CreateNot(left);
        }
        else {
            llvm::report_fatal_error("BNOT does not supported given type");
        }
    break;
    default: llvm::report_fatal_error("Uknown unary operator in code generation");
    }

    return result;
}

llvm::Value *cg::CGFunction::emitInfixExpr(ir::BinaryInfixExpr *e) {
    llvm::Value *left = emitExpr(e->getLeft());
    llvm::Value *right = emitExpr(e->getRight());
    llvm::Value *result = nullptr;
    switch(e->getOperator().getKind()) {
    case ir::OperatorKind::OP_ASSIGN:
    {
        LOGMAX("Creating assignment instruction");
        if(auto *var = llvm::dyn_cast<ir::VarAccess>(e->getLeft())) {
            if(auto *varDecl = llvm::dyn_cast<ir::VarDecl>(var->getVar())) {
                if(e->getLeft()->getType()->isMaybe() && e->getRight()->getType()->isMaybe()) {
                    if(auto r = llvm::dyn_cast<llvm::LoadInst>(right))
                        right = r->getOperand(0);
                }
                writeVar(currBB, varDecl, right);
            }
            else if(auto *fp = llvm::dyn_cast<ir::FormalParamDecl>(var->getVar())) {
                if(e->getLeft()->getType()->isMaybe() && e->getRight()->getType()->isMaybe()) {
                    if(auto r = llvm::dyn_cast<llvm::LoadInst>(right))
                        right = r->getOperand(0);
                }
                writeVar(currBB, fp, right);
            }
            else {
                llvm::report_fatal_error("Unknown left value in an assignment");
            }
        }
        else if(auto *var = llvm::dyn_cast<ir::BinaryInfixExpr>(e->getLeft())) {
            emitMemberAssignment(var, right);
        }
        else if(auto *val = llvm::dyn_cast<ir::ExternalSymbolAccess>(e->getLeft())) {
            if(auto *varDecl = llvm::dyn_cast<ir::VarDecl>(val->getExtIR())) {
                if(e->getLeft()->getType()->isMaybe() && e->getRight()->getType()->isMaybe()) {
                    if(auto r = llvm::dyn_cast<llvm::LoadInst>(right))
                        right = r->getOperand(0);
                }
                writeExtVar(val->getModDecl()->getCGModule(), varDecl, right);
            }
            else {
                llvm::report_fatal_error("Unimplemented external IR type in assignment");
            }
        }
        else {
            llvm::report_fatal_error("Left hand side of an assignment is not assignable");
        }
    }
    break;
    case ir::OperatorKind::OP_ADD:
    {
        LOGMAX("Creating ADD instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWAdd(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFAdd(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFAdd(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFAdd(intv, right);
        }
        else {
            llvm::report_fatal_error("ADD does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_SUB:
    {
        LOGMAX("Creating SUB instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWSub(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFSub(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFSub(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFSub(intv, right);
        }
        else {
            llvm::report_fatal_error("SUB does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_POW:
    {
        LOGMAX("Creating POW instruction");
        // Conversions if needed
        if(e->getLeft()->getType()->getName() == INT_CSTR) {
            left = builder.CreateSIToFP(left, floatT);
        }
        if(e->getRight()->getType()->getName() == INT_CSTR) {
            right = builder.CreateSIToFP(right, floatT);
        }

        if(left->getType() == right->getType()) {
            auto powfun = cgm.getLLVMMod()->getOrInsertFunction("pow",
                                 llvm::FunctionType::get(
                                    floatT,
                                    {
                                        floatT,
                                        floatT
                                    },
                                    false
                                 ));
            result = builder.CreateCall(powfun, {left, right});
        }
        else {
            llvm::report_fatal_error("POW does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_MUL:
    {
        LOGMAX("Creating MUL instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateNSWMul(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFMul(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFMul(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFMul(intv, right);
        }
        else {
            llvm::report_fatal_error("MUL does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_DIV:
    {
        LOGMAX("Creating DIV instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateSDiv(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFDiv(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFDiv(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFDiv(intv, right);
        }
        else {
            llvm::report_fatal_error("DIV does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_MOD:
    {
        LOGMAX("Creating MOD instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateSRem(left, right);
        }
        else if(left->getType() == right->getType() && left->getType() == floatT) {
            result = builder.CreateFRem(left, right);
        }
        else if(left->getType() == floatT && right->getType() == int64T) {
            auto intv = builder.CreateSIToFP(right, floatT);
            result = builder.CreateFRem(left, intv);
        }
        else if(left->getType() == int64T && right->getType() == floatT) {
            auto intv = builder.CreateSIToFP(left, floatT);
            result = builder.CreateFRem(intv, right);
        }
        else {
            llvm::report_fatal_error("MOD does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BLSHFT:
    {
        LOGMAX("Creating BLSHFT instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateShl(left, right);
        }
        else {
            llvm::report_fatal_error("BLSHFT does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BRSHFT:
    {
        LOGMAX("Creating BRSHFT instruction");
        if(left->getType() == right->getType() && left->getType() == int64T) {
            result = builder.CreateAShr(left, right);
        }
        else {
            llvm::report_fatal_error("BRSHFT does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BT:
    {
        LOGMAX("Creating BT instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_cmp = cgm.getLLVMMod()->getOrInsertFunction("strcmp",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    {
                                        builder.getInt8Ty()->getPointerTo(),
                                        builder.getInt8Ty()->getPointerTo()
                                    },
                                    false
                                 ));
            auto leftbf = builder.CreateExtractValue(left, 0);
            auto rightbf = builder.CreateExtractValue(right, 0);
            auto cmpval = builder.CreateCall(str_cmp, {leftbf, rightbf});
            result = builder.CreateICmpSGT(cmpval, llvm::ConstantInt::get(builder.getInt32Ty(), 0, true));
        }
        else if(left->getType() == right->getType()) {
            if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpOGT(left, right);
            }
            else {
                result = builder.CreateICmpSGT(left, right);
            }
        }
        else {
            llvm::report_fatal_error("BT does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BEQ:
    {
        LOGMAX("Creating BEQ instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_cmp = cgm.getLLVMMod()->getOrInsertFunction("strcmp",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    {
                                        builder.getInt8Ty()->getPointerTo(),
                                        builder.getInt8Ty()->getPointerTo()
                                    },
                                    false
                                 ));
            auto leftbf = builder.CreateExtractValue(left, 0);
            auto rightbf = builder.CreateExtractValue(right, 0);
            auto cmpval = builder.CreateCall(str_cmp, {leftbf, rightbf});
            result = builder.CreateICmpSGE(cmpval, llvm::ConstantInt::get(builder.getInt32Ty(), 0, true));
        }
        else if(left->getType() == right->getType()) {
            if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpOGE(left, right);
            }
            else {
                result = builder.CreateICmpSGE(left, right);
            }
        }
        else {
            llvm::report_fatal_error("BEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LT:
    {
        LOGMAX("Creating LT instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_cmp = cgm.getLLVMMod()->getOrInsertFunction("strcmp",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    {
                                        builder.getInt8Ty()->getPointerTo(),
                                        builder.getInt8Ty()->getPointerTo()
                                    },
                                    false
                                 ));
            auto leftbf = builder.CreateExtractValue(left, 0);
            auto rightbf = builder.CreateExtractValue(right, 0);
            auto cmpval = builder.CreateCall(str_cmp, {leftbf, rightbf});
            result = builder.CreateICmpSLT(cmpval, llvm::ConstantInt::get(builder.getInt32Ty(), 0, true));
        }
        else if(left->getType() == right->getType()) {
            if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpOLT(left, right);
            }
            else {
                result = builder.CreateICmpSLT(left, right);
            }
        }
        else {
            llvm::report_fatal_error("LT does not supported given type ");
        }
    }
    break;
    case ir::OperatorKind::OP_LEQ:
    {
        LOGMAX("Creating LEQ instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_cmp = cgm.getLLVMMod()->getOrInsertFunction("strcmp",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    {
                                        builder.getInt8Ty()->getPointerTo(),
                                        builder.getInt8Ty()->getPointerTo()
                                    },
                                    false
                                 ));
            auto leftbf = builder.CreateExtractValue(left, 0);
            auto rightbf = builder.CreateExtractValue(right, 0);
            auto cmpval = builder.CreateCall(str_cmp, {leftbf, rightbf});
            result = builder.CreateICmpSLE(cmpval, llvm::ConstantInt::get(builder.getInt32Ty(), 0, true));
        }
        else if(left->getType() == right->getType()) {
            if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpOLE(left, right);
            }
            else {
                result = builder.CreateICmpSLE(left, right);
            }
        }
        else {
            llvm::report_fatal_error("LEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_EQ:
    {
        LOGMAX("Creating EQ instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_eq = cgm.getLLVMMod()->getOrInsertFunction("string_Eq",
                                 llvm::FunctionType::get(
                                    int1T,
                                    { stringT, stringT },
                                    false
                                 ));
            result = builder.CreateCall(str_eq, {left, right});
        }
        else if(left->getType() == right->getType()) {
            // Matrix
            if(e->getLeft()->getType()->isMatrix()) {
                std::string eqSubName = "equals_"+e->getLeft()->getType()->getName()+"_"+e->getLeft()->getType()->getName();
                auto eqArr_f = cgm.getLLVMMod()->getOrInsertFunction(eqSubName, 
                                                    llvm::FunctionType::get(int1T, {left->getType(), left->getType()}, false));
                result = builder.CreateCall(eqArr_f, {left, right});
            }
            else if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpOEQ(left, right);
            }
            else {
                result = builder.CreateICmpEQ(left, right);
            }
        }
        else if(e->getLeft()->getType()->getName() == NONETYPE_CSTR && e->getRight()->getType()->isMaybe()) {
            auto ldv = llvm::dyn_cast<llvm::LoadInst>(right)->getOperand(0);
            auto tnone = llvm::ConstantPointerNull::get(right->getType()->getPointerTo());
            result = builder.CreateICmpEQ(ldv, tnone);
        }
        else if(e->getRight()->getType()->getName() == NONETYPE_CSTR && e->getLeft()->getType()->isMaybe()) {
            auto ldv = llvm::dyn_cast<llvm::LoadInst>(left)->getOperand(0);
            auto tnone = llvm::ConstantPointerNull::get(left->getType()->getPointerTo());
            result = builder.CreateICmpEQ(ldv, tnone);
        }
        else {
            llvm::report_fatal_error("EQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_NEQ:
    {
        LOGMAX("Creating NEQ instruction");
        if(left->getType() == right->getType() && e->getLeft()->getType()->getName() == STRING_CSTR) {
            auto str_eq = cgm.getLLVMMod()->getOrInsertFunction("string_Eq",
                                 llvm::FunctionType::get(
                                    int1T,
                                    {
                                        builder.getInt8Ty()->getPointerTo(),
                                        builder.getInt8Ty()->getPointerTo()
                                    },
                                    false
                                 ));
            auto eqval = builder.CreateCall(str_eq, {left, right});
            result = builder.CreateNot(eqval);
        }
        else if(left->getType() == right->getType()) {
            // Matrix
            if(e->getLeft()->getType()->isMatrix()) {
                std::string eqSubName = "equals_"+e->getLeft()->getType()->getName()+"_"+e->getLeft()->getType()->getName();
                auto eqArr_f = cgm.getLLVMMod()->getOrInsertFunction(eqSubName, 
                                                    llvm::FunctionType::get(int1T, {left->getType(), left->getType()}, false));
                auto areEq = builder.CreateCall(eqArr_f, {left, right});
                result = builder.CreateNot(areEq);
            }
            else if(e->getLeft()->getType()->getName() == FLOAT_CSTR) {
                result = builder.CreateFCmpONE(left, right);
            }
            else {
                result = builder.CreateICmpNE(left, right);
            }
        }
        else if(e->getLeft()->getType()->getName() == NONETYPE_CSTR && e->getRight()->getType()->isMaybe()) {
            auto ldv = llvm::dyn_cast<llvm::LoadInst>(right)->getOperand(0);
            auto tnone = llvm::ConstantPointerNull::get(right->getType()->getPointerTo());
            result = builder.CreateICmpNE(ldv, tnone);
        }
        else if(e->getRight()->getType()->getName() == NONETYPE_CSTR && e->getLeft()->getType()->isMaybe()) {
            auto ldv = llvm::dyn_cast<llvm::LoadInst>(left)->getOperand(0);
            auto tnone = llvm::ConstantPointerNull::get(left->getType()->getPointerTo());
            result = builder.CreateICmpNE(ldv, tnone);
        }
        else {
            llvm::report_fatal_error("NEQ does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BAND:
    {
        LOGMAX("Creating BAND instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateAnd(left, right);
        }
        else {
            llvm::report_fatal_error("BAND does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BXOR:
    {
        LOGMAX("Creating BXOR instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateXor(left, right);
        }
        else {
            llvm::report_fatal_error("BXOR does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_BOR:
    {
        LOGMAX("Creating OR instruction");
        if(left->getType() == int64T && left->getType() == right->getType()) {
            result = builder.CreateOr(left, right);
        }
        else {
            llvm::report_fatal_error("BOR does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_IN:
    {
        LOGMAX("Creating IN instruction");
        if(left->getType() == stringT && left->getType() == right->getType()) {
            // String
            // Contains takes arguments the other way (x in y -> contains(y, x))
            auto contains_str_fun = cgm.getLLVMMod()->getOrInsertFunction("contains_string_string",
                                    llvm::FunctionType::get(int1T, {stringT, stringT}, false));
            return builder.CreateCall(contains_str_fun, {right, left});
        }
        else if(e->getRight()->getType()->isMatrix()) {
            llvm::report_fatal_error("IN is not yet implemented for arrays");
        }
        else {
            llvm::report_fatal_error("IN does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LAND:
    {
        LOGMAX("Creating AND instruction");
        if(left->getType() == int1T && left->getType() == right->getType()) {
            result = builder.CreateAnd(left, right);
        }
        else {
            llvm::report_fatal_error("AND does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_LOR:
    {
        LOGMAX("Creating OR instruction");
        if(left->getType() == int1T && left->getType() == right->getType()) {
            result = builder.CreateOr(left, right);
        }
        else {
            llvm::report_fatal_error("OR does not supported given type");
        }
    }
    break;
    case ir::OperatorKind::OP_CONCAT:
    {
        LOGMAX("Creating CONCAT instruction");
        llvm::Value *lval = left;
        llvm::Value *rval = right;
        auto to_str_int = cgm.getLLVMMod()->getOrInsertFunction("to_string_int",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int64T,
                                    false
                                 ));
        auto to_str_float = cgm.getLLVMMod()->getOrInsertFunction("to_string_float",
                                 llvm::FunctionType::get(
                                    stringT,
                                    floatT,
                                    false
                                 ));
        auto to_str_bool = cgm.getLLVMMod()->getOrInsertFunction("to_string_bool",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int1T,
                                    false
                                 ));
        auto to_str_mint = cgm.getLLVMMod()->getOrInsertFunction("mto_string_int",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int64T->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto to_str_mfloat = cgm.getLLVMMod()->getOrInsertFunction("mto_string_float",
                                 llvm::FunctionType::get(
                                    stringT,
                                    floatT->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto to_str_mbool = cgm.getLLVMMod()->getOrInsertFunction("mto_string_bool",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int1T->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        // Cannot be just loaded in case of none
        auto to_str_mstring = cgm.getLLVMMod()->getOrInsertFunction("mto_string_string",
                                 llvm::FunctionType::get(
                                    stringT,
                                    stringT->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto str_concat = cgm.getLLVMMod()->getOrInsertFunction("string_Add_Str",
                                 llvm::FunctionType::get(
                                    voidT,
                                    {
                                        stringT->getPointerTo(),
                                        stringT,
                                        stringT
                                    },
                                    false
                                 ));
        if(!e->getLeft()->getType()->isMaybe()) {
            if(left->getType() == int64T) {
                lval = builder.CreateCall(to_str_int, { left });
            }
            else if(left->getType() == floatT) {
                lval = builder.CreateCall(to_str_float, { left });
            }
            else if(left->getType() == int1T) {
                lval = builder.CreateCall(to_str_bool, { left });
            }
            else if(e->getLeft()->getType()->getName() == NONETYPE_CSTR) {
                std::string noneS = "none";
                lval = emitExpr(new ir::StringLiteral(ir::SourceInfo(), noneS, e->getType()));
            }
        }
        else {
            auto mleft = llvm::dyn_cast<llvm::LoadInst>(left)->getOperand(0);
            mleft = llvm::dyn_cast<llvm::LoadInst>(mleft)->getOperand(0);
            if(left->getType() == int64T) {
                lval = builder.CreateCall(to_str_mint, { mleft });
            }
            else if(left->getType() == floatT) {
                lval = builder.CreateCall(to_str_mfloat, { mleft });
            }
            else if(left->getType() == int1T) {
                lval = builder.CreateCall(to_str_mbool, { mleft });
            }
            else if(left->getType() == stringT) {
                lval = builder.CreateCall(to_str_mstring, { mleft });
            }
            else {
                llvm::report_fatal_error("Unknown type in concat");
            }
        }

        if(!e->getRight()->getType()->isMaybe()) {
            if(right->getType() == int64T) {
                rval = builder.CreateCall(to_str_int, { right });
            }
            else if(right->getType() == floatT) {
                rval = builder.CreateCall(to_str_float, { right });
            }
            else if(right->getType() == int1T) {
                rval = builder.CreateCall(to_str_bool, { right });
            }
            else if(e->getRight()->getType()->getName() == NONETYPE_CSTR) {
                std::string noneS = "none";
                rval = emitExpr(new ir::StringLiteral(ir::SourceInfo(), noneS, e->getType()));
            }
        }
        else {
            auto mright = llvm::dyn_cast<llvm::LoadInst>(right)->getOperand(0);
            mright = llvm::dyn_cast<llvm::LoadInst>(mright)->getOperand(0);
            if(right->getType() == int64T) {
                rval = builder.CreateCall(to_str_mint, { mright });
            }
            else if(right->getType() == floatT) {
                rval = builder.CreateCall(to_str_mfloat, { mright });
            }
            else if(right->getType() == int1T) {
                rval = builder.CreateCall(to_str_mbool, { mright });
            }
            else if(right->getType() == stringT) {
                rval = builder.CreateCall(to_str_mstring, { mright });
            }
            else {
                llvm::report_fatal_error("Unknown type in concat");
            }
        }

        auto res = builder.CreateAlloca(stringT);
        builder.CreateCall(str_concat, {res, lval, rval});
        result = builder.CreateLoad(stringT, res);
    }
    break;
    case ir::OperatorKind::OP_ACCESS:
        // FIXME: this creates unnecessary extract for assignment where
        // access is no the left side a.c = 4. 
        // Although it can will be removed as an unused var
        if(auto rMemAcc = llvm::dyn_cast<ir::MemberAccess>(e->getRight())) {
            result = builder.CreateExtractValue(left, rMemAcc->getIndex());
        }
        else {
            llvm::report_fatal_error("Member access is of a different type");
        }
    break;
    case ir::OperatorKind::OP_SUBSCR:
    {
        if(e->getLeft()->getType()->isMatrix()) {
            // matrix
            auto elT = mapType(e->getLeft()->getType()->getDecl());
            llvm::Value* buffer = builder.CreateExtractValue(left, 0);
            auto casted = builder.CreateBitCast(buffer, elT->getPointerTo());
            auto valptr = builder.CreateGEP(elT, casted, right);
            result = builder.CreateLoad(elT, valptr);
        }
        else {
            // string
            std::string emstr = "";
            auto resStrIR = new ir::StringLiteral(ir::SourceInfo(), emstr, e->getLeft()->getType());
            auto resStr = emitExpr(resStrIR);
            delete resStrIR;
            auto resStrPtr = llvm::dyn_cast<llvm::LoadInst>(resStr)->getOperand(0);
            auto str_add = cgm.getLLVMMod()->getOrInsertFunction("string_Add_Char",
                                 llvm::FunctionType::get(
                                    voidT,
                                    {
                                        stringT->getPointerTo(),
                                        builder.getInt8Ty()
                                    },
                                    false
                                 ));
            llvm::Value* buffer = builder.CreateExtractValue(left, 0);
            auto valptr = builder.CreateGEP(builder.getInt8Ty(), buffer, right);
            auto charextr = builder.CreateLoad(builder.getInt8Ty(), valptr);

            builder.CreateCall(str_add, {resStrPtr, charextr});
            return builder.CreateLoad(stringT, resStrPtr);
        }
    }
    break;
    case ir::OperatorKind::OP_AS:
    {
        ir::TypeDecl *ogType = e->getLeft()->getType();
        ir::TypeDecl *asType = e->getRight()->getType();

        if(asType->isMaybe() && e->getLeft()->getType()->getName() != ANY_CSTR) {
            llvm::report_fatal_error("Values cannot be casted to maybe type. Use assignment.");
        }

        if(ogType->getName() == asType->getName() && ogType->isMaybe() == asType->isMaybe()) {
            // as itself
            return left;
        }

        //llvm::Type *asllvmType = mapType(asType);

        auto to_str_int = cgm.getLLVMMod()->getOrInsertFunction("to_string_int",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int64T,
                                    false
                                 ));
        auto to_str_float = cgm.getLLVMMod()->getOrInsertFunction("to_string_float",
                                 llvm::FunctionType::get(
                                    stringT,
                                    floatT,
                                    false
                                 ));
        auto to_str_bool = cgm.getLLVMMod()->getOrInsertFunction("to_string_bool",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int1T,
                                    false
                                 ));
        auto to_str_mint = cgm.getLLVMMod()->getOrInsertFunction("mto_string_int",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int64T->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto to_str_mfloat = cgm.getLLVMMod()->getOrInsertFunction("mto_string_float",
                                 llvm::FunctionType::get(
                                    stringT,
                                    floatT->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto to_str_mbool = cgm.getLLVMMod()->getOrInsertFunction("mto_string_bool",
                                 llvm::FunctionType::get(
                                    stringT,
                                    int1T->getPointerTo()->getPointerTo(),
                                    false
                                 ));
        auto to_str_mstring = cgm.getLLVMMod()->getOrInsertFunction("mto_string_string",
                                 llvm::FunctionType::get(
                                    stringT,
                                    stringT->getPointerTo()->getPointerTo(),
                                    false
                                 ));

        if(!ogType->isMaybe()) {
            if(ogType->getName() == INT_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_int, { left });
                }
                if(asType->getName() == FLOAT_CSTR) {
                    return builder.CreateSIToFP(left, floatT);
                }
                if(asType->getName() == BOOL_CSTR) {
                    return builder.CreateICmpNE(left, llvm::ConstantInt::get(int64T, 0));
                }
            }
            else if(ogType->getName() == FLOAT_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_float, { left });
                }
                if(asType->getName() == INT_CSTR) {
                    return builder.CreateFPToSI(left, int64T);
                }
                if(asType->getName() == BOOL_CSTR) {
                    return builder.CreateFCmpUNE(left, llvm::ConstantFP::get(floatT, 0.0));
                }
            }
            else if(ogType->getName() == BOOL_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_bool, { left });
                }
                if(asType->getName() == INT_CSTR) {
                    return builder.CreateZExt(left, int64T);
                }
                if(asType->getName() == FLOAT_CSTR) {
                    return builder.CreateUIToFP(left, floatT);
                }
            }
        }
        else {
            auto pleft = llvm::dyn_cast<llvm::LoadInst>(left)->getOperand(0);
            auto mleft = llvm::dyn_cast<llvm::LoadInst>(pleft)->getOperand(0);

            // Maybe type
            if(ogType->getName() == INT_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_mint, { mleft });
                }
                if(asType->getName() == FLOAT_CSTR) {
                    return builder.CreateSIToFP(left, floatT);
                }
                if(asType->getName() == BOOL_CSTR) {
                    return builder.CreateICmpNE(left, llvm::ConstantInt::get(int64T, 0));
                }
            }
            else if(ogType->getName() == FLOAT_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_mfloat, { mleft });
                }
                if(asType->getName() == INT_CSTR) {
                    return builder.CreateFPToSI(left, int64T);
                }
                if(asType->getName() == BOOL_CSTR) {
                    return builder.CreateFCmpUNE(left, llvm::ConstantFP::get(floatT, 0.0));
                }
            }
            else if(ogType->getName() == BOOL_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_mbool, { mleft });
                }
                if(asType->getName() == INT_CSTR) {
                    return builder.CreateZExt(left, int64T);
                }
                if(asType->getName() == FLOAT_CSTR) {
                    return builder.CreateUIToFP(left, floatT);
                }
            }
            else if(ogType->getName() == STRING_CSTR) {
                if(asType->getName() == STRING_CSTR) {
                    return builder.CreateCall(to_str_mstring, { mleft });
                }
            }
            else if(ogType->getName() == ANY_CSTR) {
                if(asType->isMaybe()) {
                    auto casted = builder.CreateBitCast(pleft, mapType(asType));
                    return casted;
                }
                else {
                    auto casted = builder.CreateBitCast(pleft, mapType(asType)->getPointerTo());
                    return builder.CreateLoad(mapType(asType), casted);
                }
            }
        }

        llvm::report_fatal_error("Incorrect or unimplemented cast");
    }
    break;
    default: llvm::report_fatal_error("Uknown operator in code generation");
    }
    return result;
}

void cg::CGFunction::emitStmt(ir::ExprStmt *stmt) {
    ir::Expr *e = stmt->getExpr();
    emitExpr(e);
}

void cg::CGFunction::emitStmt(ir::IfStatement *stmt) {
    bool hasElse = stmt->getElseBranch().size() > 0;

    llvm::BasicBlock *ifBB = llvm::BasicBlock::Create(ctx, "if.body", llvmFun);
    llvm::BasicBlock *elseBB = hasElse ? llvm::BasicBlock::Create(ctx, "if.else", llvmFun) : nullptr;
    llvm::BasicBlock *afterBB = llvm::BasicBlock::Create(ctx, "if.after", llvmFun);

    llvm::Value *cnd = emitExpr(stmt->getCond());
    builder.CreateCondBr(cnd, ifBB, hasElse ? elseBB : afterBB);

    setCurrBB(ifBB);
    emit(stmt->getIfBranch());
    if(!currBB->getTerminator()) {
        builder.CreateBr(afterBB);
    }

    if(hasElse) {
        setCurrBB(elseBB);
        emit(stmt->getElseBranch());
        if(!currBB->getTerminator()) {
            builder.CreateBr(afterBB);
        }
    }

    setCurrBB(afterBB);
}

void cg::CGFunction::emitStmt(ir::WhileStmt *stmt) {
    llvm::BasicBlock *whileCondBB = llvm::BasicBlock::Create(ctx, "while.cond", llvmFun);
    llvm::BasicBlock *whileBodyBB = llvm::BasicBlock::Create(ctx, "while.body", llvmFun);
    llvm::BasicBlock *whileAfterBB = llvm::BasicBlock::Create(ctx, "while.after", llvmFun);

    stmt->setAfterBB(whileAfterBB);
    stmt->setCondBB(whileCondBB);

    if(stmt->isDoWhile()) {
        builder.CreateBr(whileBodyBB);
    }
    else {
        builder.CreateBr(whileCondBB);
    }
    setCurrBB(whileCondBB);
    llvm::Value *cond = emitExpr(stmt->getCond());
    builder.CreateCondBr(cond, whileBodyBB, whileAfterBB);

    setCurrBB(whileBodyBB);
    auto stacksave = cgm.getLLVMMod()->getOrInsertFunction("llvm.stacksave", 
                                                    llvm::FunctionType::get(
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false
                                                    ));
    auto stackrestore = cgm.getLLVMMod()->getOrInsertFunction("llvm.stackrestore", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false
                                                    ));
    auto stp = builder.CreateCall(stacksave);
    emit(stmt->getBody());
    builder.CreateCall(stackrestore, { stp });
    builder.CreateBr(whileCondBB);

    setCurrBB(whileAfterBB);
}

void cg::CGFunction::emitStmt(ir::ForeachStmt *stmt) {
    auto range = llvm::dyn_cast<ir::Range>(stmt->getCollection());

    auto indexPtr = builder.CreateAlloca(int64T);

    auto stepPtr = builder.CreateAlloca(int64T);

    if(range) {
        auto strVal = emitExpr(range->getStart());
        builder.CreateStore(strVal, indexPtr);

        // generate step detection (can be 1 or -1)
        if(!range->getStep()) {
            llvm::BasicBlock *stepPos = llvm::BasicBlock::Create(ctx, "range.step.pos", llvmFun);
            llvm::BasicBlock *stepNeg = llvm::BasicBlock::Create(ctx, "range.step.neg", llvmFun);
            llvm::BasicBlock *stepEnd = llvm::BasicBlock::Create(ctx, "range.step.end", llvmFun);

            auto endVal = emitExpr(range->getEnd());

            auto eGEs = builder.CreateICmpSGE(endVal, strVal);
            builder.CreateCondBr(eGEs, stepPos, stepNeg);

            setCurrBB(stepPos);
            builder.CreateStore(llvm::ConstantInt::get(int64T, 1, true), stepPtr);
            builder.CreateBr(stepEnd);

            setCurrBB(stepNeg);
            builder.CreateStore(llvm::ConstantInt::get(int64T, -1, true), stepPtr);
            builder.CreateBr(stepEnd);

            setCurrBB(stepEnd);
        } else {
            auto stpE = emitExpr(range->getStep());
            builder.CreateStore(stpE, stepPtr);
        }
    } else {
        builder.CreateStore(llvm::ConstantInt::get(int64T, 0, true), indexPtr);
        builder.CreateStore(llvm::ConstantInt::get(int64T, 1, true), stepPtr);
    }
    if(stmt->getDefineI()) {
        auto vracc = llvm::dyn_cast<ir::VarAccess>(stmt->getI());
        auto vrdcl = llvm::dyn_cast<ir::VarDecl>(vracc->getVar());
        emitStmt(vrdcl);
    }

    llvm::BasicBlock *forCondBB = llvm::BasicBlock::Create(ctx, "for.cond", llvmFun);
    llvm::BasicBlock *forCondPosStepBB = llvm::BasicBlock::Create(ctx, "range.posstep", llvmFun);
    llvm::BasicBlock *forCondNegStepBB = llvm::BasicBlock::Create(ctx, "range.negstep", llvmFun);
    llvm::BasicBlock *forBodyBB = llvm::BasicBlock::Create(ctx, "for.body", llvmFun);
    llvm::BasicBlock *forNextIterBB = llvm::BasicBlock::Create(ctx, "for.next", llvmFun);
    llvm::BasicBlock *forAfterBB = llvm::BasicBlock::Create(ctx, "for.after", llvmFun);

    stmt->setAfterBB(forAfterBB);
    stmt->setCondBB(forCondBB);
    stmt->setNextIterBB(forNextIterBB);

    builder.CreateBr(forCondBB);

    setCurrBB(forCondBB);

    auto stacksave = cgm.getLLVMMod()->getOrInsertFunction("llvm.stacksave", 
                                                        llvm::FunctionType::get(
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false
                                                        ));
    auto stackrestore = cgm.getLLVMMod()->getOrInsertFunction("llvm.stackrestore", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false
                                                    ));

    auto index = builder.CreateLoad(int64T, indexPtr);
    llvm::Value *stp = nullptr;

    if(range) {
        auto endVal = emitExpr(range->getEnd());

        auto stepLd = builder.CreateLoad(int64T, stepPtr);
        auto posStep = builder.CreateICmpSGT(stepLd, llvm::ConstantInt::get(int64T, 0, true));
        builder.CreateCondBr(posStep, forCondPosStepBB, forCondNegStepBB);

        setCurrBB(forCondPosStepBB);
        auto cmpEndPos = builder.CreateICmpSLT(index, endVal);
        builder.CreateCondBr(cmpEndPos, forBodyBB, forAfterBB);

        setCurrBB(forCondNegStepBB);
        auto cmpEndNeg = builder.CreateICmpSGT(index, endVal);
        builder.CreateCondBr(cmpEndNeg, forBodyBB, forAfterBB);

        setCurrBB(forBodyBB);
        
        stp = builder.CreateCall(stacksave);

        auto iLd = emitExpr(stmt->getI());
        auto iPtr = llvm::dyn_cast<llvm::LoadInst>(iLd)->getOperand(0);
        builder.CreateStore(index, iPtr);
    }
    else {
        llvm::Value *coll = emitExpr(stmt->getCollection());
        auto lengthF = cgm.getLLVMMod()->getOrInsertFunction("length_"+stmt->getCollection()->getType()->getName(), 
                                                        llvm::FunctionType::get(
                                                            int64T,
                                                            mapType(stmt->getCollection()->getType()),
                                                            false
                                                        ));
        auto lengthVal = builder.CreateCall(lengthF, coll);
        auto cmplen = builder.CreateICmpSLT(index, lengthVal);
        builder.CreateCondBr(cmplen, forBodyBB, forAfterBB);

        setCurrBB(forBodyBB);

        stp = builder.CreateCall(stacksave);

        if(stmt->getCollection()->getType()->isMatrix()) {
            // matrix
            auto elT = mapType(stmt->getCollection()->getType()->getDecl());
            llvm::Value* buffer = builder.CreateExtractValue(coll, 0);
            auto casted = builder.CreateBitCast(buffer, elT->getPointerTo());
            auto valptr = builder.CreateGEP(elT, casted, index);
            auto result = builder.CreateLoad(elT, valptr);
            auto iLd = emitExpr(stmt->getI());
            auto iPtr = llvm::dyn_cast<llvm::LoadInst>(iLd)->getOperand(0);
            builder.CreateStore(result, iPtr);
        }
        else {
            // string
            std::string emstr = "";
            auto resStrIR = new ir::StringLiteral(ir::SourceInfo(), emstr, stmt->getCollection()->getType());
            auto resStr = emitExpr(resStrIR);
            delete resStrIR;
            auto resStrPtr = llvm::dyn_cast<llvm::LoadInst>(resStr)->getOperand(0);
            auto str_add = cgm.getLLVMMod()->getOrInsertFunction("string_Add_Char",
                                    llvm::FunctionType::get(
                                    voidT,
                                    {
                                        stringT->getPointerTo(),
                                        builder.getInt8Ty()
                                    },
                                    false
                                    ));
            llvm::Value* buffer = builder.CreateExtractValue(coll, 0);
            auto valptr = builder.CreateGEP(builder.getInt8Ty(), buffer, index);
            auto charextr = builder.CreateLoad(builder.getInt8Ty(), valptr);

            builder.CreateCall(str_add, {resStrPtr, charextr});
            auto result = builder.CreateLoad(stringT, resStrPtr);
            auto iLd = emitExpr(stmt->getI());
            auto iPtr = llvm::dyn_cast<llvm::LoadInst>(iLd)->getOperand(0);
            builder.CreateStore(result, iPtr);
        }
    }

    emit(stmt->getBody());
    builder.CreateBr(forNextIterBB);

    setCurrBB(forNextIterBB);
    
    llvm::Value *step = builder.CreateLoad(int64T, stepPtr);
    llvm::Value *newIndex = builder.CreateAdd(index, step);
    builder.CreateStore(newIndex, indexPtr);
    builder.CreateCall(stackrestore, { stp });
    builder.CreateBr(forCondBB);
    setCurrBB(forAfterBB);

}

void cg::CGFunction::emitStmt(ir::ReturnStmt *stmt) {
    if(fun->getName() == _ENTRY_NAME) {
        llvm::report_fatal_error("return can appear only inside of a function");
    }
    if(stmt->getValue()) {
        LOGMAX("Creating return with value");
        if(stmt->getValue()->getType()->isMaybe()) {
            llvm::Value *retVal = readVar(currBB, llvm::dyn_cast<ir::VarAccess>(stmt->getValue())->getVar(), true);
            builder.CreateRet(retVal);
        }
        else {
            llvm::Value *retVal = emitExpr(stmt->getValue());
            builder.CreateRet(retVal);
        }
    }
    else {
        LOGMAX("Creating return void");
        builder.CreateRetVoid();
    }
}

void cg::CGFunction::emitStmt(ir::BreakStmt *stmt) {
    LOGMAX("Creating break");
    ir::IR *cycle = stmt->getEnclosingIR();
    while(cycle && !llvm::isa<ir::WhileStmt>(cycle) && !llvm::isa<ir::ForeachStmt>(cycle)) {
        cycle = cycle->getEnclosingIR();
    }
    if(!cycle) {
        llvm::report_fatal_error("break can appear only inside of a while or a for loop");
    }
    if(auto loop = llvm::dyn_cast<ir::WhileStmt>(cycle)) {
        builder.CreateBr(loop->getAfterBB());
    }
    else if(auto loop = llvm::dyn_cast<ir::ForeachStmt>(cycle)) {
        builder.CreateBr(loop->getAfterBB());
    }
}

void cg::CGFunction::emitStmt(ir::ContinueStmt *stmt) {
    LOGMAX("Creating continue");
    ir::IR *cycle = stmt->getEnclosingIR();
    while(cycle && !llvm::isa<ir::WhileStmt>(cycle) && !llvm::isa<ir::ForeachStmt>(cycle)) {
        cycle = cycle->getEnclosingIR();
    }
    if(!cycle) {
        llvm::report_fatal_error("continue can appear only inside of a while or a for loop");
    }
    if(auto loop = llvm::dyn_cast<ir::WhileStmt>(cycle)) {
        builder.CreateBr(loop->getCondBB());
    }
    else if(auto loop = llvm::dyn_cast<ir::ForeachStmt>(cycle)) {
        builder.CreateBr(loop->getNextIterBB());
    }
}

void cg::CGFunction::emitStmt(ir::Import *stmt) {
    //llvm::report_fatal_error("Imports are not yet implemented");
}

void cg::CGFunction::emitStmt(ir::VarDecl *stmt) {
    LOGMAX("Local variable declaration");
    auto value = stmt->getInitValue();
    llvm::Value *v = nullptr;
    if(value) {
        v = emitExpr(value);
    }
    else if(stmt->getType()->isMaybe()){
        v = llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(mapType(stmt->getType())));
    }
    else {
        auto ty = stmt->getType()->getName();
        if(isPrimitiveType(stmt->getType())) {
            v = cgm.getTypeDefaultValue(stmt->getType());
        }
        else if(ty == STRING_CSTR) {
            std::string s = "";
            ir::StringLiteral *empt = new ir::StringLiteral(stmt->getLocation(), s, stmt->getType());
            v = emitExpr(empt);
        }
        else if(stmt->getType()->isMatrix()) {
            llvm::report_fatal_error("Local matrix intializer not yet implemented");
        }
        else {
            auto t = llvm::dyn_cast<ir::TypeDecl>(stmt->getType());
            auto strTd = llvm::dyn_cast<ir::StructDecl>(t->getDecl());
            if(!strTd) {
                llvm::report_fatal_error("Unknown type in local variable initializer");
            }
            auto inits = std::map<std::string, ir::Expr *>{};
            ir::StructLiteral *empt = new ir::StructLiteral(stmt->getLocation(), t, inits);
            v = emitExpr(empt);
        }
    }
    writeVar(currBB, stmt, v);
}

void cg::CGFunction::emit(std::vector<ir::IR *> stmts) {
    for(auto *s : stmts) {
        if(auto *stmt = llvm::dyn_cast<ir::ExprStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::ReturnStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::IfStatement>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::WhileStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::ForeachStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::Import>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::BreakStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::ContinueStmt>(s)) {
            emitStmt(stmt);
        }
        else if(auto *stmt = llvm::dyn_cast<ir::VarDecl>(s)) {
            emitStmt(stmt);
        }
        else {
            llvm::report_fatal_error("Unknown statement in code generation");
        }
    }
}

llvm::Constant *cg::CGModule::getTypeDefaultValue(ir::TypeDecl *t) {
    auto ty = t->getName();
    if(ty == INT_CSTR) {
        return llvm::ConstantInt::get(int64T, 0, true);
    }
    else if(ty == BOOL_CSTR) {
        return llvm::ConstantInt::getFalse(int1T);
    }
    else if(ty == FLOAT_CSTR) {
        return llvm::ConstantFP::get(floatT, 0.0);
    }
    else if(ty == STRING_CSTR) {
        return llvm::ConstantAggregateZero::get(stringT);
    }
    else if(t->isMatrix()) {
        return llvm::ConstantAggregateZero::get(matrixT);
    }
    else {
        llvm::report_fatal_error("Unknown type for default initializer");
    }
    return nullptr;
}

llvm::SmallVector<llvm::Constant *> cg::CGModule::getStructValsInit(ir::StructDecl *decl, std::map<std::string, ir::Expr *> inits) {
    llvm::SmallVector<llvm::Constant *> vals;
    for(auto e : decl->getElements()) {
        auto evar = llvm::dyn_cast<ir::VarDecl>(e);
        if(evar->getType()->isMaybe()) {
            llvm::report_fatal_error("Struct maybe types are not yet implemented");
        }
        auto ival = evar->getInitValue();
        for(auto [k, v] : inits) {
            if(k == evar->getName()) {
                ival = v;
                break;
            }
        }
        if(ival) {
            if(auto vcast = llvm::dyn_cast<ir::IntLiteral>(ival)) {
                vals.push_back(llvm::ConstantInt::get(ctx, vcast->getValue()));
            }
            else if(auto vcast = llvm::dyn_cast<ir::BoolLiteral>(ival)) {
                vals.push_back(llvm::ConstantInt::getBool(int1T, vcast->getValue()));
            }
            else if(auto vcast = llvm::dyn_cast<ir::FloatLiteral>(ival)) {
                vals.push_back(llvm::ConstantFP::get(ctx, vcast->getValue()));
            }
            else if(llvm::dyn_cast<ir::StringLiteral>(ival)) {
                // Initialization is handeled when new instance is created
                auto init = llvm::ConstantAggregateZero::get(stringT);
                vals.push_back(init);
            }
            else {
                // TODO: Handle structs
                llvm::report_fatal_error("Struct element initializer is not a constant");
            }
        }
        else {
            auto ty = evar->getType()->getName();
            if(isPrimitiveType(evar->getType())) {
                vals.push_back(getTypeDefaultValue(evar->getType()));
            }
            else if(ty == STRING_CSTR) {
                // Initialization is handeled when new instance is created
                auto init = llvm::ConstantAggregateZero::get(stringT);
                vals.push_back(init);
            }
            else {
                llvm::report_fatal_error("Struct nested intializer is not yet implemented");
            }
        }
    }
    return vals;
}

void cg::CGModule::defineStruct(ir::StructDecl *decl) {
    std::vector<llvm::Type*> structElements;
    for(auto elem: decl->getElements()) {
        structElements.push_back(mapType(elem));
    }
    std::string name;
    if(!decl->isLibType()) {
        name = mangleName(decl);
    }
    else {
        name = decl->getName();
    }
    auto tp = llvm::StructType::create(getLLVMCtx(), structElements, name);

    llvm::Constant *init;

    if(decl->is_zero_init()) {
        init = llvm::ConstantAggregateZero::get(tp);
    }
    else {
        init = llvm::ConstantStruct::get(tp, getStructValsInit(decl, std::map<std::string, ir::Expr*>{}));
    }

    userTypes[name] = std::make_pair(tp, init);
}

void cg::CGModule::run(ir::ModuleDecl *mod) {
    this->mod = mod;

    ptlibLoader->setupExternLib();
    ptlibLoader->setupLib();
    //ptlibLoader->setupSourceLib(ptlibMod);

    // Forward declare ptlib functions
    if(mod != ptlibMod) {
        for(auto d: ptlibMod->getDecls()) {
            if(auto f = llvm::dyn_cast<ir::FunctionDecl>(d)) {
                llvmMod->getOrInsertFunction(f->getName(), createFunctionType(f));
            }
            else if(auto v = llvm::dyn_cast<ir::VarDecl>(d)) {
                auto vPtr = new llvm::GlobalVariable(*llvmMod,
                                                mapType(v),
                                                false,
                                                llvm::GlobalValue::ExternalLinkage,
                                                nullptr,
                                                v->getName());
                globals[v] = vPtr;
            }
            else if(auto v = llvm::dyn_cast<ir::StructDecl>(d)) {
                defineStruct(v);
            }
        }
    }

    ir::FunctionDecl *entryFun = nullptr;
    std::vector<CGFunction *> funs;

    str_empty = new llvm::GlobalVariable(*llvmMod,
                                        builder.getInt8Ty()->getPointerTo(),
                                        false,
                                        llvm::GlobalValue::PrivateLinkage,
                                        nullptr);
    str_empty->setInitializer(builder.CreateGlobalStringPtr("", "", 0, llvmMod));

    for(auto *decl: mod->getDecls()) {
        auto kind = decl->getKind();
        switch(kind) {
        case ir::IRKind::IR_VAR_DECL:
        {   // new variable needs its own scope
            auto var = llvm::dyn_cast<ir::VarDecl>(decl);
            auto value = var->getInitValue();
            llvm::Type *vType = mapType(var);
            llvm::GlobalVariable *vPtr = nullptr;
            llvm::GlobalVariable *v = nullptr;
            std::string vName = mangleName(var);
            if(var->getType()->isMaybe() && value && !llvm::isa<ir::NoneLiteral>(value)) {
                vPtr = new llvm::GlobalVariable(*llvmMod,
                                                vType,
                                                false,
                                                llvm::GlobalValue::ExternalLinkage,
                                                nullptr,
                                                vName);
                vName = "";
                // Get base type because global variable is already a pointer (address)
                vPtr->setInitializer(llvm::ConstantPointerNull::get(llvm::dyn_cast<llvm::PointerType>(vType)));
                if(var->getType()->getName() == ANY_CSTR) {
                    vType = mapType(value->getType());
                }
                else {
                    vType = vType->getPointerElementType();
                }
            }
            v = new llvm::GlobalVariable(*llvmMod,
                                        vType,
                                        false,
                                        llvm::GlobalValue::ExternalLinkage,
                                        nullptr,
                                        vName);
            if(var->getType()->isMaybe() && value && !llvm::isa<ir::NoneLiteral>(value)) {
                // TODO(optim): Creating v could be avoided and just the constant could be
                // assigned bellow when initalizing maybes
                maybesToInit.push_back(std::make_pair(vPtr, v));
            }

            if(value && !llvm::isa<ir::NoneLiteral>(value)) {
                // If variable is maybe this will initialize the variable it will point to
                if(auto vcast = llvm::dyn_cast<ir::IntLiteral>(value)) {
                    v->setInitializer(llvm::ConstantInt::get(ctx, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::BoolLiteral>(value)) {
                    v->setInitializer(llvm::ConstantInt::getBool(int1T, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::FloatLiteral>(value)) {
                    v->setInitializer(llvm::ConstantFP::get(ctx, vcast->getValue()));
                }
                else if(auto vcast = llvm::dyn_cast<ir::StringLiteral>(value)) {
                    llvm::GlobalVariable *str_txt = new llvm::GlobalVariable(*llvmMod,
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr);
                    str_txt->setInitializer(builder.CreateGlobalStringPtr(vcast->getValue().c_str(), "", 0, llvmMod));
                    stringsToInit.push_back(std::make_pair(v, str_txt));
                    auto init = llvm::ConstantAggregateZero::get(stringT);
                    v->setInitializer(init);
                }
                else if(var->getType()->isMatrix()) {
                    auto init = llvm::ConstantAggregateZero::get(matrixT);
                    v->setInitializer(init);
                    matricesToInit.push_back(std::make_pair(v, llvm::dyn_cast<ir::MatrixLiteral>(value)));
                }
                else {
                    llvm::report_fatal_error("Global variable initializer is not a constant");
                }
            }
            else if(!value || !llvm::isa<ir::NoneLiteral>(value)){
                if(var->getType()->isMaybe()) {
                    auto ptt = llvm::dyn_cast<llvm::PointerType>(mapType(var->getType()));
                    v->setInitializer(llvm::ConstantPointerNull::get(ptt));
                }
                else {
                    auto ty = var->getType()->getName();
                    if(isPrimitiveType(var->getType())) {
                        v->setInitializer(getTypeDefaultValue(var->getType()));
                    }
                    else if(ty == STRING_CSTR) {
                        v->setInitializer(getTypeDefaultValue(var->getType()));
                        stringsToInit.push_back(std::make_pair(v, str_empty));
                    }
                    else if(var->getType()->isMatrix()) {
                        v->setInitializer(getTypeDefaultValue(var->getType()));
                        matricesToInit.push_back(std::make_pair(v, nullptr));
                    }
                    else {
                        // struct
                        // TODO: Handle nested structs
                        // Initialize all strings
                        if(auto struDecl = llvm::dyn_cast<ir::StructDecl>(var->getType()->getDecl())) {
                            std::string struName = struDecl->isLibType() ? struDecl->getName() : mangleName(struDecl);
                            v->setInitializer(userTypes[struName].second);
                            int index = 0;
                            for(auto e: struDecl->getElements()) {
                                if(auto eVar = llvm::dyn_cast<ir::VarDecl>(e)) {
                                    if(eVar->getType()->getName() == STRING_CSTR) {
                                        if(auto val = eVar->getInitValue()) {
                                            llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), 0);
                                            llvm::Value* stIndex = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), index);
                                            llvm::Value *elemPtr = builder.CreateGEP(mapType(var->getType()), v, {zero, stIndex});

                                            auto vcast = llvm::dyn_cast<ir::StringLiteral>(val);
                                            llvm::GlobalVariable *str_txt = new llvm::GlobalVariable(*llvmMod,
                                                                                                    builder.getInt8Ty()->getPointerTo(),
                                                                                                    false,
                                                                                                    llvm::GlobalValue::PrivateLinkage,
                                                                                                    nullptr);
                                            str_txt->setInitializer(builder.CreateGlobalStringPtr(vcast->getValue().c_str(), "", 0, llvmMod));

                                            stringsToInit.push_back(std::make_pair(elemPtr, str_txt));
                                        }
                                        else {
                                            // Default
                                            llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), 0);
                                            llvm::Value* stIndex = llvm::ConstantInt::get(llvm::Type::getInt32Ty(getLLVMCtx()), index);
                                            llvm::Value *elemPtr = builder.CreateGEP(mapType(var->getType()), v, {zero, stIndex});
                                            stringsToInit.push_back(std::make_pair(elemPtr, str_empty));
                                        }
                                    }
                                }
                                // TODO: make this function and recursively go deeper if e is StructDecl
                                ++index;
                            }
                        }
                        else {
                            llvm::report_fatal_error("Global variable is of unknown type");
                        }
                    }
                }
            }
            if(var->getType()->isMaybe() && value && !llvm::isa<ir::NoneLiteral>(value)) {
                globals[var] = vPtr;
            }
            else {
                if(var->getType()->isMaybe()) {
                    // Maybe (pointer) has to be always set to null for the check
                    auto ptt = llvm::dyn_cast<llvm::PointerType>(mapType(var->getType()));
                    v->setInitializer(llvm::ConstantPointerNull::get(ptt));
                }
                globals[var] = v;
            }
        }
        break;
        case ir::IRKind::IR_FUNCTION_DECL:
        {
            auto *fun = llvm::dyn_cast<ir::FunctionDecl>(decl);
            // This also creates forward declaration
            CGFunction *cgf = new CGFunction(*this, fun, ptlibMod);
            if(fun->getName() == _ENTRY_NAME) {
                entryFun = fun;
            }
            funs.push_back(cgf);
        }
        break;
        case ir::IRKind::IR_STRUCT_DECL:
            defineStruct(llvm::dyn_cast<ir::StructDecl>(decl));
        break;
        case ir::IRKind::IR_IMPORT:
        {
            auto impDecl = llvm::dyn_cast<ir::Import>(decl);
            modulesToInit.insert(impDecl);
        }
        break;
        default: llvm::report_fatal_error("Code generation invoked for not yet implemented IR");
        break;
        }
    }

    // Generate templated libFunctions
    for(auto f: mod->getLibFunctions()) {
        LOGMAX("Generating templated function: "+f->getName());
        if(f->getOGName() == "append") {
            ptlibLoader->appendInit(f->getName(), mapType(f->getParams()[0]), mapType(f->getParams()[1]));
        }
        else if(f->getOGName() == "length") {
            ptlibLoader->length_matrixInit(f->getName(), mapType(f->getParams()[0]));
        }
        else if(f->getOGName() == "equals") {
            ptlibLoader->equals_matrixInit(f->getName(), mapType(f->getParams()[0]), f->getParams()[0]->getType());
        }
        else {
            llvm::report_fatal_error(("Missing code for function "+f->getOGName()).c_str()); 
        }
    }

    // Create function bodies
    for(auto f: funs) {
        f->run();
    }
    
    // Insert init
    llvm::Function *init = llvm::Function::Create(llvm::FunctionType::get(
                                                builder.getVoidTy(),
                                                false
                                               ), 
                                               llvm::GlobalValue::ExternalLinkage,
                                               "init_"+this->mod->getName(),
                                               llvmMod);
    //init->setDSOLocal(true);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(getLLVMCtx(), "", init);
    setCurrBB(bb);

    // Init imported modules
    for(auto m: modulesToInit) {
        for(auto n: m->getNames()) {
            LOGMAX("Creating init call to module "+n);
            auto mInitF = llvmMod->getOrInsertFunction("init_"+n, 
                                                        llvm::FunctionType::get(
                                                            voidT,
                                                            false
                                                        ));
            builder.CreateCall(mInitF);
        }
    }

    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Init", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        {
                                                            stringTPtr,
                                                            builder.getInt8Ty()->getPointerTo()->getPointerTo()
                                                        },
                                                        false
                                                    ));
    // Init strings
    for(auto s: stringsToInit) {
        auto secloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), s.second);
        builder.CreateCall(stringInitF, { s.first, secloaded});
    }

    auto matrixCreateF = llvmMod->getOrInsertFunction("matrix_Create_Default", 
                                                      llvm::FunctionType::get(
                                                        voidT,
                                                        matrixTPtr,
                                                        false
                                                      ));
    // Init matrices
    for(auto m: matricesToInit) {
        builder.CreateCall(matrixCreateF, { m.first });
        if(m.second) {
            auto mex = m.second;
            // TODO: change to non cyclic call once add matrix is created or init matrix
            auto mPtr = builder.CreateAlloca(matrixTPtr);
            builder.CreateStore(m.first, mPtr);
            auto matrixAppend = llvmMod->getFunction("append_"+mex->getType()->getName()+"_"+mex->getType()->getDecl()->getName());
            if(!matrixAppend) {
                llvm::report_fatal_error(("Somehow correctly templated append function was not generated: append_"+mex->getType()->getName()+"_"+mex->getType()->getDecl()->getName()).c_str());
            }
            for(auto v: mex->getValue()) {
                llvm::Value *intV = nullptr;
                if(auto e = llvm::dyn_cast<ir::IntLiteral>(v)) {
                    intV = llvm::ConstantInt::get(int64T, e->getValue());
                }
                else if(auto e = llvm::dyn_cast<ir::BoolLiteral>(v)) {
                    intV = llvm::ConstantInt::get(int1T, e->getValue());
                }
                else if(auto e = llvm::dyn_cast<ir::FloatLiteral>(v)) {
                    intV = llvm::ConstantFP::get(floatT, e->getValue());
                }
                else if(llvm::isa<ir::NoneLiteral>(v)) {
                    intV = llvm::ConstantPointerNull::get(builder.getInt8Ty()->getPointerTo());
                }
                else if(auto e = llvm::dyn_cast<ir::StringLiteral>(v)) {
                    llvm::GlobalVariable *glv = new llvm::GlobalVariable(*llvmMod,
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage,
                                                            nullptr);
                    glv->setInitializer(builder.CreateGlobalStringPtr(e->getValue().c_str(), "", 0, llvmMod));
                    
                    auto strobj = builder.CreateAlloca(stringT);

                    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Init", 
                                                                llvm::FunctionType::get(
                                                                    voidT,
                                                                    {
                                                                        stringTPtr,
                                                                        builder.getInt8Ty()->getPointerTo()
                                                                    },
                                                                    false
                                                                ));
                    // Init string
                    auto vloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), glv);
                    builder.CreateCall(stringInitF, { strobj, vloaded });
                    intV = builder.CreateLoad(stringT, strobj);
                }
                else {
                    llvm::report_fatal_error("Global matrix initializer has to be a constant");
                }
                builder.CreateCall(matrixAppend, {mPtr, intV});
            }
        }
    }

    // Init maybes
    for(auto [d, v]: maybesToInit) {
        auto mallocF = getLLVMMod()->getOrInsertFunction("GC_malloc",
                            llvm::FunctionType::get(
                            builder.getInt8Ty()->getPointerTo(),
                            builder.getInt64Ty(),
                            false
                            ));
        llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
        auto ts = dataLayout->getTypeAllocSize(v->getType()->getPointerElementType());
        auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
        auto valLd = builder.CreateLoad(v->getType()->getPointerElementType(), v);
        builder.CreateStore(valLd, mem);
        builder.CreateStore(mem, d);
    }

    builder.CreateRetVoid();

    // Insert _main
    if(mainMod && !cgNoMain) {
        auto bytePtrPtrTy = builder.getInt8Ty()->getPointerTo()->getPointerTo();
        llvm::Function *main = llvm::Function::Create(llvm::FunctionType::get(
                                                    builder.getInt32Ty(),
                                                    {builder.getInt32Ty(), bytePtrPtrTy},
                                                    false
                                                ), 
                                                llvm::GlobalValue::ExternalLinkage,
                                                "main",
                                                llvmMod);
        main->setDSOLocal(true);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(getLLVMCtx(), "", main);
        setCurrBB(bb);

        builder.CreateCall(init);
        auto entryFunLLVM = llvmMod->getFunction(mangleName(entryFun));
        std::vector<llvm::Value *> args{};
        builder.CreateCall(entryFunLLVM, args);

        builder.CreateRet(llvm::ConstantInt::get(builder.getInt32Ty(), 0));
    }
}

llvm::FunctionType *cg::CodeGen::createFunctionType(ir::FunctionDecl *fun) {
    // FIXME: Handle values passed by reference
    llvm::Type *retType = mapType(fun->getReturnType());
    llvm::SmallVector<llvm::Type *> paramTypes;
    for(auto p : fun->getParams()) {
        llvm::Type *t = mapType(p);
        if(p->getType()->isMaybe()) {
            t = t->getPointerTo();
        }
        paramTypes.push_back(t);
    }
    return llvm::FunctionType::get(retType, paramTypes, false);
}

llvm::Function *cg::CGFunction::createFunction(ir::FunctionDecl *fun, llvm::FunctionType *funType) {
    llvm::Function *f = llvm::Function::Create(funType, 
                                               llvm::GlobalValue::ExternalLinkage,
                                               mangleName(fun),
                                               cgm.getLLVMMod());
    size_t idx = 0;
    for(auto i = f->arg_begin(); i != f->arg_end(); ++i, ++idx) {
        llvm::Argument *arg = i;
        ir::FormalParamDecl *param = fun->getParams()[idx];
        if(param->isByReference()) {
            // FIXME: Handle referenced params??
        }
        arg->setName(param->getName());
    }
    return f;
}

void cg::CGFunction::run() {
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(cgm.getLLVMCtx(), "entry", llvmFun);
    setCurrBB(bb);

    size_t idx = 0;
    auto &defs = currDef[bb];
    for(auto i = llvmFun->arg_begin(); i != llvmFun->arg_end(); ++i, ++idx) {
        llvm::Argument *arg = i;
        ir::FormalParamDecl *fp = fun->getParams()[idx];
        if(!fp->getType()->isMaybe()) {
            auto argPtr = builder.CreateAlloca(arg->getType());
            builder.CreateStore(arg, argPtr);
            formalParams[fp] = argPtr;
            defs.defs.insert(std::pair<ir::IR *, llvm::Value *>(fp, argPtr));
        }
        else {
            formalParams[fp] = arg;
            defs.defs.insert(std::pair<ir::IR *, llvm::Value *>(fp, arg));
        }
    }

    for(auto *d : fun->getDecl()) {
        if(auto *var = llvm::dyn_cast<ir::VarDecl>(d)) {
            llvm::Type *ty = mapType(var);
            if(ty->isAggregateType()) {
                llvm::Value *val = builder.CreateAlloca(ty);
                defs.defs.insert(std::pair<ir::IR *, llvm::Value *>(var, val));
            }
        }
    }

    auto block = fun->getDecl();
    emit(fun->getDecl());
    if(!currBB->getTerminator()) {
        builder.CreateRetVoid();
    }
}
