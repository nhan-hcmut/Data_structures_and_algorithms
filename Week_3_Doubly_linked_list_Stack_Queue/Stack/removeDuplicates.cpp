#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

string removeDuplicates(string S) {
    /*TODO*/
    stack<char> record;
    int len = S.length();
    
    for (int i = 0; i < len; i++) {
        if (record.empty() || S[i] != record.top()) record.push(S[i]);
        else record.pop();
    }
    string result = "";
    
    while (!record.empty()) {
        result = record.top() + result;
        record.pop();
    }
    return result;
}

int main() {

    //Test 1
    cout << removeDuplicates("abbaca") << endl; // Result: ca
    
    //Test 2
    cout << removeDuplicates("aab") << endl; // Result: b
    
    return 0;
}