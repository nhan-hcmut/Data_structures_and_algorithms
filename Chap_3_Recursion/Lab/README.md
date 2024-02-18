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
