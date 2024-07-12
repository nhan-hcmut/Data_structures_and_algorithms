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
