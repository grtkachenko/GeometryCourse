//#pragma once

//#include <cmath>
//#include <ostream>
//#include <limits>

//#include "primitives/point.h"
//#include "primitives/vector.h"
//using namespace primitives;
//enum class sign
//{
//    negative,
//    positive,
//    zero
//};

//inline std::ostream & operator << (std::ostream &os, sign value)
//{
//    switch (value)
//    {
//    case sign::negative : return os << "-";
//    case sign::positive : return os << "+";
//    case sign::zero : return os << "0";
//    default : return os << (int) value;
//    }
//}

//struct turn_r
//{
//    sign operator () (const point_2 &a, const point_2 &b, const point_2 &c)
//    {
//        point_2r ar(a.x, a.y), br(b.x, b.y), cr(c.x, c.y);
//        vector_2r t1 = br - ar;
//        vector_2r t2 = cr - ar;
//        auto res = t1 ^ t2;
//        if (res > 0)
//            return sign::positive;
//        else if (res < 0)
//            return sign::negative;
//        else
//            return sign::zero;
//    }
//};


//struct turn : public turn_r
//{
//    sign operator () (const point_2 &a, const point_2 &b, const point_2 &c)
//    {
//        vector_2 t1 = b - a;
//        vector_2 t2 = c - a;
//        auto res = t1 ^ t2;
//        double eps = (fabs(t1.x * t2.y) + fabs(t1.y * t2.x)) * std::numeric_limits<double>::epsilon() * 8;
//        if (res > eps)
//            return sign::positive;
//        else if (res < -eps)
//            return sign::negative;
//        else
//            return turn_r::operator()(a, b, c);
//    }
//};
