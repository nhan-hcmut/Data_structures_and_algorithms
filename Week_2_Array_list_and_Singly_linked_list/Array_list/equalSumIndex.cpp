#include<iostream>
#include<vector>
using namespace std;

int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    if (nums.empty()) return -1;
    int size = nums.size();
    if (size == 1) return 0;
    int sum = 0; // sum of all numbers
    for (int i = 0; i < size; i++) sum += nums.at(i);
    int sumLeft = 0, sumRight = sum - nums.at(0);
    for (int idx = 1; idx < size-1; idx++) {
        sumLeft += nums.at(idx-1);
        sumRight -= nums.at(idx);
        if (sumLeft == sumRight) {
            return idx;
        }
    }
    return -1;
}

int main() {

    // test 1
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums); // Result: 3
    
    /* test 2
    vector<int> nums {3};
    cout << equalSumIndex(nums); // result: 0
    */

    /* test 3
    vector<int> nums {16, 6, 4, 9, 4, 17, 17, 15, 13, 12, 9, 3, 17, 17, 16, 18, 7, 7, 7, 11};
    cout << equalSumIndex(nums); // result: -1
    */

    /* test 4
    vector<int> nums {18, 5, 14, 13, 5, 8, 10, 5, 9, 6, 16, 10, 12, 12, 18, 13, 7, 14, 2, 16, 18, 5, 17, 18, 7, 2, 14, 0, 16, 0, 11, 15, 9, 2, 10, 9, 9, 2, 0, 0, 12, 8, 3, 1, 17, 15, 18, 1, 4, 17, 1, 6, 19, 6, 12, 15, 1, 11, 0, 1, 7, 7, 16, 13, 14, 17, 10, 6, 9, 19, 10, 13, 3, 10, 2, 5, 15, 15, 11, 8, 4, 6, 14, 19, 11, 5, 3, 5, 19, 7, 14, 4, 19, 10, 11, 19, 14, 18, 16, 11};
    cout << equalSumIndex(nums); // result: -1
    */

    /* test 5
    vector<int> nums {19, 2, 15, 2, 10, 16, 6, 4, 11, 4, 13, 18, 13, 17, 11, 1, 18, 11, 17, 1, 13, 12, 17, 5, 0, 14, 19, 0, 15, 0, 4, 4, 0, 5, 9, 2, 1, 9, 10, 2, 11, 1, 2, 4, 8, 5, 1, 19, 12, 8, 7, 18, 11, 8, 1, 8, 6, 3, 1, 0, 6, 1, 3, 1, 1, 10, 5, 2, 8, 10, 7, 13, 4, 15, 11, 5, 6, 8, 19, 14, 9, 12, 12, 12, 1, 8, 9, 2, 17, 4, 1, 4, 16, 19, 9, 19, 8, 10, 2, 12, 3, 15, 12, 19, 7, 2, 7, 17, 13, 4, 3, 1, 13, 18, 13, 15, 7, 16, 2, 14, 1, 19, 2, 3, 15, 19, 9, 9, 19, 1, 5, 11, 18, 16, 6, 0, 14, 10, 0, 17, 19, 6, 17, 4, 16, 15, 14, 12, 17, 8, 15, 5, 2, 18, 9, 5, 9, 9, 16, 3, 12, 15, 1, 19, 2, 17, 9, 14, 7, 11, 14, 8, 6, 18, 6, 15, 14, 0, 18, 6, 8, 3, 5, 14, 4, 6, 17, 11, 16, 17, 5, 18, 17, 7, 12, 5, 9, 13, 0, 15, 1, 8, 10, 18, 4, 3, 14, 15, 19, 6, 2, 9, 2, 11, 12, 13, 11, 15, 19, 0, 18, 2, 9, 1, 17, 3, 2, 4, 16, 5, 0, 7, 0, 3, 0, 0, 19, 3, 12, 19, 11, 4, 13, 2, 1, 2, 7, 2, 19, 5, 18, 0, 17, 2, 19, 4, 3, 17, 12, 8, 8, 13, 16, 8, 11, 18, 11, 9, 5, 0, 4, 15, 18, 1, 4, 8, 15, 13, 14, 2, 1, 7, 7, 8, 15, 15, 8, 11, 13, 2, 18, 10, 3, 9, 5, 0, 16, 18, 12, 17, 9, 3, 8, 12, 13, 16, 18, 7, 2, 0, 10, 12, 19, 10, 2, 3, 11, 2, 16, 11, 10, 9, 3, 9, 7, 1, 15, 18, 14, 2, 14, 1, 11, 12, 6, 17, 6, 14, 8, 8, 8, 18, 15, 8, 10, 19, 18, 1, 17, 19, 18, 11, 6, 0, 4, 9, 19, 1, 9, 19, 17, 8, 18, 16, 11, 3, 14, 15, 3, 19, 6, 14, 11, 13, 0, 11, 15, 7, 0, 18, 17, 9, 19, 16, 5, 13, 12, 19, 2, 8, 3, 10, 9, 18, 4, 2, 17, 11, 13, 12, 6, 15, 11, 1, 10, 19, 10, 8, 1, 5, 19, 11, 15, 2, 10, 9, 15, 14, 12, 6, 10, 15, 18, 15, 14, 17, 15, 3, 9, 2, 6, 2, 5, 14, 4, 10, 17, 5, 17, 7, 19, 8, 8, 15, 7, 16, 4, 10, 0, 1, 3, 6, 14, 14, 18, 10, 12, 17, 7, 16, 15, 10, 2, 0, 7, 15, 4, 0, 3, 19, 4, 1, 11, 3, 6, 3, 13, 4, 0, 11, 5, 18, 18, 11, 14, 17, 6, 12, 8, 18, 9, 0, 15, 12, 17, 15, 3, 7, 4, 7};
    cout << equalSumIndex(nums); // result: -1
    */

    /* test 6
    vector<int> nums {14, 4, 19, 13, 4, 19, 6, 13, 13, 6, 7, 13, 16, 19, 5, 2, 14, 15, 19, 12, 4, 0, 17, 4, 17, 4, 2, 14, 11, 10, 7, 15, 5, 2, 7, 11, 10, 12, 3, 15, 16, 2, 16, 15, 6, 15, 15, 10, 6, 2, 0, 2, 9, 2, 18, 2, 10, 1, 2, 13, 10, 8, 6, 9, 4, 7, 4, 3, 8, 10, 10, 13, 16, 7, 12, 5, 12, 17, 5, 16, 10, 0, 6, 3, 0, 17, 17, 4, 4, 0, 8, 5, 0, 9, 16, 8, 12, 8, 9, 6, 8, 13, 19, 14, 6, 18, 3, 16, 16, 14, 18, 11, 6, 14, 5, 10, 19, 13, 9, 10, 12, 2, 13, 12, 9, 5, 2, 1, 3, 17, 11, 3, 9, 0, 1, 14, 15, 3, 4, 15, 8, 6, 7, 11, 18, 4, 12, 15, 12, 6, 15, 18, 11, 9, 5, 13, 5, 7, 16, 2, 6, 18, 1, 3, 3, 17, 9, 17, 17, 10, 12, 6, 2, 1, 11, 12, 7, 9, 16, 7, 17, 4, 11, 10, 3, 2, 15, 13, 8, 16, 9, 5, 1, 2, 0, 17, 15, 18, 6, 16, 14, 3, 18, 14, 4, 6, 7, 15, 3, 7, 12, 1, 16, 10, 4, 10, 18, 16, 11, 10, 18, 16, 14, 6, 5, 19, 12, 1, 7, 7, 17, 17, 5, 18, 7, 10, 13, 14, 18, 11, 7, 8, 0, 17, 16, 6, 19, 12, 3, 13, 10, 3, 16, 19, 10, 7, 12, 19, 8, 7, 0, 10, 5, 15, 1, 14, 10, 2, 0, 14, 6, 8, 0, 13, 6, 0, 1, 6, 11, 6, 10, 11, 0, 16, 0, 16, 18, 2, 16, 19, 0, 12, 18, 2, 19, 19, 0, 8, 8, 7, 3, 16, 12, 15, 5, 2, 12, 5, 14, 11, 1, 3, 18, 7, 4, 14, 11, 13, 13, 3, 19, 3, 1, 11, 14, 18, 15, 7, 1, 12, 13, 7, 17, 12, 6, 3, 9, 15, 10, 12, 13, 8, 16, 12, 5, 1, 19, 16, 10, 0, 16, 12, 19, 18, 3, 16, 6, 7, 16, 6, 8, 14, 12, 1, 2, 12, 8, 12, 14, 11, 17, 9, 13, 15, 13, 4, 14, 13, 9, 10, 3, 14, 11, 11, 7, 18, 13, 0, 12, 1, 15, 17, 13, 14, 6, 2, 6, 18, 17, 7, 11, 3, 17, 17, 14, 2, 7, 3, 1, 2, 17, 5, 4, 7, 17, 8, 6, 1, 4, 18, 10, 0, 7, 15, 0, 19, 18, 12, 9, 19, 10, 11, 11, 11, 13, 19, 17, 19, 15, 1, 14, 9, 11, 4, 12, 2, 2, 9, 14, 12, 0, 10, 2, 7, 13, 16, 17, 6, 9, 6, 16, 12, 15, 0, 12, 19, 17, 16, 12, 12, 9, 15, 5, 7, 16, 19, 10, 17, 8, 0, 18, 11, 0, 17, 3, 4, 4, 12, 12, 19, 10, 9, 9, 14, 3, 18, 17, 7, 3, 10, 12, 13, 12, 12, 14, 2, 12, 3, 4, 6, 0, 0, 18, 1, 8, 14, 0, 13, 9, 12, 5, 14, 10, 7, 5, 12, 14, 6, 6, 19, 9, 12, 1, 4, 5, 17, 14, 18, 6, 7, 1, 2, 5, 2, 14, 4, 1, 9, 7, 7, 8, 7, 17, 19, 9, 14, 12, 4, 9, 11, 15, 6, 15, 3, 0, 3, 11, 8, 19, 17, 7, 15, 9, 13, 1, 0, 18, 2, 3, 18, 15, 2, 8, 10, 2, 17, 2, 18, 19, 0, 4, 2, 16, 1, 18, 1, 15, 12, 19, 0, 6, 17, 10, 3, 8, 14, 8, 13, 6, 0, 17, 10, 0, 5, 9, 3, 9, 10, 9, 9, 4, 18, 6, 2, 13, 8, 1, 17, 4, 1, 0, 6, 12, 15, 16, 16, 18, 11, 7, 10, 10, 10, 4, 16, 14, 18, 4, 12, 11, 0, 3, 5, 1, 3, 0, 11, 19, 11, 5, 7, 9, 10, 19, 4, 7, 11, 16, 13, 3, 10, 6, 17, 11, 16, 7, 17, 5, 7, 9, 5, 10, 8, 12, 14, 4, 18, 1, 1, 16, 2, 2, 4, 12, 17, 7, 5, 13, 17, 7, 3, 7, 0, 8, 17, 15, 1, 15, 4, 13, 13, 19, 4, 0, 1, 15, 10, 7, 13, 6, 9, 5, 8, 19, 11, 19, 17, 18, 1, 17, 17, 13, 5, 6, 5, 14, 10, 15, 11, 0, 9, 7, 16, 19, 19, 8, 17, 1, 7, 17, 6, 7, 2, 15, 10, 9, 0, 16, 17, 17, 0, 18, 14, 13, 15, 16, 5, 15, 1, 0, 0, 17, 0, 17, 16, 17, 1, 17, 2, 18, 4, 14, 6, 3, 0, 12, 16, 15, 19, 10, 6, 10, 19, 10, 14, 12, 13, 10, 16, 0, 13, 4, 13, 14, 18, 0, 0, 0, 3, 9, 1, 17, 6, 5, 17, 10, 8, 10, 10, 18, 5, 9, 12, 1, 14, 12, 7, 17, 8, 14, 17, 8, 10, 1, 6, 0, 6, 17, 14, 12, 8, 15, 6, 18, 8, 4, 15, 6, 13, 3, 16, 14, 17, 5, 3, 9, 15, 8, 18, 13, 15, 13, 17, 4, 17, 10, 2, 11, 16, 18, 16, 10, 16, 15, 13, 6, 10, 2, 16, 0, 11, 5, 2, 18, 4, 18, 14, 11, 12, 2, 14, 3, 6, 12, 12, 0, 17, 6, 11, 10, 1, 9, 7, 18, 0, 1, 18, 1, 16, 15, 7, 11, 19, 3, 3, 2, 5, 4, 11, 3, 4, 14, 9, 8, 6, 13, 14, 3, 2, 3, 15, 10, 8, 8, 18, 15, 10, 13, 0, 14, 3, 19, 13, 17, 8, 12, 16, 11, 0, 7, 8, 8, 16, 8, 17, 16, 2, 14, 3, 5, 5, 8, 3, 7, 1, 17, 3, 6, 17, 3, 13, 2, 6, 11, 14, 14, 6, 14, 17, 9, 9, 15, 6, 2, 10, 16, 3, 10, 2, 6, 14, 16, 4, 17, 3, 0, 9, 10, 4, 10, 18, 11, 3, 12, 18, 9, 14, 19, 5, 0, 2, 15, 17, 4, 12, 18, 9, 10, 7, 7, 11, 5, 12, 9, 18, 10, 18, 1, 11, 1, 3, 12, 19, 5, 6, 13, 2, 6, 5, 4, 18, 2, 10, 10, 3, 7, 4, 8, 2, 2, 1, 10, 0, 14, 13, 7, 8, 15, 2, 19, 19, 5, 2, 4, 3, 18, 0, 5, 14, 14, 18, 16, 0, 4, 19, 5, 15, 2, 4, 19, 15, 16, 13, 12, 13, 19, 1, 0, 0, 0, 5, 6, 6, 18, 13, 9, 18, 12, 8, 15, 6, 18, 7, 3, 12, 2, 7, 17, 18, 6, 18, 16, 3, 1, 18, 16, 6, 11, 4, 16, 13, 5, 0, 9, 2, 12, 14, 19, 17, 4, 1, 11, 19, 1, 8, 15, 4, 8, 5, 2, 10, 19, 12, 16, 5, 19, 1, 6, 14, 18, 17, 5, 10, 1, 1, 9, 5, 10, 3, 1, 7, 0, 17, 13, 19, 1, 7, 1, 19, 3, 0, 10, 12, 1, 7, 19, 16, 6, 16, 14, 18, 19, 8, 2, 9, 12, 1, 6, 15, 12, 15, 19, 18, 6, 2, 15, 16, 15, 1, 19, 7, 6, 10, 3, 13, 9, 0, 15, 6, 12, 9, 16, 14, 18, 15, 7, 17, 0, 9, 12, 7, 3, 13, 7, 17, 18, 17, 8, 1, 3, 10, 9, 17, 12, 5, 8, 15, 13, 5, 12, 8, 8, 19, 4, 14, 18, 4, 7, 14, 16, 0, 15, 10, 15, 3, 12, 19, 16, 5, 11, 19, 11, 14, 14, 13, 3, 19, 18, 4, 19, 10, 12, 1, 2, 0, 16, 11, 8, 5, 11, 17, 15, 19, 2, 15, 5, 14, 7, 13, 16, 12, 0, 17, 17, 13, 18, 1, 10, 9, 16, 12, 2, 13, 16, 17, 6, 18, 9, 4, 9, 12, 6, 14, 7, 14, 14, 19, 7, 10, 8, 2, 10, 12, 0, 3, 19, 14, 19, 7, 13, 3, 15, 5, 1, 16, 7, 12, 5, 6, 6, 6, 9, 2, 17, 11, 3, 1, 2, 16, 2, 7, 14, 14, 14, 2, 11, 14, 8, 10, 14, 2, 0, 17, 3, 13, 14, 4, 15, 3, 1, 16, 13, 19, 0, 14, 8, 18, 7, 19, 19, 5, 10, 17, 2, 9, 9, 10, 12, 8, 4, 10, 18, 15, 15, 6, 3, 7, 4, 9, 4, 13, 11, 16, 2, 2, 3, 6, 2, 6, 11, 14, 0, 11, 0, 7, 19, 8, 1, 19, 8, 12, 10, 11, 1, 5, 14, 11, 12, 16, 19, 15, 7, 18, 3, 9, 10, 12, 4, 16, 15, 7, 3, 4, 18, 16, 18, 14, 18, 10, 3, 19, 10, 7, 12, 0, 11, 16, 9, 0, 1, 15, 7, 14, 12, 3, 18, 0, 13, 11, 17, 1, 17, 10, 8, 18, 1, 19, 6, 3, 6, 11, 0, 4, 11, 7, 17, 16, 1, 12, 8, 1, 15, 4, 0, 17, 10, 19, 14, 18, 6, 6, 8, 13, 9, 2, 8, 4, 12, 8, 2, 19, 4, 0, 10, 3, 19, 19, 9, 6, 7, 14, 15, 14, 9, 7, 18, 6, 2, 14, 17, 4, 6, 5, 7, 8, 2, 0, 8, 1, 19, 12, 4, 1, 16, 16, 15, 4, 17, 12, 13, 19, 16, 1, 11, 15, 12, 13, 5, 7, 19, 9, 17, 5, 4, 8, 4, 17, 2, 2, 4, 11, 8, 5, 10, 16, 1, 3, 17, 14, 9, 8, 15, 11, 13, 17, 6, 3, 15, 17, 9, 9, 14, 3, 12, 12, 5, 8, 1, 17, 1, 15, 9, 8, 0, 14, 2, 11, 11, 6, 10, 3, 16, 9, 0, 10, 17, 3, 2, 11, 15, 4, 14, 15, 10, 4, 9, 8, 12, 13, 13, 5, 4, 0, 17, 5, 2, 4, 11, 11, 16, 8, 1, 17, 14, 11, 0, 3, 17, 2, 9, 19, 12, 16, 17, 15, 0, 17, 15, 18, 14, 9, 0, 15, 11, 18, 6, 14, 11, 9, 1, 8, 13, 5, 14, 17, 18, 17, 4, 0, 0, 2, 17, 15, 9, 4, 12, 19, 16, 5, 4, 6, 3, 14, 14, 19, 1, 2, 2, 11, 14, 12, 0, 18, 1, 5, 9, 3, 13, 3, 18, 7, 15, 16, 8, 18, 7, 17, 17, 16, 13, 0, 3, 16, 6, 7, 7, 19, 3, 16, 7, 11, 17, 18, 4, 0, 6, 5, 17, 3, 10, 13, 8, 1, 10, 3, 12, 14, 13, 17, 14, 10, 12, 10, 12, 4, 12, 17, 15, 17, 8, 14, 12, 11, 0, 10, 9, 11, 4, 8, 8, 8, 6, 12, 8, 6, 8, 11, 0, 1, 8, 10, 1, 1, 12, 12, 19, 1, 0, 7, 14, 3, 13, 6, 9, 16, 5, 16, 19, 16, 0, 3, 18, 15, 13, 15, 8, 17, 1, 9, 12, 0, 11, 7, 12, 12, 18, 13, 4, 8, 15, 9, 0, 11, 13, 19, 13, 15, 5, 8, 14, 9, 18, 17, 9, 1, 18, 2, 3, 8, 11, 0, 19, 15, 15, 17, 13, 13, 5, 10, 15, 17, 12, 7, 5, 9, 13, 6, 18, 3, 7, 7, 18, 2, 9, 18, 18, 0, 14, 5, 4, 5, 3, 4, 7, 18, 12, 6, 7, 10, 2, 18, 1, 4, 16, 2, 5, 7, 13, 14, 7, 19, 8, 8, 8, 5, 17, 10, 5, 16, 8, 1, 13, 9, 12, 13, 3, 8, 1, 2, 14, 12, 8, 13, 4, 17, 2, 5, 1, 0, 0, 15, 12, 18, 3, 11, 14, 8, 4, 6, 6, 11, 9, 17, 5, 12, 8, 4, 11, 2, 11, 3, 2, 7, 12, 19, 17, 11, 11, 0, 7, 15, 11, 13, 10, 1, 14, 9, 1, 13, 7, 13, 6, 7, 16, 6, 0, 5, 3, 12, 4, 0, 1, 15, 18, 3, 10, 13, 13, 16, 15, 8, 5, 17, 17, 5, 19, 12, 5, 13, 14, 10, 9, 19, 3, 14, 2, 7, 10, 6, 10, 2, 0, 18, 8, 9, 0, 7, 9, 14, 18, 14, 5, 4, 9, 6, 19, 2, 4, 7, 17, 3, 7, 7, 4, 1, 15, 6, 14, 0, 7, 1, 5, 0, 0, 8, 7, 18, 0, 12, 14, 2, 10, 18, 2, 12, 1, 9, 4, 5, 9, 6, 2, 16, 2, 14, 12, 2, 16, 15, 9, 5, 15, 7, 19, 0, 0, 6, 15, 0, 0, 14, 16, 14, 19, 11, 13, 1, 15, 0, 17, 8, 7, 16, 7, 19, 14, 18, 10, 10, 16, 7, 15, 11, 2, 0, 12, 18, 5, 3, 7, 1, 9, 5, 4, 13, 15, 15, 15, 18, 9, 13, 14, 9, 8, 10, 5, 12, 6, 10, 2, 6, 10, 0, 19, 17, 5, 12, 6, 4, 13, 16, 4, 9, 7, 13, 17, 15, 1, 8, 0, 3, 14, 13, 10, 4, 17, 5, 11, 0, 8, 15, 11, 17, 1, 12, 10, 8, 2, 3, 19, 4, 18, 1, 2, 11, 11, 9, 0, 9, 16, 16, 18, 1, 6, 8, 1, 19, 15, 2, 14, 18, 11, 17, 14, 7, 19, 5, 11, 14, 2, 8, 19, 10, 2, 10, 8, 11, 11, 15, 9, 1, 2, 1, 8, 10, 17, 10, 16, 4, 17, 0, 1, 2, 11, 16, 10, 17, 11, 4, 19, 1, 2, 12, 3, 4, 19, 2, 19, 13, 8, 1, 7, 10, 2, 11, 4, 9, 11, 7, 7, 11, 2, 14, 13, 0, 12, 7, 16, 6, 9, 12, 13, 5, 0, 15, 10, 16, 0, 11, 18, 10, 7, 8, 19, 17};
    cout << equalSumIndex(nums); // result: -1
    */

    return 0;
}
