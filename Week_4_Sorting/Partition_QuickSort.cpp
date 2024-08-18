#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>

using namespace std;

template<class T>
class Sorting {
    private:
    static T* Partition(T* start, T* end);
    
    public:
    static void QuickSort(T* start, T* end);
};

template<class T>
T* Sorting<T>::Partition(T* start, T* end) { // using Hoare partition algorithm
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = *start;
    T *i = start, *j = end;
    do {
        do i++; while (*i < pivot);
        do j--; while (*j > pivot);
        
        // swap
        T temp = *i;
        *i = *j;
        *j = temp;
    }
    while (i < j);
    
    // undo last swap when i >= j
    T temp = *i;
    *i = *j;
    *j = temp;

    // swap the first value and j
    temp = *start;
    *start = *j;
    *j = temp;

    return j;
}

template<class T>
void Sorting<T>::QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after every time calling method Partition.
    if (start >= end) return;
    T* pivotPtr = Partition(start, end);
    cout << pivotPtr - start << ' ';
    QuickSort(start, pivotPtr);
    QuickSort(pivotPtr + 1, end);
}
#endif /* SORTING_H */

int main() {
    int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";
    
    /*result:
    Index of pivots: 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0
    Array after sorting: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    */
    return 0;
}
