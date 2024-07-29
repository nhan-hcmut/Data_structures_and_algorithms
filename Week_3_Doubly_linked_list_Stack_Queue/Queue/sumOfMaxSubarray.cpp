#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int sum = 0, maxVal = 0, len = nums.size();
    if (k < 1 || k > len || len < 1) return 0;
    
    for (int i = 0; i <= len - k; i++) {
        maxVal = nums[i];
        for (int j = 1; j < k; j++) {
            if (nums[i + j] > maxVal) maxVal = nums[i + j];
        }
        sum += maxVal;
    }
    return sum;
}

int main() {

    // test 1
    vector<int> nums {1, 2, 4, 3, 6};
    int k = 3;
    cout << sumOfMaxSubarray(nums, k); // result: 14

    /* test 2
    vector<int> nums {8016};
    int k = 1;
    cout << sumOfMaxSubarray(nums, k); // result: 8016
    */

    return 0;
}