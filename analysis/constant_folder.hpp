/**
 * @file constant_folder.hpp
 * @author Marek Sedlacek
 * @brief Constant folding
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef _CONSTANT_FOLDER_HPP_
#define _CONSTANT_FOLDER_HPP_

#include "logging.hpp"

namespace ptc {

class ConstantFolder {
private:
    ir::ModuleDecl *mod;
    Diagnostics &diags;


public:
    ConstantFolder(ir::ModuleDecl *mod, Diagnostics &diags) : mod(mod), diags(diags) {}
    void run();
};

}

#endif//_CONSTANT_FOLDER_HPP_