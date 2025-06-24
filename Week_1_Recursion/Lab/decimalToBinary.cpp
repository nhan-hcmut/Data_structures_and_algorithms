#include <iostream>
using namespace std;

int decimalToBinary(int decimal_number) {
    /*
     * STUDENT ANSWER
    */
    if (decimal_number == 0) return 0;
    
    return decimalToBinary(decimal_number / 2) * 10 + decimal_number % 2;
}

int main() {
    cout << decimalToBinary(20) << endl; // result: 10100
    
    cout << decimalToBinary(19) << endl; // result: 10011

    cout << decimalToBinary(18) << endl; // result: 10010

    cout << decimalToBinary(17) << endl; // result: 10001

    cout << decimalToBinary(16) << endl; // result: 10000

    cout << decimalToBinary(15) << endl; // result: 1111

    cout << decimalToBinary(14) << endl; // result: 1110

    cout << decimalToBinary(13) << endl; // result: 1101
    
    cout << decimalToBinary(12) << endl; // result: 1100

    cout << decimalToBinary(11) << endl; // result: 1011
    
    return 0;
}