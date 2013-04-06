#include <vector>
 
#define BOOST_TEST_MODULE testTriangleSegment
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "algo/segment_triangle_inter.h"
#include "algo/is_in_triangle.h"


BOOST_AUTO_TEST_CASE(testTriangleSegment1)
{

    point_2t<double> a(0, 0), b(1, 0), c(0, 1), d(0.1, 0.1), e(0.2, 0.2);
    cg::triangle_2t<double> tr(a, b, c);
    cg::segment_2t<double> seg(d, e);

    BOOST_CHECK_EQUAL(cg::is_intersect_tr_seg(tr, seg), true);
}

BOOST_AUTO_TEST_CASE(testTriangleSegment2)
{
    point_2t<double> a(0, 0), b(1, 0), c(0, 1), d(0.1, 0.1), e(2, 2);
    cg::triangle_2t<double> tr(a, b, c);
    cg::segment_2t<double> seg(d, e);


    BOOST_CHECK_EQUAL(cg::is_intersect_tr_seg(tr, seg), true);
}

BOOST_AUTO_TEST_CASE(testTriangleSegment3)
{
    point_2t<double> a(0, 0), b(1, 0), c(0, 1), d(3, 3), e(2, 2);
    cg::triangle_2t<double> tr(a, b, c);
    cg::segment_2t<double> seg(d, e);


    BOOST_CHECK_EQUAL(cg::is_intersect_tr_seg(tr, seg), false);
}
