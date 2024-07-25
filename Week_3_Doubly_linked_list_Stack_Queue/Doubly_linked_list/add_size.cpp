#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template<class T>
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

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* pNew = new Node(e);
    if (this->count == 0) {
        this->head = this->tail = pNew;
    }
    else {
        pNew->previous = this->tail;
        this->tail->next = pNew;
        this->tail = pNew;
    }
    this->count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if (index < 0 || this->count < index) throw std::out_of_range("Index is out of range!\n");
    
    Node* pNew = new Node(e);
    if (this->count == 0) {
        this->head = this->tail = pNew;
    }
    else if (index == 0) {
        pNew->next = this->head;
        this->head->previous = pNew;
        this->head = pNew;
    }
    else if (index == this->count) {
        pNew->previous = this->tail;
        this->tail->next = pNew;
        this->tail = pNew;
    }
    else if (index < this->count / 2) {
        Node* cur = this->head;
        for (int i = 0; i < index; i++) cur = cur->next;
        Node* pre = cur->previous;
        
        pNew->previous = pre;
        pNew->next = cur;
        
        pre->next = pNew;
        cur->previous = pNew;
    }
    else {
        Node* cur = this->tail;
        for (int i = this->count - 1; i > index; i--) cur = cur->previous;
        Node* pre = cur->previous;
        
        pNew->previous = pre;
        pNew->next = cur;
        
        pre->next = pNew;
        cur->previous = pNew;
    }
    this->count++;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

int main() {

    // test 1
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
    cout << list.toString(); // result: [0,1,2,3,4,5,6,7,8,9]

    /* test 2
    DLinkedList<int> list;
    int size = 10;
    for(int idx=0; idx < size; idx++){
    list.add(0, idx);
    }
    cout << list.toString(); // result: [9,8,7,6,5,4,3,2,1,0]
    */
    return 0;
}
