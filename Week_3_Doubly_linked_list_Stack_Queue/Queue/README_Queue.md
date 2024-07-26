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
