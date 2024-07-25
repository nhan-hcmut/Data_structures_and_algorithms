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

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    Node* temp;
    if (index <= (this->count-1) / 2) {
        temp = this->head;
        for (int i = 0; i < index; i++) temp = temp->next;
    }
    else {
        temp = this->tail;
        for (int i = this->count-1; i > index; i--) temp = temp->previous;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!\n");
    Node* temp;
    if (index <= (this->count-1)/2) {
        temp = this->head;
        for (int i = 0; i < index; i++) temp = temp->next;
    }
    else {
        temp = this->tail;
        for (int i = this->count - 1; i > index; i--) temp = temp->previous;
    }
    temp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index whether item appears in list, otherwise return -1 */
    if (this->empty()) {
        return -1;
    }
    Node* temp = this->head;
    for (int idx = 0; idx < this->count; idx++) {
        if (temp->data == item) return idx;
        temp = temp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return this->indexOf(item) != -1;
}

int main() {

    // test 1
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++) {
        list.add(idx);
    }
    for (int idx = 0; idx < size; idx++) {
        cout << list.get(idx) << " |"; // result: 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
    }

    /* test 2
    DLinkedList<int> list;
    int size = 10;
    int value[] = {2,5,6,3,67,332,43,1,0,9};
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
    for(int idx=0; idx < size; idx++){
        list.set(idx, value[idx]);
    }
    cout << list.toString(); // result: [2,5,6,3,67,332,43,1,0,9]
    */
    
    return 0;
}