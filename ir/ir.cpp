/**
 * @file ir.cpp
 * @author Marek Sedlacek
 * @brief IR handling and code representation
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * Internal Representation of the code
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

std::string ir::block2List(std::vector<ir::Expr *> block) {
    std::stringstream ss;
    std::string separator = "";
    for(auto i : block) {
        ss << separator << i->debug();
        separator = ",";
    }
    return ss.str();
}

std::string ir::block2List(std::vector<ir::IR *> block) {
    std::stringstream ss;
    std::string separator = "";
    for(auto i : block) {
        ss << separator << i->debug();
        separator = ",";
    }
    return ss.str();
}

std::string ir::block2List(std::vector<ir::FormalParamDecl *> block) {
    std::stringstream ss;
    std::string separator = "";
    for(auto i : block) {
        ss << separator << i->debug();
        separator = ",";
    }
    return ss.str();
}

std::string ir::VarDecl::debug() const {
    if(!initValue)
        return "("+td->debug()+")"+name;
    return "("+td->debug()+")"+name+"="+initValue->debug();
}
