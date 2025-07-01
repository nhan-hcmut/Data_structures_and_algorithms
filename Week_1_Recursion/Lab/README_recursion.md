# Implement function: `bool containsPattern(char* text, char* pattern);`

Given a **NON-empty** text and a pattern, implement above recursive function that returns true if pattern is present in text, otherwise false.

**<ins>Note</ins>:** Please note that you **<ins>can't</ins>** use keywords **for, while, goto** (even in variable names, comment). You can implement other recursive functions if needed.

`#include <iostream>` and `using namespace std;` have been used.

**For example:**
+ Test 1: `cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"Bach Khoa") << endl; // Result: 1`
+ Test 2: `cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"Bach KHoa") << endl; // result: 0`
+ Test 3: `cout << containsPattern((char*)"Bach Khoa", (char*)"Dai hoc Bach Khoa") << endl; // result: 0`
+ Test 4: `cout << containsPattern((char*)"Dai hoc Bach Khoa", (char*)"h Khoa") << endl; // result: 1`
+ Test 5: `cout << containsPattern((char*)"Bo mon hoa HC, Dai hoc Bach Khoa DHQG TP.HCM", (char*)"Bo mon hoa VC") << endl; // result: 0`
---
# Implement function: `int countWaySumOfSquare(int x);`

Given an integer x, find number of ways to express x as sum of squares of unique natural numbers (distinct positive whole numbers).

**<ins>For example</ins>:** x = 100 -> Output: 3 (**<ins>Explain</ins>:** 100 = 10^2 = 8^2 + 6^2 = 1^2 + 3^2 + 4^2 + 5^2 + 7^2)

**<ins>Note</ins>:** Please note that you **<ins>can't</ins>** use keywords **for, while, goto** (even in variable names, comment). You can implement other recursive functions if needed.

`<iostream>` and `<cmath>` libraries are included. `using namespace std;` has been used.

+ Test 1: `cout << "\nNumber of ways to express 100 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(100) << endl; // result: 3`

+ Test 2: `cout << "\nNumber of ways to express 0 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(0) << endl; // result: 0`

+ Test 3: `cout << "\nNumber of ways to express 50 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(50) << endl; // result: 3 (50 = 7^2 + 1^2 = 6^2 + 3^2 + 2^2 + 1^2 = 5^2 + 4^2 + 3^2)`

+ Test 4: `cout << "\nNumber of ways to express 25 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(25) << endl; // result: 2 (25 = 5^2 = 4^2 + 3^2)`

+ Test 5: `cout << "\nNumber of ways to express 75 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(75) << endl; // result: 3 (75 = 7^2 + 5^2 + 1^2 = 7^2 + 4^2 + 3^2 + 1^2 = 6^2 + 5^2 + 3^2 + 2^2 + 1^2)`

+ Test 6: `cout << "\nNumber of ways to express 87 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(87) << endl; // result: 2 (87 = 7^2 + 5^2 + 3^2 + 2^2 = 6^2 + 5^2 + 4^2 + 3^2 + 1^2)`

+ Test 7: `cout << "\nNumber of ways to express 12 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(12) << endl; // result: 0`

+ Test 8: `cout << "\nNumber of ways to express 13 as a sum of squares of unique natural numbers: " << countWaySumOfSquare(13) << endl; // result: 1`
---
# Implement function: `int decimalToBinary(int decimal_number);`

Given a positive decimal number as input, we need to convert the given positive decimal number into its equivalent binary number.

Please note that you **<ins>can't</ins>** use keywords **for, while, goto** (even in variable names, comment).

For this exercise, we have `#include <iostream>` and `using namespace std;`

**<ins>For example</ins>:**

+ Test 1: `cout << decimalToBinary(20) << endl; // Result: 10100`
+ Test 2: `cout << decimalToBinary(19) << endl; // result: 10011`
+ Test 3: `cout << decimalToBinary(18) << endl; // result: 10010`
+ Test 4: `cout << decimalToBinary(17) << endl; // result: 10001`
+ Test 5: `cout << decimalToBinary(16) << endl; // result: 10000`
+ Test 6: `cout << decimalToBinary(15) << endl; // result: 1111`
+ Test 7: `cout << decimalToBinary(14) << endl; // result: 1110`
+ Test 8: `cout << decimalToBinary(13) << endl; // result: 1101`
+ Test 9: `cout << decimalToBinary(12) << endl; // result: 1100`
+ Test 10: `cout << decimalToBinary(11) << endl; // result: 1011`
---
# Implement function: `string expand(string s);`

String s contains lowercase letters, digits, "(" and ")", satisfying the following rules:

