#pragma once

#include "DSList.h"
#include <vector>
using namespace std;
// Implement a class that provides a stack interface for your DSLists class.
namespace List {
    template<typename Object>
    class DSStack {
    private:
        DSList<Object> list;
    public:
        void push(const Object &rhs) {
            list.push_back(rhs);
        }

        Object pop() {
            return list.pop_back();
        }

        Object top() {
            if(list.getTail() == nullptr){
                throw runtime_error("you suck. List is clearly empty");
            }
            return list.getTail()->data;
        }

        bool empty() {
            return list.isEmpty();
        }

        int size() {
            return list.getSize();
        }
        Object index(int num){
            return list.index(num);
        }
        void print(){
            list.print();
        }
    };
}

namespace Vector {
    template<typename Object>
    class DSStack {
    private:
        vector<Object> list;
    public:
        void push(const Object &rhs) {
            list.push_back(rhs);
        }

        Object pop() {
            Object tmp = list[list.size()-1];
            list.pop_back();
            return tmp;
        }

        Object top() {
            return list.back();
        }

        bool empty() {
            return list.empty();
        }

        int size() {
            return list.size();
        }
    };
}
// Implement:
// push, pop, top, empty, size