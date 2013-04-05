set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)

find_package (Boost COMPONENTS system unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

set (TEST test_turn)
add_executable (${TEST} test_turn.cpp)
target_link_libraries (${TEST} ${Boost_LIBRARIES} gmp)
add_test (${TEST} ${TEST})

set (TEST test_intersect)
add_executable (${TEST} test_intersect.cpp)
target_link_libraries (${TEST} ${Boost_LIBRARIES})
add_test (${TEST} ${TEST})

enable_testing ()
