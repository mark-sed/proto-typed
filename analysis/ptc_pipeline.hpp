/**
 * @file ptc_pipeline.hpp
 * @author Marek Sedlacek
 * @brief Pipeline for IR analysis and transforms
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _PTC_PIPELINE_HPP_
#define _PTC_PIPELINE_HPP_

#include "logging.hpp"
#include "ir.hpp"

namespace ptc {

class PTCPipeline {
private:
    Diagnostics &diags;
public:
    PTCPipeline(Diagnostics &diags);

    void run(ir::ModuleDecl *mod);
};

}

#endif//_PTC_PIPELINE_HPP_