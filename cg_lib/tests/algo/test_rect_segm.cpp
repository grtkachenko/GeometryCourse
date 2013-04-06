#include <vector>
 
#define BOOST_TEST_MODULE testRectSegm
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "algo/rect_segm_inter.h"


BOOST_AUTO_TEST_CASE(testRectSegm1)
{

    point_2t<double> a(1, 1), b(4, 4), c;
    cg::range_t<double> r1(1, 3), r2(2, 4);
    cg::rectangle_2t<double> rect(r1, r2);
    cg::segment_2t<double> seg(a, b);

    BOOST_CHECK_EQUAL(cg::intersect_rect_segm(rect, seg), true);
}

BOOST_AUTO_TEST_CASE(testRectSegm2)
{
    point_2t<double> a(0, 0), b(0.9, 0.9);
    cg::range_t<double> r1(1, 3), r2(2, 4);
    cg::rectangle_2t<double> rect(r1, r2);
    cg::segment_2t<double> seg(a, b);

    BOOST_CHECK_EQUAL(cg::intersect_rect_segm(rect, seg), false);
}
BOOST_AUTO_TEST_CASE(testRectSegm3)
{
    point_2t<double> a(0, 0), b(0.5, 0.5);
    cg::range_t<double> r1(1, 3), r2(2, 4);
    cg::rectangle_2t<double> rect(r1, r2);
    cg::segment_2t<double> seg(a, b);

    BOOST_CHECK_EQUAL(cg::intersect_rect_segm(rect, seg), false);
}

BOOST_AUTO_TEST_CASE(testRectSegm4)
{
    point_2t<double> a(0, 0), b(2, 2);
    cg::range_t<double> r1(1, 3), r2(2, 4);
    cg::rectangle_2t<double> rect(r1, r2);
    cg::segment_2t<double> seg(a, b);

    BOOST_CHECK_EQUAL(cg::intersect_rect_segm(rect, seg), true);
}
