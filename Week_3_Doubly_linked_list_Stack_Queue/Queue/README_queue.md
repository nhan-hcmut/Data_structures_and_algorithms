# bfs

Research queue which is implemented in C library at: http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.

Using queue, complete function **void bfs(vector\<vector\<int\>\> graph, int start)** to traverse all the nodes of the graph from given start node using Breadth First Search algorithm and data structure queue, and print the order of visited nodes. 

You can use below libraries in this question.

#include \<iostream\>
<br/>
#include \<vector\>
<br/>
#include \<queue\>

**For example:**

+ Test:
```cpp
int init_graph[10][10] = { {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                        {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                        {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
int n = 10;
vector<vector<int>> graph(n, vector<int>());
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        if (init_graph[i][j]) graph[i].push_back(j);
    }
}
bfs(graph, 0);
```
+ Result: 0 1 2 4 6 8 3 7 5 9
---
# class_Queue

Implement all methods in class Queue with template type T. The description of each method is written as comment in frame code.
```cpp
#ifndef QUEUE_H
#define QUEUE_H
#include "DLinkedList.h"
template<class T>
class Queue {

    protected:
    DLinkedList<T> list;

    public:
    Queue() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif /* QUEUE_H */
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

+ Test:
```cpp
Queue<int> queue;
assert(queue.empty());
assert(queue.size() == 0);
```
---
# interleaveQueue

Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Your task is to implement interleaveQueue function.

\<stack\> and \<queue\> are included.

For example:

+ Test 1:
```cpp
queue<int> q;
int n; cin >> n; // input: 4
for (int i = 0; i < n; i++){
    int element; cin >> element; // input: 1 2 3 4
    q.push(element);
}
interleaveQueue(q);
while (!q.empty()){
    cout << q.front() << ' ';
    q.pop();
}
```
+ Result 1: 1 3 2 4
<br/>

+ Test 2:
```cpp
queue<int> q;
int n; cin >> n; // Input: 6
for (int i = 0; i < n; i++){
    int element; cin >> element; // input: 2 4 6 8 10 12
    q.push(element);
}
interleaveQueue(q);
while (!q.empty()){
    cout << q.front() << ' ';
    q.pop();
}
```
+ Result 2: 2 8 4 10 6 12
---
# isBipartite

Research queue which is implemented in C library at http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.

Using queue, complete function **bool isBipartite(vector\<vector\<int\>\> graph)** to determine if a graph is bipartite or not (the graph can be disconnected). You can read more details here: https://en.wikipedia.org/wiki/Bipartite_graph.

You can use below libraries in this question:

#include \<iostream\>
<br/>
#include \<vector\>
<br/>
#include \<queue\>


**For example:**

+ Test:
```cpp
int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
int n = 6;

vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}
isBipartite(graph) ? cout << "Yes" : cout << "No";
```
+ Result: Yes
---
# nthNiceNumber

A nice number is a positive integer that contains only 2's and 5's.
Some nice numbers are: 2, 5, 22, 25, 52, 55, ...
Number 2 is the first nice number.

Given an integer N, return the Nth nice number.

**Note:** \<iostream\>, \<vector\>, \<queue\> are already included.

**Constraint:**
<br/>
1 <= n <= 10^6

**Example 1:**
<br/>
Input:
n = 5

Output:
52

**Explanation:**
<br/>
The sequence of nice numbers is 2, 5, 22, 25, 52, 55, ...
The 5th number in this sequence is 52

**Example 2:**
<br/>
Input:
n = 10000

Output:
2255522252225

**For example:**

+ Test 1:
```cpp
int n;
cin >> n; // Input: 5
cout << nthNiceNumber(n) << endl;
```
+ Result 1: 52
<br/>

+ Test 2:
```cpp
int n;
cin >> n; // Input: 10000
cout << nthNiceNumber(n) << endl;
```
+ Result 2: 2255522252225
---
# secondsToBeRotten

Given a n*m grid where each cell in the grid can have a value of 0, 1 or 2, which has the following meaning:

+ 0: Empty cell
+ 1: This cell contains a fresh apple
+ 2: This cell contains a rotten apple

After 1 second, the cell with rotten apple will rot all fresh apples in all the cells adjacent to it (i.e the cells (x+1, y), (x-1, y), (x, y+1), (x, y-1))

Determine the minimum time (in seconds) required to rot all apples. If this cannot be done, return -1.

**Note:** \<iostream\>, \<vector\>, and \<queue\> are already included.

Constraint: 1 <= n, m <= 500

Hint: Have you ever heard about breadth-first-search?

**Example 1:**

Input: grid = {{2,2,0,1}}
<br/>
Output: -1

**Explanation:**
The grid is { {2, 2, 0, 1} }. The apple at (0, 3) cannot be rotten
<br/>

**Example 2:**

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
<br/>
Output: 1

**Explanation:** The grid is { {0, 1, 2}, {0, 1, 2}, {2, 1, 1} }
<br/>
Apples at positions (0,2), (1,2), (2,0) will rot apples at (0,1), (1,1), (2,2) and (2,1) after 1 second.

**For example:**

+ Test 1:
```cpp
int rows, cols;
cin >> rows >> cols; // Input: 1 4
vector<vector<int>> grid(rows, vector<int>(cols));
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) cin >> grid[i][j]; // Input: 2 2 0 1
}
cout << secondsToBeRotten(grid);
```
+ Result 1: -1
<br/>

+ Test 2:
```cpp
int rows, cols;
cin >> rows >> cols; // Input: 3 3
vector<vector<int>> grid(rows, vector<int>(cols));
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) cin >> grid[i][j]; // input: {0 1 2} {0 1 2} {2 1 1}
}
cout << secondsToBeRotten(grid);
```
+ Result 2: 1
---
# sumOfMaxSubarray

Given an array of integers.

Your task is to implement a function with following prototype:
```cpp
int sumOfMaxSubarray(vector<int>& nums, int k);
```
The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

**Note:**
+ The \<iostream\>, \<vector\>, \<queue\> and \<deque\> libraries have been included and namespace std is being used. No other libraries are allowed.
+ You can write helper functions and classes.

**For example:**

+ Test 1:
```cpp
vector<int> nums {1, 2, 4, 3, 6};
int k = 3;
cout << sumOfMaxSubarray(nums, k);
```
+ Result 1: 14
<br/>

+ Test 2:
```cpp
vector<int> nums {8016};
int k = 1;
cout << sumOfMaxSubarray(nums, k);
```
+ Result 2: 8016
---
