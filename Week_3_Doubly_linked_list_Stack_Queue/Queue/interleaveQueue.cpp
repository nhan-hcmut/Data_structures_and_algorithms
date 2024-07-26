#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    stack<int> stk;
    int half = q.size() / 2;
 
    for (int i = 0; i < half; i++) {
        stk.push(q.front());
        q.pop();
    }
 
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
 
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }
 
    for (int i = 0; i < half; i++) {
        stk.push(q.front());
        q.pop();
    }
 
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {

    // test 1
    queue<int> q;
    int n; cin >> n; // input: 4
    for (int i = 0; i < n; i++){
        int element; cin >> element; // input: 1 2 3 4
        q.push(element);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' '; // result: 1 3 2 4
        q.pop();
    }
    
    /* test 2
    queue<int> q;
    int n; cin >> n; // input: 6
    for (int i = 0; i < n; i++){
        int element; cin >> element; // input: 2 4 6 8 10 12
        q.push(element);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' '; // result: 2 8 4 10 6 12
        q.pop();
    }
    */
    return 0;
}
