#include<iostream>
using namespace std;

class LLNode {
    public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
};

LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    if (!head) return nullptr;
    LLNode *temp = head->next, *newHead = new LLNode(head->val, nullptr);
    while (temp) {
        LLNode* pNew = new LLNode(temp->val, newHead);
        newHead = pNew;
        temp = temp->next;
    }
    return newHead;
}

int main() {

    // test 1
    int arr[] = {13, 88, 60, 7, 192};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead);
    newhead->clear();
    /* result
    [13, 88, 60, 7, 192]
    [192, 7, 60, 88, 13]
    */

    /* test 2
    int arr[] = {};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: []
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead); // result: []
    newhead->clear();
    */

    /* test 3
    int arr[] = {31, 22, 46, 152, 14, 87, 196, 97, 5, 93};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: [31, 22, 46, 152, 14, 87, 196, 97, 5, 93]
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead); // result: [93, 5, 97, 196, 87, 14, 152, 46, 22, 31]
    newhead->clear();
    */

    /* test 4
    int arr[] = {115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: [115, 59, 178, 39, 109, 18, 154, 106, 94, 174, 51, 33, 132, 195, 161, 37, 61, 107, 120, 190]
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead); // result: [190, 120, 107, 61, 37, 161, 195, 132, 33, 51, 174, 94, 106, 154, 18, 109, 39, 178, 59, 115]
    newhead->clear();
    */

    /* test 5
    int arr[] = {104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head); // result: [104, 50, 154, 40, 15, 171, 56, 114, 67, 90, 46, 179, 152, 177, 139, 45, 18, 55, 38, 158, 8, 157, 143, 37, 16, 83, 173, 82, 156, 51, 124, 25, 68, 51, 194, 105, 44, 17, 97, 0, 150, 66, 71, 81, 11, 180, 148, 160, 127, 93, 108, 13, 122, 172, 39, 88, 62, 38, 61, 156, 45, 131, 69, 191, 123, 42, 103, 56, 69, 138, 185, 162, 192, 147, 71, 80, 12, 36, 191, 121, 194, 86, 92, 183, 164, 97, 185, 130, 29, 174, 112, 194, 185, 132, 27, 197, 158, 151, 51, 174]

    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead); // result: [174, 51, 151, 158, 197, 27, 132, 185, 194, 112, 174, 29, 130, 185, 97, 164, 183, 92, 86, 194, 121, 191, 36, 12, 80, 71, 147, 192, 162, 185, 138, 69, 56, 103, 42, 123, 191, 69, 131, 45, 156, 61, 38, 62, 88, 39, 172, 122, 13, 108, 93, 127, 160, 148, 180, 11, 81, 71, 66, 150, 0, 97, 17, 44, 105, 194, 51, 68, 25, 124, 51, 156, 82, 173, 83, 16, 37, 143, 157, 8, 158, 38, 55, 18, 45, 139, 177, 152, 179, 46, 90, 67, 114, 56, 171, 15, 40, 154, 50, 104]
    newhead->clear();
    */

    return 0;
}
