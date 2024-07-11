#include<iostream>
using namespace std;

// Helping functions
int mininumBracketAddHelper(string &s, int index = 0, int unmatchedOpenBracket = 0, int unmatchedCloseBracket = 0) {

    if (s[index] == '(') return mininumBracketAddHelper(s, index+1, unmatchedOpenBracket+1, unmatchedCloseBracket); // if s[index] is an open bracket, there is one more unmatched one

    if (s[index] == ')') {

        if (unmatchedOpenBracket) return mininumBracketAddHelper(s, index+1, unmatchedOpenBracket-1, unmatchedCloseBracket); // if s[index] is a close bracket and there are some unmatched open brackets, we need to decrease the number of unmatched open brackets by 1

        return mininumBracketAddHelper(s, index+1, unmatchedOpenBracket, unmatchedCloseBracket+1); // if s[index] is a close bracket and there is no unmatched open bracket, we need to increase the number of unmatched close bracket by 1
    }
    
    return unmatchedOpenBracket + unmatchedCloseBracket;
}
// End helping functions

int mininumBracketAdd(string s) {
    return mininumBracketAddHelper(s);
}

int main() {
    
    cout << mininumBracketAdd(")))((") << endl; // result: 5

    cout << mininumBracketAdd("))()))()()") << endl; // result: 4

    cout << mininumBracketAdd("") << endl; // result: 0

    cout << mininumBracketAdd(")()))()))())())))))(") << endl; // result: 12

    cout << mininumBracketAdd(")())(((())()())()())))()()))(()((((()(()()()))()((())((()))))))()(((()(((())(((()()(())(())))))(()))") << endl; // result: 10
    
    cout << mininumBracketAdd(")(()())())))))(((())))))())))()))))))((())(((()(((())((()(()))())(()(()((((((())))(((()))))((())((()()))((())(()(((()())()()())(())())))(()))()))((((()()(()))()))))()()()(()))()))()())()(()())))())())()))())())((()()(())((()()(((()((()((((((((())()()())(()()()))()()()())()(()(())())((()))((((()((((((()((()))))))()))((()())))()()((((()()()(()())((((()((((((())))(()))))(()))))()())())(((())()())()(((())))(())(((()(((())))(((()()(()(((()((()(()))())))))()(()(())()())(((()(()(())()()())()(()()))(((()))()())()))))((()())(())()))(()))())(())))()))())()()(()()(((((()(()()(()()))(()(()(())()((((()((()(()(())))()())((()()(((()))(()))()(())()((()()(((((())(((())(()())()))))()((()))((()))(()())()))()())()))(()((()()()((()()))(())(())(((())()())(())()((())(((()(())(()))(())()(((())((()())((()))(((((()(())()()()()(()(()))(()()())())))))()))))()()))(())(((((((((()))(())))(()))(()))(()((()()(((()))))(()(())((((()))(()))))(()((()((()(((()))()))(()((())()))))(()))(()()))()((((()(((()()(()))()((()(((())") << endl; // result: 70
    
    return 0;
}
