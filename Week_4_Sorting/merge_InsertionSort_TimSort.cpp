#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template<class T>
class Sorting {
    private:
    static void printArray(T* start, T* end) {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end);
    
    public:
    static void InsertionSort(T* start, T* end);
    static void TimSort(T* start, T* end, int min_size);
};

template<class T>
void Sorting<T>::merge(T* start, T* middle, T* end) {
    // TODO
    int sizeLeft = middle - start + 1;
    int sizeRight = end - middle;

    T* leftArr = new T[sizeLeft];
    T* rightArr = new T[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        leftArr[i] = start[i];
    }
    for (int i = 0; i < sizeRight; i++) {
        rightArr[i] = middle[i + 1];
    }
    int i = 0, j = 0, k = 0;
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] < rightArr[j]) {
            start[k++] = leftArr[i++];
        }
        else {
            start[k++] = rightArr[j++];
        }
    }
    while (i < sizeLeft) {
        start[k++] = leftArr[i++];
    }
    while (j < sizeRight) {
        start[k++] = rightArr[j++];
    }
}

template<class T>
void Sorting<T>::InsertionSort(T* start, T* end) {
    // TODO
    int len = end - start + 1;
    for (int i = 1; i < len; i++) {
        T temp = start[i];
        int j = i - 1;

        while (j >= 0 && start[j] > temp) {
            start[j + 1] = start[j];
            j--;
        }
        start[j + 1] = temp;
    }
}

template<class T>
void Sorting<T>::TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    int len = end - start;
    for (int i = 0; i < len; i += min_size) {
        int sub_len = min(min_size, len - i);
        InsertionSort(start + i, start + i + sub_len - 1);
    }
    cout << "Insertion Sort: ";
    printArray(start, end);
    int count = 1;
    for (int i = min_size; i < len; i *= 2) {
        for (int left = 0; left < len; left += 2 * i) {
            int mid = left + i - 1;
            int right = min(left + 2 * i - 1, len - 1);
            if (mid < right) {
                merge(start + left, start + mid, start + right);
            }
            cout << "Merge " << count++ << ": ";
            printArray(start, end);
        }
    }
}
#endif /* SORTING_H */

int main() {
    
    // Test 1
    int array[] = {19, 20, 18, 17, 12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3};
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
    /* Result 1
    Insertion Sort: 17 18 19 20 12 13 14 15 1 2 6 9 4 7 11 16 3 5 8 10
    Merge 1: 12 13 14 15 17 18 19 20 1 2 6 9 4 7 11 16 3 5 8 10
    Merge 2: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
    Merge 3: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
    Merge 4: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
    Merge 5: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
    Merge 6: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    */

    // test 2
    int array[] = { 3, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 19 };
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
    /* result
    Insertion Sort: 3 17 18 20 12 13 14 15 1 2 6 9 4 7 11 16 5 8 10 19
    Merge 1: 3 12 13 14 15 17 18 20 1 2 6 9 4 7 11 16 5 8 10 19
    Merge 2: 3 12 13 14 15 17 18 20 1 2 4 6 7 9 11 16 5 8 10 19
    Merge 3: 3 12 13 14 15 17 18 20 1 2 4 6 7 9 11 16 5 8 10 19
    Merge 4: 1 2 3 4 6 7 9 11 12 13 14 15 16 17 18 20 5 8 10 19
    Merge 5: 1 2 3 4 6 7 9 11 12 13 14 15 16 17 18 20 5 8 10 19
    Merge 6: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    */
    return 0;
}