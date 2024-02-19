# Problem 1
## Implement function: void printPattern(int n);
Given a positive number, print following pattern using recursion.

Input: n = 16
Output: 16 11 6 1 -4 1 6 11 16 (NO space at the end).

Pattern rule: First, we reduce 5 one by one until reaching a negative number or 0. Then, we add 5 one by one until reaching n.

For example:
+ Test: printPattern(14);
+ Result: 14 9 4 -1 4 9 14

# Problem 2
## Implement function: void printArray(int n);

Output: 0, 1, 2, 3, ..., n (n is a positive integer and there is NO space at the end).

For example:
+ Test 1: printArray(5);
+ Result: 0, 1, 2, 3, 4, 5
<br/><br/>
+ Test 2: printArray(10);
+ Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

# Problem 3
## Implement function: int findMax(int* arr, int length);

Requirements: Find the largest element of the array arr using recursion. "length" is the number of elements.

For example:
+ Test:<br/>
int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};<br/>
cout << findMax(arr, 10);
+ Result: 15

# Problem 4
## Implement function: bool isPalindrome(string str);

Requirements: Check if the given NON EMPTY string is palindrome or not using recursion. The given string can be a word or many words and therefore blank spaces must be ignored.

For example:
+ Test 1: cout << isPalindrome("mom");
+ Result: 1
<br/><br/>
+ Test 2: cout << isPalindrome("do geese see god");
+ Result: 1

# Problem 5
## Implement function: int findGCD(int a, int b);

Requirements: Find greatest common divisor of two positive integers a and b using recursion.

For example:
+ Test: cout << findGCD(124, 32);
+ Result: 4
