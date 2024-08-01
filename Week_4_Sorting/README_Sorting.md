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
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
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
for(int i = 0; i <int(sizeof(arr))/4;i++)
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
    static void printArray(T *start, T *end)
    {
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
