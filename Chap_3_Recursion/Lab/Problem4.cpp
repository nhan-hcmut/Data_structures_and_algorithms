#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(string str) {
    
    if (str[0] == ' ') return isPalindrome(str.substr(1, str.length()-1)); // If the first character is a blank space, remove it
    
    if (str[str.length()-1] == ' ') return isPalindrome(str.substr(0, str.length()-1)); // If the last character is a blank space, remove it
    
    if (str.length() <= 1) return true;
    
    if (str[0] != str[str.length()-1]) return false;
    
    return isPalindrome(str.substr(1, str.length()-2));
}

int main() {
    cout << isPalindrome("mom") << endl;
    cout << isPalindrome("do geese see god") << endl;
    return 0;
}
