#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// You can write helper methods

long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);
    
    long long current = 0;
    
    for (int i = 1; i <= n; i++) {
        current = q.front();
        q.pop();
        
        long long nextNice = current * 10 + 2;
        q.push(nextNice);
        q.push(nextNice + 3);
    }
    return current;
}

int main() {

    // test 1
    int n;
    cin >> n; // input: 5
    cout << nthNiceNumber(n) << endl; // result: 52
    
    /* test 2
    int n;
    cin >> n; // input: 10000
    cout << nthNiceNumber(n) << endl; // result: 2255522252225
    */
    return 0;
}