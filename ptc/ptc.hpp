/**
 * @file ptc.hpp
 * @author Marek Sedlacek
 * @brief Proto-typed compiler entry point
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _PTC_HPP_
#define _PTC_HPP_

#include "scanner.hpp"
#include <vector>
#include <string>

#define MACRO_TO_STR_HELPER(x) #x
/** Macro to convert INT macro value into string value */
#define MACRO_TO_STR(x) MACRO_TO_STR_HELPER(x)

#define PTC_VERSION_MAJOR 0  ///< Compiler's major version
#define PTC_VERSION_MINOR 7  ///< Compiler's minor version
#define PTC_VERSION_PATCH 0  ///< Compiler's patch

/** PTC version as a string */
#define PTC_VERSION MACRO_TO_STR(PTC_VERSION_MAJOR) "." MACRO_TO_STR(PTC_VERSION_MINOR) "." MACRO_TO_STR(PTC_VERSION_PATCH)

namespace ptc {

class ModuleInfo {
private:
    std::string name;
    std::string path;
    Scanner *scanner;
    bool parsed;
    bool mainMod;
    bool lib;
public:
    ModuleInfo(std::string name, bool pathSent=false);
    ~ModuleInfo() {
        if(scanner)
            delete scanner;
    }

    std::string getPath() { return path; }
    std::string getName() { return name; }
    void setMainMod(bool m) { this->mainMod = m; } 
    bool isMainMod() { return mainMod; }
    Scanner *getScanner() { return scanner; }
    ir::ModuleDecl *getModule() { return scanner->mainModule; }
    void setScanner(Scanner *s) { scanner = s; }
    bool isParsed() { return parsed; }
    void setParsed(bool p) { parsed = p; }
    void setLib(bool l) { lib = l; }
    bool isLib() { return lib; }
};

extern std::vector<ModuleInfo *> modulesToCompile;

void addModuleToCompile(std::string name, bool isMainMod=false);

}

#endif//_PTC_HPP_