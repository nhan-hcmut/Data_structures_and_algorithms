# Implement function: int findGCD(int a, int b);

**Requirements:** Find greatest common divisor of two positive integers a and b using recursion.

For example:

+ Test 1: cout << findGCD(124, 32);
+ Result: 4
<br/><br/>

+ Test 2: cout << findGCD(138, 184);
+ Result: 46
<br/><br/>

+ Test 3: cout << findGCD(138, 91);
+ Result: 1
<br/><br/>

+ Test 4: cout << findGCD(138, 6);
+ Result: 6
<br/><br/>

+ Test 5: cout << findGCD(307, 2000);
+ Result: 1
<br/><br/>

# Implement function: int findLCM(int a, int b);

This function finds lowest common multiple of two positive integers a and b using recursion.

For example:
+ Test: cout << findLCM(10, 102);
+ Result: 510

# Implement function: int findMax(int* arr, int length);

**Requirements:** Find the largest element of the array **arr** using recursion. **"length"** is the number of elements.

For example:
+ Test 1:<br/>
int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};<br/>
cout << findMax(arr, 10);
+ Result: 15
<br/><br/>
+ Test 2:<br/>
int arr[] = {291, -444, -456, 199, 465, 31, 118, -16, 103, -23, 199, 342, 291, 374, -206, -383, -15, -286, -216, -287, 155, 310, -345, -444, -254, -7, 304, -99, -143, -456, -349, 154, -38, -60, 166, -40, 256, -107, -31, -454, 486, 270, -458, -367, 258, 310, -342, -405, -361};<br/>
cout << findMax(arr, 49);
+ Result: 486

# Implement function: bool isPalindrome(string str);

**Requirements:** Check if the given NON EMPTY string is palindrome or not using recursion. The given string can be a word or a sentence and therefore blank spaces must be ignored. The "string" library is included.

For example:
+ Test 1: cout << isPalindrome("mom");
+ Result: 1
<br/><br/>
+ Test 2: cout << isPalindrome("do geese see god");
+ Result: 1

# Implement function: int myArrayToInt(char* str, int n);

This function takes a string **str** which represents a positive decimal number, **n** is the number of elements in the string as arguments and returns the value of the decimal number.

For example:
+ Test:<br/>
char str[] = "2020";<br/>
cout << myArrayToInt("2020", 4);
+ Result: 2020

# Implement function: void printArray(int n);

**Requirements:** print 0, 1, 2, 3, ..., n (n is a positive integer and there is NO space at the end).

For example:
+ Test 1: printArray(5);
+ Result: 0, 1, 2, 3, 4, 5
<br/><br/>
+ Test 2: printArray(10);
+ Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

# Implement function: void printHailstone(int number);

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

**Notes:** There is NO space at the end. Input is a positive integer.

# Implement function: void printPattern(int n);
Given a positive integer, print following pattern using recursion.

**Input:** n = 16<br/>
**Output:** 16 11 6 1 -4 1 6 11 16 (NO space at the end).

**Pattern rule:** First, we reduce 5 one by one until reaching a negative number or 0. Then, we add 5 one by one until reaching n.

For example:
+ Test: printPattern(14);
+ Result: 14 9 4 -1 4 9 14

# Implement function: string reverseSentence(string s);

This function returns the reversed sentence of string s using recursion.

**Note:**
+ String s consists only of letters (a-z and A-Z) and spaces.
+ There is only one space between two adjacent words.
+ String s does not begin or end with any spaces.

For example:
+ Test: cout << reverseSentence("data structures and algorithms is challenging");
+ Result: challenging is algorithms and structures data

# Implement function: int strLen(char* str);

This function find length of the given string using recursion.

For example:
+ Test:<br/>
char str[] = "Ho Chi Minh City University of Technology";<br/>
cout << strLen(str);
+ Result: 41
