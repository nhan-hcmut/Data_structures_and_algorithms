#include<iostream>
#include<string>
#include<stack>
using namespace std;

int baseballScore(string ops) {
    /*TODO*/
    int score = 0, len = ops.length();
    stack<int> record;
    
    for (int i = 0; i < len; i++) {
        if ('0'<=ops[i] && ops[i]<='9') {
            record.push(stoi(ops.substr(i, 1)));
        }
        else if (ops[i] == '+') {
            score = record.top();
            record.pop();
            score += record.top();
            record.push(score - record.top());
            record.push(score);
            score = 0;
        }
        else if (ops[i] == 'D') {
            record.push(record.top() * 2);
        }
        else if (ops[i] == 'C') {
            record.pop();
        }
    }
    int sum = 0;
    while (!record.empty()) {
        sum += record.top();
        record.pop();
    }
    return sum;
}

int main() {

    // Test 1
    cout << baseballScore("52CD+") << endl; // Result: 30
    
    // Test 2
    cout << baseballScore("524CD9++") << endl; // Result: 55
    
    // Test 3
    cout << baseballScore("5C4C2C11+D3") << endl; // Result: 11
    
    return 0;
}
