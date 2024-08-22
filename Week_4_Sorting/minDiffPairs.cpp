#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

string minDiffPairs(int* arr, int n) {
    // STUDENT ANSWER
    string result = "";
    sort(arr, arr + n);
    int min = INT8_MAX;

    for (int i = 0; i < n - 1; i++) {
        int g = *(arr + i) ;
        int k = *(arr + i + 1);
        int a = abs(g - k);
        if (min > a) {
            min = a;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a = abs(*(arr + i) - *(arr + i + 1));
        if (a == min) {
            result = result + "(" + to_string(*(arr + i)) + ", " + to_string(*(arr + i + 1)) + "), ";
        }
    }
    if (result.length() > 1) {
        result = result.substr(0, result.length() - 2);
    }
    return result;
}

int main() {

    // Test 1
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr, 10); // Result: (5, 6), (6, 7), (7, 8), (8, 9), (9, 10), (10, 11), (11, 12)
    
    /* Test 2
    int arr[] = {10};
    cout << minDiffPairs(arr, 1); // Result: (empty, no result)
    */

    /* Test 3
    int arr[] = {10, -1, -150, 200};
    cout << minDiffPairs(arr, 4); // Result: (-1, 10)
    */
    return 0;
}