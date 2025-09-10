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
    SLinkedList(): head(NULL), tail(NULL), count(0) {}
    ~SLinkedList() {}
    void    add(const T& e) {
        /* Insert an element into the end of the list. */
        if (this->count == 0) this->head = this->tail = new Node(e, nullptr);
        else {
            this->tail->next = new Node(e, nullptr);
            this->tail = this->tail->next;
        }
        this->count++;
    }
    void    add(int index, const T& e) {
        /* Insert an element into the list at given index. */
        if (index < 0 || this->count < index) throw std::out_of_range("Index is out of range!\n");
        
        if (this->count == 0) this->head = this->tail = new Node(e, nullptr);
        else if (index == 0) {
            Node* pNew = new Node(e, this->head);
            this->head = pNew;
        }
        else if (index == this->count) {
            this->tail->next = new Node(e, nullptr);
            this->tail = this->tail->next;
        }
        else {
            Node *pNew = new Node(e, nullptr), *pre = this->head;
            for (short i = 0; i < index-1; i++) pre = pre->next;
            pNew->next = pre->next;
            pre->next = pNew;
        }
        this->count++;
    }
    int     size() const {
        /* Return the length (size) of list */
        return this->count;
    }
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
    string toString() const {
        stringstream ss;
        ss << "[";
        Node* temp = nullptr;
        if (this->head) {
            ss << this->head->data;
            temp = this->head->next;
        }
        while (temp) {
            ss << ",";
            ss << temp->data;
            temp = temp->next;
        }
        ss << "]\n";
        string str;
        ss >> str;
        return str;
    }
    
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
        
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    
    Node* temp = this->head;
    for (short i = 0; i < index; i++) temp = temp->next;
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    Node* temp = this->head;
    for (short i = 0; i < index; i++) temp = temp->next;
    temp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
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
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return this->indexOf(item) != -1;
}

int main() {

    // Test 1
    SLinkedList<int> list;
    int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
    int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
    int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6}; 

    for (int idx = 0; idx < 8; idx++) {
        list.add(index[idx], values[idx]);
    }
    assert( list.size() == 8 );
    
    for (int idx = 0; idx < 8; idx++) {
        assert( list.get(idx) == expvalues[idx] );
    }
    cout << list.toString() << endl; // Result: [8,15,2,4,7,10,40,6]

    /* Test 2
    SLinkedList<int> list;
    assert( list.empty() == true );
    cout << list.toString() << endl; // Result: []
    */
    
    return 0;
}
