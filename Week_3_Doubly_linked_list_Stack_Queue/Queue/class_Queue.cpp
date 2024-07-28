#ifndef QUEUE_H
#define QUEUE_H

#include "DLinkedList.h"
#include<cassert>

template<class T>class Queue {
    protected:
    DLinkedList<T> list;
    
    public:
    Queue() {}
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
    void clear();
};

#endif /* QUEUE_H */

template <class T> class DLinkedList {
    public:
    class Node;     //forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    DLinkedList();
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

template<class T>
void Queue::push(T item) {
    // TODO: Push new element into the end of the queue
    this->list.add(item);
}

template<class T>
T Queue::pop() {
    // TODO: Remove an element in the head of the queue
    if (this->list->empty()) throw std::out_of_range("Empty queue.\n");
    return this->list.removeAt(0);
}

template<class T>
T Queue::top() {
    // TODO: Get value of the element in the head of the queue
    return this->list.get(0);
}

template<class T>
bool Queue::empty() {
    // TODO: Determine if the queue is empty
    return this->list.empty();
}

template<class T>
int Queue::size() {
    // TODO: Get the size of the queue
    return this->list.size();
}

template<class T>
void Queue::clear() {
    // TODO: Clear all elements of the queue
    this->list.clear();
}

int main() {
    
    Queue<int> queue;
    assert(queue.empty());
    assert(queue.size() == 0);

    return 0;
}
