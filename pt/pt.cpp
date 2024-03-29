/**
 * @file pt.cpp
 * @author Marek Sedlacek
 * @brief proto-typed - pt
 * 
 * @copyright Copyright (c) 2024
 * Manager for proto-typed compilations and executions.
 */

#include "pt.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>

/** Data needed for compilation */
struct CompileInfo {
    std::string pt_path = "pt";
    std::string ptc_path = "ptc";
    std::string cc_path = "cc";
    std::string lib_path = "/lib/ptc";
    std::string out_path = ".";
    std::string out_bin = "";
};

/** Debug print for CompileInfo */
std::ostream& operator<< (std::ostream& stream, const CompileInfo& ci) {
    stream << "Compile info:";
    stream << "\n  - pt_path: " << ci.pt_path;
    stream << "\n  - ptc_path: " << ci.ptc_path;
    stream << "\n  - cc_path: " << ci.cc_path;
    stream << "\n  - lib_path: " << ci.lib_path;
    stream << "\n  - out_path: " << ci.out_path;
    stream << "\n  - out_bin: " << ci.out_bin;
    stream << "\n";
    return stream;
}

/** Prints help information */
void print_help() {
    std::cout << 
R"(OVERVIEW: Proto-typed
USAGE: pt [pt options] [command] [ptc options]

COMMANDS:
  build [source files] [ptc options]                                    Builds an executable from given sources
  run   [source files] [ptc options] [-- [program options]]             Builds and runs an executable from given sources
  see   [source files] [ptc options] [-- [program options]]             Builds, runs and then deletes an executable from given sources

OPTIONS:
  -o <binary name>                                                      Output binary path
  --help, -h                                                            Display pt and ptc options
  --version                                                             Display ptc version
  --pt-version                                                          Display pt version
  --ptc-path=<path to ptc>                                              Sets command to use to execute ptc
  --cc-path=<path to C compiler>                                        Sets command to use to link object files and clib
  --gc-path=<path to GC library>                                        Sets garbage collector path for linking
  --out-dir=<path to out directory>                                     Directory for building artifacts
)";
}

/**
 * Prints error message and exits with failure.
 * @param msg Message to print
 */
[[noreturn]] void report_error(std::string msg) {
    std::cerr << "pt: " << msg << "\n";
    exit(1);
}

/**
 * Prints error with unknown option and exits with failure.
 * @param ci Compile Info for pt_path
 * @param opt Unknown option
 */
[[noreturn]] void report_unknown_opt(CompileInfo ci, std::string opt) {
    report_error("Unknown command line argument '" + opt + "'. Try: '" + ci.pt_path + " --help'");
}

/**
 * Checks if argument prefix matches expected one.
 * @param arg Argument to check
 * @param check Expected prefix
 */
bool is_opt(std::string arg, std::string check) {
    if(arg.length() >= check.length() && arg.substr(0, check.length()) == check) {
        return true;
    }
    return false;
}

/**
 * Check correctness of --arg=<value> options
 * @param ci Compile info so that report error can be used
 * @param arg Argument to check
 * @param check Expected value (with length already checked)
 * @param example Example of what the value could be set to
 */
void parse_set_opt(CompileInfo ci, std::string arg, std::string check, std::string example) {
    if(arg.length() == check.length() || (arg.length() == check.length()+1 && (arg[check.length()] == '=' || std::isspace(arg[check.length()])))) {
        report_error("Option "+check+" has to be set. E.g.: '"+example+"'");
    }
    if(arg[check.length()] != '=') {
        report_unknown_opt(ci, arg);
    }
}

/**
 * Runs ptc for compilation with specified args
 * then links it using cc.
 * @param ci Compilation information
 * @param args ptc arguments
 */
int run_ptc(CompileInfo ci, std::vector<std::string> args) {
    std::stringstream cmd;
    cmd << ci.ptc_path;

    bool filetype_set = false;
    bool realloc_model_set = false;
    for(auto a: args) {
        if (is_opt(a, "-filetype=")) 
            filetype_set = true;
        else if (is_opt(a, "-relocation-model="))
            realloc_model_set = true;
        cmd << " " << a;
    }
    
    if(!filetype_set)
        cmd << " " << "-filetype=obj";
    if(!realloc_model_set)
        cmd << " " << "-relocation-model=pic";

    // Linking with cc
    // gc
    cmd << " && " << ci.cc_path << " -L" << ci.lib_path << "/gc";
    // libpt
    cmd << " " << ci.lib_path << "/std/libptl.o "; // libpt.o is located with other .o files
    // All the .o files
    cmd << " " << ci.out_path << "/*.pto.o";  // TODO: Change this to use specified files if multiple files passed in by the user.
    // Set output binary
    cmd << " -o " << ci.out_bin;
    // Libs
    cmd << " -lgc -lm";
    // Remove artifacts
    cmd << " && rm -f " << ci.out_path << "/*.pto.o";

    return std::system(cmd.str().c_str());
}

