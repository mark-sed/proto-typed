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
#include "ptc.hpp"

namespace ptc {

class PTCPipeline {
private:
    Diagnostics &diags;
public:
    PTCPipeline(Diagnostics &diags);

    void run(ModuleInfo *modi);
};

}

#endif//_PTC_PIPELINE_HPP_