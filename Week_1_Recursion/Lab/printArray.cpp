#include<iostream>
using namespace std;

void printArray(int n) {
    if (n == 0) cout << "0";
    else {
        printArray(n-1);
        cout << ", " << n;
    }
}

int main() {
    printArray(5); // Result: 0, 1, 2, 3, 4, 5
    cout << endl;
    
    printArray(10); // Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    cout << endl;

    printArray(11); // Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
    cout << endl;

    printArray(22); // Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
    cout << endl;

    printArray(1); // Result: 0, 1
    cout << endl;
    
    return 0;
}
