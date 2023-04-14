/**
 * @file ptc.cpp
 * @author Marek Sedlacek
 * @brief Proto-typed compiler entry point
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) Marek Sedlacek, 2023
 */
#include "ptc.hpp"
#include "scanner.hpp"
#include "logging.hpp"
#include "llvm/Support/InitLLVM.h"
#include <string>
#include <sstream>

using namespace ptc;

int main(int argc, char *argv[]) {
    llvm::InitLLVM LLVMX(argc, argv);

    log::Logger::get().set_disable(false);
    log::Logger::get().set_log_everything(true);
    log::Logger::get().set_logging_level(MAX_LOGGING_LEVEL);

    auto scanner = new Scanner();
    auto code = &std::cin;
    if(argc > 1) {
        std::istringstream cdss(argv[1]);
        code = &cdss;
    }

    scanner->parse(code);

    return 0;
}