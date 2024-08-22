#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;

template<class T>
class Sorting {
    public:
    /* Function to print an array */
    static void printArray(T *start, T *end) {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    static void merge(T* left, T* middle, T* right);
    static void mergeSort(T* start, T* end);
};

template<class T>
void Sorting<T>::merge(T* left, T* middle, T* right) {
    /*TODO*/
    int sizeLeft = middle - left + 1, sizeRight = right - middle;

    // create 2 temporary arrays
    T *leftArray = new T[sizeLeft], *rightArray = new T[sizeRight];

    // copy data to temporary arrays
    for (int i = 0; i < sizeLeft; i++) leftArray[i] = left[i];
    for (int i = 0; i < sizeRight; i++) rightArray[i] = middle[i + 1];

    // Merge 2 temporary arrays into arr[l..r]
    int indexOfLeftArray = 0, indexOfRightArray = 0, indexOfMergedArray = 0;

    while (indexOfLeftArray < sizeLeft && indexOfRightArray < sizeRight) {
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            left[indexOfMergedArray++] = leftArray[indexOfLeftArray++];
        }
        else {
            left[indexOfMergedArray++] = rightArray[indexOfRightArray++];
        }
    }
    // copy remaining values of left sub-array (if there is any)
    while (indexOfLeftArray < sizeLeft) {
        left[indexOfMergedArray++] = leftArray[indexOfLeftArray++];
    }
    // copy remaining values of right sub-array (if there is any)
    while (indexOfRightArray < sizeRight) {
        left[indexOfMergedArray++] = rightArray[indexOfRightArray++];
    }
    delete[] leftArray;
    delete[] rightArray;
    Sorting::printArray(left, right);
}

template<class T>
void Sorting<T>::mergeSort(T* start, T* end) {
    /*TODO*/
    if (start >= end) return;
    T* middle = start + (end - start) / 2;
    mergeSort(start, middle);
    mergeSort(middle + 1, end);
    merge(start, middle, end);
}
#endif /* SORTING_H */

int main() {

    // test 1
    int arr[] = {0, 2, 4, 3, 1, 4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);

    /* result:
    0, 2
    0, 2, 4
    1, 3
    1, 3, 4
    0, 1, 2, 3, 4, 4
    */
    
    /* test 2
    int arr[] = {1};
    Sorting<int>::mergeSort(&arr[0], &arr[0]); // result: <empty>
    */

    /* test 3
    int arr[] = {-3,5,6,-22,42,5,0};
    Sorting<int>::mergeSort(&arr[0], &arr[6]);

    result:
    -3, 5
    -22, 6
    -22, -3, 5, 6
    5, 42
    0, 5, 42
    -22, -3, 0, 5, 5, 6, 42
    */
    
    return 0;
}