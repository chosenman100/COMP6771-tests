#include <iostream>

#include "ConstructorTests.h"
#include "ProvidedTests.h"
#include "MoveCopyOperatorTests.h"
#include "MattTests.h"

int main(int argc, char *argv[]) {
    std::cout << "Starting test suite.\n";

    std::cout << "Running provided tests.\n";
    provided_tests();
    std::cout << "Passed provided tests.\n";

    std::cout << "Running constructor tests.\n";
    constructor_tests();
    std::cout << "Passed constructor tests.\n";

    std::cout << "Running move and copy operator tests.\n";
    movecopyoperator_tests();
    std::cout << "Passed move and copy operator tests.\n";

    std::cout << "Running Matt's tests\n";
    matt_tests();
    std::cout << "Passed Matt's tests\n";

    std::cout << "All tests passed.\n";

    return 0;
}
