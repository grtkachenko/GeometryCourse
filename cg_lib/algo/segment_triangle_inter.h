#pragma once

#include <cg_lib/primitives/segment.h>
#include <cg_lib/algo/orientation.h>
#include <cg_lib/primitives/triangle.h>
#include <cg_lib/algo/is_in_triangle.h>
#include <cg_lib/algo/segment_intersect.h>

namespace cg {

    template <typename T>
    bool is_intersect_tr_seg(const triangle_2t<T> & tr, const segment_2t<T> & seg) {
        if (cg::is_in_triangle(tr, seg[0]) || cg::is_in_triangle(tr, seg[1])) {
            return true;
        }
        return cg::intersect_segments(segment_2t<T>(tr[0], tr[1]), seg) || cg::intersect_segments(segment_2t<T>(tr[1], tr[2]), seg) ||
                cg::intersect_segments(segment_2t<T>(tr[2], tr[0]), seg);
    }

}
