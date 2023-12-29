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

#include "ptc.hpp"
#include "ir.hpp"
#include "logging.hpp"
#include "scope.hpp"
#include "scanner.hpp"
#include "llvm/Support/SMLoc.h"
#include <vector>

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

    void resolve(ir::IR *body);
    /**
     * Runs analysis on specific expression
     * @param expr Expression to resolve
     * @param loc Location information for expr
     */
    void resolve(ir::Expr *expr, ir::SourceInfo loc);

    void resolveEmptyArray(ir::Expr *expr, ir::SourceInfo loc, ir::TypeDecl *deductedType);
    void resolveEmptyArrays(ir::Expr *expr, ir::SourceInfo loc);
    void resolveEmptyArrays(ir::IR *body);

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

class ExternalSymbolResolver {
private:
    ModuleInfo *currMod;
    std::vector<ModuleInfo *> allModules;
    Diagnostics &diags;
    Scanner *scanner;

    void resolve(std::vector<ir::IR *> body);
    void resolve(ir::IR *body);
    void resolve(ir::Expr *expr, ir::SourceInfo loc);
    void resolveType(ir::Expr **expr, ir::SourceInfo loc);
    ir::TypeDecl *resolveType(ir::TypeDecl *t, ir::SourceInfo loc);

    ModuleInfo *getModule(std::string name);
public:
    ExternalSymbolResolver(ModuleInfo *currMod, std::vector<ModuleInfo *> allModules, Diagnostics &diags, Scanner *scanner)
        : currMod(currMod), allModules(allModules), diags(diags), scanner(scanner) {}

    void run();
};

}

#endif//_RESOLVER_HPP_