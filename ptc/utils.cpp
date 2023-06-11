#include "utils.hpp"

using namespace ptc;

template<typename T>
bool utils::isOneOf(T v, std::initializer_list<T> accepted) {
    return std::find(begin(accepted), end(accepted), v) != std::end(accepted);
}
bool utils::isOneOf(llvm::StringRef v, std::initializer_list<std::string> accepted) {
    return std::find(begin(accepted), end(accepted), v.str().c_str()) != std::end(accepted);
}