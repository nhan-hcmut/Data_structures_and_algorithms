#include <iostream>
#include <sstream>
using namespace std;

class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList() : head(NULL), tail(NULL), size(0) {};
        void add(int); // Helping methods
        string toString() const; // Helping methods
        void replace(LinkedList* linked_list, int low, int high); /* TODO */
};

// Helping methods
void LinkedList::add(int value) {
    if (this->tail == NULL) {
        this->head = this->tail = new Node(value);
    }
    else {
        this->tail->next = new Node(value);
        this->tail = this->tail->next;
    }
    this->size++;
}

string LinkedList::toString() const {
    stringstream ss;
    ss << "[";
    Node* temp = this->head;
    if (temp != NULL) {
        ss << head->value;
        temp = temp->next;
    }
    while (temp != NULL) {
        ss << ",";
        ss << temp->value;
        temp = temp->next;
    }
    ss << "]";
    string str;
    ss >> str;
    return str;
}

/* TODO */
void LinkedList::replace(LinkedList* linked_list, int low, int high) {
    if (linked_list == NULL || linked_list->head == NULL) return;

    if (this->head == NULL) {
        this->head = linked_list->head;
        this->tail = linked_list->tail;
        this->size = linked_list->size;

        linked_list->head = linked_list->tail = NULL;
        linked_list->size = 0;

        return;
    }
    int index = 0;
    Node *list1prev = NULL, *list1curr = this->head, *list2temp = NULL;
    
    if (low < 1) {
        this->head = linked_list->head;
        list2temp = linked_list->head->next;
        this->head->next = list1curr->next;
        delete list1curr;
        list1prev = this->head;
        list1curr = this->head->next;
        linked_list->head = list2temp;
        linked_list->size--;
        index++;
    }
    while (index <= high && list1curr != NULL && linked_list->head != NULL) {
        if (index < low) {
            list1prev = list1curr;
            list1curr = list1curr->next;
        }
        else {
            list1prev->next = linked_list->head;
            list2temp = linked_list->head->next;
            linked_list->head->next = list1curr->next;
            delete list1curr;
            list1prev = list1prev->next;
            list1curr = list1prev->next;
            linked_list->head = list2temp;
            linked_list->size--;
        }
        index++;
    }
    if (linked_list->head == NULL) linked_list->tail = NULL;
}

int main() {

    // Test 1
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();

    l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
    l2->add(55); l2->add(45); l2->add(42);

    l1->replace(l2, -1, 2);
    cout << l1->toString() << "\n"; // result: [55,45,42,40,50]
    
    /* Test 2
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();

    l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
    l2->add(55); l2->add(45); l2->add(42);

    l1->replace(l2, 1, 3);
    cout << l1->toString() << "\n"; // result: [10,55,45,42,50]
    */
    
    /* Test 3
    LinkedList* l1 = new LinkedList();
    LinkedList* l2 = new LinkedList();

    l1->add(10); l1->add(20); l1->add(30); l1->add(40); l1->add(50);
    l2->add(55); l2->add(45); l2->add(42);

    l1->replace(l2, 2, 6);
    cout << l1->toString() << "\n"; // result: [10,20,55,45,42]
    */
    
    return 0;
}