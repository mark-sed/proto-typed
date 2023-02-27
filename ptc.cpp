/**
 * @file ptc.cpp
 * @author Marek Sedlacek
 * @brief Proto-typed compiler entry point
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) Marek Sedlacek, 2023
 */

#include <iostream>
#include <sstream>
#include <string>
#include "ptc.hpp"
#include "scanner.hpp"

using namespace ptc;

int main(int argc, char *argv[]) {

    auto scanner = new Scanner();
    auto code = &std::cin;
    if(argc > 1) {
        std::istringstream cdss(argv[1]);
        code = &cdss;
    }

    scanner->parse(code);

    return 0;
}