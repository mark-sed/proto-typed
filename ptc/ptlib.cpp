#include "ptlib.hpp"
#include "codegen.hpp"

using namespace ptc;
using namespace ptc::cg;

PTLib::PTLib(CGModule *mod, llvm::Module *llvmMod, llvm::LLVMContext &ctx) 
        : mod(mod), 
          llvmMod(llvmMod),
          ctx(ctx),
          builder(ctx) {
    voidT = mod->voidT;
    int1T = mod->int1T;
    int64T = mod->int64T;
    floatT = mod->floatT;
    stringT = mod->stringT;
    stringTPtr = mod->stringTPtr;
    matrixT = mod->matrixT;
    matrixTPtr = mod->matrixTPtr;
}

void PTLib::print_stringInit() {
    auto funType = llvm::FunctionType::get(voidT, { stringT }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::ExternalLinkage,
                                            "print_string",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);
    auto puts = llvmMod->getFunction("puts");
    llvm::Value *cstr = builder.CreateExtractValue(f->getArg(0), 0);
    builder.CreateCall(puts, { cstr });
    builder.CreateRetVoid();
}

void PTLib::to_string_intInit() {
    auto funType = llvm::FunctionType::get(stringT, { int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::ExternalLinkage,
                                            "to_string_int",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto strobj = builder.CreateAlloca(stringT);
    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Default", 
                                                llvm::FunctionType::get(
                                                    voidT,
                                                    stringTPtr,
                                                    false
                                                ));
    auto stringResize = llvmMod->getOrInsertFunction("string_Resize", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        { 
                                                            stringTPtr,
                                                            builder.getInt32Ty()
                                                        },
                                                        false
                                                    ));
    // Init string
    builder.CreateCall(stringInitF, { strobj });
    // int64 can be up to 20 characters, but log10 could be used to get the size
    builder.CreateCall(stringResize, { strobj, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 24) });

    auto snprintff = llvmMod->getOrInsertFunction("sprintf",
                                llvm::FunctionType::get(
                                builder.getInt32Ty(),
                                { 
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt8Ty()->getPointerTo()
                                },
                                true
                                ));
    auto strlenf = llvmMod->getOrInsertFunction("strlen",
                                llvm::FunctionType::get(
                                builder.getInt32Ty(),
                                builder.getInt8Ty()->getPointerTo(),
                                true
                                ));
    llvm::GlobalVariable *format = new llvm::GlobalVariable(*llvmMod,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage,
                                                        nullptr,
                                                        "");
    format->setInitializer(builder.CreateGlobalStringPtr("%ld", "", 0, llvmMod));
    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);
    llvm::Value* cstr = builder.CreateGEP(stringT, strobj, {zero, zero});
    //llvm::Value* cstr = builder.CreateExtractValue(rval, 0);
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), cstr);
    auto formatloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), format);
    builder.CreateCall(snprintff, { buffer,  formatloaded, f->getArg(0)});
    auto newlen = builder.CreateCall(strlenf, { buffer });
    llvm::Value* len = builder.CreateGEP(stringT, strobj, {zero, one});
    builder.CreateStore(newlen, len);
    auto rval = builder.CreateLoad(stringT, strobj);
    builder.CreateRet(rval);
}

