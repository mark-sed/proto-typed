#include "error.hpp"

using namespace ptc;

void err::error(std::string msg) {
    llvm::outs() << "ERROR: " << msg << "\n";
}