#include "backend_pipeline.hpp"

using namespace ptc;

BackendPipeline::BackendPipeline() {
    // Register all the basic analyses with the managers.
    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
}

void BackendPipeline::run(llvm::Module *mod, llvm::OptimizationLevel opt_level) {
    // Create the pass manager.
    // This one corresponds to a typical -O2 optimization pipeline.
    llvm::ModulePassManager MPM = PB.buildPerModuleDefaultPipeline(opt_level);

    // Optimize the IR!
    MPM.run(*mod, MAM);
}