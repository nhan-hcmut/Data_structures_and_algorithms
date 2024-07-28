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
