#include <cassert>
#include <iostream>

#include "EuclideanVector.h"
#include "util.h"

void constructor_tests() {
    {
        evec::EuclideanVector vec;
        assert(vec.getNumDimensions() == 1);
        assert(vec.get(0) == 0.0);
    }
}
