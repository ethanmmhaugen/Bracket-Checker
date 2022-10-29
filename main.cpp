#include <iostream>
#include <algorithm>
#include <fstream>
#include "DSList.h"
#include "DSStack.h"
#include <string>
#include <cstring>
#include "checker.h"
#include "testGenerator.h"

using namespace std;

int main(int argc, char **argv)
{
    string test;
    checker theBoy;
    test = argv[1];

    //the chrono stuff is for time keeping between the two variants
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    // actually running the test
    vector<int> result = theBoy.runListVersion(test);
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_time = end-start;
    //outputting time
    cout << "Time for List Stack was " << elapsed_time.count() << "!!" << endl;



    start = chrono::system_clock::now();

    //running the test for vector version
    vector<int> result2 = theBoy.runVectorVersion(test);


    end = chrono::system_clock::now();
    elapsed_time = end-start;
    cout << "Time for Vector Stack was " << elapsed_time.count() << "!!" << endl;

    //outputting the proper terminal response with the evaluate function
    int code = theBoy.evaluate(result, test);
    if(code == 0){
        return 0;
    }
    return 1;


    // A return code != 0 tells the operating system that there is an issue.

}

// in the terminal type `cd build` and then `./check_brackets test_data/*`