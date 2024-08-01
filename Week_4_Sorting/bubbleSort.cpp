#include <iostream>
#include <sstream>
using namespace std;

template <class T> class SLinkedList {
    public:
    class Node; // Forward declaration
    
    protected:
    Node* head;
    Node* tail;
    int count;
    
    public:
    SLinkedList() {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList() {};
    void add(T e) { // add a new node to the end
        Node *pNew = new Node(e);

        if (this->count == 0) {
            this->head = this->tail = pNew;
        }
        else {
            this->tail->next = pNew;
            this->tail = pNew;
        }
        this->count++;
    }
    int size() {
        return this->count;
    }
    void printList() {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail) {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
    public:
    class Node {
        private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
        
        public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort() {
    
    for (int upperBound = this->count - 1; upperBound > 0; upperBound--) {
        
        Node *firstNode = this->head, *secondNode = this->head->next;
        bool isSorted = true;
        
        for (int walker = 0; walker < upperBound; walker++) {
            
            if (firstNode->data > secondNode->data) {
                T temp = firstNode->data;
                firstNode->data = secondNode->data;
                secondNode->data = temp;
                isSorted = false;
            }
            firstNode = secondNode;
            secondNode = secondNode->next;
        }
        if (!isSorted) this->printList();
    }
}

int main() {
    
    int arr[] = {9, 2, 8, 4, 1};
    SLinkedList<int> list;
    
    for(int i = 0; i < int(sizeof(arr)) / 4; i++)
        list.add(arr[i]);
    
    list.bubbleSort();
    
    /*result:
    [2,8,4,1,9]
    [2,4,1,8,9]
    [2,1,4,8,9]
    [1,2,4,8,9]
    */
    
    return 0;
}