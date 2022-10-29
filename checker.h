//
// Created by ethan on 10/26/2022.
//

#ifndef ASSIGNMENT3_BRACKETS_CHECKER_H
#define ASSIGNMENT3_BRACKETS_CHECKER_H

#include <iostream>
#include <algorithm>
#include <fstream>
#include "DSList.h"
#include "DSStack.h"
#include <string>
#include <cstring>
#include <chrono>
class checker{
private:

public:
    checker(){
    }
    //checks output for either stack varient
    int evaluate(vector<int> result, string filename){
        //if 0 then we know the file is good
        if (result.size() == 0) {
            cout << filename << ": OK" << endl;
            return 0;

        //negative 1 means that we had a closing bracket when the stack was empty
        } else if(result[0] == -1){
            cout << filename << ": NOT OK" << endl;
            cout << "The last line your brackets matched was line " << result[2] <<
                    "\nCheck line " << result[1] << ", it has a closing bracket that doesn't match an open one. Good Luck!!" << endl;
        }
        //outputs the fact that the code isnt okay with a best guess on which lines to check
        else {
            cout << filename << ": NOT OK" << endl;
            cout << "The last time your code was correct was line " << result[result.size()-1] <<
            "\nTry rechecking line(s) ";
            for(int i = 0; i<result.size()-1; i++){
                cout<< result[i] << ", ";
            }
            cout << " they currently still have open brackets. Good luck!!" << endl;
            return 1;
        }
    }
    //list version of the stack
    vector<int> runListVersion(string filename){
        //file opener
        List::DSStack<char> myStack;
        ifstream file;
        file.open(filename);
        if(!file.is_open()){
            cout << "Error, file not found" << endl;
        }
        //Count increases for every line we check, lastCorrect holds count anytime stack size is 0,
        // hopefully indicating the last time the stack was correct
        //count and lastcorrect are passed to the int vectors to help guide the programmer on where their code went wrong
        int count = 0;
        int lastCorrect = 0;
        vector<int> line;
        string buff;
        //these bools keep track of if we are in a string or comment
        bool isString = false;
        bool isComment = false;
        bool checkComment = true;
        //should get one line at a time
        while(getline(file, buff, '\r')) {
            count++;

            //iterates through each line
            for (int i = 0; i<buff.length(); i++) {
                //checks for " to indicate entering a string
                if(buff[i] == '"' && !isString){
                    myStack.push(buff[i]);
                    isString = true;
                    checkComment = false;
                    continue;
                }
                //checks for ending a string
                if(isString && buff[i] == '"'){
                    myStack.pop();
                    isString = false;
                    checkComment = true;
                    continue;
                }
                //checks for comments... only IF we aren't in a string
                if(checkComment && buff[i] == '/'){
                    i++;
                    if(i<buff.length()) {
                        if (buff[i] == '/') {
                            break;
                        }
                        if(buff[i] == '*'){
                            isComment = true;
                        }
                    }
                }
                //checks for the /* comments
                if(isComment && buff[i] == '*'){
                    i++;
                    if(buff[i] == '/'){
                        isComment = false;
                    }
                }
                //As long as we aren't inside of a string or a comment, keep looking for brackets
                if(!isString && !isComment) {
                    if (buff[i] == '(' || buff[i] == '{' || buff[i] == '[') {
                        myStack.push(buff[i]);
                        line.push_back(count);
                        continue;
                    }
                    if (buff[i] == ')' || buff[i] == '}' || buff[i] == ']') {
                        if (myStack.empty()) {
                            if(line.size() == 0){
                                line.push_back(-1);
                                line.push_back(count);
                                line.push_back(lastCorrect);
                                return line;
                            }
                            line.push_back(lastCorrect);
                            return line;
                        } else if (buff[i] == ')' && myStack.top() == '(') {
                            myStack.pop();
                            line.pop_back();
                        } else if (buff[i] == '}' && myStack.top() == '{') {
                            myStack.pop();
                            line.pop_back();
                        } else if (buff[i] == ']' && myStack.top() == '[') {
                            myStack.pop();
                            line.pop_back();
                        } else {
                            line.push_back(lastCorrect);
                            return line;
                        }
                    }

                }
                if(myStack.size() == 0){
                    lastCorrect = count;
                }

            }
            //}
        }
        return line;
    }

    //same as the list version but with vectors
    vector<int> runVectorVersion(string filename){
        //file opener
        Vector::DSStack<char> myStack;
        ifstream file;
        file.open(filename);
        if(!file.is_open()){
            cout << "Error, file not found" << endl;
        }

        int count = 0;
        int lastCorrect = 0;
        vector<int> line;
        string buff;
        bool isString = false;
        bool isComment = false;
        bool checkComment = true;
        //should get one line at a time??
        while(getline(file, buff, '\r')) {
            count++;
            //code to check if its a comment?

            //code for once chars are separated
            for (int i = 0; i<buff.length(); i++) {
                //code to find the end of the string
                if(buff[i] == '"' && !isString){
                    myStack.push(buff[i]);
                    isString = true;
                    checkComment = false;
                    continue;
                }
                if(isString && buff[i] == '"'){
                    myStack.pop();
                    isString = false;
                    checkComment = true;
                    continue;
                }
                if(checkComment && buff[i] == '/'){
                    i++;
                    if(i<buff.length()) {
                        if (buff[i] == '/') {
                            break;
                        }
                        if(buff[i] == '*'){
                            isComment = true;
                        }
                    }
                }

                if(isComment && buff[i] == '*'){
                    i++;
                    if(buff[i] == '/'){
                        isComment = false;
                    }
                }
                //As long as we aren't inside of a string, keep looking for brackets
                if(!isString && !isComment) {
                    if (buff[i] == '(' || buff[i] == '{' || buff[i] == '[') {
                        myStack.push(buff[i]);
                        line.push_back(count);
                        continue;
                    }
                    if (buff[i] == ')' || buff[i] == '}' || buff[i] == ']') {
                        if (myStack.empty()) {
                            if(line.size() == 0){
                                line.push_back(-1);
                                line.push_back(count);
                                line.push_back(lastCorrect);
                                return line;
                            }
                            line.push_back(lastCorrect);
                            return line;
                        } else if (buff[i] == ')' && myStack.top() == '(') {
                            myStack.pop();
                            line.pop_back();
                        } else if (buff[i] == '}' && myStack.top() == '{') {
                            myStack.pop();
                            line.pop_back();
                        } else if (buff[i] == ']' && myStack.top() == '[') {
                            myStack.pop();
                            line.pop_back();
                        } else {
                            line.push_back(lastCorrect);
                            return line;
                        }
                    }

                }
                if(myStack.size() == 0){
                    lastCorrect = count;
                }

            }
            //}
        }
        return line;
    }
};

#endif //ASSIGNMENT3_BRACKETS_CHECKER_H
