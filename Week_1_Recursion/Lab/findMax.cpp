#include<iostream>
using namespace std;

int findMax(int* arr, int length) {
    
    if (length == 1) return *arr;
    
    return max(arr[length - 1], findMax(arr, length - 1));
}

int main() {
    
    int arr1[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    
    cout << findMax(arr1, 10) << endl;

    int arr2[] = {291, -444, -456, 199, 465, 31, 118, -16, 103, -23, 199, 342, 291, 374, -206, -383, -15, -286, -216, -287, 155, 310, -345, -444, -254, -7, 304, -99, -143, -456, -349, 154, -38, -60, 166, -40, 256, -107, -31, -454, 486, 270, -458, -367, 258, 310, -342, -405, -361};

    cout << findMax(arr2, 49) << endl;

    return 0;
}
