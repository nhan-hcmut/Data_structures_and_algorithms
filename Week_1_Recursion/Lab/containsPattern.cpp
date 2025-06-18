#include <iostream>
using namespace std;

// Helping function
bool matchesFromCurrent(char* text, char* pattern) {

    if (*pattern == '\0') return true; // We have reached the end of the pattern first => all characters of the pattern match => return true
    
    if (*text == '\0') return false; // We have reached the end of the text first => not match => return false
    
    if (*text != *pattern) return false; // The current character of the text does not match => return false
    
    return matchesFromCurrent(text + 1, pattern + 1); // The current character of the text matches the current character of the pattern => check if the rest of the text matches the rest of the pattern
}
// End helping function

bool containsPattern(char* text, char* pattern) {
    /*
     * STUDENT ANSWER
    */
    if (*pattern == '\0') return true; // We have reached the end of the pattern first => all characters of the pattern match => return true
    
    if (*text == '\0') return false; // We have reached the end of the text first => not match => return false
    
    if (*text != *pattern) return containsPattern(text + 1, pattern); // The current character of the text does not match => check the next character of the text
    
    if (matchesFromCurrent(text + 1, pattern + 1)) return true; // The current character of the text matches the current character of the pattern => check if the rest of the text matches the rest of the pattern

    return containsPattern(text + 1, pattern); // The rest of the text does not match the rest of the pattern => check the next character of the text
}

int main() {
    cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"Bach Khoa") << endl; // result: 1

    cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"Bach KHoa") << endl; // result: 0

    cout << containsPattern((char*)"Bach Khoa", (char*)"Dai hoc Bach Khoa") << endl; // result: 0

    cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"h Khoa") << endl; // result: 1

    cout << containsPattern((char*)"Bo mon hoa HC, Dai hoc Bach Khoa DHQG TP.HCM", (char*)"Bo mon hoa VC") << endl; // result: 0
    
    return 0;
}