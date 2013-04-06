#pragma once

#include <cg_lib/primitives/segment.h>
#include <cg_lib/algo/orientation.h>

namespace cg {

    template <typename T>
    bool intersect_segments(const segment_2t<T> & seg1, const segment_2t<T> & seg2) {

        orientation_t or1 = orientation(seg1[0], seg1[1], seg2[0]);
        orientation_t or2 = orientation(seg1[0], seg1[1], seg2[1]);


        if (or1 + or2 == 0) {
            return seg2[0] >= min_s(seg1) && seg2[0] <= max_s(seg1) || seg2[1] >= min(seg1) && seg2[1] <= max(seg1);
        }

        if (or1 == or2) {
            return false;
        }

        return orientation(seg2[0], seg2[1], seg1[0]) != orientation(seg2[0], seg2[1], seg1[1]);
    }

    template <typename T>
    point_2t<T> min_s(const segment_2t<T> & seg) {
        if (seg[0] < seg[1]) {
            return seg[0];
        }
        return seg[1];
    }
    template <typename T>
    point_2t<T> max_s(const segment_2t<T> & seg) {
        if (seg[0] < seg[1]) {
            return seg[0];
        }
        return seg[1];
    }

}
