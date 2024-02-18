#include<iostream>
using namespace std;

void printArray(int n) {
    if (n == 0) cout << "0";

    else {
        printArray(n-1);
        cout << ", ";
        cout << n;
    }
}

int main() {
    printArray(5);
    cout << endl;
    printArray(10);

    return 0;
}
