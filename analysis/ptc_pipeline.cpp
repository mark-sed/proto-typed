#include "ptc_pipeline.hpp"
#include "function_analysis.hpp"
#include "constant_folder.hpp"
#include "ir.hpp"

using namespace ptc;

PTCPipeline::PTCPipeline(Diagnostics &diags) : diags(diags) {

}

void PTCPipeline::run(ir::ModuleDecl *mod) {
    LOGMAX("Starting ptc pipeline");

    // Function Analysis
    for(auto decl : mod->getDecls()) {
        if(auto f = llvm::dyn_cast<ir::FunctionDecl>(decl)) {
            LOG1("Running function analysis on "+f->getName());
            FunctionAnalysis fcheck(f, diags);
            fcheck.run();
        }
    }

    // Constant folding
    ConstantFolder const_folder(mod, diags);
    LOG1("Running constant folder");
    const_folder.run();

    LOGMAX("Finished ptc pipeline");
}