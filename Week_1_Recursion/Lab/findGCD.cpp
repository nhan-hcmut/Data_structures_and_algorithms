#include<iostream>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) return a;
    return findGCD(b, a%b);
}

int main() {
    cout << findGCD(124, 32) << endl; // result: 4

    cout << findGCD(138, 184) << endl; // result: 46

    cout << findGCD(138, 91) << endl; // result: 1

    cout << findGCD(138, 6) << endl; // result: 6

    cout << findGCD(307, 2000) << endl; // result: 1

    return 0;
}
