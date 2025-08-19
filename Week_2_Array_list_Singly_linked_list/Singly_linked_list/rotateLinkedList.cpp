#include <iostream>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;

    LLNode() : val(0), next(nullptr) {}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next) : val(val), next(next) {}; // Constructor with customized data

    // Helping methods
    ~LLNode();
    static LLNode* createWithIterators(int*, int*);
    static void printList(LLNode*);
};

// Helping methods
LLNode::~LLNode() {
    while (this->next != nullptr) {
        LLNode *pre = this, *cur = this->next;
        
        while (cur != nullptr && cur->next != nullptr) {
            pre = cur;
            cur = cur->next;
        }
        delete cur;
        pre->next = nullptr;
    }
    delete this;
}

LLNode* LLNode::createWithIterators(int* start, int* end) {
    if (start == end) return nullptr;

    int* iterator = start;
    LLNode* head = new LLNode(*iterator, nullptr);
    LLNode* tail = head;

    iterator++;
    while (iterator != end) {
        tail->next = new LLNode(*iterator, nullptr);
        iterator++;
        tail = tail->next;
    }
    return head;
}

void LLNode::printList(LLNode* head) {
    cout << "[";
    LLNode* temp = head;
    if (temp != nullptr) {
        cout << temp->val;
        temp = temp->next;
    }
    while (temp != nullptr) {
        cout << ", " << temp->val;
        temp = temp->next;
    }
    cout << "]";
}
// End helping methods

/* TODO */
LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER9
    if (head == nullptr || head->next == nullptr || k == 0) return head;
    
    // Calculate length and find the tail
    LLNode* tail = head;
    int len = 1;

    while (tail->next != nullptr) {
        len++;
        tail = tail->next;
    }
    k %= len;
    if (k == 0) return head;
    
    // Find the new tail and new head
    LLNode* newTail = head;
    k = len - k;
    while (k > 1) {
        newTail = newTail->next;
        k--;
    }
    LLNode* newHead = newTail->next;

    // Rotate
    newTail->next = nullptr;
    tail->next = head;
    return newHead;
}
/* END TODO */

