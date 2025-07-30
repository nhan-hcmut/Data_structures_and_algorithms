#include<iostream>
#include<sstream>
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
    SLinkedList();// helping methods
    ~SLinkedList();// helping methods
    void    add(T e); // helping methods
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(const T& item);
    string toString() const; // helping methods
    
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

// helping methods
template<class T>
SLinkedList<T>::SLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template<class T>
SLinkedList<T>::~SLinkedList() {this->clear();}

template <class T>
void SLinkedList<T>::add(T e) {
    /* Insert an element into the end of the list. */
    if (this->count == 0) this->head = this->tail = new Node(e, nullptr);
    else {
        this->tail->next = new Node(e, nullptr);
        this->tail = this->tail->next;
    }
    this->count++;
}

template<class T>
int SLinkedList<T>::size() {return this->count;}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    
    Node* temp = this->head;
    for (short i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

template<class T>
string SLinkedList<T>::toString() const {
    stringstream ss;
    ss << "[";
    Node* temp = this->head;
    if (temp) {
        ss << temp->data;
        temp = temp->next;
    }
    while (temp) {
        ss << ",";
        ss << temp->data;
        temp = temp->next;
    }
    ss << "]\n";
    string result;
    ss >> result;
    return result;
}

template<class T>
int SLinkedList<T>::indexOf(T item) {
    /* Return the first index whether item appears in list, otherwise return -1 */
    if (this->empty()) return -1;
    int index = 0;
    Node* temp = this->head;
    while (temp->data != item) {
        if (!temp->next) return -1;
        temp = temp->next;
        index++;
    }
    return index;
}

template<class T>
bool SLinkedList<T>::contains(T item) {
    /* Check if item appears in the list */
    return this->indexOf(item) != -1;
}
// End helping methods

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
    else if (index == this->count - 1) {
        Node* pre = this->head;
        while (pre->next != this->tail) pre = pre->next;
        value = this->tail->data;
        delete this->tail;
        this->tail = pre;
        this->tail->next = nullptr;
    }
    else {
        Node* pre = this->head;
        for (int i = 0; i < index - 1; i++) pre = pre->next;
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
    int idx = this->indexOf(item);
    if (idx == -1) return false;
    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else if (idx == 0) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    else if (idx == this->count - 1) {
        Node* pre = this->head;
        while (pre->next != this->tail) pre = pre->next;
        delete this->tail;
        this->tail = pre;
        this->tail->next = nullptr;
    }
    else {
        Node *cur = this->head, *pre = nullptr;
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
