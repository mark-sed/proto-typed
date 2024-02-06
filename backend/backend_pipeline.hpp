#ifndef _BACKEND_PIPELINE_HPP_
#define _BACKEND_PIPELINE_HPP_

#include "llvm/IR/PassManager.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/Module.h"
#include "llvm/Passes/OptimizationLevel.h"

namespace ptc {

/**
 * Pipeline for llvm passes 
 */
class BackendPipeline {
private:
    // Create the analysis managers.
    // These must be declared in this order so that they are destroyed in the
    // correct order due to inter-analysis-manager references.
    llvm::LoopAnalysisManager LAM;
    llvm::FunctionAnalysisManager FAM;
    llvm::CGSCCAnalysisManager CGAM;
    llvm::ModuleAnalysisManager MAM;

    // Create the new pass manager builder.
    // Take a look at the PassBuilder constructor parameters for more
    // customization, e.g. specifying a TargetMachine or various debugging
    // options.
    llvm::PassBuilder PB;

public:
    /** Initialization of managers */
    BackendPipeline();

    /**
     * Runs llvm optimization pipeline
     * Currently this runs the default llvm pipeline with passed in opt level
     * @param mod Module to optimize
     * @param opt_level Optimization level to use
     */
    void run(llvm::Module *mod, llvm::OptimizationLevel opt_level);
};

}

#endif//_BACKEND_PIPELINE_HPP_