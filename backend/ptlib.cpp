/**
 * @file ptlib.cpp
 * @author Marek Sedlacek
 * @brief Prototyped standard library intrinsics
 * 
 * @copyright Copyright (c) 2024
 * Generates prototyped functions that need to be intrinsified
 * or that are templated.
 */

#include "ptlib.hpp"
#include "codegen.hpp"
#include "logging.hpp"

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
    auto printff = llvmMod->getOrInsertFunction("printf",
                                llvm::FunctionType::get(
                                builder.getInt32Ty(),
                                { 
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt8Ty()->getPointerTo()
                                },
                                true
                                ));
    llvm::GlobalVariable *format = new llvm::GlobalVariable(*llvmMod,
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage,
                                                        nullptr,
                                                        "");
    format->setInitializer(builder.CreateGlobalStringPtr("%s", "", 0, llvmMod));
    auto funType = llvm::FunctionType::get(voidT, { stringT }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            "print_string",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);
    llvm::Value *cstr = builder.CreateExtractValue(f->getArg(0), 0);
    auto formatloaded = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), format);
    builder.CreateCall(printff, { formatloaded, cstr });
    builder.CreateRetVoid();
}

void PTLib::to_string_intInit() {
    auto funType = llvm::FunctionType::get(stringT, { int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
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
                                false
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
                                            llvm::GlobalValue::PrivateLinkage,
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
                                            llvm::GlobalValue::PrivateLinkage,
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

void PTLib::to_int_base_string_intInit() {
    auto funType = llvm::FunctionType::get(int64T->getPointerTo(), { stringT, int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            "to_int_base_string_int",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *validbb = llvm::BasicBlock::Create(ctx, "valid", f);
    llvm::BasicBlock *invalidbb = llvm::BasicBlock::Create(ctx, "invalid", f);

    auto strtolF = llvmMod->getOrInsertFunction("strtol",
                                llvm::FunctionType::get(
                                int64T, {
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt8Ty()->getPointerTo()->getPointerTo(),
                                    builder.getInt32Ty() },
                                false
                                ));

    auto mallocF = llvmMod->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));

    setCurrBB(bb);
    auto end = builder.CreateAlloca(builder.getInt8Ty()->getPointerTo());
    llvm::Value *cstr = builder.CreateExtractValue(f->getArg(0), 0);
    auto base32 = builder.CreateTrunc(f->getArg(1), builder.getInt32Ty());
    auto parsedVal = builder.CreateCall(strtolF, {cstr, end, base32});

    // Check is end is 0x0
    auto endValPtr = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), end);
    auto endVal = builder.CreateLoad(builder.getInt8Ty(), endValPtr);
    auto isNotZero = builder.CreateICmpNE(endVal, llvm::ConstantInt::get(llvm::Type::getInt8Ty(ctx), 0));
    auto isStr = builder.CreateICmpEQ(endValPtr, cstr);
    // TODO: We should also check for under and overflow
    auto isError = builder.CreateOr(isNotZero, isStr);
    builder.CreateCondBr(isError, invalidbb, validbb);

    setCurrBB(validbb);
    llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
    auto ts = dataLayout->getTypeAllocSize(int64T);
    auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
    builder.CreateStore(parsedVal, mem);
    builder.CreateRet(mem);

    setCurrBB(invalidbb);
    builder.CreateRet(llvm::ConstantPointerNull::get(int64T->getPointerTo()));
}

void PTLib::to_float_stringInit() {
    auto funType = llvm::FunctionType::get(floatT->getPointerTo(), { stringT }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            "to_float_string",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *validbb = llvm::BasicBlock::Create(ctx, "valid", f);
    llvm::BasicBlock *invalidbb = llvm::BasicBlock::Create(ctx, "invalid", f);

    auto strtolF = llvmMod->getOrInsertFunction("strtod",
                                llvm::FunctionType::get(
                                floatT, {
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt8Ty()->getPointerTo()->getPointerTo() 
                                },
                                false
                                ));

    auto mallocF = llvmMod->getOrInsertFunction("GC_malloc",
                                 llvm::FunctionType::get(
                                    builder.getInt8Ty()->getPointerTo(),
                                    builder.getInt64Ty(),
                                    false
                                 ));

    setCurrBB(bb);
    auto end = builder.CreateAlloca(builder.getInt8Ty()->getPointerTo());
    llvm::Value *cstr = builder.CreateExtractValue(f->getArg(0), 0);
    auto parsedVal = builder.CreateCall(strtolF, {cstr, end});

    // Check is end is 0x0
    auto endValPtr = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), end);
    auto endVal = builder.CreateLoad(builder.getInt8Ty(), endValPtr);
    auto isNotZero = builder.CreateICmpNE(endVal, llvm::ConstantInt::get(llvm::Type::getInt8Ty(ctx), 0));
    auto isStr = builder.CreateICmpEQ(endValPtr, cstr);
    // TODO: We should also check for under and overflow
    auto isError = builder.CreateOr(isNotZero, isStr);
    builder.CreateCondBr(isError, invalidbb, validbb);

    setCurrBB(validbb);
    llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
    auto ts = dataLayout->getTypeAllocSize(floatT);
    auto mem = builder.CreateCall(mallocF, llvm::ConstantInt::get(builder.getInt64Ty(), ts, true));
    builder.CreateStore(parsedVal, mem);
    builder.CreateRet(mem);

    setCurrBB(invalidbb);
    builder.CreateRet(llvm::ConstantPointerNull::get(floatT->getPointerTo()));
}

void PTLib::length_stringInit() {
    auto funType = llvm::FunctionType::get(int64T, { stringT }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            "length_string",
                                            llvmMod);
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);
    llvm::Value *len32 = builder.CreateExtractValue(f->getArg(0), 1);
    auto len64 = builder.CreateSExt(len32, int64T);
    builder.CreateRet(len64);
}

