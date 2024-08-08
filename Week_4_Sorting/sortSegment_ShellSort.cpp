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
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    public:
    // TODO: Write your code here
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        // TODO
        int size = end - start; // read examples carefully
        
        for (int inserted = segment_idx + cur_segment_total; inserted < size; inserted += cur_segment_total) {
            T temp = start[inserted];
            int walker = inserted - cur_segment_total;
            
            while (walker >= segment_idx && start[walker] > temp) {
                start[walker + cur_segment_total] = start[walker];
                walker -= cur_segment_total;
            }
            start[walker + cur_segment_total] = temp;
        }
    }
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int phase = num_phases; phase > 0; phase--) {
            for (int seg = 0; seg < num_segment_list[phase - 1]; seg++) {
                sortSegment(start, end, seg, num_segment_list[phase - 1]);
            }
            cout << num_segment_list[phase - 1] << " segments: ";
            Sorting<T>::printArray(start, end);
        }
    }
};
#endif /* SORTING_H */

int main() {

    // test 1
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);

    /*result:
    5 segments: 5 4 3 2 1 10 9 8 7 6
    3 segments: 2 1 3 5 4 7 6 8 10 9
    1 segments: 1 2 3 4 5 6 7 8 9 10
    */
    
    /* test 2
    int num_segment_list[] = {1, 2, 6};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);

    Result:
    6 segments: 4 3 2 1 6 5 10 9 8 7
    2 segments: 2 1 4 3 6 5 8 7 10 9
    1 segments: 1 2 3 4 5 6 7 8 9 10
    */

    /* test 3
    int num_segment_list[] = {1, 2, 5};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);

    result:
    5 segments: 5 4 3 2 1 10 9 8 7 6
    2 segments: 1 2 3 4 5 6 7 8 9 10
    1 segments: 1 2 3 4 5 6 7 8 9 10
    */
    
    /* test 4
    int num_segment_list[] = {1, 2, 3};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);

    result:
    3 segments: 1 3 2 4 6 5 7 9 8 10
    2 segments: 1 3 2 4 6 5 7 9 8 10
    1 segments: 1 2 3 4 5 6 7 8 9 10
    */

    /* test 5
    int num_segment_list[] = {1, 5, 8, 10};
    int num_phases = 4;
    int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11};

    Sorting<int>::ShellSort(&array[0], &array[15], &num_segment_list[0], num_phases);

    result:
    10 segments: 3 5 4 8 11 14 15 13 1 2 9 6 7 10 12
    8 segments: 1 2 4 6 7 10 12 13 3 5 9 8 11 14 15
    5 segments: 1 2 4 3 5 9 8 11 6 7 10 12 13 14 15
    1 segments: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    */
    return 0;
}
