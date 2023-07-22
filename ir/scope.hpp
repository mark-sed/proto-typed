/**
 * @file scope.hpp
 * @author Marek Sedlacek
 * @brief Symbol scope
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SCOPE_HPP_
#define _SCOPE_HPP_

#include "llvm/ADT/StringMap.h"
#include "llvm/ADT/StringRef.h"
#include "ir.hpp"

namespace ptc {

/**
 * Symbol scope
 */
class Scope {
private:
    Scope *parent;
    llvm::StringMap<ir::IR *> symbols;
    llvm::StringMap<ir::IR *> funs;

public:
    Scope(Scope *parent=nullptr) : parent(parent) {}

    /**
     * Inserts an IR declaration into a scope if it isn't already inside
     * @param decl IR to be inserted
     * @return true if insertion was successful, false otherwise
     */
    bool insert(ir::IR *decl);

    /**
     * @brief Finds a symbol in the scope
     * @param name Symbol to find
     * @return The IR of the symbol or nullptr if not found
     */
    ir::IR *lookup(llvm::StringRef name);

    ir::IR *lookupPossibleFun(llvm::StringRef name);

    /**
     * @return Parent of the current scope 
     */
    Scope *getParent() { return parent; }

    std::string debug() {
        std::string keys;
        for(auto i: symbols.keys()) {
            keys += i;
        }
        return keys;
    }
};

}

#endif//_SCOPE_HPP_