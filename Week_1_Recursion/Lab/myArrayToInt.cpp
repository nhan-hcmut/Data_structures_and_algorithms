#include <iostream>
#include <cstring>
using namespace std;

int myArrayToInt(char* str, int n) {
    
    if (n == 1) return (int)(*str - '0');
    
    return (int)(str[n-1] - '0') + (10 * myArrayToInt(str, n-1));
}

int main()
{
    char str[] = "2020";
    
    cout << myArrayToInt(str, 4);

    return 0;
}
