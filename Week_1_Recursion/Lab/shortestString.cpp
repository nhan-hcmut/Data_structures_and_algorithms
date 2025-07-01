#include <iostream>
using namespace std;

int shortestString(string s) {
    // STUDENT ANSWER
    
    if (s.length() < 2) return s.length(); // If the string length is less than 2, no transformation is possible, so return the length of the string

    if (s.find("01") != string::npos) return shortestString(s.erase(s.find("01"), 2)); // If the string contains the substring "01", remove it and call the function recursively on the new string after erasing 2 characters starting from "01"

    if (s.find("10") != string::npos) return shortestString(s.erase(s.find("10"), 2)); // If the string contains the substring "10", remove it and call the function recursively on the new string after erasing 2 characters starting from "10"

    return s.length(); // If neither "01" nor "10" are found, no more transformations are possible, return the length of the string
}

int main() {
    cout << endl << shortestString("01110") << endl; // result: 1 ("01110" -> "011" after removing "10", then "1" after removing "01", so the result is 1)

    cout << endl << shortestString("") << endl; // result: 0 (an empty string -> no transformations needed, so the result is 0)

    cout << endl << shortestString("0") << endl; // result: 1 ("0" -> cannot be transformed, so the result is 1)

    cout << endl << shortestString("1") << endl; // result: 1 ("1" -> cannot be transformed, so the result is 1)

    cout << endl << shortestString("00") << endl; // result: 2 ("00" -> cannot be transformed, so the result is 2)

    cout << endl << shortestString("01") << endl; // result: 0 ("01" -> "01" is found and removed, so the result is 0)

    cout << endl << shortestString("10") << endl; // result: 0 ("10" -> "10" is found and removed, so the result is 0)

    cout << endl << shortestString("11") << endl; // result: 2 ("11" -> cannot be transformed, so the result is 2)
    
    return 0;
}
