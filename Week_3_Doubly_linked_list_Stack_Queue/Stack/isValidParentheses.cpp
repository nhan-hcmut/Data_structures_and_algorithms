#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses (string s) {
    /*TODO*/
    int len = s.length();
    if (len == 0) return true;

    stack<char> record;
    char top;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            record.push(s[i]);
        }
        else if (record.empty()) return false;
        else {
            top = record.top();
            record.pop();

            switch (s[i]) {
                case ')':
                    if (top == '[' || top == '{') return false;
                    break;
                
                case ']':
                    if (top == '(' || top == '{') return false;
                    break;
                
                case '}':
                    if (top == '(' || top == '[') return false;
            }
        }
    }
    return record.empty();
}

int main() {
    cout << isValidParentheses("[]") << endl; // 1
    cout << isValidParentheses("[]()") << endl; // 1
    cout << isValidParentheses("[)") << endl; // 0
    return 0;
}