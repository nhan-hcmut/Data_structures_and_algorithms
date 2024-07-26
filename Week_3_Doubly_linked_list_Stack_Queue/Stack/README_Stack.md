# baseballScore

You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:
+ A non-negative integer x (from 0 to 9) - record a new score of x
+ '+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
+ 'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
+ 'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.

Finally, return the sum of all scores in the record.

**For example:**
<br/>
ops = "52CD+"

+ '5' - add to the record. Record now is [5]
+ '2' - add to the record. Record now is [5,2]
+ 'C' - invalid the previous score (2). Record now is [5]
+ 'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
+ '+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]

Return the sum: 5+10+15 = 30

**For example:**

+ Test 1: cout << baseballScore("52CD+");
+ Result 1: 30
<br/>

+ Test 2: cout << baseballScore("524CD9++");
+ Result 2: 55
<br/>

+ Test 3: cout << baseballScore("5C4C2C11+D3");
+ Result 3: 11
---
# class_Stack

Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.
```cpp
#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
    protected:
    DLinkedList<T> list;

    public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif
```
You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.
```cpp
template <class T>
class DLinkedList {
    public:
    class Node;     //forward declaration

    protected:
    Node* head;
    Node* tail;
    int count;

    public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};
```
**For example:**

+ Test 1:
```cpp
Stack<int> stack;
cout << stack.empty() << " " << stack.size();
```
+ Result 1: 1 0
<br/>

+ Test 2:
```cpp
Stack<int> stack;

int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);
    
assert(stack.top() == 12);
    
stack.pop();
stack.pop();
    
cout << stack.top();
```
+ Result 2: 8
---