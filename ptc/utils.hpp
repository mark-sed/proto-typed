#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include "llvm/ADT/StringRef.h"
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
bool isOneOf(llvm::StringRef v, std::initializer_list<std::string> accepted);

}
}

#endif//_UTILS_HPP_