#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T> class DLinkedList {
    public:
    class Node; // Forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    DLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~DLinkedList() {
        delete this->head;
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
    }
    void    add(const T &e);
    void    add(int index, const T &e);
    
    int     size() {return this->count;}

    bool    empty() {return this->count == 0;}
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
};

template <class T> T DLinkedList<T>::removeAt(int index) {
    /* Remove element at index and return removed value */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    
    T value;
    Node* cur;
    if (this->count == 1) {
        value = this->head->data;
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else if (index == 0) {
        cur = this->head;
        value = this->head->data;
        this->head = this->head->next;
        delete cur;
    }
    else if (index == this->count-1) {
        cur = this->tail;
        value = this->tail->data;
        this->tail = this->tail->previous;
        delete cur;
    }
    else if (index < this->count / 2) {
        Node* pre = this->head;
        for (int j = 0; j < index - 1; j++) pre = pre->next;
        cur = pre->next;
        value = cur->data;
        pre->next = cur->next;
        cur->next->previous = pre;
        delete cur;
    }
    else {
        cur = this->tail;
        for (int j = this->count - 1; j > index; j--) cur = cur->previous;
        Node* pre = cur->previous;
        value = cur->data;
        pre->next = cur->next;
        cur->next->previous = pre;
        delete cur;
    }
    this->count--;
    return value;
}

template <class T> bool DLinkedList<T>::removeItem(const T& item) {
    /* Remove the first appearance of item in list and return true, otherwise return false */
    if (this->indexOf(item) == -1) return false;

    this->removeAt(this->indexOf(item));
    return true;
}

template <class T> void DLinkedList<T>::clear() {
    /* Remove all elements in list */
    while (this->count) this->removeAt(0);
}

int main() {
    DLinkedList<int> list;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};
    for (int idx = 0; idx < size; idx++) list.add(value[idx]);
    list.removeAt(0);
    cout << list.toString(); // result: [5,6,3,67,332,43,1,0,9]
    return 0;
}