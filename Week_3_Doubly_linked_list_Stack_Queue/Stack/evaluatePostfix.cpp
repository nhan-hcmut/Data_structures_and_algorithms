#include<iostream>
#include<string>
#include<stack>
using namespace std;

int evaluatePostfix(string expr) {
    /*TODO*/
    stack<int> record;
    int len = expr.length(), firstNum = 0, secondNum = 0, num;
    string str = "";
    
    for (int i = 0; i < len; i++) {
        if ('0' <= expr[i] && expr[i] <= '9') {
            num = 0;
            while ('0' <= expr[i] && expr[i] <= '9') {
                str = expr[i];
                num = num * 10 + stoi(str);
                i++;
            }
            record.push(num);
        }
        else if (expr[i] == ' ') {
            continue;
        }
        else if (expr[i] == '+') {
            secondNum = record.top();
            record.pop();
            firstNum = record.top();
            record.pop();
            record.push(firstNum + secondNum);
        }
        else if (expr[i] == '-') {
            secondNum = record.top();
            record.pop();
            firstNum = record.top();
            record.pop();
            record.push(firstNum - secondNum);
        }
        else if (expr[i] == '*') {
            secondNum = record.top();
            record.pop();
            firstNum = record.top();
            record.pop();
            record.push(firstNum * secondNum);
        }
        else if (expr[i] == '/') {
            secondNum = record.top();
            record.pop();
            firstNum = record.top();
            record.pop();
            record.push(firstNum / secondNum);
        }
    }
    return record.top();
}

int main() {
    //Test 1
    cout << evaluatePostfix("2 3 1 * + 9 -") << endl; // result: -4
    
    //Test 2
    cout << evaluatePostfix("100 200 + 2 / 5 * 7 +") << endl; // result: 757
    
    return 0;
}