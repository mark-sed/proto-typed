#ifndef _PTLIB_HPP_
#define _PTLIB_HPP_

#include "codegen.hpp"
#include "ir.hpp"
#include "llvm/Support/Casting.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"

namespace ptc {

namespace cg {

class CGModule;

class PTLib {
private:
    CGModule *mod;
    llvm::Module *llvmMod;
    llvm::LLVMContext &ctx;

    llvm::IRBuilder<> builder;
    llvm::BasicBlock *currBB;

    void setCurrBB(llvm::BasicBlock *BB) {
        currBB = BB;
        builder.SetInsertPoint(currBB);
    }

    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *floatT;
    llvm::StructType *stringT;
    llvm::PointerType *stringTPtr;
    llvm::StructType *matrixT;
    llvm::PointerType *matrixTPtr;

    void print_stringInit();
    void to_string_intInit();
    void to_string_floatInit();
    void to_string_boolInit();
    void length_stringInit();
public:
    PTLib(CGModule *mod, llvm::Module *llvmMod, llvm::LLVMContext &ctx);

    void setupExternLib();
    void setupLib();
    
    void appendInit(std::string name, llvm::Type *mt, llvm::Type *vt);
    void length_matrixInit(std::string name, llvm::Type *mt);
};

}

}

#endif//_PTLIB_HPP_