+ Two digits cannot be adjacent.

+ Two "(" cannot be adjacent.

+ One "(" and one ")" cannot be adjacent.

+ After any digit, there must be "(".

+ The quantities of "(" and ")" are equal.

**<ins>Requirements</ins>:** Change string s until new string t created, t contains only lowercase letters. These are changing rules:

+ Substrings with form "n(p)", can change to "pp...p" (n times p), where n is a digit and p is a string.

+ If p still contains "(", ")" or digits, continue to implement the above changing method.

**<ins>Notes</ins>:** `#include <iostream>`, `#include <string>` and `using namespace std;` have been used. You can add other functions for your answer, but you are **<ins>not</ins>** allowed to add other libraries.

**<ins>For example</ins>:**

+ Test 1: `cout << expand("2(ab3(cde)x)") << "\n";`
+ Result: abcdecdecdexabcdecdecdex
<br/>

+ Test 2: `cout << expand("2(x0(y))3(z)") << "\n";`
+ Result: xxzzz

---
# Implement function: `int findGCD(int a, int b);`

**Requirements:** Find greatest common divisor of two positive integers a and b using recursion.

**For example:**

+ Test 1: `cout << findGCD(124, 32);`
+ Result: 4
<br/>

+ Test 2: `cout << findGCD(138, 184);`
+ Result: 46
<br/>

+ Test 3: `cout << findGCD(138, 91);`
+ Result: 1
<br/>

+ Test 4: `cout << findGCD(138, 6);`
+ Result: 6
<br/>

+ Test 5: `cout << findGCD(307, 2000);`
+ Result: 1

---
# Implement function: `int findLCM(int a, int b);`

This function finds lowest common multiple of two positive integers a and b using recursion.

**For example:**
+ Test: `cout << findLCM(10, 102);`
+ Result: 510

---
# Implement function: `int findMax(int* arr, int length);`

**<ins>Requirements</ins>:** Find the largest element of the array **arr** using recursion. **"length"** is the number of elements.

**<ins>For example</ins>:**

+ Test 1:
```cpp
int arr1[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
cout << findMax(arr1, 10) << endl; // Result: 15
```

+ Test 2:
```cpp
int arr2[] = {10};
cout << findMax(arr2, 1) << endl; // Result: 10
```

+ Test 3:
```cpp
int arr3[] = {10, -1, -150, 200};
cout << findMax(arr3, 4) << endl; // Result: 200
```

+ Test 4:
```cpp
int arr4[] = {24,0,88,-59,-54,13,20,-11,22,-48,5,22,-40,-26,-97,88};
cout << findMax(arr4, 16) << endl; // Result: 88
```

+ Test 5:
```cpp
int arr5[] = {-85, -82, -75, -74, -70, -57, -36, -23, -21, -12, -7, 8, 20, 39, 49, 63, 66, 67, 71, 80};
cout << findMax(arr5, 20) << endl; // Result: 80
```

+ Test 6:
```cpp
int arr6[] = {291, -444, -456, 199, 465, 31, 118, -16, 103, -23, 199, 342, 291, 374, -206, -383, -15, -286, -216, -287, 155, 310, -345, -444, -254, -7, 304, -99, -143, -456, -349, 154, -38, -60, 166, -40, 256, -107, -31, -454, 486, 270, -458, -367, 258, 310, -342, -405, -361};
cout << findMax(arr6, 49) << endl; // Result: 486
```
---
# Implement function: `bool isPalindrome(string str);`

**<ins>Requirements</ins>:** Check if the given **NON EMPTY** string is palindrome or not by using recursion. The given string can be a word or a sentence and therefore blank spaces **<ins>must</ins>** be ignored. The `<iostream>`, `<string>` libraries and `using namespace std;` have been used.

**<ins>For example</ins>:**
+ Test 1: `cout << isPalindrome("mom") << endl; // Result: 1`

+ Test 2: `cout << isPalindrome("dogeeseseegod") << endl; // Result: 1`

+ Test 3: `cout << isPalindrome("do geese see god") << endl; // Result: 1`

+ Test 4: `cout << isPalindrome("racecar") << endl; // Result: 1`

+ Test 5: `cout << isPalindrome("raceeacar") << endl; // Result: 0`

+ Test 6: `cout << isPalindrome("redivaxcvider") << endl; // Result: 0`
---
# Implement function: `int minimumBracketAdd(string s);`

**<ins>Requirements</ins>:** Given a string s consisting only of '(' and ')'. This function returns the minimum number of brackets to be inserted to s so that the brackets are balanced.

