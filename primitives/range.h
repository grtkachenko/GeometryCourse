#pragma once
#include <iostream>
template <class CoordType>
class Range {
private:
    CoordType left;
    CoordType right;
public:
    Range() {}

    Range(CoordType left, CoordType right) {
        this->left = left;
        this->right = right;
    }

    Range& operator &= (const Range& right) {
        if (this->right <= right.left) {
            this->right = this->left;
        } else {
            this->left = std::max(this->left, right.left);
            this->right = std::min(this->right, right.right);
        }

        return *this;
    }
    friend std::ostream& operator << (std::ostream& ofs, const Range& r) {
        ofs << r.left << ", " << r.right;
        return ofs;
    }
};
