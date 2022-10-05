#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"

using namespace std;

int main(int argc, char **argv)
{

    cout << "Checker not implemented!" << endl;

    for (int i = 1; i < argc; ++i)
        cout << argv[i] << " - unable to check (this took ... milliseconds)\n";

    cout << "Checking all files took ... milliseconds" << endl;


    // A return code != 0 tells the operating system that there is an issue.
    return 1;
}

// in the terminal type `cd build` and then `./check_brackets test_data/*`