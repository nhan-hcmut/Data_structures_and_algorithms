#include <iostream>
#include <string>
using namespace std;

// Helping functions
int countDigit(string str, int index = 0) {
    
    if (index >= str.length()) return 0;
    
    if ('0'<=str[index] && str[index]<='9') return 1 + countDigit(str, index+1);
    
    return countDigit(str, index+1);
}

int countParenthesis(string str, int index = 0) {
    
    if (index >= str.length()) return 0;
    
    if (str[index]=='(' || str[index]==')') return 1 + countParenthesis(str, index+1);
    
    return countParenthesis(str, index+1);
}

string repeatString(string str, int num) {
    
    if (num == 0) return "";

    return str + repeatString(str, num-1);
}

int findIndexOfDigit(string str, int index = 0) { // find index of the first digit in the string
    
    if (index >= str.length()) return -1; // if there is no digit, return -1

    if ('0'<=str[index] && str[index]<='9') return index;

    return findIndexOfDigit(str, index+1);
}

int findIndexOfOpenParenthesis(string str, int index = 0) { // find index of open parenthesis

    if (index >= str.length()) return -1; // if there is no open parenthesis, return -1
    
    if (str[index] == '(') return index;

    return findIndexOfOpenParenthesis(str, index+1);
}

int findIndexOfRespectiveCloseParenthesis(string str, int indexAfterOpenParenthesis, int numberOfOpenParenthesis = 1, int numberOfCloseParenthesis = 0) { // find index of the respective close parenthesis

    if (numberOfOpenParenthesis == numberOfCloseParenthesis) return indexAfterOpenParenthesis - 1;

    if (str[indexAfterOpenParenthesis] == '(') return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis+1, numberOfOpenParenthesis+1, numberOfCloseParenthesis);

    if (str[indexAfterOpenParenthesis] == ')') return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis+1, numberOfOpenParenthesis, numberOfCloseParenthesis+1);

    return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis+1, numberOfOpenParenthesis, numberOfCloseParenthesis);
}
// End helping functions

string expand(string s) {

    if (findIndexOfDigit(s) == -1) return s; // if there is no digit, do nothing

    int indexOfOpenParenthesis = findIndexOfOpenParenthesis(s),
    indexOfCloseParenthesis = findIndexOfRespectiveCloseParenthesis(s, indexOfOpenParenthesis+1),
    sLen = s.length(),
    repetition = s[indexOfOpenParenthesis-1] - '0'; // convert from ASCII code to number

    string substring = s.substr(indexOfOpenParenthesis+1, indexOfCloseParenthesis-indexOfOpenParenthesis-1); // find substring inside 2 parentheses

    if (indexOfOpenParenthesis==1 && indexOfCloseParenthesis < sLen-1) return repeatString(expand(substring), repetition) + expand(s.substr(indexOfCloseParenthesis+1, sLen-indexOfCloseParenthesis-1)); // if a substring starts from the beginning of s and ends in the middle of s

    if (indexOfOpenParenthesis>1 && indexOfCloseParenthesis < sLen-1) return s.substr(0, indexOfOpenParenthesis-1) + repeatString(expand(substring), repetition) + expand(s.substr(indexOfCloseParenthesis+1, sLen-indexOfCloseParenthesis-1)); // if a substring starts from middle of s and ends in the middle of s

    if (indexOfOpenParenthesis>1 && indexOfCloseParenthesis == sLen-1) return s.substr(0, indexOfOpenParenthesis-1) + repeatString(expand(substring), repetition); // if a substring starts from middle of s and ends at the end of s

    return repeatString(expand(substring), repetition); // a substring starts from the beginning of s and ends at the end of s
}

int main() {

    cout << expand("2(ab3(cde)x)") << endl; // result: abcdecdecdexabcdecdecdex
    
    cout << expand("2(x0(y))3(z)") << endl; // result: xxzzz

    return 0;
}
