# Iterator

Implement `class Iterator` in `class SLinkedList`. 

**<ins>Note</ins>:** Iterator is a concept of repetitive elements on sequence structures. Iterator is implemented in `class vector`, `list` in STL container in C++ (https://www.geeksforgeeks.org/iterators-c-stl/). Your task is to implement the same simple class with iterator in C++ STL container.

Please read below example and test cases carefully.
```cpp
template <class T>
class SLinkedList
{
public:
    class Iterator; // forward declaration
    class Node;     // forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {}
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
**<ins>For example</ins>:**
+ Test 1:
```cpp
SLinkedList<int> list;
int size = 10;

for (int idx = 0; idx < size; idx++) {
    list.add(idx);
}
SLinkedList<int>::Iterator it;
int expvalue = 0;

for (it = list.begin(); it != list.end(); it++) {
    assert(*it == expvalue);
    expvalue += 1;
}
```
+ Test 2:
```cpp
SLinkedList<int> list;
int size = 10;

for (int idx = 0; idx < size; idx++) {
    list.add(idx);
}
SLinkedList<int>::Iterator it;
int expvalue = 0;

for (it = list.begin(); it != list.end(); ++it) {
    assert(*it == expvalue);
    expvalue += 1;
}
```
**<ins>Hints</ins>:**
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

Polynomials is an important application of arrays and linked lists. A polynomial is composed of different terms, each of which has a coefficient and an exponent. A polynomial p(x) is the expression in variable x which is in the form (a<sub>n</sub>x<sub>n</sub> + a<sub>n-1</sub>x<sub>n-1</sub> + .... + a<sub>1</sub>x+ a<sub>0</sub>), where a<sub>n</sub>, a<sub>n-1</sub>, ...., a<sub>0</sub> fall in the category of real numbers and `n` is the non-negative integer, which is called the degree of polynomial.

**<ins>Example</ins>:** 10x<sup>2</sup> + 26x, here 10 and 26 are coefficients and 2, 1 is its exponential value.

Points to keep in mind while working with `class Polynomial`:

- The **sign** of each coefficient and exponent is stored within the coefficient and the exponent itself.
- The storage allocation for each term in the polynomial must be done in **descending** order of their exponent.

In this exercise, the complete `class SLinkedList` is already included. You should use it and the provided framework below to implement the `class Polynomial`. The task is to implement method `insertTerm()` to insert a term into a polynomial.
```cpp
class Polynomial; // forward declaration
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

// SLinkedList has been implemented with the following attributes and methods:

class SLinkedList : IList<T>
{
public:
    class Iterator; // forward declaration
    class Node;     // forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {}
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
**<ins>For example</ins>:**
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

for (int i = 0; i < n; ++i) {
    p1.insertTerm(coeff[i], exp[i]);
}
p1.print();
```
+ Result 2:

[<br/>
Term: (5 5)<br/>
Term: (4 4)<br/>
Term: (3 3)<br/>
Term: (2 2)<br/>
Term: (1 1)<br/>
]

---
# Train

`class Train`, representing a train, is declared as follows:
```cpp
class Train {
    public:
        class TrainCar;
    private:
        TrainCar* head;
        TrainCar* tail;
        int size;
    public:
        class TrainCar {
            private:
                int remainingSpace;
                TrainCar* next;
                friend class Train;
            public:
                TrainCar() {this->next = NULL;}
                TrainCar(int remainingSpace, TrainCar* next = NULL) {
                    this->remainingSpace = remainingSpace;
                    this->next = next;
                }
        };
        Train() {
            this->head = new TrainCar(0);
            this->tail = this->head;
            this->size = 1;
        }
        int allocate(int containerSize);
        int totalRemainingSpace();
};
```
**<ins>Where</ins>:**

- `head` is the head of train (cannot contain any container, index = 0).
- `tail` is the last train car of train.
- `size` refers to the number of train cars the train has (including the head of train).

Each train car (except the head of train) can carry a certain amount of mass. Each train car includes `remainingSpace` representing its current ability of containing and `next` representing the next train car (the head of train is the first train car).

Loading containers into train cars must comply with the following rules:

- Each container can be loaded into only one train car.
- Given a container with mass M, we must load it into the train car with the smallest current ability of containing that is greater than or equal to M. If more than one train cars satisfies this condition, choose the one with the smallest index. After that, we must update its current ability of containing.

<ins>**Request</ins>:** Implement 2 methods
```cpp
int Train::allocate(int containerSize);
```
and
```cpp
int Train::totalRemainingSpace();
```

<ins>**Where</ins>:**

- The method `allocate()` loads the container with mass `containerSize` into the train. It returns the index of the train car used for loading the container (if possible) or returns -1 (if not possible).
- The method `totalRemainingSpace()` calculates the sum of the mass that the train can contain.

<ins>**Example</ins>:**

- N(M) represents that the train car with index N can contain the mass M.
- Given a train: 0(0)->1(200)->2(400)->3(300)->4(600)->5(500)->6(100)
- Call `allocate(390)`: the result is 2. Updated train: 0(0)->1(200)->2(10)->3(300)->4(600)->5(500)->6(100)
- Call `allocate(590)`: the result is 4. Updated train: 0(0)->1(200)->2(10)->3(300)->4(10)->5(500)->6(100)
- Call `totalRemainingSpace()`: the result is 1120.
- Call `allocate(510)`: the result is -1.
- Call `allocate(10)`: the result is 2. Updated train: 0(0)->1(200)->2(0)->3(300)->4(10)->5(500)->6(100)

<ins>**Note</ins>**: In this exercise, the \<iostream\> library and `using namespace std;` directive are already included. You may add other functions for your answer, but you are **NOT** allowed to add other libraries.

<ins>**For example</ins>:**
```cpp
Train* t = new Train();
t->add(200); t->add(400); t->add(300); ; t->add(600); t->add(500); t->add(100);

cout << t->allocate(390) << "\n"; // Result: 2
cout << t->allocate(590) << "\n"; // Result: 4

cout << t->totalRemainingSpace() << "\n"; // Result: 1120

cout << t->allocate(510) << "\n"; // Result: -1
cout << t->allocate(10) << "\n"; // Result: 2
```
---
# addLinkedList

`class LLNode`, representing a node of singly linked lists, is declared below:
```cpp
class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
};
```
Where `val` is the value of node, `next` is the pointer to the next node.

<ins>**Request</ins>:** Implement function
```cpp
LLNode* addLinkedList(LLNode* l0, LLNode* l1);
```

Where `l0`, `l1` are two linked lists representing 2 positive integers, each node is a digit, the head is the least significant digit (the value of each node is between 0 and 9, the length of each linked list is between 0 and 100000). This function returns the linked list representing the sum of the two integers.

**<ins>Example</ins>:** Given l0 = [2, 3] (representing 32) and l1 = [1, 8] (representing 81). The result would be l0 = [3, 1, 1] (representing 32 + 81 = 113).

**<ins>Note</ins>:**

In this exercise, the `<iostream>`, `<string>`, `<cstring>`, `<climits>`, `<utility>`, `<vector>`, `<list>`, `<stack>`, `<queue>`, `<map>`, `<unordered_map>`, `<set>`, `<unordered_set>`, `<functional>`, `<algorithm>` libraries and `using namespace std;` directive are already included. You may write helper functions and classes. Importing additional libraries is allowed, but **NOT** encouraged and may cause unexpected errors.

**<ins>For example</ins>:**
+ Test 1:
```cpp
int arr1[] = {2, 9};
int arr2[] = {0, 5};

LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));