void PTLib::environmentFuncsInit() {
    // int system(string)
    {
        auto funType = llvm::FunctionType::get(int64T, { stringT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "system_string",
                                                llvmMod);
        auto systemF = llvmMod->getOrInsertFunction("system", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), builder.getInt8Ty()->getPointerTo(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto cstr = builder.CreateExtractValue(f->getArg(0), 0);
        auto status = builder.CreateCall(systemF, {cstr});
        auto status64 = builder.CreateSExt(status, int64T);
        builder.CreateRet(status64);
    }
    // string getenv(string)
    {
        auto funType = llvm::FunctionType::get(stringT, { stringT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "getenv_string",
                                                llvmMod);
        auto getEnvF = llvmMod->getOrInsertFunction("getenv", 
                                                    llvm::FunctionType::get(builder.getInt8Ty()->getPointerTo(), builder.getInt8Ty()->getPointerTo(), false));
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
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        llvm::BasicBlock *isNullbb = llvm::BasicBlock::Create(ctx, "is.null", f);
        llvm::BasicBlock *notNullbb = llvm::BasicBlock::Create(ctx, "not.null", f);
        setCurrBB(bb);
        auto cstr = builder.CreateExtractValue(f->getArg(0), 0);
        auto strobj = builder.CreateAlloca(stringT);
        builder.CreateCall(stringInitF, { strobj });
        auto valuecstr = builder.CreateCall(getEnvF, {cstr});

        auto retNull = builder.CreateICmpEQ(valuecstr, llvm::ConstantPointerNull::get(builder.getInt8Ty()->getPointerTo()));
        builder.CreateCondBr(retNull, isNullbb, notNullbb);

        setCurrBB(isNullbb);
        auto rvalEmpty = builder.CreateLoad(stringT, strobj);
        builder.CreateRet(rvalEmpty);

        setCurrBB(notNullbb);
        builder.CreateCall(stringAdd, { strobj, valuecstr });
        auto rval = builder.CreateLoad(stringT, strobj);
        builder.CreateRet(rval);
    }
    // bool setenv(string, string, bool)
    {
        auto funType = llvm::FunctionType::get(int1T, { stringT, stringT, int1T }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "setenv_string_string_bool",
                                                llvmMod);
        auto setEnvF = llvmMod->getOrInsertFunction("setenv", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), 
                                                        {
                                                            builder.getInt8Ty()->getPointerTo(), 
                                                            builder.getInt8Ty()->getPointerTo(),
                                                            builder.getInt32Ty()
                                                        },
                                                        false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto name = builder.CreateExtractValue(f->getArg(0), 0);
        auto value = builder.CreateExtractValue(f->getArg(1), 0);
        auto overwrite = builder.CreateZExt(f->getArg(2), builder.getInt32Ty());
        auto status = builder.CreateCall(setEnvF, {name, value, overwrite});
        auto statusBool = builder.CreateICmpEQ(status, llvm::ConstantInt::get(builder.getInt32Ty(), 0, true));
        builder.CreateRet(statusBool);
    }
    // void exit(int)
    {
        auto funType = llvm::FunctionType::get(voidT, int64T, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "exit_int",
                                                llvmMod);
        f->addFnAttr("noreturn");
        auto exitF = llvmMod->getOrInsertFunction("exit", 
                                                    llvm::FunctionType::get(voidT, builder.getInt32Ty(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto status = builder.CreateTrunc(f->getArg(0), builder.getInt32Ty());
        builder.CreateCall(exitF, {status});
        builder.CreateRetVoid();
    }
    // int timestamp()
    {
        auto funType = llvm::FunctionType::get(int64T, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "timestamp",
                                                llvmMod);
        auto timeF = llvmMod->getOrInsertFunction("time", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), builder.getInt32Ty(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto timestamp32 = builder.CreateCall(timeF, llvm::ConstantPointerNull::get(builder.getInt32Ty()->getPointerTo()));
        auto ts64 = builder.CreateZExt(timestamp32, int64T);
        builder.CreateRet(ts64);
    }
}

void PTLib::randFuncsInit() {
    // void set_seed(int)
    {
        auto funType = llvm::FunctionType::get(voidT, { int64T }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "set_seed_int",
                                                llvmMod);
        auto srandF = llvmMod->getOrInsertFunction("srand", 
                                                    llvm::FunctionType::get(voidT, builder.getInt32Ty(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto seed = builder.CreateTrunc(f->getArg(0), builder.getInt32Ty());
        builder.CreateCall(srandF, {seed});
        builder.CreateRetVoid();
    }
    // float rand_float(float min, float max)
    /*{
        auto funType = llvm::FunctionType::get(floatT, { floatT, floatT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "rand_float_float_float",
                                                llvmMod);
        auto randF = llvmMod->getOrInsertFunction("rand", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto rndInt = builder.CreateCall(randF);
        auto range = builder.CreateFSub(f->getArg(1), f->getArg(0));
        auto divVal = builder.CreateFDiv(llvm::ConstantFP::get(floatT, llvm::ConstantFP::get(floatT, 2147483647.0)), range);
        auto rndFlt = builder.CreateSIToFP(rndInt, floatT);
        auto randFlt = builder.CreateFDiv(rndFlt, divVal);
        auto 
        builder.CreateRet();
    }*/
    // int rand_uint()
    {
        auto funType = llvm::FunctionType::get(int64T, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "rand_uint",
                                                llvmMod);
        auto randF = llvmMod->getOrInsertFunction("rand", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), false));
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        auto rndInt = builder.CreateCall(randF);
        auto rndInt64 = builder.CreateZExt(rndInt, int64T);
        builder.CreateRet(rndInt64);
    }
}

void PTLib::trigonFuncsInit() {
    auto funType = llvm::FunctionType::get(floatT, { floatT }, false);
    // float sin(float)
    {
        auto sinF = llvmMod->getOrInsertFunction("llvm.sin.f64", 
                                                llvm::FunctionType::get(floatT, floatT, false));

        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "sin_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(sinF, f->getArg(0));
        builder.CreateRet(v);
    }
    // float cos(float)
    {
        auto cosF = llvmMod->getOrInsertFunction("llvm.cos.f64", 
                                                llvm::FunctionType::get(floatT, floatT, false));

        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "cos_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(cosF, f->getArg(0));
        builder.CreateRet(v);
    }
    // float tan(float)
    {
        // LLVM does not have intrinsic for this, call tanl from libc
        auto tanF = llvmMod->getOrInsertFunction("tan", 
                                                llvm::FunctionType::get(floatT, floatT, false));

        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "tan_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(tanF, f->getArg(0));
        builder.CreateRet(v);
    }
}

void PTLib::stringFuncsInit() {
    // int ord(string)
    {
        auto funType = llvm::FunctionType::get(int64T, { stringT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "ord_string",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *cstr = builder.CreateExtractValue(f->getArg(0), 0);
        llvm::Value *chr0 = builder.CreateLoad(builder.getInt8Ty(), cstr);
        llvm::Value *extChr = builder.CreateZExt(chr0, int64T);
        builder.CreateRet(extChr);
    }
    // string chr(int)
    {
        auto funType = llvm::FunctionType::get(stringT, { int64T }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "chr_int",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        
        auto strobj = builder.CreateAlloca(stringT);
        auto stringInitF = llvmMod->getOrInsertFunction("string_Create_Default", 
                                                    llvm::FunctionType::get(voidT, stringTPtr, false));
        auto stringAddChr = llvmMod->getOrInsertFunction("string_Add_Char", 
                                                        llvm::FunctionType::get(voidT, { stringTPtr, builder.getInt8Ty() }, false));
        // Init string
        builder.CreateCall(stringInitF, { strobj });
        auto parChr = builder.CreateTrunc(f->getArg(0), builder.getInt8Ty());
        builder.CreateCall(stringAddChr, { strobj, parChr });
        auto rval = builder.CreateLoad(stringT, strobj);
        builder.CreateRet(rval);
    }
}

void PTLib::floatFuncsInit() {
    // bool is_nan(float)
    {
        auto isnanF = llvmMod->getOrInsertFunction("isnan", 
                                                    llvm::FunctionType::get(int1T, floatT, false));
        auto funType = llvm::FunctionType::get(int1T, { floatT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "is_nan_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(isnanF, f->getArg(0));
        builder.CreateRet(v);
    }
}

void PTLib::logFuncsInit() {
    // float log(float)
    {
        auto logF = llvmMod->getOrInsertFunction("log", 
                                                    llvm::FunctionType::get(floatT, floatT, false));
        auto funType = llvm::FunctionType::get(floatT, { floatT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "ln_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(logF, f->getArg(0));
        builder.CreateRet(v);
    }
    // float log10(float)
    {
        auto logF = llvmMod->getOrInsertFunction("log10", 
                                                    llvm::FunctionType::get(floatT, floatT, false));
        auto funType = llvm::FunctionType::get(floatT, { floatT }, false);
        llvm::Function *f = llvm::Function::Create(funType, 
                                                llvm::GlobalValue::PrivateLinkage,
                                                "log10_float",
                                                llvmMod);
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
        setCurrBB(bb);
        llvm::Value *v = builder.CreateCall(logF, f->getArg(0));
        builder.CreateRet(v);
    }
}

void PTLib::appendInit(std::string name, llvm::Type *mt, llvm::Type *vt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }
        
    auto funType = llvm::FunctionType::get(voidT, { mt->getPointerTo(), vt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto appendPrepF = llvmMod->getOrInsertFunction("matrix_Append_Prepare", 
                                                llvm::FunctionType::get(
                                                    voidT,
                                                    matrixTPtr,
                                                    false
                                                ));

    auto arg0 = builder.CreateLoad(mt, f->getArg(0));
    builder.CreateCall(appendPrepF, { arg0 });
    
    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);
    llvm::Value* bufferPtr = builder.CreateGEP(matrixT, arg0, {zero, zero});
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), bufferPtr);

    auto casted = builder.CreateBitCast(buffer, vt->getPointerTo());
    
    //get length and subtract 1
    auto indexPtr = builder.CreateGEP(matrixT, arg0, {zero, one});
    auto length = builder.CreateLoad(builder.getInt32Ty(), indexPtr);
    auto index = builder.CreateSub(length, one);

    auto valptr = builder.CreateGEP(vt, casted, index);
    builder.CreateStore(f->getArg(1), valptr);
    
    builder.CreateRetVoid();
}

void PTLib::mappend_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }
        
    auto funType = llvm::FunctionType::get(voidT, { mt->getPointerTo(), vt->getPointerTo() }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto appendPrepF = llvmMod->getOrInsertFunction("matrix_Append_Prepare", 
                                                llvm::FunctionType::get(
                                                    voidT,
                                                    matrixTPtr,
                                                    false
                                                ));

    auto arg0 = builder.CreateLoad(mt, f->getArg(0));
    builder.CreateCall(appendPrepF, { arg0 });
    
    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);
    llvm::Value* bufferPtr = builder.CreateGEP(matrixT, arg0, {zero, zero});
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), bufferPtr);

    auto casted = builder.CreateBitCast(buffer, vt->getPointerTo());
    
    //get length and subtract 1
    auto indexPtr = builder.CreateGEP(matrixT, arg0, {zero, one});
    auto length = builder.CreateLoad(builder.getInt32Ty(), indexPtr);
    auto index = builder.CreateSub(length, one);

    auto valptr = builder.CreateGEP(vt, casted, index);
    auto apval = builder.CreateLoad(vt, f->getArg(1));
    builder.CreateStore(apval, valptr);
    
    builder.CreateRetVoid();
}

void PTLib::remove_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(voidT, { mt->getPointerTo(), int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *removeStartBB = llvm::BasicBlock::Create(ctx, "remove.start", f);
    llvm::BasicBlock *removeHeaderBB = llvm::BasicBlock::Create(ctx, "remove.header", f);
    llvm::BasicBlock *removeLoopBB = llvm::BasicBlock::Create(ctx, "remove.loop", f);
    llvm::BasicBlock *changeLenBB = llvm::BasicBlock::Create(ctx, "change.len", f);

    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);

    setCurrBB(bb);

    // Check if it is the last element - then just change the length
    auto arg0 = builder.CreateLoad(mt, f->getArg(0));
    llvm::Value* len32Ptr = builder.CreateGEP(matrixT, arg0, {zero, one});
    auto len32 = builder.CreateLoad(builder.getInt32Ty()->getPointerTo(), len32Ptr);
    auto len64 = builder.CreateSExt(len32, int64T);
    auto lastI = builder.CreateNSWSub(len64, llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 1));

    auto isLastEl = builder.CreateICmpEQ(lastI, f->getArg(1));
    builder.CreateCondBr(isLastEl, changeLenBB, removeStartBB);

    setCurrBB(removeStartBB);
    auto idxPtr = builder.CreateAlloca(int64T);
    auto pos = f->getArg(1);
    builder.CreateStore(pos, idxPtr);
    llvm::Value* bufferPtr = builder.CreateGEP(matrixT, arg0, {zero, zero});
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), bufferPtr);
    auto casted = builder.CreateBitCast(buffer, vt->getPointerTo());
    builder.CreateBr(removeHeaderBB);

    setCurrBB(removeHeaderBB);
    auto idx = builder.CreateLoad(int64T, idxPtr);
    auto isSmaller = builder.CreateICmpSLT(idx, lastI);
    builder.CreateCondBr(isSmaller, removeLoopBB, changeLenBB);
    setCurrBB(removeLoopBB);

    auto newIdx = builder.CreateNSWAdd(idx, llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 1));
    auto valptr = builder.CreateGEP(vt, casted, idx);
    auto valNextPtr = builder.CreateGEP(vt, casted, newIdx);
    auto valNext = builder.CreateLoad(vt, valNextPtr);
    builder.CreateStore(valNext, valptr);

    builder.CreateStore(newIdx, idxPtr);
    builder.CreateBr(removeHeaderBB);

    setCurrBB(changeLenBB);
    auto newLen = builder.CreateNSWSub(len32, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1));
    builder.CreateStore(newLen, len32Ptr);

    builder.CreateRetVoid();
}

void PTLib::length_matrixInit(std::string name, llvm::Type *mt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(int64T, { mt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);
    llvm::Value *len32 = builder.CreateExtractValue(f->getArg(0), 1);
    auto len64 = builder.CreateSExt(len32, int64T);
    builder.CreateRet(len64);
}

void PTLib::equals_matrixInit(std::string name, llvm::Type *mt, ir::TypeDecl *vt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(int1T, { mt, mt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));
    
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *compareBB = llvm::BasicBlock::Create(ctx, "compare", f);
    llvm::BasicBlock *loopCondBB = llvm::BasicBlock::Create(ctx, "loop.cond", f);
    llvm::BasicBlock *loopBodyBB = llvm::BasicBlock::Create(ctx, "loop.body", f);
    llvm::BasicBlock *loopCntBB = llvm::BasicBlock::Create(ctx, "loop.cnt", f);
    llvm::BasicBlock *notEqBB = llvm::BasicBlock::Create(ctx, "not.eq", f);
    llvm::BasicBlock *eqBB = llvm::BasicBlock::Create(ctx, "are.eq", f);
    setCurrBB(bb);
    
    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);

    auto length1 = builder.CreateExtractValue(f->getArg(0), 1);
    auto length2 = builder.CreateExtractValue(f->getArg(1), 1);
    auto sameLen = builder.CreateICmpEQ(length1, length2);
    builder.CreateCondBr(sameLen, compareBB, notEqBB);

    setCurrBB(compareBB);

    auto buffer1 = builder.CreateExtractValue(f->getArg(0), 0);
    auto buffer2 = builder.CreateExtractValue(f->getArg(1), 0);

    // If not array of array, and not array of compound type,
    // then just compare memory as the types are the same
    // In case of any, user has to know what they are doing
    if(vt->getDimensions() == 1) {
        // TODO: Handle maybe
        if(vt->getBaseName() == STRING_CSTR) {
            auto str_eq = llvmMod->getOrInsertFunction("string_Eq",
                                 llvm::FunctionType::get(
                                    int1T, { builder.getInt8Ty()->getPointerTo(), builder.getInt8Ty()->getPointerTo() },
                                    false
                                 ));
            
            auto iPtr = builder.CreateAlloca(builder.getInt32Ty());
            builder.CreateStore(zero, iPtr);
            builder.CreateBr(loopCondBB);
            setCurrBB(loopCondBB);

            auto i = builder.CreateLoad(builder.getInt32Ty(), iPtr);
            auto iend = builder.CreateICmpSGE(i, length1);
            builder.CreateCondBr(iend, eqBB, loopBodyBB);

            setCurrBB(loopBodyBB);

            auto casted1Ptr = builder.CreateBitCast(buffer1, stringT->getPointerTo());
            auto casted2Ptr = builder.CreateBitCast(buffer2, stringT->getPointerTo());

            auto casted1 = builder.CreateGEP(stringT, casted1Ptr, i);
            auto casted2 = builder.CreateGEP(stringT, casted2Ptr, i);

            auto loaded1 = builder.CreateLoad(stringT, casted1);
            auto loaded2 = builder.CreateLoad(stringT, casted2);

            auto rval = builder.CreateCall(str_eq, {loaded1, loaded2});
            builder.CreateCondBr(rval, loopCntBB, notEqBB);

            setCurrBB(loopCntBB);
            auto newI = builder.CreateNSWAdd(i, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1));
            builder.CreateStore(newI, iPtr);
            builder.CreateBr(loopCondBB);
        }
        else if(llvm::dyn_cast<ir::TypeDecl>(vt->getDecl()) &&
                llvm::dyn_cast<ir::TypeDecl>(vt->getDecl())->getDecl() &&
                llvm::isa<ir::StructDecl>(llvm::dyn_cast<ir::TypeDecl>(vt->getDecl())->getDecl())) {
            // Struct
            auto strDc = llvm::dyn_cast<ir::StructDecl>(llvm::dyn_cast<ir::TypeDecl>(vt->getDecl())->getDecl());
            
            std::string eqSubName = "equals_"+strDc->getName()+"_"+strDc->getName();
            llvm::Function *eqSub_f = nullptr;
            for(auto [kn, fin] : generated) {
                if(kn == eqSubName) {
                    eqSub_f = fin;
                }
            }
            
            if(!eqSub_f) {
                llvm::report_fatal_error("Sub struct equals was not generated");
            }

            auto iPtr = builder.CreateAlloca(builder.getInt32Ty());
            builder.CreateStore(zero, iPtr);
            builder.CreateBr(loopCondBB);
            setCurrBB(loopCondBB);

            auto i = builder.CreateLoad(builder.getInt32Ty(), iPtr);
            auto iend = builder.CreateICmpSGE(i, length1);
            builder.CreateCondBr(iend, eqBB, loopBodyBB);

            setCurrBB(loopBodyBB);

            auto casted1Ptr = builder.CreateBitCast(buffer1, mod->mapType(vt->getDecl())->getPointerTo());
            auto casted2Ptr = builder.CreateBitCast(buffer2, mod->mapType(vt->getDecl())->getPointerTo());

            auto casted1 = builder.CreateGEP(mod->mapType(vt->getDecl()), casted1Ptr, i);
            auto casted2 = builder.CreateGEP(mod->mapType(vt->getDecl()), casted2Ptr, i);

            auto loaded1 = builder.CreateLoad(mod->mapType(vt->getDecl()), casted1);
            auto loaded2 = builder.CreateLoad(mod->mapType(vt->getDecl()), casted2);

            auto rval = builder.CreateCall(eqSub_f, {loaded1, loaded2});
            builder.CreateCondBr(rval, loopCntBB, notEqBB);

            setCurrBB(loopCntBB);
            auto newI = builder.CreateNSWAdd(i, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1));
            builder.CreateStore(newI, iPtr);
            builder.CreateBr(loopCondBB);
        }
        else {
            auto memcmp_f = llvmMod->getOrInsertFunction("memcmp", 
                                                    llvm::FunctionType::get(builder.getInt32Ty(), 
                                                    {builder.getInt8Ty()->getPointerTo(), 
                                                     builder.getInt8Ty()->getPointerTo(),
                                                     int64T}, 
                                                    false));

            auto tsize = 1;
            if(vt->getBaseName() == INT_CSTR) {
                tsize = int64T->getPrimitiveSizeInBits()/8;
            }
            else if(vt->getBaseName() == BOOL_CSTR) {
                tsize = int1T->getPrimitiveSizeInBits()/8;
            }
            else if(vt->getBaseName() == FLOAT_CSTR) {
                tsize = floatT->getPrimitiveSizeInBits()/8;
            }
            else if(vt->getBaseName() == ANY_CSTR) {
                llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
                tsize = dataLayout->getTypeAllocSize(builder.getInt8Ty()->getPointerTo());
            }
            else if(llvm::isa<ir::FunTypeDecl>(vt->getBaseDecl())) {
                llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
                tsize = dataLayout->getTypeAllocSize(builder.getInt8Ty()->getPointerTo());
            }
            else {
                llvm::report_fatal_error("Unknown data type for memcmp");
            }
            auto byteSize = builder.CreateNSWMul(length1, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), tsize));
            auto cmpIndex = builder.CreateCall(memcmp_f, {buffer1, buffer2, byteSize});
            auto memEq = builder.CreateICmpEQ(cmpIndex, zero);
            builder.CreateCondBr(memEq, eqBB, notEqBB);
        }
    }
    else {
        // If array of array, then call this method on all the subarrays
        std::string eqSubName = "equals_"+vt->getDecl()->getName()+"_"+vt->getDecl()->getName();
        llvm::Function *eqSub_f = nullptr;
        for(auto [kn, fin] : generated) {
            if(kn == eqSubName) {
                eqSub_f = fin;
            }
        }
        
        if(!eqSub_f) {
            llvm::report_fatal_error("Sub equals was not generated");
        }

        auto iPtr = builder.CreateAlloca(builder.getInt32Ty());
        builder.CreateStore(zero, iPtr);
        builder.CreateBr(loopCondBB);
        setCurrBB(loopCondBB);

        auto i = builder.CreateLoad(builder.getInt32Ty(), iPtr);
        auto iend = builder.CreateICmpSGE(i, length1);
        builder.CreateCondBr(iend, eqBB, loopBodyBB);

        setCurrBB(loopBodyBB);

        auto casted1Ptr = builder.CreateBitCast(buffer1, mt->getPointerTo());
        auto casted2Ptr = builder.CreateBitCast(buffer2, mt->getPointerTo());

        auto casted1 = builder.CreateGEP(mt, casted1Ptr, i);
        auto casted2 = builder.CreateGEP(mt, casted2Ptr, i);

        auto loaded1 = builder.CreateLoad(matrixT, casted1);
        auto loaded2 = builder.CreateLoad(matrixT, casted2);

        auto rval = builder.CreateCall(eqSub_f, {loaded1, loaded2});
        builder.CreateCondBr(rval, loopCntBB, notEqBB);

        setCurrBB(loopCntBB);
        auto newI = builder.CreateNSWAdd(i, llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1));
        builder.CreateStore(newI, iPtr);
        builder.CreateBr(loopCondBB);
    }

    
    setCurrBB(notEqBB);
    builder.CreateRet(llvm::ConstantInt::get(int1T, 0));

    setCurrBB(eqBB);
    builder.CreateRet(llvm::ConstantInt::get(int1T, 1));
}

