#include <iostream>

#include "constructor_tests.h"

int main(int argc, char *argv[]) {
    std::cout << "Starting test suite.\n";

    std::cout << "Running constructor_tests.cpp\n";
    constructor_tests();
    std::cout << "Passed constructor_tests.cpp\n";

    std::cout << "All tests passed.\n";

    return 0;
}
