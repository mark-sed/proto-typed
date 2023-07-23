#include "resolver.hpp"
#include "scanner.hpp"
#include "llvm/Support/Casting.h"

using namespace ptc;

void UnresolvedSymbolResolver::resolve(ir::Expr * expr, llvm::SMLoc loc) {
    if(auto e = llvm::dyn_cast<ir::FunctionCall>(expr)) {
        if(e->isUnresolved()) {
            LOGMAX("Resolving function "+e->getUnresolvedFun()->getName());
            auto name = e->getUnresolvedFun()->getName();
            if(!globalScope->lookupPossibleFun(name)) {
                // Undefined
                diags.report(loc, diag::ERR_UNDEFINED_VAR, name);
            }
            else {
                std::string properName = encodeFunction(name, e->getParams());
                auto propFIR = globalScope->lookup(properName);
                if(!propFIR) {
                    diags.report(loc, diag::ERR_INCORRECT_ARGS, name);
                }
                else {
                    LOGMAX("Resolved function "+name)
                    auto propF = llvm::dyn_cast<ir::FunctionDecl>(propFIR);
                    e->setFun(propF);
                    e->setUnresolved(false);
                    e->setType(propF->getReturnType());
                }
            }
        }
    }
}

void UnresolvedSymbolResolver::resolve(std::vector<ir::IR *> body) {
    for(auto i : body) {
        // Statements to resolve further
        if(auto stmt = llvm::dyn_cast<ir::ReturnStmt>(i)) {
            resolve(stmt->getValue(), stmt->getLocation());
        }
        else if(auto stmt = llvm::dyn_cast<ir::FunctionDecl>(i)) {
            resolve(stmt->getDecl());
        }
        else if(auto stmt = llvm::dyn_cast<ir::ExprStmt>(i)) {
            resolve(stmt->getExpr(), stmt->getLocation());   
        }
    }
}

void UnresolvedSymbolResolver::run() {
    auto decls = mod->getDecls();
    resolve(decls);
}