void PTLib::find_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt, ir::TypeDecl *vtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }
    
    auto funType = llvm::FunctionType::get(int64T, { mt, vt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));
    
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *loopCondBB = llvm::BasicBlock::Create(ctx, "loop.cond", f);
    llvm::BasicBlock *loopBodyBB = llvm::BasicBlock::Create(ctx, "loop.body", f);
    llvm::BasicBlock *loopFoundBB = llvm::BasicBlock::Create(ctx, "loop.found", f);
    llvm::BasicBlock *loopCntBB = llvm::BasicBlock::Create(ctx, "loop.cnt", f);
    llvm::BasicBlock *returnBB = llvm::BasicBlock::Create(ctx, "f.ret", f);
    setCurrBB(bb);
    
    llvm::Value* zero = llvm::ConstantInt::get(int64T, 0);

    auto foundIPtr = builder.CreateAlloca(int64T);
    builder.CreateStore(llvm::ConstantInt::get(int64T, -1), foundIPtr);
    auto length1 = builder.CreateExtractValue(f->getArg(0), 1);
    auto length64 = builder.CreateSExt(length1, int64T);
    auto buffer1 = builder.CreateExtractValue(f->getArg(0), 0);

    // TODO: Handle maybe
    auto str_eq = llvmMod->getOrInsertFunction("string_Eq",
                            llvm::FunctionType::get(
                            int1T, { builder.getInt8Ty()->getPointerTo(), builder.getInt8Ty()->getPointerTo() },
                            false
                            ));

    auto iPtr = builder.CreateAlloca(int64T);
    builder.CreateStore(zero, iPtr);
    builder.CreateBr(loopCondBB);
    setCurrBB(loopCondBB);

    auto i = builder.CreateLoad(int64T, iPtr);
    auto iend = builder.CreateICmpSGE(i, length64);
    builder.CreateCondBr(iend, returnBB, loopBodyBB);

    setCurrBB(loopBodyBB);

    auto casted1Ptr = builder.CreateBitCast(buffer1, vt->getPointerTo());
    auto casted1 = builder.CreateGEP(vt, casted1Ptr, i);

    auto loaded1 = builder.CreateLoad(vt, casted1);

    llvm::Value *rval = nullptr;
    
    if(mtt->getDimensions() > 1) {
        std::string eqSubName = "equals_"+mtt->getDecl()->getName()+"_"+mtt->getDecl()->getName();
        llvm::Function *eqSub_f = nullptr;
        for(auto [kn, fin] : generated) {
            if(kn == eqSubName) {
                eqSub_f = fin;
            }
        }
        
        if(!eqSub_f) {
            llvm::report_fatal_error("Sub equals for find was not generated");
        }
        rval = builder.CreateCall(eqSub_f, {loaded1, f->getArg(1)});
    }
    else if(vtt->getDecl() && llvm::isa<ir::StructDecl>(vtt->getDecl())) {
        // Struct
        std::string eqSubName = "equals_"+vtt->getDecl()->getName()+"_"+vtt->getDecl()->getName();
        llvm::Function *eqSub_f = nullptr;
        for(auto [kn, fin] : generated) {
            if(kn == eqSubName) {
                eqSub_f = fin;
            }
        }
        
        if(!eqSub_f) {
            llvm::report_fatal_error("Sub struct equals for find was not generated");
        }
        rval = builder.CreateCall(eqSub_f, {loaded1, f->getArg(1)});
    }
    else if(vtt->getBaseName() == FLOAT_CSTR) {
        rval = builder.CreateFCmpOEQ(loaded1, f->getArg(1));
    }
    else if(vtt->getBaseName() == STRING_CSTR) {
        rval = builder.CreateCall(str_eq, {loaded1, f->getArg(1)});
    }
    else {
        rval = builder.CreateICmpEQ(loaded1, f->getArg(1));
    }
    
    builder.CreateCondBr(rval, loopFoundBB, loopCntBB);

    setCurrBB(loopFoundBB);
    builder.CreateStore(i, foundIPtr);
    builder.CreateBr(returnBB);

    setCurrBB(loopCntBB);
    auto newI = builder.CreateNSWAdd(i, llvm::ConstantInt::get(int64T, 1));
    builder.CreateStore(newI, iPtr);
    builder.CreateBr(loopCondBB);
    
    setCurrBB(returnBB);
    auto ri = builder.CreateLoad(int64T, foundIPtr);
    builder.CreateRet(ri);
}

