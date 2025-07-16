#include<iostream>
#include<string>
#include<cstring>
#include<climits>
#include<utility>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<functional>
#include<algorithm>
using namespace std;

int steadySpeed(vector<int>& p) {
    int size = p.size();
    if (size < 3) return size; // If the size is less than 3, then either 1 or 2 positions are always a valid constant speed sublist
    
    /*
    First variable: Start with a sublist of length 2 (minimum for checking constant speed).
    Second variable: Store the maximum length of any constant-speed sublist found.
    Third variable: Calculate the initial speed (difference between first two positions).
    */
    int lengthOfCurrentSublist = 2, result = 2, speed = abs(p.at(1) - p.at(0));

    // Loop through the position list starting from the third element
    for (int i = 2; i < size; i++) {
        int currentSpeed = abs(p.at(i) - p.at(i - 1)); // Calculate the difference between current and previous position (i.e., speed at this interval)

        if (currentSpeed == speed) lengthOfCurrentSublist++; // If current speed is equal to previous speed, we are still in a constant speed sublist

        else {
            result = max(result, lengthOfCurrentSublist); // Speed changed, update the result if needed
            lengthOfCurrentSublist = 2; // Reset current sublist length to 2 (current and previous positions)
            speed = currentSpeed; // Update the speed to the new speed
        }
    }
    result = max(result, lengthOfCurrentSublist); // Final check to ensure the last sublist is considered
    return result;
}

int main() {
    // Test 1
    vector<int> positions1 {5, 4, 3, 5, 4, 5, 1, 3, 5, 3};
    cout << steadySpeed(positions1) << endl; // Result: 4
    
    // Test 2
    vector<int> positions2 {0, 3, 6, 3, 0};
    cout << steadySpeed(positions2) << endl; // Result: 5
    
    // Test 3
    vector<int> positions3 {0, 1, 2, 4, 8, 16, 32, 64, 128};
    cout << steadySpeed(positions3) << endl; // Result: 3
    
    // Test 4
    vector<int> positions4 {0, 1, 3, 6, 10, 15, 21, 28, 37};
    cout << steadySpeed(positions4) << endl; // Result: 2

    return 0;
}