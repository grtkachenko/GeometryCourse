#pragma once

#include <iterator>
#include <algorithm>

template < class RangeIterator, class OutIterator >
OutIterator intersect(RangeIterator b, RangeIterator e,
                      typename std::iterator_traits<RangeIterator>::value_type search_b,
                      typename std::iterator_traits<RangeIterator>::value_type search_e,
                      OutIterator out) {
    return std::copy(std::lower_bound(b, e, search_b), std::lower_bound(b, e, search_e), out);
}
