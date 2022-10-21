#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"
using namespace std;

// add includes


TEST_CASE("Check that DSList works", "[DSList]")


{
    // add test cases (create lists and specify what the expected output is)
    /*SECTION("Constructor") {
        DSList<int> l = DSList<int>();
        CHECK(l.getHead() == nullptr);
        CHECK(l.getTail() == nullptr);
        CHECK(l.getSize() == 0);

        // This creates an error
        int i = 5;
        l.push_front(i);
        CHECK(l.getHead()->data == 5);
        CHECK(l.getTail()->data == 5);
        CHECK(l.getSize() == 1);
        CHECK(l.findNum(5) == 0);
        CHECK(l.getSize() == 1);
        CHECK(l.findNum(5) == 0);
        CHECK(l.getHead()->data == 5);
        CHECK(l.getTail()->data == 5);
        l.~DSList();
        //l2.~DSList();
    }
    SECTION("Pop test") {
        DSList<int> l2 = DSList<int>();
        for (int i = 0; i < 3; i++) {
            l2.push_front(i);
        }
        l2.print();
        CHECK(l2.getHead()->data == 2);
        CHECK(l2.getTail()->data == 0);
        CHECK(l2.getSize() == 3);
        CHECK(l2.findNum(3) == -1);
        CHECK(l2.findNum(2) == 0);
        CHECK(l2.getTail() != nullptr);

        CHECK(l2.pop_front() == 2);
        l2.print();
        CHECK(l2.getHead()->data == 1);
        CHECK(l2.getSize() == 2);
        l2.pop_val(0);
        l2.print();
        CHECK(l2.getTail()->data == 1);
        CHECK(l2.getSize() == 1);
        CHECK(l2.pop_index(0) == 1);
        CHECK(l2.getSize() == 0);
        CHECK(l2.isEmpty() == true);
        l2.print();
    }*/
    SECTION("More Test"){
        DSList<char> l = DSList<char>();
        l.push_front('A');
        l.print();
        CHECK(l.findNum('A') == 0);
        CHECK(l.getHead()->data == 'A');
        CHECK(l.getTail()->data == 'A');
        l.push_index('B',1);
        l.print();
        CHECK(l.getHead()->data == 'A');
        CHECK(l.getTail()->data == 'B');
        CHECK(l.findNum('B') == 1);
        l.push_back('C');
        l.print();
        CHECK(l.getTail()->data == 'C');
        CHECK(l.getSize() == 3);
        CHECK(l.findNum('C') == 2);
        CHECK(l.pop_back() == 'C');
        CHECK(l.getTail()->data == 'B');
        CHECK(l.getSize() == 2);
        l.print();
        l.pop_back();
        l.pop_back();
        CHECK_THROWS(l.pop_front());
        CHECK_THROWS(l.push_index(2,2));
        l.~DSList();
    }



}



// you can run the test using Run CTest in the task bar or by running the tests executable. 