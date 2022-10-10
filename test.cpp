#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"
using namespace std;

// add includes


TEST_CASE("Check that DSList works", "[DSList]")


{
    // add test cases (create lists and specify what the expected output is)
    SECTION("Constructor") {
        DSList<int> *l = new DSList<int>();
        CHECK(l->getHead() == nullptr);
        CHECK(l->getTail() == nullptr);
        CHECK(l->getSize() == 0);

        // This creates an error
        int i = 5;
        l->push_front(i);
        CHECK(l->getSize() == 1);
        CHECK(l->findNum(5) == 0);
        DSList<int> *l2 = l;
        CHECK(l2->getSize() == 1);
        CHECK(l2->findNum(5) == 0);
        l->~DSList();
        //l2->~DSList();
    }
    SECTION("Pop test") {
        DSList<int> *l2 = new DSList<int>();
        for (int i = 0; i < 3; i++) {
            l2->push_front(i);
        }
        l2->print();
        CHECK(l2->getSize() == 3);
        CHECK(l2->findNum(3) == -1);
        CHECK(l2->findNum(2) == 0);
        CHECK(l2->getTail() != nullptr);

        CHECK(l2->pop_front() == 2);
        CHECK(l2->getSize() == 2);
        l2->pop_val(0);
        CHECK(l2->getSize() == 1);
        CHECK(l2->pop_index(0) == 1);
        CHECK(l2->getSize() == 0);
        l2->print();
    }



}



// you can run the test using Run CTest in the task bar or by running the tests executable. 