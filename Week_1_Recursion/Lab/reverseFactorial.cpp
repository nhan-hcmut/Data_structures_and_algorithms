#include <iostream>
using namespace std;

/* Method 2
int reverseFactorialRec(int n, int kFactorial = 1, int k = 1) {

    if (kFactorial > n) return -1;
    
    if (kFactorial == n) return k;
    
    return reverseFactorialRec(n, kFactorial * (k + 1), k + 1);
}
End method 2 */

// Helping functions
int factorial(int num) {
    
    if (num == 1) return 1;
    
    return num * factorial(num - 1);
}

int reverseFactorialRec(int n, int result = 1) { // 'result' is initially set to 1 and is incremented until factorial of result == n or exceeds n

    if (factorial(result) > n) return -1; // If factorial of result exceeds n, return -1 (no valid result found)
    
    if (factorial(result) == n) return result; // If factorial of result equals n, return the result (this is the number whose factorial equals n)
    
    return reverseFactorialRec(n, result + 1); // If factorial of result is less than n, try the next number (increment result and call recursively)
}
// End helping functions

int reverseFactorial(int n) {
    // STUDENT ANSWER
    
    if (n < 1) return -1; // If n is less than 1, return -1 because no factorial is less than 1
    
    return reverseFactorialRec(n);
}

int main() {

    cout << endl << reverseFactorial(120) << endl; // result: 5 (because 120 = 5!)
    
    cout << endl << reverseFactorial(24) << endl; // result: 4 (because 24 = 4!)

    cout << endl << reverseFactorial(6) << endl; // result: 3 (because 6 = 3!)

    cout << endl << reverseFactorial(2) << endl; // result: 2 (because 2 = 2!)

    cout << endl << reverseFactorial(1) << endl; // result: 1 (because 1 = 1!)

    cout << endl << reverseFactorial(0) << endl; // result: -1 (because there are no such numbers, return -1)

    cout << endl << reverseFactorial(3) << endl; // result: -1 (because there are no such numbers, return -1)

    cout << endl << reverseFactorial(4) << endl; // result: -1 (because there are no such numbers, return -1)

    cout << endl << reverseFactorial(5) << endl; // result: -1 (because there are no such numbers, return -1)

    return 0;
}
