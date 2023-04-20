/**
 * @file scope.cpp
 * @author Marek Sedlacek
 * @brief Symbol scope
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "scope.hpp"

using namespace ptc;

bool Scope::insert(ir::IR *decl) {
    return symbols.insert(std::pair<llvm::StringRef, ir::IR*>(
        decl->getName(), decl
    )).second;
}

ir::IR *Scope::lookup(llvm::StringRef name) {
    Scope *s = this;
    while(s) {
        auto i = s->symbols.find(name);
        if(i != s->symbols.end()) {
            return i->second;
        }
        s = s->getParent();
    }
    return nullptr;
}