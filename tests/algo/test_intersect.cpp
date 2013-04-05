#include <vector>
 
#define BOOST_TEST_MODULE testIntersect
#include <boost/test/unit_test.hpp>

#include "algo/intersect.h"

BOOST_AUTO_TEST_CASE(testIntersect1)
{
	std::vector<int> v1 = {10, 20, 30, 40, 50, 53, 70, 2832};
	std::vector<int> v2;
	intersect(v1.begin(), v1.end(), 30, 52, std::back_inserter(v2));
	std::vector<int> ans = {30, 40, 50};
	BOOST_CHECK_EQUAL_COLLECTIONS(v2.begin(), v2.end(), ans.begin(), ans.end());
}