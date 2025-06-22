#include <iostream>
#include <string>
using namespace std;

// Helping functions
int countDigit(const string& str, int index = 0) { // Count the number of digits in the string
    
    if (index >= str.length()) return 0; // If the index is out of bounds, return 0 to stop the recursion
    
    if ('0' <= str[index] && str[index] <= '9') return 1 + countDigit(str, index + 1); // If the character at the index is a digit, the result is 1 plus the number of digits from the next character onward
    
    return countDigit(str, index + 1); // If the character at the index is not a digit, the result is the number of digits from the next character onward
}

int countParenthesis(const string& str, int index = 0) {
    
    if (index >= str.length()) return 0; // If the index is out of bounds, return 0 to stop the recursion
    
    if (str[index] == '(' || str[index] == ')') return 1 + countParenthesis(str, index + 1); // If the character at the index is a parenthesis, the result is 1 plus the number of parentheses from the next character onward
    
    return countParenthesis(str, index + 1); // If the character at the index is not a parenthesis, the result is the number of parenthesis from the next character onward
}

string repeatString(const string& str, int num) { // Repeat string str "num" times
    
    if (num == 0) return ""; // If num = 0, return an empty string

    return str + repeatString(str, num - 1); // If num > 0, concatenate string "str" with the result of repeating it "num-1" times
}

int findIndexOfDigit(const string& str, int index = 0) { // Find index of the first digit in the string
    
    if (index >= str.length()) return -1; // If there are no digits, return -1

    if ('0' <= str[index] && str[index] <= '9') return index;

    return findIndexOfDigit(str, index + 1);
}

int findIndexOfOpenParenthesis(const string& str, int index = 0) { // Find index of open parenthesis

    if (index >= str.length()) return -1; // If there is no open parenthesis, return -1
    
    if (str[index] == '(') return index;

    return findIndexOfOpenParenthesis(str, index + 1);
}

int findIndexOfRespectiveCloseParenthesis(const string& str, int indexAfterOpenParenthesis, int numberOfOpenParenthesis = 1, int numberOfCloseParenthesis = 0) { // Find index of the respective close parenthesis

    if (numberOfOpenParenthesis == numberOfCloseParenthesis) return indexAfterOpenParenthesis - 1; // If the number of open parentheses and close parentheses are the same -> we have found the respective close parenthesis

    if (str[indexAfterOpenParenthesis] == '(') return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis + 1, numberOfOpenParenthesis + 1, numberOfCloseParenthesis);

    if (str[indexAfterOpenParenthesis] == ')') return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis + 1, numberOfOpenParenthesis, numberOfCloseParenthesis + 1);

    return findIndexOfRespectiveCloseParenthesis(str, indexAfterOpenParenthesis + 1, numberOfOpenParenthesis, numberOfCloseParenthesis);
}
// End helping functions

string expand(string s) {

    if (findIndexOfDigit(s) == -1) return s; // If there are no digits, do nothing

    int indexOfOpenParenthesis = findIndexOfOpenParenthesis(s),
        indexOfCloseParenthesis = findIndexOfRespectiveCloseParenthesis(s, indexOfOpenParenthesis + 1),
        sLen = s.length(),
        repetition = s[indexOfOpenParenthesis - 1] - '0'; // convert from ASCII code to number

    string substring = s.substr(indexOfOpenParenthesis + 1, indexOfCloseParenthesis - indexOfOpenParenthesis - 1); // find substring inside 2 parentheses

    if (indexOfOpenParenthesis == 1 && indexOfCloseParenthesis < sLen - 1) return repeatString(expand(substring), repetition) + expand(s.substr(indexOfCloseParenthesis + 1, sLen - indexOfCloseParenthesis - 1)); // if a substring starts from the beginning of s and ends in the middle of s

    if (indexOfOpenParenthesis > 1 && indexOfCloseParenthesis < sLen - 1) return s.substr(0, indexOfOpenParenthesis - 1) + repeatString(expand(substring), repetition) + expand(s.substr(indexOfCloseParenthesis + 1, sLen - indexOfCloseParenthesis - 1)); // if a substring starts from middle of s and ends in the middle of s

    if (indexOfOpenParenthesis > 1 && indexOfCloseParenthesis == sLen - 1) return s.substr(0, indexOfOpenParenthesis - 1) + repeatString(expand(substring), repetition); // if a substring starts from middle of s and ends at the end of s

    return repeatString(expand(substring), repetition); // a substring starts from the beginning of s and ends at the end of s
}

int main() {

    cout << expand("2(ab3(cde)x)") << endl; // result: abcdecdecdexabcdecdecdex
    
    cout << expand("2(x0(y))3(z)") << endl; // result: xxzzz

    return 0;
}
