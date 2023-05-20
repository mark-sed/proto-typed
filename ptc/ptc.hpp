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

#define MACRO_TO_STR_HELPER(x) #x
/** Macro to convert INT macro value into string value */
#define MACRO_TO_STR(x) MACRO_TO_STR_HELPER(x)

#define PTC_VERSION_MAJOR 0  ///< Compiler's major version
#define PTC_VERSION_MINOR 2  ///< Compiler's minor version
#define PTC_VERSION_PATCH 0  ///< Compiler's patch

/** PTC version as a string */
#define PTC_VERSION MACRO_TO_STR(PTC_VERSION_MAJOR) "." MACRO_TO_STR(PTC_VERSION_MINOR) "." MACRO_TO_STR(PTC_VERSION_PATCH)

#endif//_PTC_HPP_