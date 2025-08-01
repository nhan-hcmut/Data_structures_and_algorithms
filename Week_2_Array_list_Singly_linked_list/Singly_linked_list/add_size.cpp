#include<iostream>
#include<sstream>
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
    SLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~SLinkedList() {
        Node* temp = nullptr;
        while(this->head) {
            temp = this->head;
            this->head = this->head->next;
            delete temp;
            this->count--;
        }
        this->tail = nullptr;
    }
    /* TO DO */
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    /* END TO DO */
    string toString() const; // helping method

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
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

/* TO DO */
template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if (this->count == 0) this->head = this->tail = new Node(e, nullptr);
    else {
        this->tail->next = new Node(e, nullptr);
        this->tail = this->tail->next;
    }
    this->count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
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

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */
    return this->count;
}
/* END TO DO */

// helping method
template<class T>
string SLinkedList<T>::toString() const {
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
        ss << "]";
        string result;
        ss >> result;
        return result;
}
// End helping method

int main() {

    // Test 1
    SLinkedList<int> list;
    int size = 10;

    for (int index = 0; index < size; index++) {
        list.add(index);
    }

    cout << list.toString() << endl; // Result: [0,1,2,3,4,5,6,7,8,9]
    
    /* Test 2
    SLinkedList<int> list;
    int size = 10;

    for (int index = 0; index < size; index++) {
        list.add(0, index);
    }

    cout << list.toString() << endl; // Result: [9,8,7,6,5,4,3,2,1,0]
    */
    
    return 0;
}
