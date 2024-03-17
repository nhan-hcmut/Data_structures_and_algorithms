#include <iostream>
using namespace std;

int strLen(char* str) {
    
    if (*str == '\0') return 0;
    
    return 1 + strLen(str+1);
}

int main() {
    char str[] = "Ho Chi Minh City University of Technology";
    
    cout << strLen(str);

    return 0;
}
