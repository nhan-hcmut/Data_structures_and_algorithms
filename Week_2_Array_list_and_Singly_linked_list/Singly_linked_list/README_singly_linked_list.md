# Iterator

Implement Iterator class in class SLinkedList. 

**Note:** Iterator is a concept of repetitive elements on sequence structures. Iterator is implemented in class vector, list in STL container in C++ (https://www.geeksforgeeks.org/iterators-c-stl/). Your task is to implement the simple same class with iterator in C++ STL container.

Please read example and testcase carefully.
```cpp
template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};
```

**For example:**

+ Test 1:
```cpp
SLinkedList<int> list;
    
int size = 10;
for(int idx=0; idx < size; idx++){
    list.add(idx);
}
        
SLinkedList<int>::Iterator it;
int expvalue = 0;
for(it = list.begin(); it != list.end(); it++){
    assert(*it == expvalue);
    expvalue += 1;
}
```

+ Test 2:
```cpp
SLinkedList<int> list;
    
int size = 10;
for(int idx=0; idx < size; idx++){
    list.add(idx);
}
        
SLinkedList<int>::Iterator it;
int expvalue = 0;
for(it = list.begin(); it != list.end(); ++it){
    assert(*it == expvalue);
    expvalue += 1;
}
```

**Hints:**
```cpp
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}
```
---
# Polynomial

Polynomials is an important application of arrays and linked lists. A polynomial is composed of different terms where each of them holds a coefficient and an exponent. A polynomial p(x) is the expression in variable x which is in the form (a<sub>n</sub>x<sub>n</sub> + a<sub>n-1</sub>x<sub>n-1</sub> + .... + a<sub>1</sub>x+ a<sub>0</sub>), where a<sub>n</sub>, a<sub>n-1</sub>, ...., a<sub>0</sub> fall in the category of real numbers and 'n' is the non-negative integer, which is called the degree of polynomial.

**Example:** 10x<sup>2</sup> + 26x, here 10 and 26 are coefficients and 2, 1 is its exponential value.

Points to keep in Mind while working with Polynomials:
- The sign of each coefficient and exponent is stored within the coefficient and the exponent itself.
- The storage allocation for each term in the polynomial must be done in descending order of their exponent.

In this question, **complete SLinkedList class is included**. You should use this class to complete your Polynomial class with initialized frame as following. This task is implement insertTerm to insert a term into a polynomial.

```cpp
class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};


class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};


//SLinkedList has been done with the following attributes and methods:

class SLinkedList : IList<T>
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration

protected:
    Node* head;
    Node* tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {};
    virtual ~SLinkedList();
    virtual void add(const T& e);
    virtual void add(int index, const T& e);
    virtual T removeAt(int index);
    virtual bool removeItem(const T& removeItem);
    virtual bool empty();
    virtual int size();
    virtual void clear();
    virtual T get(int index);
    virtual void set(int index, const T& e);
    virtual int indexOf(const T& item);
    virtual bool contains(const T& item);
};
```

**For example:**

+ Test 1:
```cpp
Polynomial *poly = new Polynomial();
poly->insertTerm(6.0, 2);
poly->insertTerm(4.0, 5);
poly->insertTerm(4.0, 3);
poly->insertTerm(6.0, 5);
poly->insertTerm(-1.0, 0);
poly->insertTerm(-6.0, 6);
poly->insertTerm(6.0, 6);
poly->print();
```
+ Result 1:
<br/>
[<br/>
Term: (10 5)<br/>
Term: (4 3)<br/>
Term: (6 2)<br/>
Term: (-1 0)<br/>
]
<br/><br/>

+ Test 2:
```cpp
int n = 5;
int coeff[] = { 1, 2, 3, 4, 5 };
int exp[] = { 1, 2, 3, 4, 5 };

Polynomial p1;
for (int i = 0; i < n; ++i)
    p1.insertTerm(coeff[i], exp[i]);

p1.print();
```
+ Result 2:
<br/>
[<br/>
Term: (5 5)<br/>
Term: (4 4)<br/>
Term: (3 3)<br/>
Term: (2 2)<br/>
Term: (1 1)<br/>
]

---
# addLinkedList

Class LLNode is used to store a node in a singly linked list, described on the following:
```cpp
class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
};
```
Where val is the value of node, next is the pointer to the next node.

Request: Implement function:
```cpp
LLNode* addLinkedList(LLNode* l0, LLNode* l1);
```
Where l0, l1 are two linked lists represented positive integers, each node is a digit, the head is the least significant digit (the value of each node is between 0 and 9, the length of each linked list is between 0 and 100000). This function returns the linked list representing the sum of the two integers.

**Example:**

Given l0 = [2, 3] (representing 32) and l1 = [1, 8] (representing 81). The result would be l0 = [3, 1, 1] (representing 32 + 81 = 113).

**Note:**

In this exercise, these libraries \<iostream\>, \<string\>, \<cstring\>, \<climits\>, \<utility\>, \<vector\>, \<list\>, \<stack\>, \<queue\>, \<map\>, \<unordered_map\>, \<set\>, \<unordered_set\>, \<functional\>, \<algorithm\> have been included and namespace std is used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.

**For example:**

+ Test:
```cpp
int arr1[] = {2, 9};
int arr2[] = {0, 5};
LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
LLNode* newhead = addLinkedList(head1, head2);
LLNode::printList(newhead);
head1->clear();
head2->clear();
newhead->clear();
```
+ Result: [2, 4, 1]

---
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

---
# partition

Class LinkedList is used to represent single linked list, described as the following:
```cpp
class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
	void partition(int k);
};
```
In this class; head, tail and size are the pointers of the first element, the last element and size of linked list.

**Request:** Implement function
```cpp
void LinkedList::partition(int k);
```
To rearrange elements in this linked list by this way: split all elements of this linked list to 3 groups include: group I (the value  of each element is smaller than k), group II (the value of each element is equal to k) and group III (the value of each element is larger than k); after that, move group I to the head  of linked list, group II is after group I and group III is after group II. Note that the orders of the elements of each group are unchanged.

**Example:**

+ The given linked list: 10->55->45->42->50

+ k=45

In this case, group I includes elements with value 10 and 42, group II includes elements with 45 and group III includes elements with value 55 and 50. Rearrange by above way,  this linked list will become 10->42->45->55->50 (the orders of th elements in each group is unchanged: 10 before 42 and 55 before 50).

**Note:** In this exercise, libraries \<iostream\>, \<sstream\> and using namespace std; have been used. You can add other functions for your answer, but you are not allowed to add other libraries.

**For example:**

+ Test:
```cpp
LinkedList* l1 = new LinkedList();
l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
l1->partition(45);
cout << l1->toString() << "\n";
```
+ Result: [20,30,10,40,45,60,55]

---
# removeAt_removeItem_clear

Implement methods removeAt, removeItem and clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
```cpp
template <class T>class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
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
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.get(0) == list.removeAt(0));
cout << list.toString();
```
+ Result 1: [1,2,3,4,5,6,7,8,9]
<br/>

+ Test 2:
```cpp
SLinkedList<int> list;
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.get(9) == list.removeAt(9));
cout << list.toString();
```
+ Result 2: [0,1,2,3,4,5,6,7,8]
<br/>

+ Test 3:
```cpp
SLinkedList<int> list;
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.removeItem(9));

cout << list.toString();
```
+ Result 3: [0,1,2,3,4,5,6,7,8]

---
# reverseLinkedList

Class LLNode representing a node of singly linked lists is declared as below:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
Given a singly linked list head node.
Your task is to implement a function with following prototype:
```cpp
LLNode* reverseLinkedList(LLNode* head);
```
The function returns head node of the reversed singly linked list.

**Note:**
+ The \<iostream\> library has been included and namespace std is used. No other libraries are allowed.
+ The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
+ You can write helper functions.

**For example:**

+ Test 1:
```cpp
int arr[] = {13, 88, 60, 7, 192};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
newhead->clear();
```
+ Result 1:

[13, 88, 60, 7, 192]
<br/>
[192, 7, 60, 88, 13]
<br/>

+ Test 2:
```cpp
int arr[] = {};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
newhead->clear();
```
+ Result 2:

[]
<br/>
[]
<br/>

+ Test 3:
```cpp
int arr[] = {31, 22, 46, 152, 14, 87, 196, 97, 5, 93};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
newhead->clear();
```
+ Result 3:

[31, 22, 46, 152, 14, 87, 196, 97, 5, 93]
<br/>
[93, 5, 97, 196, 87, 14, 152, 46, 22, 31]
<br/>

+ Test 4:
```cpp
int arr[] = {115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
newhead->clear();
```
+ Result 4:

[115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190]
<br/>
[190, 120, 107, 61, 37, 161, 195, 132, 33, 51, 174, 94, 106, 154, 18, 109, 39, 178, 59, 115]
<br/>

+ Test 5:
```cpp
int arr[] = {104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
newhead->clear();
```
+ Result 5:

[104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174]
<br/>
<br/>
[174, 51, 151, 158, 197, 27, 132, 185, 194, 112, 174, 29, 130, 185, 97, 164, 183, 92, 86, 194, 121, 191, 36, 12, 80, 71, 147, 192, 162, 185, 138, 69, 56, 103, 42, 123, 191, 69, 131, 45, 156, 61, 38, 62, 88, 39, 172, 122, 13, 108, 93, 127, 160, 148, 180, 11, 81, 71, 66, 150, 0, 97, 17, 44, 105, 194, 51, 68, 25, 124, 51, 156, 82, 173, 83, 16, 37, 143, 157, 8, 158, 38, 55, 18, 45, 139, 177, 152, 179, 46, 90, 67, 114, 56, 171, 15, 40, 154, 50, 104]

---
# rotateLinkedList

Class LLNode representing a node of singly linked lists is declared as below:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
Given a singly linked list head node and a integer k.
Your task is to implement a function with following prototype:
```cpp
LLNode* rotateLinkedList(LLNode* head, int k);
```
The function returns head node of the rotated singly linked list obtained after rotate the linked list to the right by k places.

**Note:**
+ The \<iostream\> library has been used and namespace std is used. No other libraries are allowed.
+ The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
+ You can write helper functions.

**For example:**

+ Test 1:
```cpp
int arr[] = {2, 4, 6, 6, 3};
int k = 3;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
```
+ Result 1:

[2, 4, 6, 6, 3]
<br/>
[6, 6, 3, 2, 4]
<br/>

+ Test 2:
```cpp
int arr[] = {};
int k = 2;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
```
+ Result 2:

[]
<br/>
[]
<br/>

+ Test 3:
```cpp
int arr[] = {0, 4, 2, 5, 1, 0, 6, 4, 8, 6};
int k = 11;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
```
+ Result 3:

[0, 4, 2, 5, 1, 0, 6, 4, 8, 6]
<br/>
[6, 0, 4, 2, 5, 1, 0, 6, 4, 8]
<br/>

+ Test 4:
```cpp
int arr[] = {6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9};
int k = 35;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
```
+ Result 4:

[6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9]
<br/>
<br/>
[0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9, 6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9]
