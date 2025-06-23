#include <iostream>
#include <cmath>
using namespace std;

int countWaySumOfSquareRec(int x, int uniqueInteger) { // Recursive helper function to count the number of ways to express x as sum of squares of unique natural numbers, starting from uniqueInteger
    
    int remainder = x - (uniqueInteger * uniqueInteger); // Calculate the remaining value after subtracting the square of the current unique integer
    
    if (remainder == 0) return 1; // If remainder is exactly 0, we found a valid combination
    
    if (remainder < 0) return 0; // If remainder is negative, the current combination is invalid
    
    return countWaySumOfSquareRec(x, uniqueInteger + 1) + countWaySumOfSquareRec(remainder, uniqueInteger + 1); // Recursive case: Explore 2 paths. Path 1: Exclude the current uniqueInteger and go to the next one. Path 2: Include the current uniqueInteger (subtract its square from x) and try the next one
}

int countWaySumOfSquare(int x) {
    /*
     * STUDENT ANSWER
    */
   if (x < 1) return 0;
   return countWaySumOfSquareRec(x, 1);
}

int main() {
    cout << "\nNumber of ways to express 100 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(100) << endl; // result: 3

    cout << "\nNumber of ways to express 0 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(0) << endl; // result: 0
    
    cout << "\nNumber of ways to express 50 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(50) << endl; // result: 3 (50 = 7^2 + 1^2 = 6^2 + 3^2 + 2^2 + 1^2 = 5^2 + 4^2 + 3^2)

    cout << "\nNumber of ways to express 25 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(25) << endl; // result: 2 (25 = 5^2 = 4^2 + 3^2)
    
    cout << "\nNumber of ways to express 75 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(75) << endl; // result: 3 (75 = 7^2 + 5^2 + 1^2 = 7^2 + 4^2 + 3^2 + 1^2 = 6^2 + 5^2 + 3^2 + 2^2 + 1^2)

    cout << "\nNumber of ways to express 87 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(87) << endl; // result: 2 (87 = 7^2 + 5^2 + 3^2 + 2^2 = 6^2 + 5^2 + 4^2 + 3^2 + 1^2)

    cout << "\nNumber of ways to express 12 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(12) << endl; // result: 0

    cout << "\nNumber of ways to express 13 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(13) << endl; // result: 1 (13 = 3^2 + 2^2)
    
    return 0;
}