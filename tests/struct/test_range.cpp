#define BOOST_TEST_MODULE testRange
#include <boost/test/unit_test.hpp>

#include "primitives/range.h"

BOOST_AUTO_TEST_CASE(testRange1)
{
    BOOST_CHECK_EQUAL(1, 2);
// TODO: operator == doesn't seem to work :(

/*
    BOOST_CHECK_EQUAL(list.size(), 3);
    BOOST_CHECK_NE(list.find(3), list.end());
    BOOST_CHECK_EQUAL(list.find(11), list.end());
 */
}

// TODO: cover all methods with test