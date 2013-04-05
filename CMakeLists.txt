cmake_minimum_required (VERSION 2.8)
project (my_comp_geometry)
set (CMAKE_CXX_FLAGS "-stdlib=libc++ -std=c++11 -Wall -pg")
include_directories (.)
add_subdirectory (cg_lib)
add_subdirectory (first)

enable_testing ()

