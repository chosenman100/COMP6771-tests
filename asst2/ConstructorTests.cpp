#include <cassert>
#include <iostream>
#include <list>

#include "EuclideanVector.h"
#include "util.h"

void constructor_tests() {
    {
        // Default constructor.
        evec::EuclideanVector vec;
        assert(vec.getNumDimensions() == 1);
        assert(vec.get(0) == 0.0);
    }

    {
        // One argument.
        evec::EuclideanVector vec(5U);
        assert(vec.getNumDimensions() == 5);
        assert(vec.get(1) == 0.0);
        assert(vec.get(3) == 0.0);
    }

    {
        // One argument that gets converted.
        evec::EuclideanVector vec(25);
        assert(vec.getNumDimensions() == 25);
        assert(vec.get(24) == 0.0);
        assert(vec.get(0) == 0.0);
    }

    {
        // Two arguments.
        evec::EuclideanVector vec(10U, -1.0);
        assert(vec.getNumDimensions() == 10);
        assert(vec.get(6) == -1.0);
    }

    {
        // Two arguments that get coverted.
        evec::EuclideanVector vec(12, 32);
        assert(vec.getNumDimensions() == 12);
        assert(vec.get(2) == 32.0);
    }

    {
        // A vector of dimension 0.
        evec::EuclideanVector vec(0, 10.0);
        assert(vec.getNumDimensions() == 0);
    }

    {
        // A list iterator.
        std::list<double> l{-2.2, -3.5, 1.0, 0.0};
        evec::EuclideanVector vec{l.begin(), l.end()};
        assert(vec.getNumDimensions() == 4);
        assert(vec.get(0) == -2.2);
        assert(vec.get(1) == -3.5);
        assert(vec.get(2) == 1.0);
        assert(vec.get(3) == 0.0);
    }

    {
        // A const list iterator.
        const std::list<double> l{-1000.0, 0.001, 0.0};
        evec::EuclideanVector vec{l.cbegin(), l.cend()};
        assert(vec.getNumDimensions() == 3);
        assert(vec.get(0) == -1000.0);
        assert(vec.get(1) == 0.001);
        assert(vec.get(2) == 0.0);
    }

    {
        // A vector iterator.
        std::vector<double> l{-2.2, -3.5, 1.0, 0.0};
        evec::EuclideanVector vec{l.begin(), l.end()};
        assert(vec.getNumDimensions() == 4);
        assert(vec.get(0) == -2.2);
        assert(vec.get(1) == -3.5);
        assert(vec.get(2) == 1.0);
        assert(vec.get(3) == 0.0);
    }

    {
        // A const vector iterator.
        const std::vector<double> l{-1000.0, 0.001, 0.0};
        evec::EuclideanVector vec{l.cbegin(), l.cend()};
        assert(vec.getNumDimensions() == 3);
        assert(vec.get(0) == -1000.0);
        assert(vec.get(1) == 0.001);
        assert(vec.get(2) == 0.0);
    }

    {
        // Generic initializer list.
        evec::EuclideanVector vec{23421.32, 1000.0, -0.0001, 1000.0};
        assert(vec.getNumDimensions() == 4);
        assert(vec.get(0) == 23421.32);
        assert(vec.get(1) == 1000.0);
        assert(vec.get(2) == -0.0001);
        assert(vec.get(3) == 1000.0);
    }

    {
        // Initializer list with one element that gets converted.
        evec::EuclideanVector vec{5U};
        assert(vec.getNumDimensions() == 1);
        assert(vec.get(0) == 5.0);
    }

    {
        // Initializer list with two elements that get converted.
        evec::EuclideanVector vec{5, 10};
        assert(vec.getNumDimensions() == 2);
        assert(vec.get(0) == 5.0);
        assert(vec.get(1) == 10.0);
    }

    {
        // Copy constructor.
        evec::EuclideanVector vec1(1000, 12.3);
        evec::EuclideanVector vec2{vec1};
        assert(vec2.getNumDimensions() == 1000);
        assert(vec2.get(0) == 12.3);
        assert(vec2.get(511) == 12.3);
        assert(vec2.get(999) == 12.3);
    }

    {
        // Const copy constructor.
        const evec::EuclideanVector vec1(1000, 12.3);
        evec::EuclideanVector vec2{vec1};
        assert(vec2.getNumDimensions() == 1000);
        assert(vec2.get(0) == 12.3);
        assert(vec2.get(511) == 12.3);
        assert(vec2.get(999) == 12.3);
    }

    {
        // Move constructor.
        evec::EuclideanVector vec1(10000, -1000.1);
        evec::EuclideanVector vec2{std::move(vec1)};
        assert(vec1.getNumDimensions() == 0);
        assert(vec2.getNumDimensions() == 10000);
        assert(vec2.get(0) == -1000.1);
        assert(vec2.get(511) == -1000.1);
        assert(vec2.get(9999) == -1000.1);
    }
}