// pt main.
int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    CompileInfo compile_info;
    compile_info.pt_path = std::string(argv[0]);

    for(int arg_i = 1; arg_i < argc; ++arg_i) {
        std::string arg = std::string(argv[arg_i]);
        if (arg == "build") {
            if (arg_i == argc-1) {
                report_error("Command 'build' requires source file(s) to compile");
            }
            std::vector<std::string> ptc_args;
            std::string out_bin_name = "";
            for (int i = arg_i+1; i < argc; ++i) {
                if(out_bin_name.empty() && argv[i][0] != '-') {
                    out_bin_name = argv[i];
                }
                ptc_args.push_back(argv[i]);
            }
            if(compile_info.out_bin.empty()) {
                compile_info.out_bin = std::filesystem::path(out_bin_name).stem();
            }

            auto status = run_ptc(compile_info, ptc_args);
            if (status < 0 || WEXITSTATUS(status))
                return 1; // TODO: print error msg?
            return 0;
        }
        else if (arg == "run" || arg == "see") {
            if (arg_i == argc-1 || (std::string(argv[arg_i+1]) == "--" && arg_i+1 == argc-1)) {
                report_error("Command '"+ arg +"' requires source file(s) to compile and run");
            }
            // Additional arguments to the program can be taken after --
            std::vector<std::string> ptc_args;
            std::vector<std::string> program_args;
            bool in_prog_args = false;
            std::string out_bin_name = "";
            for (int i = arg_i+1; i < argc; ++i) {
                if (std::string(argv[i]) == "--" && !in_prog_args) {
                    in_prog_args = true;
                    continue;
                }
                if(out_bin_name.empty() && argv[i][0] != '-') {
                    out_bin_name = argv[i];
                }
                if (!in_prog_args) {
                    ptc_args.push_back(argv[i]);
                }
                else {
                    program_args.push_back(argv[i]);
                }
            }

            if(compile_info.out_bin.empty()) {
                compile_info.out_bin = std::filesystem::path(out_bin_name).stem();
            }

            auto status = run_ptc(compile_info, ptc_args);

            // Failure
            if (status < 0 || WEXITSTATUS(status)) {
                return 1; // TODO: print error msg?
            }

            std::stringstream run_cmd;
            if(compile_info.out_bin.length() > 2 && compile_info.out_bin.substr(0, 2) != "./" && compile_info.out_bin[0] != '/') {
                run_cmd << "./";
            }
            run_cmd << compile_info.out_bin;
            for(auto a: program_args) {
                run_cmd << " " << a;
            }
            
            auto ret = std::system(run_cmd.str().c_str());

            if(arg == "see") {
                // Delete binary
                std::system((std::string("rm -f ")+compile_info.out_bin).c_str());
            }

            return WEXITSTATUS(ret);
        }
        else if (arg == "-o") {
            if(arg_i == argc-1) {
                report_error("Option '-o' requires output file path");
            }
            compile_info.out_bin = std::string(argv[arg_i+1]);
            ++arg_i;
            continue;
        }
        else if (arg == "--version") {
            auto status = std::system((compile_info.ptc_path+" --version").c_str());

            // Failure
            if (status < 0 || WEXITSTATUS(status)) {
                return 1; // TODO: print error msg?
            }
            return 0;
        }
        else if (arg == "--pt-version") {
            std::cout << "pt " << PT_VERSION << "\n";
            return 0;
        }
        else if (arg == "--help" || arg == "-h") {
            print_help();
            std::cout << std::endl;
            auto status = std::system((compile_info.ptc_path+" --help").c_str());

            // Failure
            if (status < 0 || WEXITSTATUS(status)) {
                return 1; // TODO: print error msg?
            }
            return 0;
        }
        else if (arg.length() >= 10 && arg.substr(0, 10) == "--ptc-path" ) {
            parse_set_opt(compile_info, arg, "--ptc-path", "--ptc-path=/usr/bin/ptc");
            compile_info.ptc_path = arg.substr(11);
        }
        else if (arg.length() >= 9 && arg.substr(0, 9) == "--cc-path" ) {
            parse_set_opt(compile_info, arg, "--cc-path", "--cc-path=/usr/bin/clang");
            compile_info.cc_path = arg.substr(10);
        }
        else if (arg.length() >= 10 && arg.substr(0, 10) == "--lib-path" ) {
            parse_set_opt(compile_info, arg, "--lib-path", "--lib-path=/usr/lib/ptc");
            compile_info.lib_path = arg.substr(11);
        }
        else if (arg.length() >= 9 && arg.substr(0, 9) == "--out-dir" ) {
            parse_set_opt(compile_info, arg, "--out-dir", "--out-dir=/tmp");
            compile_info.out_path = arg.substr(10);
        }
        else {
            report_unknown_opt(compile_info, arg);
        }
    }

    return 0;
}