#include <iostream>
using namespace std;

template <class T> class Sorting {
    public:
    /* Function to print an array */
    static void printArray(T *start, T *end) {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end) {
    int size = end - start;
    
    for (int lowerBound = 0; lowerBound < size - 1; lowerBound++) {
        int indexOfMin = lowerBound;
        
        for (int walker = indexOfMin + 1; walker < size; walker++) {
            if (start[walker] < start[indexOfMin]) {
                indexOfMin = walker;
            }
        }
        T temp = start[lowerBound];
        start[lowerBound] = start[indexOfMin];
        start[indexOfMin] = temp;
        printArray(start, end);
    }
}

int main() {
    
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
    /*result:
    -2, 2, 8, 1, 0, 9
    -2, 0, 8, 1, 2, 9
    -2, 0, 1, 8, 2, 9
    -2, 0, 1, 2, 8, 9
    -2, 0, 1, 2, 8, 9
    */
    return 0;
}