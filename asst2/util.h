#ifndef UTIL_H
#define UTIL_H

#include <cmath>
#include <vector>
#include "EuclideanVector.h"

constexpr double eps = 1e-7;

inline bool almost_eq(double a, double b) {
    return ::abs(a - b) < eps;
}

inline void assertEquals(const evec::EuclideanVector& myvec, std::vector<double> values) {
    assert(myvec.getNumDimensions() == values.size());
    for (auto i = 0U; i < values.size(); i++) {
        assert(almost_eq(myvec.get(i), values.at(i)));
    }
}

#endif
