#include<iostream>
using namespace std;

// Helping functions
int minimumBracketAddHelper(const string &s, int index = 0, int unmatchedOpenBracket = 0, int unmatchedCloseBracket = 0) {
    if (index >= s.length()) return unmatchedOpenBracket + unmatchedCloseBracket; // If index >= s.length() -> out of bounds -> all parentheses are checked -> stop

    if (s[index] == '(') return minimumBracketAddHelper(s, index + 1, unmatchedOpenBracket + 1, unmatchedCloseBracket); // if s[index] is an open bracket, there is one more unmatched one

    if (unmatchedOpenBracket) return minimumBracketAddHelper(s, index + 1, unmatchedOpenBracket - 1, unmatchedCloseBracket); // if s[index] is a close bracket and there are some unmatched open brackets, we need to decrease the number of unmatched open brackets by 1
    
    return minimumBracketAddHelper(s, index + 1, unmatchedOpenBracket, unmatchedCloseBracket + 1); // if s[index] is a close bracket and there is no unmatched open bracket, we need to increase the number of unmatched close bracket by 1
}
// End helping functions

int minimumBracketAdd(string s) {
    return minimumBracketAddHelper(s);
}

int main() {
    
    cout << minimumBracketAdd(")))((") << endl; // result: 5

    cout << minimumBracketAdd("))()))()()") << endl; // result: 4

    cout << minimumBracketAdd("") << endl; // result: 0

    cout << minimumBracketAdd(")()))()))())())))))(") << endl; // result: 12

    cout << minimumBracketAdd(")())(((())()())()())))()()))(()((((()(()()()))()((())((()))))))()(((()(((())(((()()(())(())))))(()))") << endl; // result: 10
    
    cout << minimumBracketAdd(")(()())())))))(((())))))())))()))))))((())(((()(((())((()(()))())(()(()((((((())))(((()))))((())((()()))((())(()(((()())()()())(())())))(()))()))((((()()(()))()))))()()()(()))()))()())()(()())))())())()))())())((()()(())((()()(((()((()((((((((())()()())(()()()))()()()())()(()(())())((()))((((()((((((()((()))))))()))((()())))()()((((()()()(()())((((()((((((())))(()))))(()))))()())())(((())()())()(((())))(())(((()(((())))(((()()(()(((()((()(()))())))))()(()(())()())(((()(()(())()()())()(()()))(((()))()())()))))((()())(())()))(()))())(())))()))())()()(()()(((((()(()()(()()))(()(()(())()((((()((()(()(())))()())((()()(((()))(()))()(())()((()()(((((())(((())(()())()))))()((()))((()))(()())()))()())()))(()((()()()((()()))(())(())(((())()())(())()((())(((()(())(()))(())()(((())((()())((()))(((((()(())()()()()(()(()))(()()())())))))()))))()()))(())(((((((((()))(())))(()))(()))(()((()()(((()))))(()(())((((()))(()))))(()((()((()(((()))()))(()((())()))))(()))(()()))()((((()(((()()(()))()((()(((())") << endl; // result: 70
    
    return 0;
}
