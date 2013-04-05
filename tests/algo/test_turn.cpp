#include <random>
#include <ctime>

#define BOOST_TEST_MODULE testTurn
#include <boost/test/unit_test.hpp>

#include "primitives/point.h"
#include "algo/turn.h"

BOOST_AUTO_TEST_CASE(testTurn1)
{
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_real_distribution<double> rnd(0, 1);
    
    turn double_turn;
    turn_r rational_turn;

    for(int TESTS = 10000; TESTS > 0; --TESTS) {
        primitives::point_2 a(rnd(e), rnd(e)), b(rnd(e), rnd(e));
        double t = rnd(e);
        double cx = a.x * t + b.x * (1 - t);
        double cy = a.y * t + b.y * (1 - t);
        
        primitives::point_2 c(cx, cy);
        
        for(int i = 0; i < 10; ++i) {
            if(rnd(e) > 0.5)
                c.x *= 1.0 + std::numeric_limits<double>::epsilon();
            else
                c.x *= 1.0 - std::numeric_limits<double>::epsilon();
            if(rnd(e) > 0.5)
                c.y *= 1.0 + std::numeric_limits<double>::epsilon();
            else
                c.y *= 1.0 - std::numeric_limits<double>::epsilon();

            sign s = double_turn(a, b, c);
            sign r_s = rational_turn(a, b, c);
        
            if( s != r_s )
                BOOST_FAIL(
                "\n(" << a.x << ", " << a.y << ") " << 
                "(" << b.x << ", " << b.y << ") " <<
                "(" << c.x << ", " << c.y << ")\n" <<
                "double orientation : " << s << "\n" <<
                "rational orientation : " << r_s );
        }
    }
}

