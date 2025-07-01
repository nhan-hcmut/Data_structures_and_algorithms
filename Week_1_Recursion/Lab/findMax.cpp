#include<iostream>
using namespace std;

int findMax(int* arr, int length) {
    
    if (length == 1) return *arr;
    
    return max(arr[length - 1], findMax(arr, length - 1));
}

int main() {
    int arr1[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(arr1, 10) << endl; // Result: 15

    int arr2[] = {10};
    cout << findMax(arr2, 1) << endl; // Result: 10

    int arr3[] = {10, -1, -150, 200};
    cout << findMax(arr3, 4) << endl; // Result: 200

    int arr4[] = {24,0,88,-59,-54,13,20,-11,22,-48,5,22,-40,-26,-97,88};
    cout << findMax(arr4, 16) << endl; // Result: 88

    int arr5[] = {-85, -82, -75, -74, -70, -57, -36, -23, -21, -12, -7, 8, 20, 39, 49, 63, 66, 67, 71, 80};
    cout << findMax(arr5, 20) << endl; // Result: 80

    int arr6[] = {291, -444, -456, 199, 465, 31, 118, -16, 103, -23, 199, 342, 291, 374, -206, -383, -15, -286, -216, -287, 155, 310, -345, -444, -254, -7, 304, -99, -143, -456, -349, 154, -38, -60, 166, -40, 256, -107, -31, -454, 486, 270, -458, -367, 258, 310, -342, -405, -361};
    cout << findMax(arr6, 49) << endl; // Result: 486

    return 0;
}
