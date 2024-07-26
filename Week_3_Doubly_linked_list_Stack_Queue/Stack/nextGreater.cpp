#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// iostream, stack and vector are included

vector<int> nextGreater(vector<int>& arr) {
    vector<int> result;
    int len = arr.size();
    
    if (len < 2) {
        result.push_back(-1);
        return result;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[j] > arr[i]) {
                result.push_back(arr[j]);
                break;
            }
            if (j == len - 1) result.push_back(-1);
        }
    }
    result.push_back(-1); // the next greater number of the last element is always -1
    return result;
}

int main() {

    //Test 1
    int N;
    cin >> N; // Input: 4
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) cin >> nums[i]; // Input: 15 2 4 10
    vector<int> greaterNums = nextGreater(nums);
    
    for (int i : greaterNums) 
        cout << i << ' '; // Result: -1 4 10 -1
    cout << '\n';
    
    /* Test 2
    int N;
    cin >> N; // input: 5
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i]; // input: 1 4 6 9 6
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' '; // result: 4 6 9 -1 -1
    cout << '\n';
    */
    return 0;
}
