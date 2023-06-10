/**
 * @file ir.cpp
 * @author Marek Sedlacek
 * @brief IR handling and code representation
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ir.hpp"

using namespace ptc;

std::string ir::block2String(std::vector<ir::IR *> block) {
    std::stringstream ss;
    for(auto i : block) {
        ss << i->debug() << std::endl;
    }
    return ss.str();
}

std::string ir::block2String(std::vector<ir::Expr *> block) {
    std::stringstream ss;
    for(auto i : block) {
        ss << i->debug() << std::endl;
    }
    return ss.str();
}