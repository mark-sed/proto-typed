/**
 * @file scope.cpp
 * @author Marek Sedlacek
 * @brief Symbol scope
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "scope.hpp"
#include "ir.hpp"
#include "llvm/Support/Casting.h"
#include <vector>

using namespace ptc;

bool Scope::insert(ir::IR *decl) {
    if(auto f = llvm::dyn_cast<ir::FunctionDecl>(decl)) {
        funs.insert(std::pair<llvm::StringRef, ir::IR*>(
            f->getOGName(), decl));
    }
    return symbols.insert(std::pair<llvm::StringRef, ir::IR*>(
        decl->getName(), decl
    )).second;
}

ir::IR *Scope::lookup(llvm::StringRef name, bool isMaybe) {
    Scope *s = this;
    while(s) {
        auto i = s->symbols.find(name);
        if(i != s->symbols.end()) {
            if(isMaybe && llvm::isa<ir::TypeDecl>(i->second)) {
                auto t = llvm::dyn_cast<ir::TypeDecl>(i->second);
                auto mbT = t->clone();
                mbT->setMaybe(true);
                return mbT;
            }
            return i->second;
        }
        s = s->getParent();
    }
    return nullptr;
}

ir::IR *Scope::lookupPossibleFun(llvm::StringRef name) {
    Scope *s = this;
    while(s) {
        auto i = s->funs.find(name);
        if(i != s->funs.end()) {
            return i->second;
        }
        s = s->getParent();
    }
    return nullptr;
}
