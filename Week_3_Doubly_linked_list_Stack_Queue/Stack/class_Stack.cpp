#include<iostream>
using namespace std;
/*
You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.
*/
template <class T> class DLinkedList {
    public:
    class Node;     //forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};
/*
Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.
*/
#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"

template <class T> class Stack {
    protected:
    DLinkedList<T> list;
    
    public:
    Stack() {}
    void push(T item);
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};
#endif

template <class T> void Stack<T>::push(T item) {
    // TODO: Push new element into the top of the stack
    this->list.add(item);
}

template <class T> T Stack<T>::pop() {
    // TODO: Remove an element on top of the stack
    return this->list.removeAt(this->list.size()-1);
}

template <class T> T Stack<T>::top() {
    // TODO: Get value of the element on top of the stack
    return this->list.get(this->list.size()-1);
}

template <class T> bool Stack<T>::empty() {
    // TODO: Determine if the stack is empty
    return this->list.empty();
}

template <class T> int Stack<T>::size() {
    // TODO: Get the size of the stack
    return this->list.size();
}

template <class T> void Stack<T>::clear() {
    // TODO: Clear all elements of the stack
    this->list.clear();
}

int main() {

    // Test 1
    Stack<int> stack;
    cout << stack.empty() << " " << stack.size(); // Result: 1 0
    
    /* Test 2
    Stack<int> stack;

    int item[] = { 3, 1, 4, 5, 2, 8, 10, 12 };
    for (int idx = 0; idx < 8; idx++) stack.push(item[idx]);
        
    assert(stack.top() == 12);
        
    stack.pop();
    stack.pop();
        
    cout << stack.top(); // Result: 8
    */
    
    return 0;
}
