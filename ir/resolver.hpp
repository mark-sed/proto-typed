/**
 * @file resolver.hpp
 * @author Marek Sedlacek
 * @brief Resolver for analysis that cannot be done in scanner
 * 
 * @copyright Copyright (c) 2023
 * Resolves types and does additional analysis that can be done
 * only after the whole IR is generated.
 */

#ifndef _RESOLVER_HPP_
#define _RESOLVER_HPP_

#include "ir.hpp"
#include "logging.hpp"
#include "scope.hpp"
#include "scanner.hpp"
#include "llvm/Support/SMLoc.h"

namespace ptc {

/**
 * Class for resolving unknown types (unresolved symbols)
 */
class UnresolvedSymbolResolver {
private:
    ir::ModuleDecl *mod;
    Scope *globalScope;
    Diagnostics &diags;
    Scanner *scanner;

    /**
     * Runs analysis on a list of statements
     * @param body list of statements 
     */
    void resolve(std::vector<ir::IR *> body);
    /**
     * Runs analysis on specific expression
     * @param expr Expression to resolve
     * @param loc Location information for expr
     */
    void resolve(ir::Expr * expr, llvm::SMLoc loc);

public:
    /**
     * @param mod Module declaration
     * @param globalScope Module's global scope
     * @param diags Diagnostics for error reporting
     * @param scanner Scanner which did the module parsing
     */
    UnresolvedSymbolResolver(ir::ModuleDecl *mod, Scope *globalScope, Diagnostics &diags, Scanner *scanner) 
        : mod(mod), globalScope(globalScope), diags(diags), scanner(scanner) {}

    /**
     * Runs all the resolver pipeline
     */
    void run();
};

/**
 * Does function analysis
 */
class FunctionAnalyzer {
private:
    ir::FunctionDecl *fun;
    Diagnostics &diags;

    void checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected);
public:
    /**
     * @param fun Function to analyse
     * @param diags Diagnostics for reporting errors
     */
    FunctionAnalyzer(ir::FunctionDecl *fun, Diagnostics &diags)
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

#endif//_RESOLVER_HPP_