LLNode* newhead = addLinkedList(head1, head2);
LLNode::printList(newhead); // Result: [2, 4, 1]

head1->clear();
head2->clear();
newhead->clear();
```
+ Test 2:
```cpp
int arr1[] = {2, 3};
int arr2[] = {1, 8};

LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));

LLNode* newhead = addLinkedList(head1, head2);
LLNode::printList(newhead); // Result: [3, 1, 1]

head1->clear();
head2->clear();
newhead->clear();
```
---
# add_size

Implement the methods `add()` and `size()` in the `template class SLinkedList` (which implements the List ADT), representing a singly linked list with type T, using the provided framework. Descriptions of each method are given below.
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
**<ins>For example</ins>:**
+ Test 1:
```cpp
SLinkedList<int> list;
int size = 10;

for (int index = 0; index < size; index++) {
    list.add(index);
}
cout << list.toString() << endl; // Result: [0,1,2,3,4,5,6,7,8,9]
```
+ Test 2:
```cpp
SLinkedList<int> list;
int size = 10;

for (int index = 0; index < size; index++) {
    list.add(0, index);
}
cout << list.toString() << endl; // Result: [9,8,7,6,5,4,3,2,1,0]
```
---
# foldLinkedList

`class LLNode`, representing a node of singly linked lists, is declared as follows:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
**<ins>Request</ins>:** Given a singly linked list head node. Your task is to implement a function with following prototype:
```cpp
LLNode* foldLinkedList(LLNode* head);
```
This function returns head node of the folded singly linked list.

**<ins>More info</ins>:** A folded singly linked list is achieved by taking the first half of the linked list and folding over the second half and merging the intersecting nodes by taking their sum.

**<ins>Note</ins>:**

- The `<iostream>` library and `using namespace std;` directive are already included. **NO** other libraries are allowed.
- The constructors and methods of `class LLNode` have been fully defined so you do not need to redefine them.
- You may write helper functions.

**<ins>For example</ins>:**
+ Test 1:
```cpp
int arr1[] = {9, 5, 7, 5, 0};
LLNode* head = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));

LLNode::printList(head); // Result: [9, 5, 7, 5, 0]
cout << "\n";

LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead); // Result: [7, 10, 9]
cout << "\n";
```
+ Test 2:
```cpp
int arr2[] = {8, 4, 6, 8, 5, 3};
LLNode* head = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));

LLNode::printList(head); // Result: [8, 4, 6, 8, 5, 3]
cout << "\n";

LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead); // Result: [14, 9, 11]
cout << "\n";
```

+ Test 3:
```cpp
int arr3[] = {};
LLNode* head = LLNode::createWithIterators(arr3, arr3 + sizeof(arr3) / sizeof(int));

LLNode::printList(head); // Result: []
cout << "\n";

LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead); // Result: []
cout << "\n";
```
    
+ Test 4:
```cpp
int arr4[] = {7, 3, 1, 9, 4, 6, 3, 8, 5, 5};
LLNode* head = LLNode::createWithIterators(arr4, arr4 + sizeof(arr4) / sizeof(int));

LLNode::printList(head); // Result: [7, 3, 1, 9, 4, 6, 3, 8, 5, 5]
cout << "\n";

LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead); // Result: [10, 12, 9, 8, 12]
cout << "\n";
```
    
+ Test 5:
```cpp
int arr5[] = {8, 6, 9, 7, 3, 7, 6, 0, 3, 2, 2, 4, 6, 3, 6, 4, 2, 8, 3, 4, 2, 9, 4, 9, 5, 8, 5, 6, 9, 1, 5, 5, 9, 3, 1, 4, 2, 0, 1, 5, 1, 2, 9, 5, 0, 5, 3, 5, 1, 0, 6, 7, 3, 0, 9, 4, 0, 6, 0, 1, 3, 2, 9, 6, 6, 4, 4, 1, 5, 9, 6, 1, 1, 7, 9, 7, 7, 5, 1, 8, 4, 1, 4, 3, 0, 7, 7, 7, 9, 2, 9, 4, 2, 1, 2, 5, 7, 6, 5, 3, 1, 7, 2, 4, 3};

LLNode* head = LLNode::createWithIterators(arr5, arr5 + sizeof(arr5) / sizeof(int));

LLNode::printList(head); // Result: [8, 6, 9, 7, 3, 7, 6, 0, 3, 2, 2, 4, 6, 3, 6, 4, 2, 8, 3, 4, 2, 9, 4, 9, 5, 8, 5, 6, 9, 1, 5, 5, 9, 3, 1, 4, 2, 0, 1, 5, 1, 2, 9, 5, 0, 5, 3, 5, 1, 0, 6, 7, 3, 0, 9, 4, 0, 6, 0, 1, 3, 2, 9, 6, 6, 4, 4, 1, 5, 9, 6, 1, 1, 7, 9, 7, 7, 5, 1, 8, 4, 1, 4, 3, 0, 7, 7, 7, 9, 2, 9, 4, 2, 1, 2, 5, 7, 6, 5, 3, 1, 7, 2, 4, 3]
cout << "\n";

LLNode* newhead = foldLinkedList(head);
LLNode::printList(newhead); // Result: [3, 7, 15, 4, 1, 11, 3, 6, 3, 7, 18, 8, 7, 9, 5, 1, 7, 13, 7, 4, 10, 12, 14, 8, 16, 11, 6, 16, 9, 10, 8, 12, 2, 11, 10, 15, 11, 6, 15, 7, 8, 5, 4, 7, 10, 6, 11, 10, 4, 14, 11, 10, 11]
cout << "\n";
```
---
# get_set_empty_indexOf_contains

Implement methods `get()`, `set()`, `empty()`, `indexOf()` and `contains()` in `template class SLinkedList` (which implements the List ADT), representing a singly linked list with type T, using the provided framework. Descriptions of each method are given below.
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
    SLinkedList(): head(NULL), tail(NULL), count(0) {}
    ~SLinkedList() {};
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
**<ins>For example</ins>:**
+ Test 1:
```cpp
SLinkedList<int> list;
int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6};

for (int idx = 0; idx < 8; idx++) {
   list.add(index[idx], values[idx]);
}
assert( list.size() == 8 );

for (int idx = 0; idx < 8; idx++) {
    assert( list.get(idx) == expvalues[idx] );
}
cout << list.toString() << endl; // Result: [8,15,2,4,7,10,40,6]
```

+ Test 2:
```cpp
SLinkedList<int> list;
assert( list.empty() == true );
cout << list.toString() << endl; // Result: []
```
---
# partition

`class LinkedList`, representing singly linked lists, is declared as follows:
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
**<ins>Where</ins>:** `head`, `tail` and `size` are the pointer to the first element, the pointer to the last element, and the size of linked list, respectively.

**<ins>Request</ins>:** Implement method
```cpp
void LinkedList::partition(int k);
```

The method above rearranges elements of this linked list in this way:

+ Splitting all elements of this linked list into 3 groups.
+ Group I: the value  of each element is smaller than k.
+ Group II: the value of each element is equal to k.
+ Group III: the value of each element is larger than k.
+ After that, move group I to the head of linked list, group II is after group I and group III is after group II. Note that the order of the elements in each group remains unchanged.

**<ins>Example</ins>:**

+ The given linked list: 10->55->45->42->50
+ k = 45
+ Group I includes elements with value 10 and 42.
+ Group II includes elements with 45.
+ Group III includes elements with value 55 and 50.
+ After rearranging, this linked list becomes: 10->42->45->55->50 (the order of the elements in each group remains unchanged: 10 before 42 and 55 before 50).

**<ins>Note</ins>:** In this exercise, `<iostream>`, `<sstream>` libraries and `using namespace std;` directive are already included. You may add other functions for your answer, but you are **NOT** allowed to add other libraries.

**<ins>For example</ins>:**
+ Test 1:
```cpp
LinkedList* l1 = new LinkedList();
l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);

