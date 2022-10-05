#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes


TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)

    REQUIRE(0 + 1 == 1);
    // This creates an error
    REQUIRE(0 == 1);
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 