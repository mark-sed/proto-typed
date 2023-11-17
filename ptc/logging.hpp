/**
 * @file logging.hpp
 * @author Marek Sedlacek
 * @brief Logging and reporting for ptc
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _LOGGING_HPP_
#define _LOGGING_HPP_

#include "parser.hpp"
#include "ir.hpp"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/SMLoc.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include <sstream>
#include <string>
#include <vector>
#include <ostream>
#include <set>
#include <cstring>

namespace ptc {

/**
 * Namespace to guard diagnostics messages
 */
namespace diag {
enum diagmsg{
#define DIAG(id, level, msg) id,
#include "diagnostics.def"
};
}

/**
 * Reporting for errors, warnings and info
 */
class Diagnostics {
    static const char *getDiagnosticText(unsigned diagID);
    static llvm::SourceMgr::DiagKind getDiagnosticKind(unsigned diagID);

    llvm::SourceMgr &srcMgr;
    unsigned numErrors;

public:
    Diagnostics(llvm::SourceMgr &srcMgr) : srcMgr(srcMgr), numErrors(0) {}

    /**
     * @return The number of errors that has occured
     */
    unsigned getNumErrors() { return numErrors; }

    /**
     * Reports an error, warning or note in LLVM style
     * 
     * @tparam Args 
     * @param loc Location where the report occures
     * @param diagID Report ID
     * @param arguments Arguments to fill in report message if needed
     */
    template <typename... Args>
    void report(ir::SourceInfo loc, unsigned diagID, Args &&... arguments) {
        std::string msg = llvm::formatv(getDiagnosticText(diagID),
                      std::forward<Args>(arguments)...).str();
        llvm::SourceMgr::DiagKind kind = getDiagnosticKind(diagID);
        // llvm::SMLoc(), kind, msg
        llvm::SmallVector<std::pair<unsigned, unsigned>, 4> ColRanges;
        ColRanges.push_back(std::make_pair(loc.l_end - loc.l_start,
                                           loc.c_end - loc.l_end));
        auto smdiag = llvm::SMDiagnostic(srcMgr, llvm::SMLoc(), 
                                          loc.filename, loc.l_start,
                                          loc.c_start, kind, msg, 
                                          loc.snippet,
                                          ColRanges);
        srcMgr.PrintMessage(llvm::errs(), smdiag);
        numErrors += (kind == llvm::SourceMgr::DK_Error);
    }
};

/** Logging for debugging */
namespace log {

/**
 * Error message output
 * @warning Use Diagnostics for real error messages
 * @param msg Error message
 */
void error(std::string msg);

/**
 * Base class for all loggers
 */ 
class BaseLogger {
protected:
    bool disable;
    bool log_everything;
    unsigned logging_level;
    std::vector<std::ostream *> streams;
    std::ios_base::fmtflags flags;
public:
    /** Constructor */
    BaseLogger();
    /** 
     * Destructor. 
     * Flushes streams 
     */
    ~BaseLogger();

    /**
     * Setter for disabling
     * @param disable If true, the logger will be disabled
     */
    void set_disable(bool disable) { this->disable=disable; }

    /**
     * Sets logging level to be printed
     * @param level Verbosity level
     */ 
    void set_logging_level(unsigned level) { this->logging_level = level; }

    /**
     * Adds a new initialized ostream to log to
     */ 
    void add_stream(std::ostream *stream) { this->streams.push_back(stream); }

    /**
     * Setter for logging everything
     * @param log_everything new value
     */ 
    void set_log_everything(bool log_everything) { this->log_everything = log_everything; }

    /**
     * Setter for flags
     */
    void set_flags(std::ios_base::fmtflags flags) { this->flags = flags; }

    /**
     * Getter for flags
     */ 
    std::ios_base::fmtflags get_flags() { return flags; }

    /** Getter for log_everything */
    bool is_log_everything() { return this->log_everything; }
};


/**
 * Class for debugging logs
 */ 
class Logger : public BaseLogger {
private:
    std::set<std::string> enabled;
    int error_num;
public:
    /// Default constructor for get instance
    Logger();
    ~Logger();

    /**
     * @return logger instance 
     */ 
    static Logger &get();

    /**
     * Debug logging
     * @param level Verbosity level
     * @param file_func __FILE__ should be passed here or the file name
     * @param message Message to print
     */
    void debug(unsigned level, const std::string &file_func, const std::string &message);

    int get_error_num() { return error_num; }
    void add_error() { error_num += 1; }
    void clear_errors() { error_num = 0; }
    
    /**
     * Set file::functions to output to log
     * @param enabled Set of file::function names
     */
    void set_enabled(std::set<std::string> enabled) { this->enabled = enabled; }
};

}
}

/// Tabs for logging
#define TAB1 "\t"
#define TAB2 TAB1 TAB1
#define TAB3 TAB2 TAB1
#define TAB4 TAB3 TAB1
#define TAB5 TAB4 TAB1

/// Maximum logging level
#ifndef MAX_LOGGING_LEVEL
#define MAX_LOGGING_LEVEL 5
#endif

/// Helper macro to strip file's path
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/// Logging macro
#ifndef DISABLE_LOGGING
    /// @param level Verbosity level
    /// @param message Can be even stream
    #define LOG(level, message) if ((level) <= MAX_LOGGING_LEVEL) { \
        std::stringstream out; \
        out.setf(ptc::log::Logger::get().get_flags()); \
        out << message; \
        ptc::log::Logger::get().debug(level, std::string(__FILENAME__)+std::string("::")+std::string(__func__), out.str()); }
    /// Logs whole container
    #define LOG_CONT(level, message, container) if ((level) <= MAX_LOGGING_LEVEL) { \
        std::stringstream out; \
        out.setf(ptc::log::Logger::get().get_flags()); \
        out << message << std::endl; \
        for(auto v: (container)) { out << TAB1 << v << std::endl; } \
        ptc::log::Logger::get().debug(level, std::string(__FILENAME__)+std::string("::")+std::string(__func__), out.str()); }
    /// Logs container of strings which will be sanitized (removes escape sequences)
    #define LOG_CONT_SANITIZE(level, message, container) if ((level) <= MAX_LOGGING_LEVEL) { \
        std::stringstream out; \
        out.setf(ptc::log::Logger::get().get_flags()); \
        out << message << std::endl; \
        for(auto v: (container)) { out << Utils::sanitize(v) << std::endl; } \
        ptc::log::Logger::get().debug(level, std::string(__FILENAME__)+std::string("::")+std::string(__func__), out.str()); }
#else
    #define LOG(level, message)
    #define LOG_CONT(level, message, container)
    #define LOG_CONT_SANITIZE(level, message, container)
#endif//DISABLE_LOGGING

#define LOG1(message) LOG(1, message)
#define LOG2(message) LOG(2, message)
#define LOG3(message) LOG(3, message)
#define LOG4(message) LOG(4, message)
#define LOG5(message) LOG(5, message)
#define LOGMAX(message) LOG(MAX_LOGGING_LEVEL, message)

#endif//_LOGGING_HPP_