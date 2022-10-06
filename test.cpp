#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"

// add includes


TEST_CASE("Check that DSList works", "[DSList]")
{
    // add test cases (create lists and specify what the expected output is)
    DSList l = new DSList();
    CHECK(0 + 1 == 1);
    // This creates an error
    CHECK(0 == 1);
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 