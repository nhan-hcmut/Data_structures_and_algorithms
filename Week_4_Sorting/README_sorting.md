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
# maxNumberOfPeople

A hotel has m rooms left, there are n people who want to stay in this hotel. You have to distribute the rooms so that as many people as possible will get a room to stay.

However, each person has a desired room size, he/she will accept the room if its size is close enough to the desired room size.

More specifically, if the maximum difference is k, and the desired room size is x, then he or she will accept a room if its size is between x - k and x + k

Determine the maximum number of people who will get a room to stay by implementing function:
```cpp
int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k);
```

**input:**

+ vector<int> rooms: rooms[i] is the size of the ith room
+ vector<int> people: people[i] the desired room size of the ith person
+ int k: maximum allowed difference. If the desired room size is x, he or she will accept a room if its size is between x - k and x + k

**output:**

the maximum number of people who will get a room to stay.

**Note:** The \<iostream\>, \<vector\> and \<algorithm\> library are already included for you.

**Constraints:**
1 <= rooms.length, people.length <= 2 * 10^5
0 <= k <= 10^9
1 <= rooms[i], people[i] <= 10^9

**Example 1:**

Input:
rooms = {57, 45, 80, 65}
people = {30, 60, 75}
k = 5
Output:
2

**Explanation:**
2 is the maximum amount of people that can stay in this hotel.
There are 3 people and 4 rooms, the first person cannot stay in any room, the second and third person can stay in the first and third room, respectively

**Example 2:**

Input:
rooms = {59, 5, 65, 15, 42, 81, 58, 96, 50, 1}
people = {18, 59, 71, 65, 97, 83, 80, 68, 92, 67}
k = 1000
Output:
10

**For example:**

+ Test 1:
```cpp
int peopleCount, roomCount, k;
cin >> peopleCount >> roomCount >> k;

vector<int> people(peopleCount);
vector<int> rooms(roomCount);

for (int i = 0; i < peopleCount; i++)
    cin >> people[i];
for (int i = 0; i < roomCount; i++)
    cin >> rooms[i];
cout << maxNumberOfPeople(rooms, people, k) << '\n';
```
+ Input 1:
<br/>
3 4 5
<br/>
30 60 75
<br/>
57 45 80 65

+ Result 1: 2

+ Test 2:
```cpp
int peopleCount, roomCount, k;
cin >> peopleCount >> roomCount >> k;

vector<int> people(peopleCount);
vector<int> rooms(roomCount);

for (int i = 0; i < peopleCount; i++)
    cin >> people[i];
for (int i = 0; i < roomCount; i++)
    cin >> rooms[i];
cout << maxNumberOfPeople(rooms, people, k) << '\n';
```
+ Input 2:
<br/>
10 10 1000
<br/>
18 59 71 65 97 83 80 68 92 67
<br/>
59 5 65 15 42 81 58 96 50 1

+ Result 2: 10

---
# mergeLists_mergeSortList

The best way to sort a singly linked list given the head pointer is probably using merge sort.

Both Merge sort and Insertion sort can be used for linked lists. The slow random-access performance of a linked list makes other algorithms (such as quick sort) perform poorly, and others (such as heap sort) completely impossible. Since worst case time complexity of Merge Sort is O(nLogn) and Insertion sort is O(n^2), merge sort is preferred. 

Additionally, Merge Sort for linked list only requires a small constant amount of auxiliary storage.

To gain a deeper understanding about Merge sort on linked lists, let's implement mergeLists and mergeSortList function below

**Constraints:**

0 <= list.length <= 10^4
0 <= node.val <= 10^6

Use the nodes in the original list and don't modify ListNode's val attribute. 
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b);

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head);
```

**For example:**

+ Test 1:
```cpp
int arr1[] = {1, 3, 5, 7, 9};
int arr2[] = {2, 4, 6, 8};
unordered_map<ListNode*, int> nodeAddr;
ListNode* a = init(arr1, sizeof(arr1) / 4, nodeAddr);
ListNode* b = init(arr2, sizeof(arr2) / 4, nodeAddr);
ListNode* merged = mergeLists(a, b);
try {
    printList(merged, nodeAddr);
}
catch(char const* err) {
    cout << err << '\n';
}
freeMem(merged);
```
+ Result 1: 1 2 3 4 5 6 7 8 9


+ Test 2:
```cpp
int size;
cin >> size;
int* array = new int[size];
for(int i = 0; i < size; i++) cin >> array[i];
unordered_map<ListNode*, int> nodeAddr;
ListNode* head = init(array, size, nodeAddr);
ListNode* sorted = mergeSortList(head);
try {
    printList(sorted, nodeAddr);
}
catch(char const* err) {
    cout << err << '\n';
}
freeMem(sorted);
delete[] array;
```
+ Input 2:
<br/>
9
<br/>
9 3 8 2 1 6 7 4 5 
<br/>
<br/>

+ Result 2: 1 2 3 4 5 6 7 8 9

---
# merge_InsertionSort_TimSort

Implement static methods merge, InsertionSort and TimSort in class Sorting to sort an array in ascending order. 

merge is responsible for merging two sorted subarrays. It takes three pointers: start, middle, and end, representing the left, middle, and right portions of an array. 

InsertionSort is an implementation of the insertion sort algorithm. It takes two pointers, start and end, and sorts the elements in the range between them in ascending order using the insertion sort technique.

TimSort is an implementation of the TimSort algorithm, a hybrid sorting algorithm that combines insertion sort and merge sort. It takes two pointers, start and end, and an integer min_size, which determines the minimum size of subarrays to be sorted using insertion sort. The function first applies insertion sort to small subarrays, prints the intermediate result, and then performs merge operations to combine sorted subarrays until the entire array is sorted.

```cpp
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
}

