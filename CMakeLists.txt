cmake_minimum_required(VERSION 3.8)

# Setup project, languages and standards
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(ptc)
    #set(CMAKE_CXX_STANDARD 17)

    #if(NOT CMAKE_BUILD_TYPE)
    #set(CMAKE_BUILD_TYPE Release)
    #endif()

    #set(CMAKE_CXX_FLAGS_DEBUG "-O3 -g -DDEVELOPER")
    #set(CMAKE_CXX_FLAGS_RELEASE "-O3")

    # LLVM

  find_package(LLVM REQUIRED HINTS "${LLVM_CMAKE_PATH}")
  list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

  #include(ChooseMSVCCRT) # For Windows only
  include(AddLLVM)
  include(HandleLLVMOptions)

  include_directories("${LLVM_BINARY_DIR}/include" "${LLVM_INCLUDE_DIR}")
  link_directories("${LLVM_LIBRARY_DIR}")

  set(PTC_BUILT_STANDALONE 1)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "In-source builds are not allowed. ")
endif()

include(AddPtc)

# Includes for headers
include_directories(BEFORE
    ${CMAKE_CURRENT_BINARY_DIR}/frontend
    ${CMAKE_CURRENT_SOURCE_DIR}/frontend
    ${CMAKE_CURRENT_BINARY_DIR}/ptc
    ${CMAKE_CURRENT_SOURCE_DIR}/ptc
)

add_subdirectory(frontend)
add_subdirectory(ptc)

# Source files excluding main
#set(SOURCES 
    #frontend/scanner.cpp
    #frontend/lexer.cpp
    #frontend/parser.cpp
    #error.cpp
#)

# Targets
# ebe target
#add_executable(
#    ${PROJECT_NAME}
#    ptc.cpp
#    ${SOURCES}
#)
#target_link_libraries(${PROJECT_NAME} m)

#if(CMAKE_BUILD_TYPE STREQUAL "Debug")

    # Rebuilding lexer and parser when files don't exist and flex and bison are present
#    find_package(BISON REQUIRED)
#    find_package(FLEX REQUIRED)
#    if(BISON_FOUND)
#            if(FLEX_FOUND)
#                bison_target(parser ${CMAKE_CURRENT_SOURCE_DIR}/frontend/parser.yy ${CMAKE_CURRENT_SOURCE_DIR}/frontend/parser.cpp)
#                flex_target(lexer ${CMAKE_CURRENT_SOURCE_DIR}/frontend/lexer.ll ${CMAKE_CURRENT_SOURCE_DIR}/frontend/lexer.cpp COMPILE_FLAGS "--header-file=frontend/lexer.hpp")
#                ADD_FLEX_BISON_DEPENDENCY(lexer parser)
#            endif(FLEX_FOUND)
#    endif (BISON_FOUND)

#endif(CMAKE_BUILD_TYPE STREQUAL "Debug")