#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class SLinkedList {
    public:
    class Node; // Forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
    
    public:
    class Node {
        private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
        
        public:
        Node() {this->next = nullptr;}
        Node(Node* next) {this->next = next;}
        Node(T data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
};

template<class T>
T SLinkedList<T>::removeAt(int index) {
    /* Remove element at index and return removed value */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    T value;
    if (this->count == 1) {
        value = this->head->data;
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else if (index == 0) {
        value = this->head->data;
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    else if (index == this->count-1) {
        Node* pre = this->head;
        while (pre->next != this->tail) pre = pre->next;
        value = this->tail->data;
        delete this->tail;
        this->tail = pre;
    }
    else {
        Node* pre = this->head;
        for (int i = 0; i < index-1; i++) pre = pre->next;
        Node* cur = pre->next;
        value = cur->data;
        pre->next = cur->next;
        delete cur;
    }
    this->count--;
    return value;
}

template<class T>
bool SLinkedList<T>::removeItem(const T& item) {
    /* Remove the first appearance of item in list and return true, otherwise return false */
    if (!this->contains(item)) return false;
    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else if (this->indexOf(item) == 0) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    else if (this->indexOf(item) == this->count-1) {
        Node* pre = this->head;
        while (pre->next != this->tail) pre = pre->next;
        delete this->tail;
        this->tail = pre;
    }
    else {
        Node *cur = this->head, *pre = nullptr;
        int idx = this->indexOf(item);
        for (int i = 0; i < idx; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
    this->count--;
    return true;
}

template<class T>
void SLinkedList<T>::clear() {
    /* Remove all elements in list */
    while (this->count) this->removeAt(0);
}

int main() {

    // test 1
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(0) == list.removeAt(0));

    cout << list.toString(); // result: [1,2,3,4,5,6,7,8,9]

    /* test 2
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));

    cout << list.toString(); // result: [0,1,2,3,4,5,6,7,8]
    */
    /* test 3
    SLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.removeItem(9));

    cout << list.toString(); // result: [0,1,2,3,4,5,6,7,8]
    */
    
    return 0;
}
