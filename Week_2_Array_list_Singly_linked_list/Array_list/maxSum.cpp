`#include<iostream>
using namespace std;

int maxSum(int* nums, int n, int k) {
    int result = 0;
    int* memo = new int[n + 1]; // Create a memoization array to store the maximum S(W) value
    
    for (int i = 0; i < n + 1; i++) memo[i] = 0; // Initialize all elements of the memo array to 0
    
    for (int i = 0; i < n + 1; i++) { // Iterate through each possible starting position of a sub-array
        int maxEle = 0; // Stores the largest element in the current sub-array
        
        for (int j = 1; j <= k && i + j <= n; j++) { // Try forming sub-arrays of size 1 to k starting from position i
            
            if (nums[i + j - 1] > maxEle) { // Update maxEle to be the maximum of current sub-array
                maxEle = nums[i + j - 1];
            }
            // Calculate S-value for the sub-array of size j (from i to i + j - 1) and update memo[i + j] if we get a larger sum
            if (memo[i] + j * maxEle > memo[i + j]) {
                memo[i + j] = memo[i] + j * maxEle;
            }
        }
    }
    result = memo[n];
    delete[] memo;
    return result;
}

int main() {

    int arr[] = {1, 6, 3, 2, 2, 5, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, length, 3) << "\n"; // Result: 35
    
    return 0;
}