**<ins>Note</ins>:**
+ A sequence of brackets is balanced when there are no unmatched brackets. Example: "()(())" is balanced, but "))()" is not.
+ The `<iostream>` library and `using namespace std;` are used. **<ins>No</ins>** other libraries are allowed.
+ You can write helper functions.

**<ins>For example</ins>:**

+ Test 1: `cout << minimumBracketAdd("()(())");`
+ Result: 0
<br/><br/>

+ Test 2: `cout << minimumBracketAdd("))()");`
+ Result: 2
<br/><br/>

+ Test 3: `cout << minimumBracketAdd(")))((");`
+ Result: 5
<br/><br/>

+ Test 4: `cout << minimumBracketAdd("))()))()()");`
+ Result: 4
<br/><br/>

+ Test 5: `cout << minimumBracketAdd("");`
+ Result: 0
<br/><br/>

+ Test 6: `cout << minimumBracketAdd(")()))()))())())))))(");`
+ Result: 12
<br/><br/>

+ Test 7: `cout << minimumBracketAdd(")())(((())()())()())))()()))(()((((()(()()()))()((())((()))))))()(((()(((())(((()()(())(())))))(()))");`
+ Result: 10
<br/><br/>

+ Test 8: `cout << minimumBracketAdd(")(()())())))))(((())))))())))()))))))((())(((()(((())((()(()))())(()(()((((((())))(((()))))((())((()()))((())(()(((()())()()())(())())))(()))()))((((()()(()))()))))()()()(()))()))()())()(()())))())())()))())())((()()(())((()()(((()((()((((((((())()()())(()()()))()()()())()(()(())())((()))((((()((((((()((()))))))()))((()())))()()((((()()()(()())((((()((((((())))(()))))(()))))()())())(((())()())()(((())))(())(((()(((())))(((()()(()(((()((()(()))())))))()(()(())()())(((()(()(())()()())()(()()))(((()))()())()))))((()())(())()))(()))())(())))()))())()()(()()(((((()(()()(()()))(()(()(())()((((()((()(()(())))()())((()()(((()))(()))()(())()((()()(((((())(((())(()())()))))()((()))((()))(()())()))()())()))(()((()()()((()()))(())(())(((())()())(())()((())(((()(())(()))(())()(((())((()())((()))(((((()(())()()()()(()(()))(()()())())))))()))))()()))(())(((((((((()))(())))(()))(()))(()((()()(((()))))(()(())((((()))(()))))(()((()((()(((()))()))(()((())()))))(()))(()()))()((((()(((()()(()))()((()(((())");`
+ Result: 70

---
# Implement function: `int myArrayToInt(char* str, int n);`

**<ins>Requirements</ins>:** This function takes a string **str** which represents a positive decimal number (base 10 number), **n** is the number of elements in the string as arguments and returns the value of the decimal number. `#include <iostream>`, `#include <cstring>` and `using namespace std;` have been used.

**<ins>For example</ins>:**
+ Test:<br/>
```cpp
char str[] = "2020";
cout << myArrayToInt("2020", 4);
```
+ Result: 2020
---
# Implement function: `int oddSumSublist(vector<int>& nums, int m);`

Given a vector of integers. This recursive function returns the number of **<ins>contiguous</ins>** sublists with odd sum. The number may be too large, so the result should mod m.

**<ins>Note</ins>:**
- The `<iostream>` and `<vector>` libraries have been included and `namespace std` has beeen used. **<ins>No</ins>** other libraries are allowed.
- Using loop keywords (for, while, do) are **<ins>not</ins>** allowed, even in comments and variable names.
- You can write helper functions.

**<ins>For example</ins>:**
+ Test 1:
```cpp
vector<int> vec {58, 70, 125, 86};
int m = 12132;
cout << oddSumSublist(vec, m); // Result: 6
```
+ Test 2:
```cpp
vec = {6};
cout << endl << oddSumSublist(vec, m) << endl; // result: 0
```
+ Test 3:
```cpp
vec = {13};
cout << endl << oddSumSublist(vec, m) << endl; // result: 1
```
+ Test 4:
```cpp
vec = {6, 13};
cout << endl << oddSumSublist(vec, m) << endl; // result: 2
```
+ Test 5:
```cpp
vec = {3, 14};
cout << endl << oddSumSublist(vec, m) << endl; // result: 2
```
+ Test 6:
```cpp
vec = {6, 14};
cout << endl << oddSumSublist(vec, m) << endl; // result: 0
```
+ Test 7:
```cpp
vec = {3, 13};
cout << endl << oddSumSublist(vec, m) << endl; // result: 2
```
+ Test 8:
```cpp
vec = {5, 4, 4, 5, 1, 3};
cout << endl << oddSumSublist(vec, m) << endl; // result: 12
```
+ Test 9:
```cpp
vec = {1, 3, 5};
cout << endl << oddSumSublist(vec, m) << endl; // result: 4
```
+ Test 10:
```cpp
vec = {2, 4, 6};
cout << endl << oddSumSublist(vec, m) << endl; // result: 0
```
+ Test 11:
```cpp
vec = {1, 2, 3, 4};
cout << endl << oddSumSublist(vec, m) << endl; // result: 6
```
+ Test 12:
```cpp
vec = {1, 2, 3, 4, 5};
cout << endl << oddSumSublist(vec, m) << endl; // result: 9
```
+ Test 13:
```cpp
vec = {1, 2, 3, 4, 5, 6, 7};
cout << endl << oddSumSublist(vec, m) << endl; // result: 16
```
---
# Implement function: `void printArray(int n);`

