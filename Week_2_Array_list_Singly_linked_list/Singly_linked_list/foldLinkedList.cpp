#include <iostream>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;

    LLNode() : val(0), next(nullptr) {}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next) : val(val), next(next) {}; // Constructor with customized data

    // Helping methods
    static LLNode* createWithIterators(int* start, int* end) {
        if (start == end) return nullptr;
        LLNode* head = new LLNode(*start, nullptr);
        start++;
        LLNode* tail = head;
        while (start != end) {
            tail->next = new LLNode(*start, nullptr);
            tail = tail->next;
            start++;
        }
        return head;
    }
    static void printList(LLNode* head) {
        cout << "[";
        LLNode* temp = nullptr;
        if (head != nullptr) {
            cout << head->val;
            temp = head->next;
        }
        while (temp != nullptr) {
            cout << ", " << temp->val;
            temp = temp->next;
        }
        cout << "]";
    }
};

// Helping functions
LLNode* getTail(LLNode* ptr) {
    while (ptr->next != nullptr) ptr = ptr->next;
    return ptr;
}

void removeTail(LLNode* head, LLNode* tail) {
    LLNode* newTail = head;
    while (newTail->next != tail) newTail = newTail->next;
    delete tail;
    newTail->next = nullptr;
}

LLNode* reverseLinkedList(LLNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    LLNode *pre = nullptr, *cur = head, *forward = nullptr;
    while (cur != nullptr) {
        forward = cur->next;
        cur->next = pre;
        pre = cur;
        cur = forward;
    }
    return pre;
}
// End helping functions

/* TODO */
LLNode* foldLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if (head == nullptr || head->next == nullptr) return head;
    
    LLNode* temp = head;
    do {
        LLNode* tail = getTail(head);
        if (temp == tail) break;
        temp->val += tail->val;
        removeTail(head, tail);
        temp = temp->next;
    }
    while (temp != nullptr);
    return reverseLinkedList(head);
}
/* END TODO */

int main() {
    
    // Test 1
    int arr[] = {9, 5, 7, 5, 0};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // Result: [9, 5, 7, 5, 0]
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead); // Result: [7, 10, 9]
    
    /* Test 2
    int arr[] = {8, 4, 6, 8, 5, 3};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // Result: [8, 4, 6, 8, 5, 3]
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead); // Result: [14, 9, 11]
    */
    
    /* Test 3
    int arr[] = {};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // Result: []
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead); // Result: []
    */
    
    /* Test 4
    int arr[] = {7, 3, 1, 9, 4, 6, 3, 8, 5, 5};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // Result: [7, 3, 1, 9, 4, 6, 3, 8, 5, 5]
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead); // Result: [10, 12, 9, 8, 12]
    */
    
    /* Test 5
    int arr[] = {8, 6, 9, 7, 3, 7, 6, 0, 3, 2, 2, 4, 6, 3, 6, 4, 2, 8, 3, 4, 2, 9, 4, 9, 5, 8, 5, 6, 9, 1, 5, 5, 9, 3, 1, 4, 2, 0, 1, 5, 1, 2, 9, 5, 0, 5, 3, 5, 1, 0, 6, 7, 3, 0, 9, 4, 0, 6, 0, 1, 3, 2, 9, 6, 6, 4, 4, 1, 5, 9, 6, 1, 1, 7, 9, 7, 7, 5, 1, 8, 4, 1, 4, 3, 0, 7, 7, 7, 9, 2, 9, 4, 2, 1, 2, 5, 7, 6, 5, 3, 1, 7, 2, 4, 3};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // Result: [8, 6, 9, 7, 3, 7, 6, 0, 3, 2, 2, 4, 6, 3, 6, 4, 2, 8, 3, 4, 2, 9, 4, 9, 5, 8, 5, 6, 9, 1, 5, 5, 9, 3, 1, 4, 2, 0, 1, 5, 1, 2, 9, 5, 0, 5, 3, 5, 1, 0, 6, 7, 3, 0, 9, 4, 0, 6, 0, 1, 3, 2, 9, 6, 6, 4, 4, 1, 5, 9, 6, 1, 1, 7, 9, 7, 7, 5, 1, 8, 4, 1, 4, 3, 0, 7, 7, 7, 9, 2, 9, 4, 2, 1, 2, 5, 7, 6, 5, 3, 1, 7, 2, 4, 3]
    cout << "\n";
    LLNode* newhead = foldLinkedList(head);
    LLNode::printList(newhead); // Result: [3, 7, 15, 4, 1, 11, 3, 6, 3, 7, 18, 8, 7, 9, 5, 1, 7, 13, 7, 4, 10, 12, 14, 8, 16, 11, 6, 16, 9, 10, 8, 12, 2, 11, 10, 15, 11, 6, 15, 7, 8, 5, 4, 7, 10, 6, 11, 10, 4, 14, 11, 10, 11]
    */
    return 0;
}