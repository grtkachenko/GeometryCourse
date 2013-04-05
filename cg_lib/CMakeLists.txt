include_directories (.)
add_subdirectory (tests)
enable_testing ()

file(GLOB_RECURSE HEADERS "*.h")
add_custom_target(cg_lib_headers SOURCES ${HEADERS})

