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
# canEatFood

A Maze is given as 5*5 binary matrix of blocks and there is a rat initially at the upper left most block i.e., maze[0][0] and the rat wants to eat food which is present at some given block in the maze (fx, fy). In a maze matrix, 0 means that the block is a dead end and 1 means that the block can be used in the path from source to destination. The rat can move in any direction (not diagonally) to any block provided the block is not a dead end.

Your task is to implement a function with following prototype to check if there exists any path so that the rat can reach the food or not:
```cpp
bool canEatFood(int maze[5][5], int fx, int fy);
```
Template:
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
    public:
    int x, y;
    int dir;
    node(int i, int j) {
        x = i;
        y = j;
  
        // Initially direction set to 0
        dir = 0;
    }
};
```
**Some suggestions:**
<br/>
- X : x coordinate of the node
- Y : y coordinate of the node
- dir : This variable will be used to tell which all directions we have tried and which to choose next. We will try all the directions in anti-clockwise manner starting from up.

If dir=0 try up direction.
<br/>
If dir=1 try left direction.
<br/>
If dir=2 try down direction.
<br/>
If dir=3 try right direction.

**For example:**

+ Test 1:
```cpp
// Maze matrix
int maze[5][5] = {
    { 1, 0, 1, 1, 0 },
    { 1, 1, 1, 0, 1 },
    { 0, 1, 0, 1, 1 },
    { 1, 1, 1, 1, 0 },
    { 1, 0, 0, 1, 0 }
};

// Food coordinates
int fx = 1, fy = 4;

cout << canEatFood(maze, fx, fy);
```
+ Result 1: 1
<br/>

+ Test 2:
```cpp
// Maze matrix
int maze[5][5] = {
    { 1, 0, 1, 1, 0 },
    { 1, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 1 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 }
};

// Food coordinates
int fx = 2, fy = 3;

cout << canEatFood(maze, fx, fy);
```
+ Result 2: 1
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
# evaluatePostfix

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.

**For example:** Given string S is  "2 3 1 * + 9 -". If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

**Requirement:** Write the function to evaluate the value of postfix expression.

**For example:**

+ Test 1:
```cpp
cout << evaluatePostfix("2 3 1 * + 9 -");
```
+ Result 1: -4
<br/>

+ Test 2:
```cpp
cout << evaluatePostfix("100 200 + 2 / 5 * 7 +");
```
+ Result 2: 757
---
# nextGreater

Given an array nums[] of size N having distinct elements, the task is to find the next greater element for each element of the array
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist a next greater of a element, the next greater element for it is -1

**Note:** \<iostream\>, \<stack\> and \<vector\> are already included

Constraints:
<br/>
1 <= nums.length <= 10^5
<br/>
0 <= nums[i] <= 10^9

**Example 1:**
<br/>
Input: nums = {15, 2, 4, 10}
<br/>
Output: {-1, 4, 10, -1}

**Example 2:**
<br/>
Input: nums = {1, 4, 6, 9, 6}
<br/>
Output: {4, 6, 9, -1, -1}

**For example:**

+ Test 1:
```cpp
int N;
cin >> N; // input: 4
vector<int> nums(N);
for(int i = 0; i < N; i++) cin >> nums[i]; // input: 15 2 4 10
vector<int> greaterNums = nextGreater(nums);
for(int i : greaterNums)
    cout << i << ' ';
cout << '\n';
```
+ Result 1: -1 4 10 -1
<br/>

+ Test 2:
```cpp
int N;
cin >> N; // input: 5
vector<int> nums(N);
for(int i = 0; i < N; i++) cin >> nums[i]; // input: 1 4 6 9 6
vector<int> greaterNums = nextGreater(nums);
for(int i : greaterNums) cout << i << ' ';
cout << '\n';
```
+ Result 2: 4 6 9 -1 -1
---
# removeDuplicates

Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.

Included **libraries:** \<vector\>, \<list\>, \<stack\>

**For example:**

+ Test 1:
```cpp
cout << removeDuplicates("abbaca");
```
+ Result 1: ca
<br/>

+ Test 2:
```cpp
cout << removeDuplicates("aab");
```
+ Result 2: b
---
# stock_span

The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of the stock’s price for each day.

The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day, plus 1 (for itself).

**For example:** take the stock's price sequence [100, 80, 60, 70, 60, 75, 85].

The given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on.

Hence the output will be [1, 1, 1, 2, 1, 4, 6].

**Requirement:** Write a program to calculate the spans from the stock's prices.

(Source: Geeks For Geeks)
**For example:**

Input	Result

100 80 60 70 60 75 85
	1 1 1 2 1 4 6

10 4 5 90 120 80
	1 1 2 4 5 1

---
