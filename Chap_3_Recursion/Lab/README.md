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

# Problem 6
## Implement recursive function: void printHailstone(int number);

Rules of Hailstone sequences:
+ If a number is even, divide it by 2.
+ If a number is odd, multiply it by 3 and add 1.
+ The sequence stops when reaching number 1.

For example:
+ Test 1: printHailstone(6);
+ Result: 6 3 10 5 16 8 4 2 1
<br/><br/>
+ Test 2: printHailstone(7);
+ Result: 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

Notes: There is NO space at the end. Input is a positive integer.

# Problem 7
## Implement recursive function: int myArrayToInt(char* str, int n);

This function takes a string **str** which represents a positive decimal number, **n** is the number of elements in the string as arguments and returns the value of the decimal number.

For example:
+ Test:<br/>
char str[] = "2020";<br/>
cout << myArrayToInt("2020", 4);
+ Result: 2020

# Problem 8
## Implement function: int findLCM(int a, int b);

This function finds lowest common multiple of two positive integers a and b using recursion.

For example:
+ Test: cout << findLCM(10, 102);
+ Result: 510
