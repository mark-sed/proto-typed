#ifndef _ERROR_HPP_
#define _ERROR_HPP_

#include "llvm/Support/raw_ostream.h"
#include <string>

namespace ptc {
namespace err {

void error(std::string msg);

}
}

#endif//_ERROR_HPP_