template<class T>
void Sorting<T>::InsertionSort(T* start, T* end) {
    // TODO
}

template<class T>
void Sorting<T>::TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and every time calling method merge.
}

#endif /* SORTING_H */
```

**For example:**

+ Test 1:
```cpp
int array[] = { 19, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 3 };
int min_size = 4;
Sorting<int>::TimSort(&array[0], &array[20], min_size);
```
+ Result 1:
<br/>
Insertion Sort: 17 18 19 20 12 13 14 15 1 2 6 9 4 7 11 16 3 5 8 10
<br/>
Merge 1: 12 13 14 15 17 18 19 20 1 2 6 9 4 7 11 16 3 5 8 10
<br/>
Merge 2: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
<br/>
Merge 3: 12 13 14 15 17 18 19 20 1 2 4 6 7 9 11 16 3 5 8 10
<br/>
Merge 4: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
<br/>
Merge 5: 1 2 4 6 7 9 11 12 13 14 15 16 17 18 19 20 3 5 8 10
<br/>
Merge 6: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
<br/>

+ Test 2:
```cpp
int array[] = { 3, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 19 };
int min_size = 4;
Sorting<int>::TimSort(&array[0], &array[20], min_size);
Insertion Sort: 3 17 18 20 12 13 14 15 1 2 6 9 4 7 11 16 5 8 10 19
```
+ Result 2:
<br/>
Insertion Sort: 3 17 18 20 12 13 14 15 1 2 6 9 4 7 11 16 5 8 10 19
<br/>
Merge 1: 3 12 13 14 15 17 18 20 1 2 6 9 4 7 11 16 5 8 10 19
<br/>
Merge 2: 3 12 13 14 15 17 18 20 1 2 4 6 7 9 11 16 5 8 10 19
<br/>
Merge 3: 3 12 13 14 15 17 18 20 1 2 4 6 7 9 11 16 5 8 10 19
<br/>
Merge 4: 1 2 3 4 6 7 9 11 12 13 14 15 16 17 18 20 5 8 10 19
<br/>
Merge 5: 1 2 3 4 6 7 9 11 12 13 14 15 16 17 18 20 5 8 10 19
<br/>
Merge 6: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

---
# merge_mergeSort

Implement static methods Merge and MergeSort in class Sorting to sort an array in ascending order. The Merge method has already been defined a call to method printArray so you do not have to call this method again to print your array.
```cpp
#ifndef SORTING_H
#define SORTING_H

#include <iostream>

using namespace std;

template <class T>
class Sorting {

    public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
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
void Sorting<T>::merge(T* left, T* middle, T* right){
    /*TODO*/
    Sorting::printArray(left, right);
}

template<class T>
void Sorting<T>::mergeSort(T* start, T* end) {
    /*TODO*/
}
#endif /* SORTING_H */
```

**For example:**

+ Test 1:
```cpp
int arr[] = {0,2,4,3,1,4};
Sorting<int>::mergeSort(&arr[0], &arr[5]);
```
+ Result 1:

0, 2
<br/>
0, 2, 4
<br/>
1, 3
<br/>
1, 3, 4
<br/>
0, 1, 2, 3, 4, 4
<br/>

+ Test 2:
```cpp
int arr[] = {1};
Sorting<int>::mergeSort(&arr[0], &arr[0]);
```
+ Result 2: \<empty ouput\> (nothing is printed out)

+ Test 3:
```cpp
int arr[] = {-3,5,6,-22,42,5,0};
Sorting<int>::mergeSort(&arr[0], &arr[6]);
```
+ Result 3:

-3, 5
<br/>
-22, 6
<br/>
-22, -3, 5, 6
<br/>
5, 42
<br/>
0, 5, 42
<br/>
-22, -3, 0, 5, 5, 6, 42

---
# minDiffPairs

Given a list of distinct unsorted integers nums.

Your task is to implement a function with following prototype:
```cpp
string minDiffPair(int* arr, int n);
```
This function identify and return all pairs of elements with the smallest absolute difference among them. If there are multiple pairs that meet this criterion, the function should find and return all of them.

**Note:** Following libraries are included: \<iostream\>, \<string\>, \<algorithm\>, \<sstream\>

**For example:**

+ Test 1:
```cpp
int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
cout << minDiffPairs(arr, 10);
```
+ Result 1: (5, 6), (6, 7), (7, 8), (8, 9), (9, 10), (10, 11), (11, 12)

+ Test 2:
```cpp
int arr[] = {10};
cout << minDiffPairs(arr, 1);
int arr[] = {10, -1, -150, 200};
cout << minDiffPairs(arr, 4);
```
+ Result 2: (-1, 10)

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
