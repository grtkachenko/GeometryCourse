#pragma once

#include <gmpxx.h>

namespace primitives
{

template <class Scalar> struct vector_2t;

typedef vector_2t<double>       vector_2;
typedef vector_2t<mpq_class>    vector_2r;
typedef vector_2t<int>          vector_2i;

template <class Scalar>
struct vector_2t
{
    Scalar x, y;

    vector_2t(Scalar x, Scalar y)
        : x(x)
        , y(y)
    {}

    vector_2t()
        : x(0)
        , y(0)
    {}
};

template <class Scalar>
vector_2t<Scalar> operator + (vector_2t<Scalar> const &v1, vector_2t<Scalar> const &v2)
{   
    return vector_2t<Scalar>(v1.x + v2.x, v1.y + v2.y);
}

template <class Scalar>
vector_2t<Scalar> operator - (vector_2t<Scalar> const &v1, vector_2t<Scalar> const &v2)
{
    return vector_2t<Scalar>(v1.x - v2.x, v1.y - v2.y);
}

template <class Scalar>
Scalar operator ^ (vector_2t<Scalar> const &v1, vector_2t<Scalar> const &v2)
{
    return v1.x * v2.y - v2.x * v1.y;
}

template <class Scalar>
Scalar operator * (vector_2t<Scalar> const &v1, vector_2t<Scalar> const &v2)
{
    return v1.x * v1.x + v1.y * v1.y;
}

template <class Scalar>
vector_2t<Scalar> const operator - (vector_2t<Scalar> const &v)
{
    return vector_2t<Scalar>(-v.x, -v.y);
}

} // namespace primitives
