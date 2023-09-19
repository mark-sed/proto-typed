/**
 * @file utils.hpp
 * @author Marek Sedlacek
 * @brief Helper functions
 * 
 * @copyright Copyright (c) 2023
 * General helper functions
 */

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "llvm/ADT/StringRef.h"
#include "llvm/IR/Value.h"
#include <cstring>
#include <initializer_list>
#include <algorithm>

namespace ptc {
namespace utils {

/**
 * @param v Value to check if is in accepted
 * @param accepted Accepted values
 * @return true if v is in accepted
 * @return false if v is not in accepted
 */
template<typename T>
bool isOneOf(T v, std::initializer_list<T> accepted);
template<typename T>
bool isOneOf(T *v, std::initializer_list<T *> accepted);
bool isOneOf(llvm::StringRef v, std::initializer_list<std::string> accepted);
bool isOneOf(llvm::Type *v, std::initializer_list<llvm::Type *> accepted);

}
}

#endif//_UTILS_HPP_