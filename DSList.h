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
    Node *listCurr = list.head;
    while(listCurr->next != nullptr){
        listCurr = listCurr->next;
        curr->next = new Node(listCurr->data, nullptr, curr);
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
    size = 0;
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
int findNum(Object num){
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
Object index(int index){
    Node* curr = head;
    while(curr && index>0){
        curr = curr->next;
        index--;
    }
    return curr->data;
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

//insert from the tail
void push_back(Object value){
    Node* curr = tail;
    Node* insert = new Node(value, nullptr, nullptr);
    size++;
    if(curr!= nullptr){
        insert->prev = curr;
        curr->next = insert;
    }
    else{
        head = insert;
    }
    tail = insert;
}

// insert at a specified position.
/*void push_index(Node x, int index){
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
*/
//insert at a specified position using value only
void push_index(Object value, int index){
    Node* curr = head;
    if(index>size){
        throw runtime_error("you suck. List is not that long yet");
    }
    else {
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        if(index!=size && index != 0) {
            Node *pre = curr->prev;
            Node *insert = new Node(value, curr, pre);
            pre->next = insert;
            curr->prev = insert;
            size++;
        }
        else if (index == 0){
            push_front(value);
        }
        else{
            push_back(value);
        }

    }
}
// remove the element in front (pop_front)
Object pop_front(){
    /*if(head == nullptr){
        return;
    }
     */
    if(head==nullptr){
        throw runtime_error("you suck. List is clearly empty");
    }
    while(head!=nullptr) {
        Node *curr = head->next;
        if (curr != nullptr) {
            curr->prev = nullptr;
        } else {
            tail = nullptr;
        }
        Object stuff = head->data;
        delete head;
        head = curr;
        size--;
        return stuff;
    }
}

//Pop from back
Object pop_back(){
    if(head==nullptr){
        throw runtime_error("you suck. List is clearly empty");
    }
    while(head!=nullptr) {
        Node *curr = tail->prev;
        if (curr != nullptr) {
            curr->next = nullptr;
        } else {
            head = nullptr;
        }
        Object stuff = tail->data;
        delete tail;
        tail = curr;
        size--;
        return stuff;
    }
}
// remove using position.
Object pop_index(int index){
        if(head==nullptr){
            throw runtime_error("you suck. List is clearly empty");
        }
        if(index !=0 && index !=size-1) {
            Node* curr = head;
            for (int i = 0; i< index; i++){
                curr = curr->next;
            }
            Object stuff = curr->data;
            Node *behind = curr->next;
            Node *front = curr->prev;
            behind->prev = front;
            front->next = behind;
            size--;
            delete curr;
            return stuff;
        }
        else if(index == 0){
            pop_front();
        }
        else{
            pop_back();
        }
}
// remove an element with a specific value (find and remove)
void pop_val(Object val){
    if(head==nullptr){
        throw runtime_error("you suck. List is clearly empty");
    }
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
    if(head==nullptr){
        throw runtime_error("you suck. List is clearly empty");
    }
    Node* curr = head;
    Node* tmp = curr;
    int count = 0;
    while(curr != nullptr) {
        while (curr->data != val) {
            curr = curr->next;
        }
        if(curr->prev == nullptr){
            head = curr->next;
            curr->next->prev = nullptr;
            count++;
        }
        if (curr->next == nullptr){

        }
        for (int i = 0; i < count; i++) {
            size--;
        }
    }
}

int count(Object value){
    int count = 0;
    Node* curr = head;
    while(curr!=nullptr){
        if(curr->data == value){
            count++;
        }
        curr = curr->next;
    }
    return count;
};

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