int main() {

    // test 1
    int arr[] = {2, 4, 6, 6, 3};
    int k = 3;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // [2, 4, 6, 6, 3]
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead); // [6, 6, 3, 2, 4]
    
    /* test 2
    int arr[] = {};
    int k = 2;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: []
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead); // result: []
    */

    /* test 3
    int arr[] = {0, 4, 2, 5, 1, 0, 6, 4, 8, 6};
    int k = 11;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: [0, 4, 2, 5, 1, 0, 6, 4, 8, 6]
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead); // result: [6, 0, 4, 2, 5, 1, 0, 6, 4, 8]
    */

    /* test 4
    int arr[] = {6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9};
    int k = 35;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: [6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9, 0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9]
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead); // result: [0, 2, 7, 0, 5, 5, 6, 8, 3, 1, 9, 3, 0, 1, 4, 6, 6, 9, 2, 2, 0, 6, 7, 4, 4, 6, 0, 7, 3, 5, 2, 9, 1, 0, 9, 6, 1, 3, 2, 6, 0, 0, 0, 3, 3, 9, 8, 5, 6, 0, 7, 7, 8, 5, 7, 7, 9, 6, 3, 3, 0, 0, 8, 0, 0, 4, 9, 7, 1, 7, 2, 7, 5, 4, 4, 7, 5, 9, 2, 4, 5, 7, 9, 7, 9, 7, 2, 0, 6, 7, 6, 5, 1, 9, 7, 1, 2, 7, 8, 7, 5, 4, 7, 6, 9]
    */

    /* test 5
    int arr[] = {9, 1, 7, 5, 8, 6, 2, 2, 2, 6, 0, 8, 1, 9, 6, 8, 4, 8, 4, 3, 7, 0, 7, 8, 9, 5, 3, 4, 7, 4, 3, 5, 2, 2, 7, 8, 9, 7, 1, 9, 9, 8, 3, 5, 7, 1, 6, 9, 1, 2, 0, 6, 8, 0, 4, 1, 6, 5, 8, 7, 6, 8, 0, 5, 7, 8, 8, 6, 7, 5, 8, 0, 7, 6, 4, 9, 5, 9, 6, 4, 1, 5, 6, 2, 2, 6, 7, 0, 3, 4, 2, 3, 9, 0, 9, 6, 3, 6, 7, 5, 5, 5, 9, 0, 6, 1, 1, 5, 0, 9, 1, 1, 1, 0, 4, 6, 3, 3, 3, 5, 8, 7, 4, 7, 1, 7, 1, 8, 4, 2, 0, 1, 9, 0, 7, 9, 2, 8, 9, 2, 5, 3, 5, 9, 3, 2, 7, 3, 5, 9, 5, 5, 3, 2, 3, 9, 4, 1, 6, 1, 8, 3, 1, 4, 5, 2, 5, 7, 7, 0, 9, 6, 6, 4, 8, 1, 1, 6, 0, 2, 6, 0, 7, 5, 5, 0, 5, 2, 6, 9, 9, 9, 9, 2, 3, 0, 6, 8, 8, 4, 5, 6, 2, 8, 5, 9, 8, 3, 6, 8, 8, 6, 2, 1, 2, 1, 4, 6, 2, 0, 9, 3, 9, 6, 4, 2, 3, 6, 2, 0, 9, 8, 7, 0, 6, 0, 7, 0, 5, 9, 4, 3, 7, 9, 7, 3, 5, 7, 0, 3, 1, 8, 9, 9, 4, 0, 8, 6, 4, 6, 7, 3, 8, 1, 2, 1, 5, 4, 9, 5, 9, 5, 8, 6, 6, 8, 9, 4, 4, 0, 6, 4, 5, 3, 0, 3, 9, 7, 1, 7, 2, 5, 0, 1, 9, 1, 2, 5, 6, 8, 7, 1, 6, 9, 6, 2, 8, 1, 2, 0, 4, 3, 4, 6, 7, 1, 0, 7, 0, 7, 9, 4, 0, 1, 2, 3, 5, 6, 3, 5, 6, 7, 5, 4, 2, 4, 8, 2, 5, 8, 8, 6, 6, 2, 6, 6, 8, 1, 2, 2, 8, 0, 8, 9, 0, 7, 9, 0, 1, 6, 6, 3, 6, 5, 1, 5, 9, 0, 3, 7, 3, 7, 2, 0, 0, 2, 7, 5, 2, 9, 5, 5, 8, 1, 7, 7, 9, 7, 1, 1, 6, 4, 3, 8, 0, 7, 9, 1, 0, 9, 5, 2, 7, 2, 1, 5, 3, 9, 7, 6, 9, 1, 3, 5, 5, 0, 6, 9, 4, 7, 1, 7, 2, 0, 4, 5, 8, 1, 6, 1, 0, 7, 2, 2, 6, 7, 4, 4, 9, 5, 4, 5, 2, 0, 8, 0, 5, 5, 1, 8, 9, 4, 5, 6, 1, 2, 0, 7, 0, 2, 1, 6, 8, 8, 7, 8, 7, 0, 1, 8, 5, 6, 5, 9, 2, 2, 9, 3, 6, 0, 1, 7, 9, 8, 1, 1, 5, 4, 5, 7, 5, 0, 2, 0, 4, 4, 8, 0, 7, 3};
    int k = 196;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead); // result: [6, 2, 8, 1, 2, 0, 4, 3, 4, 6, 7, 1, 0, 7, 0, 7, 9, 4, 0, 1, 2, 3, 5, 6, 3, 5, 6, 7, 5, 4, 2, 4, 8, 2, 5, 8, 8, 6, 6, 2, 6, 6, 8, 1, 2, 2, 8, 0, 8, 9, 0, 7, 9, 0, 1, 6, 6, 3, 6, 5, 1, 5, 9, 0, 3, 7, 3, 7, 2, 0, 0, 2, 7, 5, 2, 9, 5, 5, 8, 1, 7, 7, 9, 7, 1, 1, 6, 4, 3, 8, 0, 7, 9, 1, 0, 9, 5, 2, 7, 2, 1, 5, 3, 9, 7, 6, 9, 1, 3, 5, 5, 0, 6, 9, 4, 7, 1, 7, 2, 0, 4, 5, 8, 1, 6, 1, 0, 7, 2, 2, 6, 7, 4, 4, 9, 5, 4, 5, 2, 0, 8, 0, 5, 5, 1, 8, 9, 4, 5, 6, 1, 2, 0, 7, 0, 2, 1, 6, 8, 8, 7, 8, 7, 0, 1, 8, 5, 6, 5, 9, 2, 2, 9, 3, 6, 0, 1, 7, 9, 8, 1, 1, 5, 4, 5, 7, 5, 0, 2, 0, 4, 4, 8, 0, 7, 3, 9, 1, 7, 5, 8, 6, 2, 2, 2, 6, 0, 8, 1, 9, 6, 8, 4, 8, 4, 3, 7, 0, 7, 8, 9, 5, 3, 4, 7, 4, 3, 5, 2, 2, 7, 8, 9, 7, 1, 9, 9, 8, 3, 5, 7, 1, 6, 9, 1, 2, 0, 6, 8, 0, 4, 1, 6, 5, 8, 7, 6, 8, 0, 5, 7, 8, 8, 6, 7, 5, 8, 0, 7, 6, 4, 9, 5, 9, 6, 4, 1, 5, 6, 2, 2, 6, 7, 0, 3, 4, 2, 3, 9, 0, 9, 6, 3, 6, 7, 5, 5, 5, 9, 0, 6, 1, 1, 5, 0, 9, 1, 1, 1, 0, 4, 6, 3, 3, 3, 5, 8, 7, 4, 7, 1, 7, 1, 8, 4, 2, 0, 1, 9, 0, 7, 9, 2, 8, 9, 2, 5, 3, 5, 9, 3, 2, 7, 3, 5, 9, 5, 5, 3, 2, 3, 9, 4, 1, 6, 1, 8, 3, 1, 4, 5, 2, 5, 7, 7, 0, 9, 6, 6, 4, 8, 1, 1, 6, 0, 2, 6, 0, 7, 5, 5, 0, 5, 2, 6, 9, 9, 9, 9, 2, 3, 0, 6, 8, 8, 4, 5, 6, 2, 8, 5, 9, 8, 3, 6, 8, 8, 6, 2, 1, 2, 1, 4, 6, 2, 0, 9, 3, 9, 6, 4, 2, 3, 6, 2, 0, 9, 8, 7, 0, 6, 0, 7, 0, 5, 9, 4, 3, 7, 9, 7, 3, 5, 7, 0, 3, 1, 8, 9, 9, 4, 0, 8, 6, 4, 6, 7, 3, 8, 1, 2, 1, 5, 4, 9, 5, 9, 5, 8, 6, 6, 8, 9, 4, 4, 0, 6, 4, 5, 3, 0, 3, 9, 7, 1, 7, 2, 5, 0, 1, 9, 1, 2, 5, 6, 8, 7, 1, 6, 9]
    */

    return 0;
}