**<ins>Requirements</ins>:** print 0, 1, 2, 3, ..., n (n is a positive integer and there is **<ins>NO</ins>** space at the end).

**<ins>For example</ins>:**
+ Test 1: `printArray(5);`
+ Result: 0, 1, 2, 3, 4, 5

+ Test 2: `printArray(10);`
+ Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

+ Test 3: `printArray(11);`
+ Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11

+ Test 4: `printArray(22);`
+ Result: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22

+ Test 5: `printArray(1);`
+ Result: 0, 1
---
# Implement function: `void printHailstone(int number);`

Rules of Hailstone sequences:
+ If a number is even, divide it by 2.
+ If a number is odd, multiply it by 3 and add 1.
+ The sequence stops when reaching number 1.

**<ins>Notes</ins>:** There is **<ins>NO</ins>** space at the end. Input is a positive integer.

**<ins>For example</ins>:**
+ Test 1: `printHailstone(5); // Result: 5 16 8 4 2 1`

+ Test 2: `printHailstone(6); // Result: 6 3 10 5 16 8 4 2 1`

+ Test 3: `printHailstone(7); // Result: 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1`

+ Test 4: `printHailstone(11); // Result: 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1`

+ Test 5: `printHailstone(12); // Result: 12 6 3 10 5 16 8 4 2 1`

+ Test 6: `printHailstone(13); // Result: 13 40 20 10 5 16 8 4 2 1`

+ Test 7: `printHailstone(22); // Result: 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1`

+ Test 8: `printHailstone(23); // Result: 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1`

+ Test 9: `printHailstone(32); // Result: 32 16 8 4 2 1`
---
# Implement function: `void printPattern(int n);`
Given a positive integer, print following pattern using recursion.

**Input:** n = 16<br/>
**Output:** 16 11 6 1 -4 1 6 11 16 (NO space at the end).

**Pattern rule:** First, we reduce 5 one by one until reaching a negative number or 0. Then, we add 5 one by one until reaching n.

**<ins>For example</ins>:**
+ Test: `printPattern(14);`
+ Result: 14 9 4 -1 4 9 14
---
# Implement function: `int reverseFactorial(int n);`

Given an integer n. This function returns an integer k such that k! = n. If there are no such numbers, return -1. If n = 1, the function returns k = 1.

**<ins>Note</ins>:**
- The `<iostream>` library and `namespace std` have been used. **<ins>No</ins>** other libraries are allowed.
- Using loop keywords (for, while, do) are **<ins>not</ins>** allowed, even in comments and variable names.
- You can write helper functions.

**<ins>For example</ins>:**

+ Test 1: `cout << endl << reverseFactorial(120) << endl; // result: 5 (because 120 = 5!)`

+ Test 2: `cout << endl << reverseFactorial(24) << endl; // result: 4 (because 24 = 4!)`

+ Test 3: `cout << endl << reverseFactorial(6) << endl; // result: 3 (because 6 = 3!)`

+ Test 4: `cout << endl << reverseFactorial(2) << endl; // result: 2 (because 2 = 2!)`

+ Test 5: `cout << endl << reverseFactorial(1) << endl; // result: 1 (because 1 = 1!)`

+ Test 6: `cout << endl << reverseFactorial(0) << endl; // result: -1 (because there are no such numbers, return -1)`

+ Test 7: `cout << endl << reverseFactorial(3) << endl; // result: -1 (because there are no such numbers, return -1)`

+ Test 8: `cout << endl << reverseFactorial(4) << endl; // result: -1 (because there are no such numbers, return -1)`

