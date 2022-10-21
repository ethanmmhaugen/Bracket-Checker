#include <iostream>
#include <algorithm>

#include "DSList.h"
#include "DSStack.h"

using namespace std;

bool isCorrect(string test, List::DSStack<char>& myStack) {

    for (const char &letter: test) {
        if (letter == '(' || letter == '{' || letter == '[')
            myStack.push(letter);
        if(letter == ')' || letter == '}' || letter == ']'){
            if(myStack.empty()){
                return false;
            }
            else if(letter == ')' && myStack.top() == '('){
                    myStack.pop();
            }else if(letter == '}' && myStack.top() == '{'){
                    myStack.pop();
            }else if(letter == ']' && myStack.top() == '[') {
                myStack.pop();
            }
            else {
                return false;
            }
        }
        cout << myStack.size() << endl;
    }
    if(myStack.empty()){
        return true;
    }
    else{
        return false;
    }

}
int main(int argc, char **argv)
{
    List::DSStack<char> myStack;
    string test = "lijbvwej(wetbrbrst{hrthrs}rstbrsb)rhedyh";



    if (isCorrect(test, myStack)) {
        cout << "your code is bulletproof" << endl;
        return 0;
    } else {
        cout << "She's almost bulletproof" << endl;
        return 1;
    }

    // A return code != 0 tells the operating system that there is an issue.

}

// in the terminal type `cd build` and then `./check_brackets test_data/*`