void PTLib::contains_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt, ir::TypeDecl *vtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(int1T, { mt, vt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    std::string findSubName = "find_"+mtt->getName()+"_"+vtt->getName();
    llvm::Function *findSub_f = nullptr;
    for(auto [kn, fin] : generated) {
        if(kn == findSubName) {
            findSub_f = fin;
        }
    }
    
    if(!findSub_f) {
        llvm::report_fatal_error("Find for contains was not generated");
    }

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto rval = builder.CreateCall(findSub_f, {f->getArg(0), f->getArg(1)});
    llvm::Value *found = builder.CreateICmpNE(rval, llvm::ConstantInt::get(int64T, -1));

    builder.CreateRet(found);
}

void PTLib::slice_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(mt, { mt, int64T, int64T, int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    std::string appSubName = "append_"+mtt->getName()+"_"+mtt->getDecl()->getName();
    llvm::Function *appSub_f = nullptr;
    for(auto [kn, fin] : generated) {
        if(kn == appSubName) {
            appSub_f = fin;
        }
    }
    
    if(!appSub_f) {
        llvm::report_fatal_error("Append for slice was not generated");
    }

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *loopCondBB = llvm::BasicBlock::Create(ctx, "loop.cond", f);
    llvm::BasicBlock *forCondPosStepBB = llvm::BasicBlock::Create(ctx, "range.posstep", f);
    llvm::BasicBlock *forCondNegStepBB = llvm::BasicBlock::Create(ctx, "range.negstep", f);
    llvm::BasicBlock *forBodyBB = llvm::BasicBlock::Create(ctx, "loop.body", f);
    llvm::BasicBlock *forAfterBB = llvm::BasicBlock::Create(ctx, "loop.after", f);

    setCurrBB(bb);

    auto matPtr = builder.CreateAlloca(matrixTPtr);
    auto matobj = builder.CreateAlloca(matrixT);
    builder.CreateStore(matobj, matPtr);
    auto matrixCreateF = llvmMod->getOrInsertFunction("matrix_Create_Default", 
                                                    llvm::FunctionType::get(
                                                    voidT,
                                                    matrixTPtr,
                                                    false
                                                    ));
    builder.CreateCall(matrixCreateF, matobj);

    // TODO: Dont go over bounderies
    //auto length1 = builder.CreateExtractValue(f->getArg(0), 1);
    //auto length64 = builder.CreateSExt(length1, int64T);
    auto buffer1 = builder.CreateExtractValue(f->getArg(0), 0);

    auto iPtr = builder.CreateAlloca(int64T);
    builder.CreateStore(f->getArg(1), iPtr);
    auto stepLd = builder.CreateNSWSub(f->getArg(2), f->getArg(1));
    builder.CreateBr(loopCondBB);

    setCurrBB(loopCondBB);
    auto i = builder.CreateLoad(int64T, iPtr);
    auto posStep = builder.CreateICmpSGT(stepLd, llvm::ConstantInt::get(int64T, 0, true));
    builder.CreateCondBr(posStep, forCondPosStepBB, forCondNegStepBB);

    setCurrBB(forCondPosStepBB);
    auto cmpEndPos = builder.CreateICmpSLT(i, f->getArg(3));
    builder.CreateCondBr(cmpEndPos, forBodyBB, forAfterBB);

    setCurrBB(forCondNegStepBB);
    auto cmpEndNeg = builder.CreateICmpSGT(i, f->getArg(3));
    builder.CreateCondBr(cmpEndNeg, forBodyBB, forAfterBB);

    setCurrBB(forBodyBB);

    auto casted1Ptr = builder.CreateBitCast(buffer1, vt->getPointerTo());
    auto casted1 = builder.CreateGEP(vt, casted1Ptr, i);

    auto loaded1 = builder.CreateLoad(vt, casted1);
    
    builder.CreateCall(appSub_f, {matPtr, loaded1});

    auto newI = builder.CreateNSWAdd(i, stepLd);
    builder.CreateStore(newI, iPtr);
    builder.CreateBr(loopCondBB);
    
    setCurrBB(forAfterBB);
    auto matStru = builder.CreateLoad(matrixT, matobj);
    builder.CreateRet(matStru);
}

void PTLib::slice2_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(mt, { mt, int64T, int64T }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    std::string slice3Name = "slice_"+mtt->getName()+"_int_int_int";
    llvm::Function *slice3_f = nullptr;
    for(auto [kn, fin] : generated) {
        if(kn == slice3Name) {
            slice3_f = fin;
        }
    }
    
    if(!slice3_f) {
        llvm::report_fatal_error("Slice3 for slice2 was not generated");
    }

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    llvm::BasicBlock *smallerBB = llvm::BasicBlock::Create(ctx, "next.smaller", f);
    llvm::BasicBlock *biggerBB = llvm::BasicBlock::Create(ctx, "next.bigger", f);
    llvm::BasicBlock *callBB = llvm::BasicBlock::Create(ctx, "call.slice", f);
    setCurrBB(bb);

    auto nextPtr = builder.CreateAlloca(int64T);
    auto isBigger = builder.CreateICmpSGE(f->getArg(1), f->getArg(2));
    builder.CreateCondBr(isBigger, biggerBB, smallerBB);

    setCurrBB(smallerBB);
    auto nextAdd = builder.CreateNSWAdd(f->getArg(1), llvm::ConstantInt::get(int64T, 1, true));
    builder.CreateStore(nextAdd, nextPtr);
    builder.CreateBr(callBB);

    setCurrBB(biggerBB);
    auto nextSub = builder.CreateNSWSub(f->getArg(1), llvm::ConstantInt::get(int64T, 1, true));
    builder.CreateStore(nextSub, nextPtr);
    builder.CreateBr(callBB);

    setCurrBB(callBB);
    auto next = builder.CreateLoad(int64T, nextPtr);
    auto rval = builder.CreateCall(slice3_f, {f->getArg(0), f->getArg(1), next, f->getArg(2)});

    builder.CreateRet(rval);
}

void PTLib::reverse_matrixInit(std::string name, llvm::Type *mt, ir::TypeDecl *mtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(mt, { mt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    std::string slice3Name = "slice_"+mtt->getName()+"_int_int_int";
    llvm::Function *slice3_f = nullptr;
    for(auto [kn, fin] : generated) {
        if(kn == slice3Name) {
            slice3_f = fin;
        }
    }
    
    if(!slice3_f) {
        llvm::report_fatal_error("Slice3 for reverse was not generated");
    }

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto len = builder.CreateExtractValue(f->getArg(0), 1);
    auto len64 = builder.CreateZExt(len, int64T);
    auto start = builder.CreateNSWSub(len64, llvm::ConstantInt::get(int64T, 1, true));
    auto next = builder.CreateNSWSub(len64, llvm::ConstantInt::get(int64T, 2, true));

    auto rval = builder.CreateCall(slice3_f, {f->getArg(0), start, next, llvm::ConstantInt::get(int64T, -1, true)});

    builder.CreateRet(rval);
}

void PTLib::join_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(mt, { mt, mt }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    setCurrBB(bb);

    auto matPtr = builder.CreateAlloca(matrixTPtr);
    auto matobj = builder.CreateAlloca(matrixT);
    builder.CreateStore(matobj, matPtr);
    auto matrixCreateF = llvmMod->getOrInsertFunction("matrix_Create_Default", 
                                                    llvm::FunctionType::get(
                                                    voidT,
                                                    matrixTPtr,
                                                    false
                                                    ));
    auto matrixResizeF = llvmMod->getOrInsertFunction("matrix_Resize", 
                                                    llvm::FunctionType::get(
                                                    voidT,
                                                    { matrixTPtr, builder.getInt32Ty() },
                                                    false
                                                    ));
    auto memcpyF = llvmMod->getOrInsertFunction("memcpy", 
                                                    llvm::FunctionType::get(
                                                    builder.getInt8Ty()->getPointerTo(),
                                                    { builder.getInt8Ty()->getPointerTo(), 
                                                        builder.getInt8Ty()->getPointerTo(),
                                                        builder.getInt64Ty() },
                                                    false
                                                    ));
    builder.CreateCall(matrixCreateF, matobj);

    auto len1 = builder.CreateExtractValue(f->getArg(0), 1);
    auto len2 = builder.CreateExtractValue(f->getArg(1), 1);

    llvm::DataLayout* dataLayout = new llvm::DataLayout(llvmMod);
    auto tsize = dataLayout->getTypeAllocSize(vt);

    auto size1 = builder.CreateNSWMul(len1, llvm::ConstantInt::get(builder.getInt32Ty(), tsize, true));
    auto size2 = builder.CreateNSWMul(len2, llvm::ConstantInt::get(builder.getInt32Ty(), tsize, true));

    auto sumSize = builder.CreateNSWAdd(size1, size2);

    builder.CreateCall(matrixResizeF, {matobj, sumSize});

    auto buff1 = builder.CreateExtractValue(f->getArg(0), 0);
    auto buff2 = builder.CreateExtractValue(f->getArg(1), 0);
    auto mat = builder.CreateLoad(matrixT, matobj);
    auto buffer = builder.CreateExtractValue(mat, 0);
    builder.CreateCall(memcpyF, {buffer, buff1, size1});
    auto buffBitC = builder.CreateBitCast(buffer, vt->getPointerTo());
    auto bufferOff = builder.CreateGEP(vt, buffBitC, len1);
    builder.CreateCall(memcpyF, {bufferOff, buff2, size2});

    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);
    llvm::Value* len = builder.CreateGEP(matrixT, matobj, {zero, one});
    auto totalLen = builder.CreateNSWAdd(len1, len2);
    builder.CreateStore(totalLen, len);
    auto matVal = builder.CreateLoad(matrixT, matobj);
    builder.CreateRet(matVal);
}

void PTLib::insert_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(voidT, { mt, vt, int64T}, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    std::string appSubName = "append_"+mtt->getName()+"_"+mtt->getDecl()->getName();
    llvm::Function *appSub_f = nullptr;
    for(auto [kn, fin] : generated) {
        if(kn == appSubName) {
            appSub_f = fin;
        }
    }
    
    if(!appSub_f) {
        llvm::report_fatal_error("Append for slice was not generated");
    }


    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);
    //llvm::BasicBlock *removeStartBB = llvm::BasicBlock::Create(ctx, "insert.start", f);
    llvm::BasicBlock *headerBB = llvm::BasicBlock::Create(ctx, "insert.header", f);
    llvm::BasicBlock *loopBB = llvm::BasicBlock::Create(ctx, "insert.loop", f);
    llvm::BasicBlock *endBB = llvm::BasicBlock::Create(ctx, "end", f);

    llvm::Value* zero = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 0);
    llvm::Value* one = llvm::ConstantInt::get(llvm::Type::getInt32Ty(ctx), 1);

    setCurrBB(bb);

    auto arg0 = builder.CreateLoad(mt, f->getArg(0));
    llvm::Value* len32Ptr = builder.CreateGEP(matrixT, arg0, {zero, one});
    auto len32 = builder.CreateLoad(builder.getInt32Ty()->getPointerTo(), len32Ptr);
    auto len64 = builder.CreateSExt(len32, int64T);
    //auto lastI = builder.CreateNSWSub(len64, llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 1));

    // Append value (to enlarge list)
    builder.CreateCall(appSub_f, {f->getArg(0), f->getArg(1)});

    //setCurrBB(removeStartBB);
    auto idxPtr = builder.CreateAlloca(int64T);
    auto pos = f->getArg(2);
    builder.CreateStore(len64, idxPtr);
    llvm::Value* bufferPtr = builder.CreateGEP(matrixT, arg0, {zero, zero});
    auto buffer = builder.CreateLoad(builder.getInt8Ty()->getPointerTo(), bufferPtr);
    auto casted = builder.CreateBitCast(buffer, vt->getPointerTo());
    builder.CreateBr(headerBB);

    setCurrBB(headerBB);
    auto idx = builder.CreateLoad(int64T, idxPtr);
    auto doLoop = builder.CreateICmpSGE(idx, pos);
    builder.CreateCondBr(doLoop, loopBB, endBB);
    setCurrBB(loopBB);

    auto newIdx = builder.CreateNSWSub(idx, llvm::ConstantInt::get(llvm::Type::getInt64Ty(ctx), 1));
    auto valptr = builder.CreateGEP(vt, casted, idx);
    auto valPrevPtr = builder.CreateGEP(vt, casted, newIdx);
    auto valPrev = builder.CreateLoad(vt, valPrevPtr);
    builder.CreateStore(valPrev, valptr);

    builder.CreateStore(newIdx, idxPtr);
    builder.CreateBr(headerBB);

    setCurrBB(endBB);
    auto posIndexPtr = builder.CreateGEP(vt, casted, pos);
    builder.CreateStore(f->getArg(1), posIndexPtr);

    builder.CreateRetVoid();
}

void PTLib::equals_structInit(std::string name, llvm::Type *st, ir::TypeDecl *stt) {
    for(auto [kn, _] : generated) {
        if(kn == name) {
            return;
        }
    }

    auto funType = llvm::FunctionType::get(int1T, { st, st }, false);
    llvm::Function *f = llvm::Function::Create(funType, 
                                            llvm::GlobalValue::PrivateLinkage,
                                            name,
                                            llvmMod);
    generated.push_back(std::make_pair(name, f));

    auto stDecl = llvm::dyn_cast<ir::StructDecl>(stt->getDecl());

    llvm::BasicBlock *bb = llvm::BasicBlock::Create(ctx, "entry", f);

    std::vector<llvm::BasicBlock *> cmpBBs;
    for(unsigned int i = 0; i < stDecl->getElements().size(); ++i) {
        cmpBBs.push_back(llvm::BasicBlock::Create(ctx, "cmp."+std::to_string(i), f));
    }

    llvm::BasicBlock *notEqBB = llvm::BasicBlock::Create(ctx, "not.eq", f);

    auto str_eq = llvmMod->getOrInsertFunction("string_Eq",
                            llvm::FunctionType::get(
                            int1T, { builder.getInt8Ty()->getPointerTo(), builder.getInt8Ty()->getPointerTo() },
                            false
                            ));

    setCurrBB(bb);

    int index = 0;
    for(auto e : stDecl->getElements()) {
        auto el1 = builder.CreateExtractValue(f->getArg(0), index);
        auto el2 = builder.CreateExtractValue(f->getArg(1), index);
        llvm::Value *isEq = nullptr;
        if(auto stm = llvm::dyn_cast<ir::VarDecl>(e)) {
            if(stm->getType()->isMaybe() && stm->getType()->getName() != ANY_CSTR) {
                // TODO: Check if both maybe
                el1 = builder.CreateLoad(mod->mapType(stm->getType())->getPointerElementType(), el1);
                el2 = builder.CreateLoad(mod->mapType(stm->getType())->getPointerElementType(), el2);
            }

            if(stm->getType()->isMatrix()) {
                std::string eqName = "equals_"+stm->getType()->getName()+"_"+stm->getType()->getName();
                llvm::Function *eq_f = nullptr;
                for(auto [kn, fin] : generated) {
                    if(kn == eqName) {
                        eq_f = fin;
                    }
                }
                
                if(!eq_f) {
                    llvm::report_fatal_error("Matrix equals for struct equals was not generated");
                }

                isEq = builder.CreateCall(eq_f, {el1, el2});
            }
            else if(stm->getType()->getDecl()) {
                std::string eqName = "equals_"+stm->getType()->getDecl()->getName()+"_"+stm->getType()->getDecl()->getName();
                llvm::Function *eq_f = nullptr;
                for(auto [kn, fin] : generated) {
                    if(kn == eqName) {
                        eq_f = fin;
                    }
                }
                
                if(!eq_f) {
                    llvm::report_fatal_error("Struct equals for struct equals was not generated");
                }

                isEq = builder.CreateCall(eq_f, {el1, el2});
            }
            else if(stm->getType()->getName() == STRING_CSTR) {
                isEq = builder.CreateCall(str_eq, {el1, el2});
            }
            else if(stm->getType()->getName() == FLOAT_CSTR) {
                isEq = builder.CreateFCmpOEQ(el1, el2);
            }
            else {
                isEq = builder.CreateICmpEQ(el1, el2);
            }
        }
        else if(auto stm = llvm::dyn_cast<ir::StructDecl>(e)) {
            std::string eqName = "equals_"+stm->getName()+"_"+stm->getName();
            llvm::Function *eq_f = nullptr;
            for(auto [kn, fin] : generated) {
                if(kn == eqName) {
                    eq_f = fin;
                }
            }
            
            if(!eq_f) {
                llvm::report_fatal_error("Struct equals for struct equals was not generated");
            }

            isEq = builder.CreateCall(eq_f, {el1, el2});
        }
        else {
            llvm::report_fatal_error("Unknown IR in struct for EQ");
        }

        builder.CreateCondBr(isEq, cmpBBs[index], notEqBB);
        setCurrBB(cmpBBs[index]);

        ++index;
    }

    builder.CreateRet(llvm::ConstantInt::get(int1T, 1, true));
    setCurrBB(notEqBB);
    builder.CreateRet(llvm::ConstantInt::get(int1T, 0, true));
}

void PTLib::setupLib() {
    print_stringInit();
    
    to_string_intInit();
    to_string_floatInit();
    to_string_boolInit();

    to_int_base_string_intInit();
    to_float_stringInit();

    length_stringInit();

    trigonFuncsInit();
    stringFuncsInit();
    floatFuncsInit();

    logFuncsInit();
    
    environmentFuncsInit();
    randFuncsInit();
}

void PTLib::setupExternLib() {
    
}