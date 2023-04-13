#ifndef _SCOPE_HPP_
#define _SCOPE_HPP_

#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include "ir.hpp"

namespace ptc {

class Scope {
private:
    Scope *parent;
    llvm::StringMap<ir::IR *> symbols;

public:
    Scope(Scope *parent=nullptr) : parent(parent) {}

    bool insert(ir::IR *decl);
    ir::IR *lookup(llvm::StringRef name);

    Scope *getParent() { return parent; }
};

}

#endif//_SCOPE_HPP_