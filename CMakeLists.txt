cmake_minimum_required(VERSION 3.4.3)

# Setup project, languages and standards
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(ptc)
    set(CMAKE_CXX_STANDARD 17)

    # LLVM
    find_package(LLVM REQUIRED HINTS "${LLVM_CMAKE_PATH}")
    list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})

    message(LLVM_CMAKE_PATH=${LLVM_CMAKE_PATH})
    message(LLVM_CMAKE_PATH=${LLVM_DIR})

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
    ${CMAKE_CURRENT_BINARY_DIR}/ir
    ${CMAKE_CURRENT_SOURCE_DIR}/ir
    ${CMAKE_CURRENT_BINARY_DIR}/ptc
    ${CMAKE_CURRENT_SOURCE_DIR}/ptc
    ${CMAKE_CURRENT_BINARY_DIR}/backend
    ${CMAKE_CURRENT_SOURCE_DIR}/backend
)

add_subdirectory(frontend)
add_subdirectory(ir)
add_subdirectory(ptc)
add_subdirectory(backend)
