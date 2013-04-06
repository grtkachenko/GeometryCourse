#pragma once

#include <cg_lib/primitives/segment.h>
#include <cg_lib/primitives/rectangle.h>
#include <cg_lib/algo/segment_intersect.h>
#include <cg_lib/algo/orientation.h>

namespace cg {

    template <typename T>
    bool intersect_rect_segm(const rectangle_2t<T>& rect, const segment_2t<T> & seg) {
        if (rect.contains(seg[0]) || rect.contains(seg[1])) {
            return true;
        }

        return cg::intersect_segments(segment_2t<T>(rect.corner(0, 0), rect.corner(0, 1)), seg) ||
               cg::intersect_segments(segment_2t<T>(rect.corner(0, 1), rect.corner(1, 1)), seg) ||
               cg::intersect_segments(segment_2t<T>(rect.corner(1, 1), rect.corner(1, 0)), seg) ||
               cg::intersect_segments(segment_2t<T>(rect.corner(1, 0), rect.corner(0, 0)), seg);
    }


}
