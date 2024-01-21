/**
 * @file pt.cpp
 * @author Marek Sedlacek
 * @brief proto-typed - pt
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2024
 * Manager for proto-typed compilations and executions.
 */

#include "pt.hpp"
#include <iostream>

void print_help() {
    std::cout << 
R"(OVERVIEW: Proto-typed
USAGE: pt [options] [ptc options]

OPTIONS:
  --help, -h                                                            Display pt and ptc options
  --pt-version                                                          Display pt version
)";

// TODO: Call ptc with --help
}


int main(int argc, char* argv[]) {
    if(argc < 2) {
        print_help();
        return 1;
    }
    return 0;
}