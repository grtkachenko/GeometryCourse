#pragma once

#include <gmpxx.h>

#include "primitives/vector.h"

namespace primitives
{

template <class Scalar> struct point_2t;

typedef point_2t<double>    point_2;
typedef point_2t<int>       point_2i;
typedef point_2t<mpq_class> point_2r;

template <class Scalar>
struct point_2t
{
    Scalar x, y;

    point_2t(Scalar x, Scalar y)
        : x(x)
        , y(y)
    {}

    point_2t()
        : x(0)
        , y(0)
    {}

    point_2t<Scalar> &operator += (vector_2t<Scalar> const &delta)
    {
        x += delta.x;
        y += delta.y;
        return *this;
    }
};

template <class Scalar>
inline bool operator < (point_2t<Scalar> const &a, point_2t<Scalar> const &b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

template <class Scalar>
bool operator > (point_2t<Scalar> const &a, point_2t<Scalar> const &b)
{
    return b < a;
}

template <class Scalar>
bool operator == (point_2t<Scalar> const &a, point_2t<Scalar> const &b)
{
    return (a.x == b.x) && (a.y == b.y);
}

template <class Scalar>
bool operator != (point_2t<Scalar> const &a, point_2t<Scalar> const &b)
{
    return !(a == b);
}

template <class Scalar>
vector_2t<Scalar> const operator - (point_2t<Scalar> const &a, point_2t<Scalar> const &b)
{
    return vector_2t<Scalar>(a.x - b.x, a.y - b.y);
}

template <class Scalar>
point_2t<Scalar> const operator + (point_2t<Scalar> const &pt, vector_2t<Scalar> const &delta)
{
    return point_2t<Scalar>(pt.x + delta.x, pt.y + delta.y);
}

} // namespace primitives