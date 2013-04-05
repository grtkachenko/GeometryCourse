#pragma once
#include <iostream>
#include <vector>
#include "range.h"

template <class CoordType>
class Rect {
private:
    std::vector<Range<CoordType> > data;
public:
    Rect(const std::vector<Range<CoordType> >& data) : data(data) {}
    Rect& operator &= (const Rect<CoordType>& rect) {
        if (rect.data.size() == 0 || rect.data.size() != this->data.size()) {
            std::cout << "Incorrect argument rectangle" << std::endl;
            return *this;
        }
        for (int i = 0; i < data.size(); i++) {
            data[i] &= rect.data[i];
        }
        return *this;
    }

    friend std::ostream& operator << (std::ostream& ofs, const Rect& r) {
        for (auto it = r.data.begin(); it != r.data.end(); it++) {
            ofs << "[" << *it << "]";
            if ((it + 1) != r.data.end()) {
                ofs << ", ";
            }
        }
        return ofs;
    }
};
