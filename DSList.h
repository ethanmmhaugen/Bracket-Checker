#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position
 *
 * 1. Use a postion index to refer to an element. This is simpler to
 *    implement compared to iterators (see iterator version), but does not
 *    play as nicely with the STL.
 * 2. Optional: Use a sentinel node (a node without data that represents the
 *    beginning of the list).
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;
        Node *prev;

        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
            : data{d}, next{n}, prev {p} {};
    };
    
    Node *head;
    Node *tail;
    int size;

public:

// You need to implement
// Default construction
DSList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}
// Copy constructor
DSList(const DSList& list){
    head = new Node(list.head->data);
    size = 1;
    Node *curr = head;
    while(list.head->next != nullptr){
        list.head = list.head->next;
        curr->next = new Node(list.head->data, nullptr, curr);
        size++;
        curr = curr->next;
    }
    tail = curr;
}
// Destructor
~DSList() {
    Node* curr= head->next;
    while(curr != nullptr){
        head = curr->next;
        delete curr;
        curr = head;
    }
}
// size
int getSize(){
    return size;
}
// empty?
bool isEmpty(){
    return(size == 0);
}
// clear
// find an element with a specific value (and return the position. First element in list is pos 0).
// insert in front (push_front).

// insert at a specified position.
// remove the element in front (pop_front)
// remove using position.
// remove an element with a specific value (find and remove)

};

#endif
