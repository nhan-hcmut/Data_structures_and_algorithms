#include<iostream>
#include<vector>
using namespace std;

// Calculate cumulative sum from index 0 to a given index
int cumulativeSum(const vector<int>& vec, int index) {
    
    if (index < 0) return 0; // Base case 1: if index is negative, return 0
    
    if (index < 1) return vec.at(0); // Base case 2: if index is 0, return the first element
    
    return vec.at(index) + cumulativeSum(vec, index - 1); // Recursive case: return current element + cumulative sum of previous elements
}

// Calculate the number of contiguous sublists whose sum is odd
int oddSumSublistRec(vector<int>& vec, int index = 0, int oddSumCount = 0, int evenSumCount = 1, int result = 0) {
    
    if (index >= vec.size()) return result; // Base case: if index reaches the end of the vector, return the result
    
    /*
    A sublist's sum is odd if and only if the difference between two prefix sums is odd.
    By tracking how many prefix sums so far are even or odd,
    the algorithm uses parity to efficiently count how many previous prefix sums (even or odd) can pair with the current one to produce an odd sublist sum
    */
    
    if (cumulativeSum(vec, index) % 2) return oddSumSublistRec(vec, index + 1, oddSumCount + 1, evenSumCount, result + evenSumCount); // If cumulative sum up to this index is odd, add number of even prefix sums to result (because current odd sum - an even prefix sum = an odd sublist)

    return oddSumSublistRec(vec, index + 1, oddSumCount, evenSumCount + 1, result + oddSumCount); // If cumulative sum is even, add number of odd prefix sums to result (because current even sum - an odd prefix sum = an odd sublist)
}

int oddSumSublist(vector<int>& nums, int m) {
    // STUDENT ANSWER
    return oddSumSublistRec(nums) % m; // The number may be too large, so the result should mod m
}

int main() {
    // Test 1
    vector<int> vec {58, 70, 125, 86};
    int m = 12132;
    cout << endl << oddSumSublist(vec, m) << endl; // result: 6
    
    // Test 2
    vec = {6};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 0

    // Test 3
    vec = {13};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 1

    // Test 4
    vec = {6, 13};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 2

    // Test 5
    vec = {3, 14};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 2

    // Test 6
    vec = {6, 14};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 0

    // Test 7
    vec = {3, 13};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 2

    // Test 8
    vec = {5, 4, 4, 5, 1, 3};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 12

    // Test 9
    vec = {1, 3, 5};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 4

    // Test 10
    vec = {2, 4, 6};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 0

    // Test 11
    vec = {1, 2, 3, 4};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 6

    // Test 12
    vec = {1, 2, 3, 4, 5};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 9

    // Test 13
    vec = {1, 2, 3, 4, 5, 6, 7};
    cout << endl << oddSumSublist(vec, m) << endl; // result: 16
    
    return 0;
}