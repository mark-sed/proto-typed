cmake_minimum_required(VERSION 3.8)

# Setup project, languages and standards
project(ptc)
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O3 -g -DDEVELOPER")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Includes for headers
include_directories(.)
include_directories(frontend)

# Source files excluding main
set(SOURCES 
    frontend/scanner.cpp
    frontend/lexer.cpp
    frontend/parser.cpp
)

# Targets
# ebe target
add_executable(
    ${PROJECT_NAME}
    ptc.cpp
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME} m)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")

    # Rebuilding lexer and parser when files don't exist and flex and bison are present
    find_package(BISON REQUIRED)
    find_package(FLEX REQUIRED)
    if(BISON_FOUND)
            if(FLEX_FOUND)
                bison_target(parser ${CMAKE_CURRENT_SOURCE_DIR}/frontend/parser.yy ${CMAKE_CURRENT_SOURCE_DIR}/frontend/parser.cpp)
                flex_target(lexer ${CMAKE_CURRENT_SOURCE_DIR}/frontend/lexer.ll ${CMAKE_CURRENT_SOURCE_DIR}/frontend/lexer.cpp COMPILE_FLAGS "--header-file=frontend/lexer.hpp")
                ADD_FLEX_BISON_DEPENDENCY(lexer parser)
            endif(FLEX_FOUND)
    endif (BISON_FOUND)

endif(CMAKE_BUILD_TYPE STREQUAL "Debug")