# add_size

Implement methods add and size in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given below.
```cpp
template <class T>class SLinkedList {

public:
    class Node; // Forward declaration

protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList() : head(head), tail(tail), count(0) {}
    ~SLinkedList() {
        Node* temp = nullptr;
        while(this->head) {
            temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->count--;
        }
        this->tail = nullptr;
    }
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    string toString() const;
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};
```
**For example:**

+ Test 1:
```cpp
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(index);
}

cout << list.toString();
```
+ Result 1: [0,1,2,3,4,5,6,7,8,9]
<br/>

+ Test 2:
```cpp
SLinkedList<int> list;
int size = 10;

for(int index = 0; index < size; index++){
    list.add(0, index);
}

cout << list.toString();
```
+ Result 2: [9,8,7,6,5,4,3,2,1,0]

---
# get_set_empty_indexOf_contains

Implement methods get, set, empty, indexOf and contains in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given below.
```cpp
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
    string toString() const;

    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};
```
**For example:**

+ Test 1:
```cpp
SLinkedList<int> list;
int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6}; 

for (int idx = 0; idx < 8; idx++){
   list.add(index[idx], values[idx]);
}

assert( list.size() == 8 );
        
for (int idx = 0; idx < 8; idx++){
    assert( list.get(idx) == expvalues[idx] );
}

cout << list.toString();
```
+ Result 1: [8,15,2,4,7,10,40,6]
<br/>

+ Test 2:
```cpp
SLinkedList<int> list;

assert( list.empty() == true );
cout << list.toString();
```
+ Result 2: []
