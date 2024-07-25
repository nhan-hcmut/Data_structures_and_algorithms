#include<iostream>
#include<string>
#include<sstream>
using namespace std;

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
    ~DLinkedList() {
        delete this->head;
        delete this->tail;
    }
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

    Iterator begin() {
        return Iterator(this, true);
    }
    Iterator end() {
        return Iterator(this, false);
    }

    public:
    class Node {
    
        private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin() {
            return Iterator(this, true);
        }
        Iterator end() {
            return Iterator(this, false);
        }

        public:
        Node() {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data) {
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

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
*/
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) {
    this->pList = pList;
    if (begin) {
        this->current = (pList == nullptr) ? nullptr : this->pList->head;
        this->index = (pList == nullptr) ? -1 : 0;
    }
    else {
        this->current = nullptr;
        this->index = (pList == nullptr) ? 0 : this->pList->count;
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator) {
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e) {
    this->pList->set(this->index, e);
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() {
    return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() {
    /*
    * TODO: delete Node in pList which Node* current point to.
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    if (this->current == this->pList->head) {
        this->current = nullptr;
        this->index = -1;
        this->pList->removeAt(0);
    }
    else {
        this->current = this->current->previous;
        this->pList->removeAt(this->index);
        this->index--;
    }
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) {
    return this->current != iterator.current || this->index != iterator.index;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() {
    if (!this->pList && this->index >= this->pList->count) throw std::out_of_range("Out of range!\n");

    if (!this->current && this->index == -1) {
        this->current = this->pList->head;
        this->index = 0;
    }
    else {
        this->current = this->current->next;
        this->index++;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) {
    if (!this->current && this->index >= this->pList->count) throw std::out_of_range("Out of range!\n");
    
    Iterator newIt = *this;
    ++(*this);
    return newIt;
}

int main() {

    // Test 1
    DLinkedList<int> list;
    int size = 10;
    
    for(int idx=0; idx < size; idx++) {
        list.add(idx);
    }
    DLinkedList<int>::Iterator it = list.begin();
    
    for(; it != list.end(); it++) {
        cout << *it << " |"; // result: 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
    }

    /* test 2
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
    cout << list.toString(); // result: []
    */

    /* test 3
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++) {
        list.add(idx);
    }

    DLinkedList<int>::Iterator it = list.begin();
    for(; it != list.end(); it++)
    {
        it.remove();
    }
    cout << list.toString(); // result: []
    */
    return 0;
}