+ Test 9: `cout << endl << reverseFactorial(5) << endl; // result: -1 (because there are no such numbers, return -1)`
---
# Implement function: `string reverseSentence(string s);`

This function returns the reversed sentence of string s using recursion.

**<ins>Note</ins>:**
+ String s consists only of letters (a-z and A-Z) and spaces.
+ There is only one space between two adjacent words.
+ String s does not begin or end with any spaces.
+ `#include <iostream>` and `using namespace std;` have been used.

**<ins>For example</ins>:**
+ Test 1: `cout << reverseSentence("data structure and algorithm is scary");`
+ Result: scary is algorithm and structure data
<br/>

+ Test 2: `cout << reverseSentence("data structures and algorithms is challenging");`
+ Result: challenging is algorithms and structures data
---
# Implement function: `int shortestString(string s);`

Given a string s consisting only of 0 and 1. You can delete any two adjacent letters if they are different. The function returns the length of the smallest string that you can make if you're able to perform the above operation on string s as many times as you want.

**<ins>Note</ins>:**
- The `<iostream>` library and `namespace std` have been used. **<ins>No</ins>** other libraries are allowed.
- Using loop keywords (for, while, do) are **<ins>not</ins>** allowed, even in comments and variable names.
- You can write helper functions.

**<ins>For example</ins>:**

+ Test 1: `cout << endl << shortestString("01110") << endl; // result: 1 ("01110" -> "011" after removing "10", then "1" after removing "01", so the result is 1)`

+ Test 2: `cout << endl << shortestString("") << endl; // result: 0 (an empty string -> no transformations needed, so the result is 0)`

+ Test 3: `cout << endl << shortestString("0") << endl; // result: 1 ("0" -> cannot be transformed, so the result is 1)`

+ Test 4: `cout << endl << shortestString("1") << endl; // result: 1 ("1" -> cannot be transformed, so the result is 1)`

+ Test 5: `cout << endl << shortestString("00") << endl; // result: 2 ("00" -> cannot be transformed, so the result is 2)`

+ Test 6: `cout << endl << shortestString("01") << endl; // result: 0 ("01" -> "01" is found and removed, so the result is 0)`

+ Test 7: `cout << endl << shortestString("10") << endl; // result: 0 ("10" -> "10" is found and removed, so the result is 0)`

+ Test 8: `cout << endl << shortestString("11") << endl; // result: 2 ("11" -> cannot be transformed, so the result is 2)`
---
# Implement function: `int strLen(char* str);`

This function find length of the given string using recursion.

**<ins>For example</ins>:**
+ Test 1:<br/>
```cpp
char str[] = "Ho Chi Minh City University of Technology";
cout << strLen(str);
```
+ Result: 41
<br/>

+ Test 2:<br/>
```cpp
char str[] = "Truong DH Bach Khoa";
cout << strLen(str);
```
+ Result: 19
---
# Implement function: `int superString(string x, string y, int m, int n);`

A string is called a subsequence of the string S if it can be derived from string S by deleting some or no elements without changing the order of the remaining characters.

**<ins>Example</ins>:**

- "abd" is a subsequence of "abcdef" because it is derived from "abcdef" by deleting characters 'c', 'd', 'f' and does not change the order of remaining characters.

- "adc" is not a subsequence of "abcdef" because the order of remaining characters is changed.

A string is called a superstring of two other strings A and B if both strings A and B are subsequences of it. The superstring of A and B that has the smallest length is called the shortest superstring.

**<ins>Request</ins>:** Inputs are two strings x, y and their lengths m, n. Implement function `superString(x, y, m, n);` to find then return the length of the shortest superstring of x and y.

**<ins>Example</ins>:**
<br/>
Two strings are "ABCBDAB" and "BDCABA". The length of the shortest superstring ("ABCBDCABA", "ABDCABDAB" or "ABDCBDABA") is 9.

**<ins>Note</ins>:**
<br/>
In this exercise, libraries `<iostream>`, and `<string>` have been included and `using namespace std;` has been used. You can add other functions but are **<ins>not</ins>** allowed to add other libraries. Because this problem is used for practicing recursion, you are **NOT** allowed to use keywords while, for and do.

**<ins>For example</ins>:**

+ Test 1:<br/>
```cpp
string x = "ABCBDAB"; 
string y = "BDCABA";
int m = x.length(), n = y.length();
cout << superString(x, y, m, n) << "\n"; // Result: 9
```

+ Test 2:<br/>
```cpp
string x = "abcde"; 
string y = "efghijkl";
int m = x.length(), n = y.length();
cout << superString(x, y, m, n) << "\n"; // Result: 12
```
---
