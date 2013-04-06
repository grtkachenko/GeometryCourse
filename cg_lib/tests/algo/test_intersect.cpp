#include <vector>
 
#define BOOST_TEST_MODULE testInter
#include <boost/test/unit_test.hpp>


#include "algo/segment_intersect.h"

using namespace std;
using namespace primitives;
using namespace cg;

BOOST_AUTO_TEST_CASE(testIntersect1)
{

    point_2t<double> a(0, 0), b(1, 1), c(0, 1), d(1, 0);
    segment_2t<double> seg1(a, b), seg2(c, d);
    BOOST_CHECK_EQUAL(intersect_segments(seg1, seg2), true);
}

BOOST_AUTO_TEST_CASE(testIntersect2)
{

    point_2t<double> a(0, 0), b(1, 1), c(0, 1), d(1, 0);
    segment_2t<double> seg1(a, c), seg2(b, d);
    BOOST_CHECK_EQUAL(intersect_segments(seg1, seg2), false);
}

BOOST_AUTO_TEST_CASE(testIntersect3)
{

    point_2t<double> a(0, 0), b(1, 1), c(0, 1);
    segment_2t<double> seg1(a, c), seg2(a, b);
    BOOST_CHECK_EQUAL(intersect_segments(seg1, seg2), true);
}

