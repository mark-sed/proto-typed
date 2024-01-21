/**
 * @file pt.hpp
 * @author Marek Sedlacek
 * @brief proto-typed - pt
 * 
 * @copyright Copyright (c) 2024
 * Manager for proto-typed compilations and executions.
 */

#ifndef _PT_HPP_
#define _PT_HPP_

#define MACRO_TO_STR_HELPER(x) #x
/** Macro to convert INT macro value into string value */
#define MACRO_TO_STR(x) MACRO_TO_STR_HELPER(x)

#define PT_VERSION_MAJOR 0  ///< Compiler's major version
#define PT_VERSION_MINOR 1  ///< Compiler's minor version
#define PT_VERSION_PATCH 0  ///< Compiler's patch

/** PT version as a string */
#define PT_VERSION MACRO_TO_STR(PT_VERSION_MAJOR) "." MACRO_TO_STR(PT_VERSION_MINOR) "." MACRO_TO_STR(PT_VERSION_PATCH)

#endif//_PT_HPP_