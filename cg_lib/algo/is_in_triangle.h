#pragma once

#include <cg_lib/primitives/segment.h>
#include <cg_lib/algo/orientation.h>
#include <cg_lib/primitives/triangle.h>

namespace cg {

    template <typename T>
    bool is_in_triangle(const triangle_2t<T> & tr, const point_2t<T> & p) {

        orientation_t or1 = orientation(p, tr[0], tr[1]);
        orientation_t or2 = orientation(p, tr[1], tr[2]);
        orientation_t or3 = orientation(p, tr[2], tr[0]);
        return or1 != CG_RIGHT && or2 != CG_RIGHT && or3 != CG_RIGHT;
    }

}