l1->partition(45);
cout << l1->toString() << "\n"; // Result: [20,30,10,40,45,60,55]
```
+ Test 2:
```cpp
LinkedList* l2 = new LinkedList();
l2->add(10); l2->add(55); l2->add(45); l2->add(42); l2->add(50);

l2->partition(45);
cout << l2->toString() << "\n"; // Result: [10,42,45,55,50]
```
---
# reduceDuplicate

Given node root of a singly linked list, implement below function:
```cpp
void reduceDuplicate(Node* root);
```

This function reduces consecutive duplicate elements in the linked list. If there are identical consecutive elements, only one is retained.

**<ins>Example</ins>:** We have a linked list 1->2->2->2->3->4->4->5->2. After executing the function `reduceDuplicate()`, we obtain linked list 1->2->3->4->5->2. The last number 2 is retained because it is not consecutive with the previous block 2->2->2.

**<ins>Note</ins>:** You may include additional libraries. You only need to implement the `reduceDuplicate()` function. Others are already defined.

Implementation of `class Node` is given below.
```cpp
class Node
{
    int data;
    Node* next;
public:
    Node() : data(0), next(nullptr) {}
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
    int getData()
    {
        return this->data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    Node* getNext()
    {
        return this->next;
    }
    void setNext(Node* next)
    {
        this->next = next;
    }
};
```
**<ins>For example</ins>:**
+ Test 1:
```cpp
Node* node1 = new Node(1, nullptr);
Node* node2 = new Node(1, node1);
Node* node3 = new Node(0, node2);

printList(node3); // Result: HEAD -> 0 -> 1 -> 1 -> NULL
cout << endl;

reduceDuplicate(node3);
printList(node3); // Result: HEAD -> 0 -> 1 -> NULL
cout << endl;
clear(node3);
```
+ Test 2:
```cpp
Node* node1 = new Node(2, nullptr);
Node* node2 = new Node(5, node1);
Node* node3 = new Node(4, node2);
Node* node4 = new Node(4, node3);
Node* node5 = new Node(3, node4);
Node* node6 = new Node(2, node5);
Node* node7 = new Node(2, node6);
Node* node8 = new Node(2, node7);
Node* node9 = new Node(1, node8);

printList(node9); // result: HEAD -> 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5 -> 2 -> NULL
cout << endl;

reduceDuplicate(node9);
printList(node9); // result: HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> 2 -> NULL
cout << endl;
clear(node9);
```
+ Test 3:
```cpp
Node* node1 = new Node(6, nullptr);

printList(node1); // result: HEAD -> 6 -> NULL
cout << endl;

reduceDuplicate(node1);
printList(node1); // result: HEAD -> 6 -> NULL
cout << endl;
clear(node1);
```
---
# removeAt_removeItem_clear

Implement methods `removeAt()`, `removeItem()` and `clear()` in `template class SLinkedList` (which implements the List ADT), representing a singly linked list with type T, using the provided framework. Descriptions of each method are given below:
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
**<ins>For example</ins>:**
+ Test 1:
```cpp
SLinkedList<int> list;
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.get(0) == list.removeAt(0));
cout << list.toString() << endl; // Result: [1,2,3,4,5,6,7,8,9]
```
+ Test 2:
```cpp
SLinkedList<int> list;
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.get(9) == list.removeAt(9));
cout << list.toString() << endl; // Result: [0,1,2,3,4,5,6,7,8]
```
+ Test 3:
```cpp
SLinkedList<int> list;
for (int i = 0; i < 10; ++i) list.add(i);
assert(list.removeItem(9));
cout << list.toString() << endl; // Result: [0,1,2,3,4,5,6,7,8]
```
---
# replace

`class LinkedList`, representing singly linked lists, is declared as follows:
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
        void replace(LinkedList* linked_list, int low, int high);
};
```
**<ins>Where</ins>:** `head`, `tail` and `size` are pointer to the first element, pointer to the last element, and size of linked list, respectively.

**<ins>Request</ins>:** Implement method
```cpp
replace(LinkedList* linked_list, int low, int high);
```

