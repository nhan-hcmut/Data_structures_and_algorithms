# Partition_QuickSort

Implement static methods Partition and QuickSort in class Sorting to sort an array in ascending order. 
```cpp
#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
class Sorting {
    private:
    static T* Partition(T* start, T* end);

    public:
    static void QuickSort(T* start, T* end);
};

template<class T>
T* Sorting<T>::Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
}

template<class T>
void Sorting<T>::QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after every time calling method Partition.
}
#endif /* SORTING_H */
```
You can read the pseudocode of the algorithm used to in method Partition in the "HoarePartition.png" image.

**For example:**

+ Test:
```cpp
int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
cout << "Index of pivots: ";
Sorting<int>::QuickSort(&array[0], &array[20]);
cout << "\n";
cout << "Array after sorting: ";
for (int i : array) cout << i << " ";
```
+ Result:

Index of pivots: 2 0 0 6 1 0 2 1 0 0 2 1 0 0 0 0 0 0 1 0
<br/>
Array after sorting: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

---
# bubbleSort

Implement method bubbleSort() in class SLinkedList to sort this list in ascending order. After each bubble, we will print out a list to check (using printList).
```cpp
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
    public:
    class Node; // Forward declaration

    protected:
    Node* head;
    Node* tail;
    int count;

    public:
    SLinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e) {
        Node *pNew = new Node(e);

        if (this->count == 0) {
            this->head = this->tail = pNew;
        }
        else {
            this->tail->next = pNew;
            this->tail = pNew;
        }
        this->count++;
    }
    int size() {
        return this->count;
    }
    void printList() {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail) {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
    public:
    class Node {
        private:
        T data;
        Node* next;
        friend class SLinkedList<T>;

        public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    void bubbleSort();
};
```
**For example:**

+ Test:
```cpp
int arr[] = {9, 2, 8, 4, 1};
SLinkedList<int> list;
for (int i = 0; i < int(sizeof(arr)) / 4; i++)
    list.add(arr[i]);
list.bubbleSort();
```
+ Result:
<br/>
[2,8,4,1,9]
<br/>
[2,4,1,8,9]
<br/>
[2,1,4,8,9]
<br/>
[1,2,4,8,9]

---
# selectionSort

Implement static method selectionSort in class Sorting to sort an array in ascending order.  After each selection, we will print out a list to check (using printArray). 
```cpp
#include <iostream>
using namespace std;

template <class T>
class Sorting {
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
```
**For example:**

+ Test:
```cpp
int arr[] = {9, 2, 8, 1, 0, -2};
Sorting<int>::selectionSort(&arr[0], &arr[6]);
```
+ Result:
<br/>
-2, 2, 8, 1, 0, 9
<br/>
-2, 0, 8, 1, 2, 9
<br/>
-2, 0, 1, 8, 2, 9
<br/>
-2, 0, 1, 2, 8, 9
<br/>
-2, 0, 1, 2, 8, 9

---
# sortSegment_ShellSort

Implement static methods sortSegment and ShellSort in class Sorting to sort an array in ascending order. 

```cpp
#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
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
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};
#endif /* SORTING_H */
```

**For example:**

+ Test 1:
```cpp
int num_segment_list[] = {1, 3, 5};
int num_phases = 3;
int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
```
+ Result 1:

5 segments: 5 4 3 2 1 10 9 8 7 6
<br/>
3 segments: 2 1 3 5 4 7 6 8 10 9
<br/>
1 segments: 1 2 3 4 5 6 7 8 9 10

+ Test 2:
```cpp
int num_segment_list[] = {1, 2, 6};
int num_phases = 3;
int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
```
+ Result 2:

6 segments: 4 3 2 1 6 5 10 9 8 7
<br/>
2 segments: 2 1 4 3 6 5 8 7 10 9
<br/>
1 segments: 1 2 3 4 5 6 7 8 9 10

+ Test 3:
```cpp
int num_segment_list[] = {1, 2, 5};
int num_phases = 3;
int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
```
+ Result 3:

5 segments: 5 4 3 2 1 10 9 8 7 6
<br/>
2 segments: 1 2 3 4 5 6 7 8 9 10
<br/>
1 segments: 1 2 3 4 5 6 7 8 9 10

+ Test 4:
```cpp
int num_segment_list[] = {1, 2, 3};
int num_phases = 3;
int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
```
+ Result 4:

3 segments: 1 3 2 4 6 5 7 9 8 10
<br/>
2 segments: 1 3 2 4 6 5 7 9 8 10
<br/>
1 segments: 1 2 3 4 5 6 7 8 9 10

+ Test 5:
```cpp
int num_segment_list[] = {1, 5, 8, 10};
int num_phases = 4;
int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11};

Sorting<int>::ShellSort(&array[0], &array[15], &num_segment_list[0], num_phases);
```
+ Result 5:

10 segments: 3 5 4 8 11 14 15 13 1 2 9 6 7 10 12
<br/>
8 segments: 1 2 4 6 7 10 12 13 3 5 9 8 11 14 15
<br/>
5 segments: 1 2 4 3 5 9 8 11 6 7 10 12 13 14 15
<br/>
1 segments: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

---
