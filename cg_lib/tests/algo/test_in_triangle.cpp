#include <vector>
 
#define BOOST_TEST_MODULE testTriangle
#include <boost/test/unit_test.hpp>

#include "algo/is_in_triangle.h"


BOOST_AUTO_TEST_CASE(testTriangle1)
{

    point_2t<double> a(0, 0), b(0.5, 0.5), c(0, 1), d(1, 0);
    cg::triangle_2t<double> tr(a, d, c);

    BOOST_CHECK_EQUAL(cg::is_in_triangle(tr, b), true);
}

BOOST_AUTO_TEST_CASE(testTriangle2)
{
    point_2t<double> a(0, 0), b(0, 0.5), c(0, 1), d(1, 0);
    cg::triangle_2t<double> tr(a, d, c);

    BOOST_CHECK_EQUAL(cg::is_in_triangle(tr, b), true);
}

BOOST_AUTO_TEST_CASE(testTriangle3)
{
    point_2t<double> a(0, 0), b(1.5, 0.5), c(0, 1), d(1, 0);
    cg::triangle_2t<double> tr(a, d, c);

    BOOST_CHECK_EQUAL(cg::is_in_triangle(tr, b), false);
}
