#ifndef UTIL_H
#define UTIL_H

#include <cmath>

constexpr double eps = 1e-7;

inline bool almost_eq(double a, double b) {
    return ::abs(a - b) < eps;
}

#endif