void PTLib::to_string_floatInit() {
    auto funType = llvm::FunctionType::get(stringT, { floatT }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::ExternalLinkage,
                                            "to_string_float",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto strobj = builder.CreateAlloca(stringT);
    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Default", 
                                                llvm::FunctionType::get(
                                                    voidT,
                                                    stringTPtr,
                                                    false
                                                ));
    auto stringResize = llvmMod->getOrInsertFunction("string_Resize", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        { 
                                                            stringTPtr,
                                                            builder.getInt32Ty()
                                                        },
                                                        false
                                                    ));
    // Init string
    builder.CreateCall(stringInitF, { strobj });
    // int64 can be up to 20 characters, but log10 could be used to get the size
    builder.CreateCall(stringResize, { strobj, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 24) });

    auto snprintff = llvmMod->getOrInsertFunction("sprintf",
                                llvm::FunctionType::get(
                                builder.getInt32Ty(),
                                { 
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt8Ty()->getPointerTo()
                                },
                                true
                                ));
    auto strlenf = llvmMod->getOrInsertFunction("strlen",
                                llvm::FunctionType::get(
                                builder.getInt32Ty(),
                                builder.getInt8Ty()->getPointerTo(),
                                true
                                ));
    llvm::GlobalVariable *format = new llvm::GlobalVariable(*llvmMod,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage,
                                                        nullptr,
                                                        "");
    format->setInitializer(builder.CreateGlobalStringPtr("%.16g", "", 0, llvmMod));
    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);
    llvm::Value* cstr = builder.CreateGEP(stringT, strobj, {zero, zero});
    //llvm::Value* cstr = builder.CreateExtractValue(rval, 0);
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), cstr);
    auto formatloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), format);
    builder.CreateCall(snprintff, { buffer,  formatloaded, f->getArg(0)});
    auto newlen = builder.CreateCall(strlenf, { buffer });
    llvm::Value* len = builder.CreateGEP(stringT, strobj, {zero, one});
    builder.CreateStore(newlen, len);
    auto rval = builder.CreateLoad(stringT, strobj);
    builder.CreateRet(rval);
}

void PTLib::to_string_boolInit() {
    auto funType = llvm::FunctionType::get(stringT, { int1T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::ExternalLinkage,
                                            "to_string_bool",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto strobj = builder.CreateAlloca(stringT);
    auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Default", 
                                                llvm::FunctionType::get(
                                                    voidT,
                                                    stringTPtr,
                                                    false
                                                ));
    auto stringAdd = llvmMod->getOrInsertFunction("string_Add_CStr", 
                                                    llvm::FunctionType::get(
                                                        voidT,
                                                        { 
                                                            stringTPtr,
                                                            builder.getInt8Ty()->getPointerTo()
                                                        },
                                                        false
                                                    ));
    // Init string
    builder.CreateCall(stringInitF, { strobj });

    llvm::GlobalVariable *trueStr = new llvm::GlobalVariable(*llvmMod,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage,
                                                        nullptr,
                                                        "");
    trueStr->setInitializer(builder.CreateGlobalStringPtr("true", "", 0, llvmMod));
    llvm::GlobalVariable *falseStr = new llvm::GlobalVariable(*llvmMod,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage,
                                                        nullptr,
                                                        "");
    falseStr->setInitializer(builder.CreateGlobalStringPtr("false", "", 0, llvmMod));
    
    auto trueBB = llvm::BasicBlock::Create(ctx, "truestr", f);
    auto falseBB = llvm::BasicBlock::Create(ctx, "falsestr", f);
    auto endBB = llvm::BasicBlock::Create(ctx, "end", f);

    auto cmp = builder.CreateICmpEQ(f->getArg(0), llvm::ConstantInt::get(llvm::Type::getInt1Ty(ctx), 1));
    builder.CreateCondBr(cmp, trueBB, falseBB);

    // True
    setCurrBB(trueBB);
    auto cstr = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), trueStr);
    builder.CreateCall(stringAdd, { strobj, cstr });
    builder.CreateBr(endBB);
    
    // False
    setCurrBB(falseBB);
    auto cstrf = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), falseStr);
    builder.CreateCall(stringAdd, { strobj, cstrf });
    builder.CreateBr(endBB);
    
    // End
    setCurrBB(endBB);
    auto rval = builder.CreateLoad(stringT, strobj);
    builder.CreateRet(rval);
}

void PTLib::setupLib() {
    print_stringInit();
    to_string_intInit();
    to_string_floatInit();
    to_string_boolInit();
}

void PTLib::setupExternLib() {
    // printf
    auto bytePtrTy = builder.getInt8Ty()->getPointerTo();
    llvmMod->getOrInsertFunction("printf",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    bytePtrTy,
                                    true
                                 ));
    // puts
    llvmMod->getOrInsertFunction("puts",
                                 llvm::FunctionType::get(
                                    builder.getInt32Ty(),
                                    bytePtrTy,
                                    false
                                 ));
}