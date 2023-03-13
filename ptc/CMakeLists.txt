set(LLVM_LINK_COMPONENTS
    Support
)

add_ptc_tool(ptc
  ptc.cpp
  error.cpp
)

target_link_libraries(ptc
    PRIVATE
    ptcFrontend
)