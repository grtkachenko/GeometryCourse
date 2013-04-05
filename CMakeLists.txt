cmake_minimum_required (VERSION 2.8)
set (CMAKE_CXX_FLAGS "-stdlib=libc++ -std=c++11 -Wall")
project (geom_library)
include_directories (.)
add_subdirectory (tests)
enable_testing ()

