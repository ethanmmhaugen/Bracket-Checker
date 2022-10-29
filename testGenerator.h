//
// Created by ethan on 10/29/2022.
//

#ifndef ASSIGNMENT3_BRACKETS_TESTGENERATOR_H
#define ASSIGNMENT3_BRACKETS_TESTGENERATOR_H

#include <ostream>
#include <random>
#include <cstdlib>
#include "DSStack.h"
#include "checker.h"

class testGenerator{
private:
public:
    testGenerator(){

    }
    void makeFile(List::DSStack<char> list){
        ofstream output;
        string input;
        cout << "Enter output file name: \n" << endl;
        cin >> input;
        output.open(input);

        for(int i = 0; i<list.size(); i++){
            output << list.index(i) << endl;
        }
        output.close();
    }
    void createTest(int num){
        List::DSStack<char> list;
        for(int i = 0; i<(num/2); i++){
            int j = (rand()%4);
            if(j == 0){
                list.push('(');
            }
            else if(j == 1){
                list.push('{');
            }
            else if(j == 2){
                list.push('[');
            }
            else if(j == 3){
                list.push('"');
            }
        }
        for(int i = 0; i<list.size(); i++){
            if(list.index(list.size()-1-i) == '('){
                list.push(')');
            }
            else if(list.index(list.size()-1-i) == '{'){
                list.push('}');
            }
            else if(list.index(list.size()-1-i) == '['){
                list.push(']');
            }
            else if(list.index(list.size()-1-i) == '"'){
                list.push('"');
            }
        }
        list.print();
        makeFile(list);
    }
};
#endif //ASSIGNMENT3_BRACKETS_TESTGENERATOR_H