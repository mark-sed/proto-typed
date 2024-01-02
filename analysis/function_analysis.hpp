/**
 * @file function_analysis.hpp
 * @author Marek Sedlacek
 * @brief Function analysis and error reporting
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _FUNCTION_ANALYSIS_HPP_
#define _FUNCTION_ANALYSIS_HPP_

#include "ir.hpp"
#include "logging.hpp"

namespace ptc {

/**
 * Does function analysis
 */
class FunctionAnalysis {
private:
    ir::FunctionDecl *fun;
    Diagnostics &diags;

    void countReturns(std::vector<ir::IR *> decls, int *num_found, int *nested_ret);
    void checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected);
public:
    /**
     * @param fun Function to analyse
     * @param diags Diagnostics for reporting errors
     */
    FunctionAnalysis(ir::FunctionDecl *fun, Diagnostics &diags)
        : fun(fun), diags(diags) {}

    /**
     * Checks correctness of returns
     * If all the paths contains return and if their types are correct
     */
    void checkReturns();

    /**
     * Runs the whole function analysis pipeline
     * If used, then there is no need to call specific analysis functions.
     */
    void run();
};

}

#endif//_FUNCTION_ANALYSIS_HPP_