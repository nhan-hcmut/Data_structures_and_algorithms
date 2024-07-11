#include<iostream>
#include<algorithm>
using namespace std;

int buyCar(int* nums, int length, int k) {
    int sum = 0, count = 0;
    sort(nums, nums + length); // <algorithm> library
    for (short i = 0; i < length; i++) {
        
        if ((sum + nums[i]) > k) return count;
        
        sum += nums[i];
        count++;
    }
    return count;
}

int main() {
    
    int nums[] = {90, 30, 40, 90, 20};

    int length = sizeof(nums) / sizeof(nums[0]);
    
    cout << buyCar(nums, length, 90) << "\n"; // Result: 3
    
    return 0;
}
