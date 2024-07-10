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
    printHailstone(6);
    cout << endl;
    
    printHailstone(7);
    cout << endl;

    return 0;
}
