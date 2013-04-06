#pragma once

#include <stdexcept>
#include <boost/lexical_cast.hpp>

#include "cg_lib/primitives/point.h"
using namespace primitives;

namespace cg
{

   template <class Scalar>
   struct triangle_2t
   {
      triangle_2t() {}

      triangle_2t(point_2t<Scalar> const & a, point_2t<Scalar> const & b, point_2t<Scalar> const & c)
         : a(a)
         , b(b)
         , c(c)
      {}

      point_2t<Scalar> const & operator[] (size_t i) const
      {
         switch (i)
         {
         case 0: return a;
         case 1: return b;
         case 2: return c;

         default:
            throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
         }
      }

      point_2t<Scalar> & operator[] (size_t i)
      {
         switch (i)
         {
         case 0: return a;
         case 1: return b;
         case 2: return c;
         default:
            throw std::logic_error("invalid index: " + boost::lexical_cast<std::string>(i));
         }
      }

   private:
      point_2t<Scalar> a, b, c;
   };
}
