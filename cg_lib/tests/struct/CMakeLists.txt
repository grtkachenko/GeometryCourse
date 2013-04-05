set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)

find_package (Boost COMPONENTS system unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

set (TEST test_skiplist)
add_executable (${TEST} test_skiplist.cpp)
target_link_libraries (${TEST} ${Boost_LIBRARIES})
add_test (${TEST} ${TEST})

set (TEST test_range)
add_executable (${TEST} test_range.cpp)
target_link_libraries (${TEST} ${Boost_LIBRARIES})
add_test (${TEST} ${TEST})

enable_testing ()
