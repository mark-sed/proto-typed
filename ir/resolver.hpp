#ifndef _RESOLVER_HPP_
#define _RESOLVER_HPP_

#include "ir.hpp"
#include "logging.hpp"
#include "scope.hpp"
#include "llvm/Support/SMLoc.h"

namespace ptc {

class UnresolvedSymbolResolver {
private:
    ir::ModuleDecl *mod;
    Scope *globalScope;
    Diagnostics &diags;

    void resolve(std::vector<ir::IR *> body);
    void resolve(ir::Expr * expr, llvm::SMLoc loc);

public:
    UnresolvedSymbolResolver(ir::ModuleDecl *mod, Scope *globalScope, Diagnostics &diags) 
        : mod(mod), globalScope(globalScope), diags(diags) {}

    void run();
};

class FunctionAnalyzer {
private:
    ir::FunctionDecl *fun;
    Diagnostics &diags;

    void checkReturnType(std::vector<ir::IR *> decls, int *num_found, int *nested_ret, ir::TypeDecl * expected);
public:
    FunctionAnalyzer(ir::FunctionDecl *fun, Diagnostics &diags)
        : fun(fun), diags(diags) {}

    void checkReturns();
    void run();
};

}

#endif//_RESOLVER_HPP_