#include <iostream>
#include <stack>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;

    LLNode() : val(0), next(nullptr) {}; // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next) : val(val), next(next) {}; // Constructor with customized data

    // Helping methods
    static LLNode* createWithIterators(int* start, int* end) {
        if (start == nullptr) return nullptr;
        LLNode* head = new LLNode(*start, nullptr);
        LLNode* current = head;
        start++;
        while (start != end) {
            current->next = new LLNode(*start, nullptr);
            current = current->next;
            start++;
        }
        return head;
    }
    void printList() const {
        cout << "[" << this->val;
        LLNode* temp = this->next;
        while (temp != nullptr) {
            cout << "," << temp->val;
            temp = temp->next;
        }
        cout << "]" << endl;
    }
    void clear() {
        while (this->next != nullptr) {
            LLNode *prev = this, *curr = this->next;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            delete curr;
        }
        delete this;
    }
};

/* TODO */
LLNode* replaceFirstGreater(LLNode* head) {
    // STUDENT ANSWER
    LLNode* curr = head;

    while (curr->next != nullptr) {
        LLNode* temp = curr->next;

        while (temp != nullptr && temp->val <= curr->val) {
            temp = temp->next;
        }
        if (temp == nullptr) curr->val = 0;
        else curr->val = temp->val;

        curr = curr->next;
    }
    curr->val = 0;
    return head;
}

int main() {

    // Test 1
    int arr1[] = {6};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    head1->printList(); // result: [6]

    head1 = replaceFirstGreater(head1);
    head1->printList(); // result: [0]

    head1->clear();
    cout << endl;

    // Test 2
    int arr2[] = {1, 3};
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    head2->printList(); // result: [1,3]

    head2 = replaceFirstGreater(head2);
    head2->printList(); // result: [3,0]

    head2->clear();
    cout << endl;

    // Test 3
    int arr3[] = {3, 1, 4};
    LLNode* head3 = LLNode::createWithIterators(arr3, arr3 + sizeof(arr3) / sizeof(int));
    head3->printList(); // result: [3,1,4]

    head3 = replaceFirstGreater(head3);
    head3->printList(); // result: [4,4,0]

    head3->clear();
    cout << endl;

    // Test 4
    int arr4[] = {5, 7, 1, 4};
    LLNode* head4 = LLNode::createWithIterators(arr4, arr4 + sizeof(arr4) / sizeof(int));
    head4->printList(); // result: [5,7,1,4]

    head4 = replaceFirstGreater(head4);
    head4->printList(); // result: [7,0,4,0]

    head4->clear();
    cout << endl;
    
    // Test 5
    int arr5[] = {5, 8, 8, 2, 3};
    LLNode* head5 = LLNode::createWithIterators(arr5, arr5 + sizeof(arr5) / sizeof(int));
    head5->printList(); // result: [5,8,8,2,3]

    head5 = replaceFirstGreater(head5);
    head5->printList(); // result: [8,0,0,3,0]

    head5->clear();
    cout << endl;
    
    // Test 6
    int arr6[] = {5, 2, 6, 3, 1, 5};
    LLNode* head6 = LLNode::createWithIterators(arr6, arr6 + sizeof(arr6) / sizeof(int));
    head6->printList(); // result: [5,2,6,3,1,5]

    head6 = replaceFirstGreater(head6);
    head6->printList(); // result: [6,6,0,5,5,0]

    head6->clear();
    cout << endl;
    
    // Test 7
    int arr7[] = {1, 2, 3, 4, 5, 6, 7};
    LLNode* head7 = LLNode::createWithIterators(arr7, arr7 + sizeof(arr7) / sizeof(int));
    head7->printList(); // result: [1,2,3,4,5,6,7]

    head7 = replaceFirstGreater(head7);
    head7->printList(); // result: [2,3,4,5,6,7,0]

    head7->clear();
    
    return 0;
}
