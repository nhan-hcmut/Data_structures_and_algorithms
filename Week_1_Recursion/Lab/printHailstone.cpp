#include<iostream>
using namespace std;

void printHailstone(int number) {
    cout << number;
    if (number == 1) return;
    
    cout << ' ';
    if (number%2 == 0) printHailstone(number/2);
    else printHailstone(3*number + 1);
}

int main() {
    printHailstone(5); // Result: 5 16 8 4 2 1
    cout << endl;
    
    printHailstone(6); // Result: 6 3 10 5 16 8 4 2 1
    cout << endl;
    
    printHailstone(7); // Result: 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(11); // Result: 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(12); // Result: 12 6 3 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(13); // Result: 13 40 20 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(22); // Result: 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(23); // Result: 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
    cout << endl;

    printHailstone(32); // Result: 32 16 8 4 2 1
    cout << endl;

    return 0;
}
