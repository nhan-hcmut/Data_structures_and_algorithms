#include<iostream>
using namespace std;

class LLNode {
    public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (!head || !head->next) return head;
    LLNode* temp = head;
    int len = 1;
    while (temp->next) {
        len++;
        temp = temp->next;
    }
    temp->next = head;
    k %= len;
    k = len - k;
    while (k--) {
        temp = temp->next;
        head = head->next;
    }
    temp->next = nullptr;
    return head;
}

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

    return 0;
}
