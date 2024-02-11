/**
 * @file ptlib.hpp
 * @author Marek Sedlacek
 * @brief Prototyped standard library intrinsics
 * 
 * @copyright Copyright (c) 2024
 * Generates prototyped functions that need to be intrinsified
 * or that are templated.
 */

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
#include <vector>

namespace ptc {

namespace ir {
    class TypeDecl;
}

namespace cg {

class CGModule;

/**
 * Class that handles ptlib code generation
 */
class PTLib {
private:
    CGModule *mod;
    llvm::Module *llvmMod;
    llvm::LLVMContext &ctx;

    llvm::IRBuilder<> builder;
    llvm::BasicBlock *currBB;

    std::vector<std::pair<std::string, llvm::Function*>> generated;

    void setCurrBB(llvm::BasicBlock *BB) {
        currBB = BB;
        builder.SetInsertPoint(currBB);
    }

    // LLVM types for PT types
    llvm::Type *voidT;
    llvm::Type *int1T;
    llvm::Type *int64T;
    llvm::Type *floatT;
    llvm::StructType *stringT;
    llvm::PointerType *stringTPtr;
    llvm::StructType *matrixT;
    llvm::PointerType *matrixTPtr;

    // PTLib function generation
    void print_stringInit();
    void to_string_intInit();
    void to_string_floatInit();
    void to_string_boolInit();
    void to_int_base_string_intInit();
    void to_float_stringInit();
    void length_stringInit();
    void system_stringInit();

    void trigonFuncsInit();
    void stringFuncsInit();
    void floatFuncsInit();
    void maybeFuncsInit();
    void logFuncsInit();
    void environmentFuncsInit();
    void randFuncsInit();

public:
    /**
     * @param mod Codegen module
     * @param llvmMod LLVM module
     * @param ctx LLVM context
     */
    PTLib(CGModule *mod, llvm::Module *llvmMod, llvm::LLVMContext &ctx);

    /**
     * Adds external functions to ptlib
     */
    void setupExternLib();
    /**
     * Generates internal PTlib functions
     */
    void setupLib();
    
    /**
     * Code generation for templated matrix append function
     * `void append(matrix mt, element vt)`
     * 
     * @param name Function name (generated from the name and args)
     * @param mt Matrix type
     * @param vt Element type
     */
    void appendInit(std::string name, llvm::Type *mt, llvm::Type *vt);
    void mappend_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt);
    void length_matrixInit(std::string name, llvm::Type *mt);
    void equals_matrixInit(std::string name, llvm::Type *mt, ir::TypeDecl *vt);
    void equals_structInit(std::string name, llvm::Type *st, ir::TypeDecl *stt);
    void find_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt, ir::TypeDecl *vtt);
    void contains_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt, ir::TypeDecl *vtt);
    void slice_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt);
    void slice2_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt);
    void reverse_matrixInit(std::string name, llvm::Type *mt, ir::TypeDecl *mtt);
    void join_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt);
    void remove_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt);
    void insert_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt);
    void minsert_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, ir::TypeDecl *mtt);
    void sort_matrixInit(std::string name, llvm::Type *mt, llvm::Type *vt, llvm::Type *cmpf);
};

}

}

#endif//_PTLIB_HPP_