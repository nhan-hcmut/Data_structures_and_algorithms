#include<iostream>
#include<sstream>
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
                Node() {this->next = nullptr;}
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = nullptr) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(nullptr), tail(nullptr), size(0) {};
	void partition(int k);

    string toString() const {
        stringstream ss;
        ss << "[";
        Node* temp = this->head;
        if (temp) {
            while (temp) {
                ss << "," << temp->value;
                temp = temp->next;
            }
        }
        ss << "]";
        string str;
        ss >> str;
        return str;
    }
};

void LinkedList::partition(int k) {
    if (!head || !head->next) return;
    Node* group1_head = nullptr;
    Node* group1_tail = nullptr;
    Node* group2_head = nullptr;
    Node* group2_tail = nullptr;
    Node* group3_head = nullptr;
    Node* group3_tail = nullptr;
    Node* current = head;
    while (current) {
        if (current->value < k) {
            if (!group1_head) {
                group1_head = current;
                group1_tail = current;
            }
            else {
                group1_tail->next = current;
                group1_tail = current;
            }
        }
        else if (current->value == k) {
            if (!group2_head) {
                group2_head = current;
                group2_tail = current;
            }
            else {
                group2_tail->next = current;
                group2_tail = current;
            }
        }
        else {
            if (!group3_head) {
                group3_head = current;
                group3_tail = current;
            }
            else {
                group3_tail->next = current;
                group3_tail = current;
            }
        }
        current = current->next;
    }
    if (group1_head) {
        head = group1_head;
        tail = group1_tail;
    }
    if (group2_head) {
        if (group1_head) {
            group1_tail->next = group2_head;
            tail = group2_tail;
        }
        else {
            head = group2_head;
            tail = group2_tail;
        }
    }
    if (group3_head) {
        tail = group3_tail;
        if (group2_head) group2_tail->next = group3_head;
        else if (group1_head) group1_tail->next = group3_head;
        else head = group3_head;
    }
}

int main() {

    // Test
    LinkedList* l1 = new LinkedList();
    l1->add(20); l1->add(30); l1->add(10); l1->add(60); l1->add(40); l1->add(45); l1->add(55);
    l1->partition(45);
    cout << l1->toString() << "\n"; // Result: [20,30,10,40,45,60,55]
    
    return 0;
}
