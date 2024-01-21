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
#include <string>
#include <vector>

/**
 * Prints help information
 */
void print_help() {
    std::cout << 
R"(OVERVIEW: Proto-typed
USAGE: pt [command | option]

COMMANDS:
  build [source files] [ptc options]                                    Builds an executable from given sources
  run   [source files] [ptc options] [-- [program options]]             Builds and runs an executable from given sources

OPTIONS:
  --help, -h                                                            Display pt and ptc options
  --version                                                             Display ptc version
  --pt-version                                                          Display pt version
)";
// TODO: Call ptc with --help
}

/**
 * Prints error message and exits with error.
 */
[[noreturn]] void report_error(std::string msg) {
    std::cerr << "pt: " << msg << "\n";
    exit(1);
}

// pt main.
int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    std::string pt_path = std::string(argv[0]);

    for(int arg_i = 1; arg_i < argc; ++arg_i) {
        std::string arg = std::string(argv[arg_i]);
        if (arg == "build") {
            if (arg_i == argc-1) {
                report_error("Command 'build' requires source file(s) to compile");
            }
            std::vector<char *> ptc_args;
            for (int i = 2; i < argc; ++i) {
                ptc_args.push_back(argv[i]);
            }

            return 0;
        }
        else if (arg == "run") {
            if (arg_i == argc-1 || (std::string(argv[arg_i+1]) == "--" && arg_i+1 == argc-1)) {
                report_error("Command 'run' requires source file(s) to compile and run");
            }
            // Additional arguments to the program can be taken after --
            std::vector<char *> ptc_args;
            std::vector<char *> program_args;
            bool in_prog_args = false;
            for (int i = arg_i+1; i < argc; ++i) {
                if (std::string(argv[i]) == "--" && !in_prog_args) {
                    in_prog_args = true;
                    continue;
                }
                if (!in_prog_args) {
                    ptc_args.push_back(argv[i]);
                }
                else {
                    program_args.push_back(argv[i]);
                }
            }

            return 0;
        }
        else if (arg == "--version") {
            return 0;
        }
        else if (arg == "--pt-version") {
            std::cout << "pt " << PT_VERSION << "\n";
            return 0;
        }
        else if (arg == "--help" || arg == "-h") {
            print_help();
            return 0;
        }
        else {
            report_error("Unknown command line argument '" + arg + "'. Try: '" + pt_path + " --help'");
        }
    }

    return 0;
}