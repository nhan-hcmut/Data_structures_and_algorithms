#include <iostream>
using namespace std;

int strLen(char* str) {
    
    if (*str == '\0') return 0;
    
    return 1 + strLen(str+1);
}

int main() {
    char str1[] = "Ho Chi Minh City University of Technology";
    cout << strLen(str1) << endl;

    char str2[] = "Truong DH Bach Khoa";
    cout << strLen(str2) << endl;
    
    return 0;
}