+ low <= high and high >= 0
+ This method deletes all elements from position low to position high in the linked list (head's position is 0). After that, add linked_list to this linked list at the position after low - 1 (if low - 1 < 0, the head of this linked list becomes the head of linked_list).
+ If high >= size, delete all elements from low position to the last position of this linked list. If low < 0, delete all elements from the first position of this linked list to high position.

**<ins>Example</ins>:**

+ The given linked list: 10->20->30->40->50
+ The linked_list: 55->45->42
+ low = 1, high = 3
+ In this case, delete all elements from position 1 (value 20) to position 3 (value 40). After that, add linked_list to this linked list to the position after position 0 (value 10). Therefore, this linked list becomes: 10->55->45->42->50.

**<ins>Note</ins>:** In this exercise, the `<iostream>`, `<sstream>` libraries and `using namespace std;` directive are already included. You may add other functions. However, you are not allowed to add additional libraries.

**<ins>For example</ins>:**
+ Test 1:
```cpp
LinkedList* l1 = new LinkedList();
LinkedList* l2 = new LinkedList();

l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
l2->add(55); l2->add(45); l2->add(42);

l1->replace(l2, -1, 2);
cout << l1->toString() << "\n"; // Result: [55,45,42,40,50]
```
+ Test 2:
```cpp
LinkedList* l1 = new LinkedList();
LinkedList* l2 = new LinkedList();

l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
l2->add(55); l2->add(45); l2->add(42);

l1->replace(l2, 1, 3);
cout << l1->toString() << "\n"; // result: [10,55,45,42,50]
```
+ Test 3:
```cpp
LinkedList* l1 = new LinkedList();
LinkedList* l2 = new LinkedList();

l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
l2->add(55); l2->add(45); l2->add(42);

l1->replace(l2, 2, 6);
cout << l1->toString() << "\n"; // result: [10,20,55,45,42]
```
---
# replaceFirstGreater

`class LLNode`, representing a node of singly linked lists, is declared as follows:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
Given a singly linked list head node. Your task is to implement a function with following prototype:
```cpp
LLNode* replaceFirstGreater(LLNode* head);
```

This function returns head node of the singly linked list after replacing every node's value with the first greater node's value to its right. If a node doesn't have a next greater node, set its value to 0.

**<ins>Note</ins>:**

- The `<iostream>`, `<stack>` libraries and `using namespace std;` directive are already included. **NO** other libraries are allowed.
- The constructors and methods of `class LLNode` have been fully defined so you do not need to redefine them.
- You may write helper functions.

**<ins>For example</ins>:**
+ Test 1:
```cpp
int arr1[] = {6};
LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
head1->printList(); // result: [6]

head1 = replaceFirstGreater(head1);
head1->printList(); // result: [0]
cout << endl;

head1->clear();
```
+ Test 2:
```cpp
int arr2[] = {1, 3};
LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
head2->printList(); // result: [1,3]

head2 = replaceFirstGreater(head2);
head2->printList(); // result: [3,0]
cout << endl;

head2->clear();
```
+ Test 3:
```cpp
int arr3[] = {3, 1, 4};
LLNode* head3 = LLNode::createWithIterators(arr3, arr3 + sizeof(arr3) / sizeof(int));
head3->printList(); // result: [3,1,4]

head3 = replaceFirstGreater(head3);
head3->printList(); // result: [4,4,0]
cout << endl;

head3->clear();
```
+ Test 4:
```cpp
int arr4[] = {5, 7, 1, 4};
LLNode* head4 = LLNode::createWithIterators(arr4, arr4 + sizeof(arr4) / sizeof(int));
head4->printList(); // result: [5,7,1,4]

head4 = replaceFirstGreater(head4);
head4->printList(); // result: [7,0,4,0]
cout << endl;

head4->clear();
```
+ Test 5:
```cpp
int arr5[] = {5, 8, 8, 2, 3};
LLNode* head5 = LLNode::createWithIterators(arr5, arr5 + sizeof(arr5) / sizeof(int));
head5->printList(); // result: [5,8,8,2,3]

head5 = replaceFirstGreater(head5);
head5->printList(); // result: [8,0,0,3,0]
cout << endl;

head5->clear();
```
+ Test 6:
```cpp
int arr6[] = {5, 2, 6, 3, 1, 5};
LLNode* head6 = LLNode::createWithIterators(arr6, arr6 + sizeof(arr6) / sizeof(int));
head6->printList(); // result: [5,2,6,3,1,5]

head6 = replaceFirstGreater(head6);
head6->printList(); // result: [6,6,0,5,5,0]
cout << endl;

head6->clear();
```
+ Test 7:
```cpp
int arr7[] = {1, 2, 3, 4, 5, 6, 7};
LLNode* head7 = LLNode::createWithIterators(arr7, arr7 + sizeof(arr7) / sizeof(int));
head7->printList(); // result: [1,2,3,4,5,6,7]

head7 = replaceFirstGreater(head7);
head7->printList(); // result: [2,3,4,5,6,7,0]
cout << endl;

head7->clear();
```
---
# reverseLinkedList

`class LLNode`, representing a node of singly linked lists, is declared below:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
Given a singly linked list's head node. Your task is to implement the function with following prototype:
```cpp
LLNode* reverseLinkedList(LLNode* head);
```
This function returns the head node of the reversed singly linked list.

**<ins>Note</ins>:**

+ The `<iostream>` library and `using namespace std;` directive are already included. **NO** other libraries are allowed.
+ The constructors and methods of `class LLNode` have been fully defined so you do not need to redefine them.
+ You may write helper functions.

**<ins>For example</ins>:**
+ Test 1:
```cpp
int arr[] = {13, 88, 60, 7, 192};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
cout << "\n";

newhead->clear();
```
+ Result 1:

[13, 88, 60, 7, 192]
<br/>
[192, 7, 60, 88, 13]
<br/><br/>

+ Test 2:
```cpp
int arr[] = {};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
cout << "\n";

if (newhead != nullptr) newhead->clear();
```
+ Result 2:

[]
<br/>
[]
<br/><br/>

+ Test 3:
```cpp
int arr[] = {31, 22, 46, 152, 14, 87, 196, 97, 5, 93};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
cout << "\n";

newhead->clear();
```
+ Result 3:

[31, 22, 46, 152, 14, 87, 196, 97, 5, 93]
<br/>
[93, 5, 97, 196, 87, 14, 152, 46, 22, 31]
<br/><br/>

+ Test 4:
```cpp
int arr[] = {115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190};
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
cout << "\n";

newhead->clear();
```
+ Result 4:

[115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190]
<br/>
[190, 120, 107, 61, 37, 161, 195, 132, 33, 51, 174, 94, 106, 154, 18, 109, 39, 178, 59, 115]
<br/><br/>

+ Test 5:
```cpp
int arr[] = {104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174};

LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = reverseLinkedList(head);
LLNode::printList(newhead);
cout << "\n";

newhead->clear();
```
+ Result 5:

[104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174]
<br/>
<br/>
[174, 51, 151, 158, 197, 27, 132, 185, 194, 112, 174, 29, 130, 185, 97, 164, 183, 92, 86, 194, 121, 191, 36, 12, 80, 71, 147, 192, 162, 185, 138, 69, 56, 103, 42, 123, 191, 69, 131, 45, 156, 61, 38, 62, 88, 39, 172, 122, 13, 108, 93, 127, 160, 148, 180, 11, 81, 71, 66, 150, 0, 97, 17, 44, 105, 194, 51, 68, 25, 124, 51, 156, 82, 173, 83, 16, 37, 143, 157, 8, 158, 38, 55, 18, 45, 139, 177, 152, 179, 46, 90, 67, 114, 56, 171, 15, 40, 154, 50, 104]

---
# rotateLinkedList

`class LLNode`, representing a node of singly linked lists, is declared below:
```cpp
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};
```
Given a singly linked list's head node and an integer k. Your task is to implement the function with following prototype:
```cpp
LLNode* rotateLinkedList(LLNode* head, int k);
```
This function returns the head node of the rotated singly linked list obtained after rotating the linked list to the right by k places.

**<ins>Note</ins>:**

+ The `<iostream>` library and `using namespace std;` directive are already included. **NO** other libraries are allowed.
+ The constructors and methods of `class LLNode` have been fully defined so you do not need to redefine them.
+ You may write helper functions.

**<ins>For example</ins>:**
+ Test 1:
```cpp
int arr[] = {2, 4, 6, 6, 3};
int k = 3;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
cout << "\n";
```
+ Result 1:

[2, 4, 6, 6, 3]
<br/>
[6, 6, 3, 2, 4]
<br/><br/>

+ Test 2:
```cpp
int arr[] = {};
int k = 2;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
cout << "\n";
```
+ Result 2:

[]
<br/>
[]
<br/><br/>

+ Test 3:
```cpp
int arr[] = {0, 4, 2, 5, 1, 0, 6, 4, 8, 6};
int k = 11;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
cout << "\n";
```
+ Result 3:

[0, 4, 2, 5, 1, 0, 6, 4, 8, 6]
<br/>
[6, 0, 4, 2, 5, 1, 0, 6, 4, 8]
<br/><br/>

+ Test 4:
```cpp
int arr[] = {6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9};
int k = 35;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
cout << "\n";
```
+ Result 4:

[6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9]
<br/>
<br/>
[0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9, 6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9]
<br/><br/>

+ Test 5:
```cpp
int arr[] = {9, 1, 7, 5, 8, 6, 2, 2, 2, 6, 0, 8, 1, 9, 6, 8, 4, 8, 4, 3, 7, 0, 7, 8, 9, 5, 3, 4, 7, 4, 3, 5, 2, 2, 7, 8, 9, 7, 1, 9, 9, 8, 3, 5, 7, 1, 6, 9, 1, 2, 0, 6, 8, 0, 4, 1, 6, 5, 8, 7, 6, 8, 0, 5, 7, 8, 8, 6, 7, 5, 8, 0, 7, 6, 4, 9, 5, 9, 6, 4, 1, 5, 6, 2, 2, 6, 7, 0, 3, 4, 2, 3, 9, 0, 9, 6, 3, 6, 7, 5, 5, 5, 9, 0, 6, 1, 1, 5, 0, 9, 1, 1, 1, 0, 4, 6, 3, 3, 3, 5, 8, 7, 4, 7, 1, 7, 1, 8, 4, 2, 0, 1, 9, 0, 7, 9, 2, 8, 9, 2, 5, 3, 5, 9, 3, 2, 7, 3, 5, 9, 5, 5, 3, 2, 3, 9, 4, 1, 6, 1, 8, 3, 1, 4, 5, 2, 5, 7, 7, 0, 9, 6, 6, 4, 8, 1, 1, 6, 0, 2, 6, 0, 7, 5, 5, 0, 5, 2, 6, 9, 9, 9, 9, 2, 3, 0, 6, 8, 8, 4, 5, 6, 2, 8, 5, 9, 8, 3, 6, 8, 8, 6, 2, 1, 2, 1, 4, 6, 2, 0, 9, 3, 9, 6, 4, 2, 3, 6, 2, 0, 9, 8, 7, 0, 6, 0, 7, 0, 5, 9, 4, 3, 7, 9, 7, 3, 5, 7, 0, 3, 1, 8, 9, 9, 4, 0, 8, 6, 4, 6, 7, 3, 8, 1, 2, 1, 5, 4, 9, 5, 9, 5, 8, 6, 6, 8, 9, 4, 4, 0, 6, 4, 5, 3, 0, 3, 9, 7, 1, 7, 2, 5, 0, 1, 9, 1, 2, 5, 6, 8, 7, 1, 6, 9, 6, 2, 8, 1, 2, 0, 4, 3, 4, 6, 7, 1, 0, 7, 0, 7, 9, 4, 0, 1, 2, 3, 5, 6, 3, 5, 6, 7, 5, 4, 2, 4, 8, 2, 5, 8, 8, 6, 6, 2, 6, 6, 8, 1, 2, 2, 8, 0, 8, 9, 0, 7, 9, 0, 1, 6, 6, 3, 6, 5, 1, 5, 9, 0, 3, 7, 3, 7, 2, 0, 0, 2, 7, 5, 2, 9, 5, 5, 8, 1, 7, 7, 9, 7, 1, 1, 6, 4, 3, 8, 0, 7, 9, 1, 0, 9, 5, 2, 7, 2, 1, 5, 3, 9, 7, 6, 9, 1, 3, 5, 5, 0, 6, 9, 4, 7, 1, 7, 2, 0, 4, 5, 8, 1, 6, 1, 0, 7, 2, 2, 6, 7, 4, 4, 9, 5, 4, 5, 2, 0, 8, 0, 5, 5, 1, 8, 9, 4, 5, 6, 1, 2, 0, 7, 0, 2, 1, 6, 8, 8, 7, 8, 7, 0, 1, 8, 5, 6, 5, 9, 2, 2, 9, 3, 6, 0, 1, 7, 9, 8, 1, 1, 5, 4, 5, 7, 5, 0, 2, 0, 4, 4, 8, 0, 7, 3};
int k = 196;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";

LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
```
+ Result 5:

[9, 1, 7, 5, 8, 6, 2, 2, 2, 6, 0, 8, 1, 9, 6, 8, 4, 8, 4, 3, 7, 0, 7, 8, 9, 5, 3, 4, 7, 4, 3, 5, 2, 2, 7, 8, 9, 7, 1, 9, 9, 8, 3, 5, 7, 1, 6, 9, 1, 2, 0, 6, 8, 0, 4, 1, 6, 5, 8, 7, 6, 8, 0, 5, 7, 8, 8, 6, 7, 5, 8, 0, 7, 6, 4, 9, 5, 9, 6, 4, 1, 5, 6, 2, 2, 6, 7, 0, 3, 4, 2, 3, 9, 0, 9, 6, 3, 6, 7, 5, 5, 5, 9, 0, 6, 1, 1, 5, 0, 9, 1, 1, 1, 0, 4, 6, 3, 3, 3, 5, 8, 7, 4, 7, 1, 7, 1, 8, 4, 2, 0, 1, 9, 0, 7, 9, 2, 8, 9, 2, 5, 3, 5, 9, 3, 2, 7, 3, 5, 9, 5, 5, 3, 2, 3, 9, 4, 1, 6, 1, 8, 3, 1, 4, 5, 2, 5, 7, 7, 0, 9, 6, 6, 4, 8, 1, 1, 6, 0, 2, 6, 0, 7, 5, 5, 0, 5, 2, 6, 9, 9, 9, 9, 2, 3, 0, 6, 8, 8, 4, 5, 6, 2, 8, 5, 9, 8, 3, 6, 8, 8, 6, 2, 1, 2, 1, 4, 6, 2, 0, 9, 3, 9, 6, 4, 2, 3, 6, 2, 0, 9, 8, 7, 0, 6, 0, 7, 0, 5, 9, 4, 3, 7, 9, 7, 3, 5, 7, 0, 3, 1, 8, 9, 9, 4, 0, 8, 6, 4, 6, 7, 3, 8, 1, 2, 1, 5, 4, 9, 5, 9, 5, 8, 6, 6, 8, 9, 4, 4, 0, 6, 4, 5, 3, 0, 3, 9, 7, 1, 7, 2, 5, 0, 1, 9, 1, 2, 5, 6, 8, 7, 1, 6, 9, 6, 2, 8, 1, 2, 0, 4, 3, 4, 6, 7, 1, 0, 7, 0, 7, 9, 4, 0, 1, 2, 3, 5, 6, 3, 5, 6, 7, 5, 4, 2, 4, 8, 2, 5, 8, 8, 6, 6, 2, 6, 6, 8, 1, 2, 2, 8, 0, 8, 9, 0, 7, 9, 0, 1, 6, 6, 3, 6, 5, 1, 5, 9, 0, 3, 7, 3, 7, 2, 0, 0, 2, 7, 5, 2, 9, 5, 5, 8, 1, 7, 7, 9, 7, 1, 1, 6, 4, 3, 8, 0, 7, 9, 1, 0, 9, 5, 2, 7, 2, 1, 5, 3, 9, 7, 6, 9, 1, 3, 5, 5, 0, 6, 9, 4, 7, 1, 7, 2, 0, 4, 5, 8, 1, 6, 1, 0, 7, 2, 2, 6, 7, 4, 4, 9, 5, 4, 5, 2, 0, 8, 0, 5, 5, 1, 8, 9, 4, 5, 6, 1, 2, 0, 7, 0, 2, 1, 6, 8, 8, 7, 8, 7, 0, 1, 8, 5, 6, 5, 9, 2, 2, 9, 3, 6, 0, 1, 7, 9, 8, 1, 1, 5, 4, 5, 7, 5, 0, 2, 0, 4, 4, 8, 0, 7, 3]
<br/>
<br/>
[6, 2, 8, 1, 2, 0, 4, 3, 4, 6, 7, 1, 0, 7, 0, 7, 9, 4, 0, 1, 2, 3, 5, 6, 3, 5, 6, 7, 5, 4, 2, 4, 8, 2, 5, 8, 8, 6, 6, 2, 6, 6, 8, 1, 2, 2, 8, 0, 8, 9, 0, 7, 9, 0, 1, 6, 6, 3, 6, 5, 1, 5, 9, 0, 3, 7, 3, 7, 2, 0, 0, 2, 7, 5, 2, 9, 5, 5, 8, 1, 7, 7, 9, 7, 1, 1, 6, 4, 3, 8, 0, 7, 9, 1, 0, 9, 5, 2, 7, 2, 1, 5, 3, 9, 7, 6, 9, 1, 3, 5, 5, 0, 6, 9, 4, 7, 1, 7, 2, 0, 4, 5, 8, 1, 6, 1, 0, 7, 2, 2, 6, 7, 4, 4, 9, 5, 4, 5, 2, 0, 8, 0, 5, 5, 1, 8, 9, 4, 5, 6, 1, 2, 0, 7, 0, 2, 1, 6, 8, 8, 7, 8, 7, 0, 1, 8, 5, 6, 5, 9, 2, 2, 9, 3, 6, 0, 1, 7, 9, 8, 1, 1, 5, 4, 5, 7, 5, 0, 2, 0, 4, 4, 8, 0, 7, 3, 9, 1, 7, 5, 8, 6, 2, 2, 2, 6, 0, 8, 1, 9, 6, 8, 4, 8, 4, 3, 7, 0, 7, 8, 9, 5, 3, 4, 7, 4, 3, 5, 2, 2, 7, 8, 9, 7, 1, 9, 9, 8, 3, 5, 7, 1, 6, 9, 1, 2, 0, 6, 8, 0, 4, 1, 6, 5, 8, 7, 6, 8, 0, 5, 7, 8, 8, 6, 7, 5, 8, 0, 7, 6, 4, 9, 5, 9, 6, 4, 1, 5, 6, 2, 2, 6, 7, 0, 3, 4, 2, 3, 9, 0, 9, 6, 3, 6, 7, 5, 5, 5, 9, 0, 6, 1, 1, 5, 0, 9, 1, 1, 1, 0, 4, 6, 3, 3, 3, 5, 8, 7, 4, 7, 1, 7, 1, 8, 4, 2, 0, 1, 9, 0, 7, 9, 2, 8, 9, 2, 5, 3, 5, 9, 3, 2, 7, 3, 5, 9, 5, 5, 3, 2, 3, 9, 4, 1, 6, 1, 8, 3, 1, 4, 5, 2, 5, 7, 7, 0, 9, 6, 6, 4, 8, 1, 1, 6, 0, 2, 6, 0, 7, 5, 5, 0, 5, 2, 6, 9, 9, 9, 9, 2, 3, 0, 6, 8, 8, 4, 5, 6, 2, 8, 5, 9, 8, 3, 6, 8, 8, 6, 2, 1, 2, 1, 4, 6, 2, 0, 9, 3, 9, 6, 4, 2, 3, 6, 2, 0, 9, 8, 7, 0, 6, 0, 7, 0, 5, 9, 4, 3, 7, 9, 7, 3, 5, 7, 0, 3, 1, 8, 9, 9, 4, 0, 8, 6, 4, 6, 7, 3, 8, 1, 2, 1, 5, 4, 9, 5, 9, 5, 8, 6, 6, 8, 9, 4, 4, 0, 6, 4, 5, 3, 0, 3, 9, 7, 1, 7, 2, 5, 0, 1, 9, 1, 2, 5, 6, 8, 7, 1, 6, 9]
