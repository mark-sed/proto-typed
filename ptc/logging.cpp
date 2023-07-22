/**
 * @file logging.cpp
 * @author Marek Sedlacek
 * @brief Logging and reporting for ptc
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "logging.hpp"
#include <iostream>

using namespace ptc;

void log::error(std::string msg) {
    llvm::outs() << "ERROR: " << msg << "\n";
    Logger::get().add_error();
}

using namespace ptc::log;

BaseLogger::BaseLogger() : disable(false), log_everything(false), logging_level{0} {

}

BaseLogger::~BaseLogger() {
    for(auto s: streams){
        s->flush();
    }
}

Logger::Logger() : BaseLogger(), error_num(0) {
    streams.push_back(&std::cerr);
}

Logger::~Logger() {
    
}

Logger &Logger::get() {
    static Logger instance;
    return instance;
}

void Logger::debug(unsigned level, const std::string &file_func, const std::string &message) {
    if (disable || level > logging_level) {
        return;
    }
    // Check if function has logging enabled
    if (!log_everything) {
        if(enabled.find(file_func) == enabled.end()){
            return;
        }
    }
    // Output log to all registered streams
    for (auto s: streams) {
        (*s) << std::boolalpha << file_func << ": " << message << std::endl;
    }
}

namespace {

const char *diagnosticText[] = {
#define DIAG(id, level, msg) msg,
#include "diagnostics.def"
};

llvm::SourceMgr::DiagKind diagnosticKind[] = {
#define DIAG(id, level, msg) llvm::SourceMgr::DK_##level,
#include "diagnostics.def"
};

}

const char *Diagnostics::getDiagnosticText(unsigned diagID) {
  return diagnosticText[diagID];
}

llvm::SourceMgr::DiagKind Diagnostics::getDiagnosticKind(unsigned diagID) {
  return diagnosticKind[diagID];
}