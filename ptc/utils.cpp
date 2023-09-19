/**
 * @file utils.cpp
 * @author Marek Sedlacek
 * @brief Helper functions
 * 
 * @copyright Copyright (c) 2023
 * General helper functions
 */

#include "utils.hpp"
#include "llvm/IR/Value.h"

using namespace ptc;

template<typename T>
bool utils::isOneOf(T v, std::initializer_list<T> accepted) {
    return std::find(begin(accepted), end(accepted), v) != std::end(accepted);
}
bool utils::isOneOf(llvm::StringRef v, std::initializer_list<std::string> accepted) {
    return std::find(begin(accepted), end(accepted), v.str().c_str()) != std::end(accepted);
}
bool utils::isOneOf(llvm::Type *v, std::initializer_list<llvm::Type *> accepted) {
    return std::find(begin(accepted), end(accepted), v) != std::end(accepted);
}