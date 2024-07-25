# DataLog

In this exercise, we will use Standard Template Library List (click open in other tab to show more) to implement a Data Log. 

This is a simple implementation in applications using undo and redo. For example in Microsoft Word, you must have nodes to store states when Ctrl Z or Ctrl Shift Z to go back or forward.

DataLog has a doubly linked list to store the states of data (an integer) and iterator to mark the current state. Each state is stored in a node, the transition of states is depicted in the figure below. 

Your task in this exercise is implement functions marked with /*  * TODO   */.
```cpp
class DataLog {
    private:
    list<int> logList;
    list<int>::iterator currentState;

    public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};
```
**Note:** Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list, we use forward list.

We have include \<iostream\>, \<list\> and using namespace std;

**For example:**

+ Test 1:
```cpp
DataLog log(10);
log.save();
log.addCurrentState(15);
log.save();
log.addCurrentState(15);
log.undo();
log.printLog();
```
+ Result1: [ 10 ] => Current state: [ 25 ] => [ 40 ] => END_LOG
<br/><br/>

+ Test 2:
```cpp
DataLog log(10);
log.save();
log.addCurrentState(15);
log.save();
log.addCurrentState(15);
log.save();
log.subtractCurrentState(5);
log.printLog();
```
+ Result 2: [ 10 ] => [ 25 ] => [ 40 ] => Current state: [ 35 ] => END_LOG
---
# Iterator

Implement Iterator class in class DLinkedList. 

**Note:** Iterator is a concept of repetitive elements on sequence structures. Iterator is implemented in class vector, list in STL container in C++ (https://www.geeksforgeeks.org/iterators-c-stl/). Your task is to implement the simple same class with iterator in C++ STL container.

```cpp
template <class T>
class DLinkedList {
    public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
    
    protected:
    Node *head;
    Node *tail;
    int count;
    
    public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
    
    public:
    class Node {
        
        private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

        public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator {
        
        private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
        
        public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};
```
Please read example carefully to see how we use the iterator.

**For example:**

+ Test 1:
```cpp
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
    list.add(idx);
}
DLinkedList<int>::Iterator it = list.begin();
for(; it != list.end(); it++)
{
    cout << *it << " |";
}
```
+ Result 1: 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
<br/><br/>

+Test 2:
```cpp
DLinkedList<int> list;
int size = 10;
for (int idx = 0; idx < size; idx++)
{
    list.add(idx);
}

DLinkedList<int>::Iterator it = list.begin();
while (it != list.end())
{
    it.remove();
    it++;
}
cout << list.toString();
```
+ Result 2: []
<br/><br/>

+ Test 3:
```cpp
DLinkedList<int> list;
int size = 10;
for (int idx = 0; idx < size; idx++)
{
    list.add(idx);
}

DLinkedList<int>::Iterator it = list.begin();
for(; it != list.end(); it++)
{
    it.remove();
}
cout << list.toString();
```
+ Result 3: []

---
# add_size

Implement methods add, size in template class DLinkedList (which implements List ADT) representing the doubly linked list with type T with the initialized frame. The description of each method is given in the code.

```cpp
template <class T>
class DLinkedList {
    public:
    class Node; // Forward declaration

    protected:
    Node* head;
    Node* tail;
    int count;

    public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();

    public:
    class Node {

        private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};
```
In this exercise, we have include \<iostream\>, \<string\>, \<sstream\> and using namespace std.

**For example:**

+ Test 1:
```cpp
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
   list.add(idx);
}
cout << list.toString();
```
+ Result 1: [0,1,2,3,4,5,6,7,8,9]
<br/><br/>

+ Test 2:
```cpp
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
   list.add(0, idx);
}
cout << list.toString();
```
+ Result 2: [9,8,7,6,5,4,3,2,1,0]
---
# get_set_empty_indexOf_contains

Implement methods get, set, empty, indexOf, contains in template class DLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

```cpp
template <class T>
class DLinkedList {
    public:
    class Node; // Forward declaration

    protected:
    Node* head;
    Node* tail;
    int count;

    public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);

    public:
    class Node {

        private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};
```
In this exercise, we have include \<iostream\>, \<string\>, \<sstream\> and using namespace std.

**For example:**

+ Test 1:
```cpp
DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
  list.add(idx);
}
for(int idx=0; idx < size; idx++){
  cout << list.get(idx) << " |";
}
```
+ Result 1: 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
<br/><br/>

+ Test 2:
```cpp
DLinkedList<int> list;
int size = 10;
int value[] = {2,5,6,3,67,332,43,1,0,9};
for(int idx=0; idx < size; idx++){
  list.add(idx);
}
for(int idx=0; idx < size; idx++){
  list.set(idx, value[idx]);
}
cout << list.toString();
```
+ Result 2: [2,5,6,3,67,332,43,1,0,9]
---
# removeAt_removeItem_clear

Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.

```cpp
template <class T>
class DLinkedList {
    public:
    class Node; // Forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
    
    public:
    class Node {
        private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};
```
In this exercise, we have include \<iostream\>, \<string\>, \<sstream\> and using namespace std.

**For example:**

+ Test:
```cpp
DLinkedList<int> list;
int size = 10;
int value[] = {2,5,6,3,67,332,43,1,0,9};

for(int idx=0; idx < size; idx++){
  list.add(value[idx]);
}
list.removeAt(0);
cout << list.toString();
```
+ Result: [5,6,3,67,332,43,1,0,9]
---