#include<iostream>
using namespace std;

int findMax(int* arr, int length) {
    if (length == 1) return arr[0];
    
    return ( arr[0] > findMax(arr+1, length-1) ) ? arr[0] : findMax(arr+1, length-1);
}

int main() {
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(arr, 10);

    return 0;
}
