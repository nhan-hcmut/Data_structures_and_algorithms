#include<iostream>
using namespace std;

int findMore(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int findMax(int* arr, int length) {
    
    if (length == 1) return *arr;
    
    return findMore(arr[length-1], findMax(arr, length-1));
}

int main() {
    
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    
    cout << findMax(arr, 10);

    return 0;
}
