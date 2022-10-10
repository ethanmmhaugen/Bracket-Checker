#ifndef DSList_H
#define DSList_H
using namespace std;
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
    Node* curr= head;
    while(curr != nullptr){
        head = curr->next;
        delete curr;
        curr = head;
    }
    head = nullptr;
    tail = nullptr;

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
int findNum(int num){
    Node* tmp = head;
    int count = 0;
    while(tmp !=nullptr){
        if(tmp->data == num){
            return count;
        }
        tmp = tmp->next;
        count++;
    }
    return -1;
}
// insert in front (push_front).
void push_front(Node x){
    Node* curr = head;
    curr->prev = x;
    x->next = curr;
    head = x;

}

//insert in front using value only
void push_front(Object value){
    Node* curr = head;
    Node* insert = new Node(value, nullptr, nullptr);
    size++;
    if(curr!= nullptr){
        insert->next = curr;
        curr->prev = insert;
    }
    else{
        tail = insert;
    }
    head = insert;
}

// insert at a specified position.
void push_index(Node x, int index){
    Node* curr = head;
    for (int i = 0; i< index; i++){
        curr = curr->next;
    }
    Node* pre = curr->prev;
    curr->prev = x;
    x->next = curr;
    pre->next = x;
    x->prev = pre;
}

//insert at a specified position using value only
void push_index(int index, Object value){
    Node* curr = head;
    for (int i = 0; i< index; i++){
        curr = curr->next;
    }
    Node* pre = curr->prev;
    Node* insert = new Node(value, curr, pre);
    pre->next = insert;
    curr->prev = insert;
}
// remove the element in front (pop_front)
Object pop_front(){
    /*if(head == nullptr){
        return;
    }
     */
    Node* curr = head->next;
    if(curr != nullptr){
        curr->prev = nullptr;
    }
    else{
        tail = nullptr;
    }
    Object stuff = head->data;
    delete head;
    head = curr;
    size--;
    return stuff;
}
// remove using position.
Object pop_index(int index){
        Node* curr = head;
        for (int i = 0; i< index; i++){
            curr = curr->next;
        }
        Object stuff = curr->data;
        Node* behind = curr->next;
        Node* front = curr->prev;
        if(behind != nullptr) {
            behind->prev = front;
        }
        else{
            tail = front;
        }
        if(front != nullptr) {
            front->next = behind;
        }
        else{
            head = behind;
        }
        delete curr;
        size--;
        return stuff;
}
// remove an element with a specific value (find and remove)
void pop_val(Object val){
    Node* curr = head;
    while(curr->data != val && curr->next != nullptr){
        curr = curr->next;
    }
    if(curr->data == val) {
        if (curr->next != nullptr && curr->prev != nullptr) {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;

        } else if (curr->next == nullptr) {
            tail = curr->prev;
            curr->prev->next = nullptr;
        } else {
            head = curr->next;
            curr->next->prev = nullptr;
        }
        delete curr;
        size--;
    }
}
//remove all objects with a specific value
void pop_all_val(Object val){
    Node* curr = head;
    while(curr->data != val && curr->next != nullptr){
        curr = curr->next;
    }
    if(curr->next != nullptr) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete curr;
    }
    size--;
}

Node* getHead(){
    return head;
}
Node* getTail(){
    return tail;
}

void print() {
    if(head == NULL) {
        cout << "empty list";
    } else {
        Node* current = head;
        while(current != NULL) {
            if(current->next != NULL) {
                cout << current->data << " <=> ";
            } else {
                cout << current->data << endl;
            }
            current = current->next;
        }
    }
}



};

#endif
