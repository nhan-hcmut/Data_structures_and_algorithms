#include <iostream>
#include <sstream>
using namespace std;

class LinkedList {
    public:
        class Node; // forward declaration
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
                Node() {this->next = NULL;}
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
        void partition(int k); /* TODO */

        // Helping methods
        ~LinkedList() {
            while (this->head != NULL) {
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
                this->size--;
            }
            this->tail = NULL;
        }
        void add(int val) {
            Node* pNew = new Node(val);
            if (this->tail == NULL) this->head = this->tail = pNew;
            else { /* this->tail != NULL */
                this->tail->next = pNew;
                this->tail = pNew;
            }
            this->size++;
        }
        string toString() const {
            stringstream ss;
            ss << "[";
            Node* temp = NULL;
            if (this->head != NULL) {
                ss << head->value;
                temp = head->next;
            }
            while (temp != NULL) {
                ss << "," << temp->value;
                temp = temp->next;
            }
            ss << "]";
            string str;
            ss >> str;
            return str;
        }
};

/* TODO */
void LinkedList::partition(int k) {
    if (this->head == NULL || this->head->next == NULL) return;
    
    Node *group1_head = nullptr, *group1_tail = nullptr;
    Node *group2_head = nullptr, *group2_tail = nullptr;
    Node *group3_head = nullptr, *group3_tail = nullptr;
    Node* current = this->head;

    while (current != NULL) {
        if (current->value < k) {
            if (group1_head == NULL) group1_head = group1_tail = current;
            else {
                group1_tail->next = current;
                group1_tail = current;
            }
        }
        else if (current->value == k) {
            if (group2_head == NULL) group2_head = group2_tail = current;
            else {
                group2_tail->next = current;
                group2_tail = current;
            }
        }
        else { /* current->value > k */
            if (group3_head == NULL) group3_head = group3_tail = current;
            else { /* group3_head != NULL */
                group3_tail->next = current;
                group3_tail = current;
            }
        }
        current = current->next;
    }
    if (group1_head != NULL) {
        this->head = group1_head;
        this->tail = group1_tail;
    }
    if (group2_head != NULL) {
        if (group1_head != NULL) {
            group1_tail->next = group2_head;
            this->tail = group2_tail;
        }
        else { /* group1_head == NULL */
            this->head = group2_head;
            this->tail = group2_tail;
        }
    }
    if (group3_head != NULL) {
        this->tail = group3_tail;
        
        if (group2_head != NULL) group2_tail->next = group3_head;
        else if (group1_head != NULL) group1_tail->next = group3_head; /* group2_head == NULL */
        else this->head = group3_head; /* group2_head && group1_head == NULL */
    }
}
/* END TODO */

int main() {

    // Test 1
    LinkedList* l1 = new LinkedList();
    l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n"; // Result: [20,30,10,40,45,60,55]
    
    // Test 2
    LinkedList* l2 = new LinkedList();
    l2->add(10); l2->add(55); l2->add(45); l2->add(42); l2->add(50);
    l2->partition(45);
    cout << l2->toString() << "\n"; // Result: [10,42,45,55,50]

    return 0;
}
