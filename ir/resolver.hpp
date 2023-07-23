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
    Diagnostics diags;

    void resolve(std::vector<ir::IR *> body);
    void resolve(ir::Expr * expr, llvm::SMLoc loc);

public:
    UnresolvedSymbolResolver(ir::ModuleDecl *mod, Scope *globalScope, Diagnostics &diags) 
        : mod(mod), globalScope(globalScope), diags(diags) {}

    void run();
};

}

#endif//_RESOLVER_HPP_