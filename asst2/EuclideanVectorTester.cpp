#include <iostream>

#include "ConstructorTests.h"
#include "ProvidedTests.h"

int main(int argc, char *argv[]) {
    std::cout << "Starting test suite.\n";

    std::cout << "Running provided tests.\n";
    provided_tests();
    std::cout << "Passed provided tests.\n";

    std::cout << "Running constructor tests.\n";
    constructor_tests();
    std::cout << "Passed constructor tests.\n";

    std::cout << "All tests passed.\n";

    return 0;
}
