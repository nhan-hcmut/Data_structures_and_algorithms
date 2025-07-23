#include<iostream>
#include<string>
#include<cstring>
#include<climits>
#include<utility>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<functional>
#include<algorithm>
using namespace std;

class LLNode {
    public:
    int val;
    LLNode* next;

    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next) {
        this->val = val;
        this->next = next;
    }
    // Helping methods
    static LLNode* createWithIterators(int*, int*);
    static void printList(LLNode*);
    void clear();
    // End helping methods
};

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    LLNode* newHead = new LLNode(); // A dummy node which needs to be deleted at the end
    LLNode* current = newHead;
    int sum = 0, carry = 0;
    
    while (l0 != nullptr && l1 != nullptr) {
        sum = l0->val + l1->val + carry;
        carry = sum / 10;
        sum %= 10;
        current->next = new LLNode(sum, nullptr);
        current = current->next;
        l0 = l0->next;
        l1 = l1->next;
    }
    while (l0 != nullptr) {
        sum = l0->val + carry;
        carry = sum / 10;
        sum %= 10;
        current->next = new LLNode(sum, nullptr);
        current = current->next;
        l0 = l0->next;
    }
    while (l1 != nullptr) {
        sum = l1->val + carry;
        carry = sum / 10;
        sum %= 10;
        current->next = new LLNode(sum, nullptr);
        current = current->next;
        l1 = l1->next;
    }
    if (carry == 1) {
        current->next = new LLNode(1, nullptr);
    }
    current = newHead;
    newHead = newHead->next;
    delete current;
    return newHead;
}

// Helping methods
LLNode* LLNode::createWithIterators(int* start, int* end) {
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

void LLNode::printList(LLNode* head) {
    cout << "\n[";
    
    if (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    while (head != nullptr) {
        cout << ", " << head->val;
        head = head->next;
    }
    cout << "]\n";
}

void LLNode::clear() {
    LLNode* current = this;
    LLNode* following = nullptr;
    
    while (current != nullptr) {
        following = current->next;
        delete current;
        current = following;
    }
}
// End helping methods

int main() {
    // test 1
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead); //result: [2, 4, 1]
    
    head1->clear();
    head2->clear();
    newhead->clear();
    
    /* test 2
    int arr1[] = {2, 3};
    int arr2[] = {1, 8};
    
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead); // Result: [3, 1, 1]
    
    head1->clear();
    head2->clear();
    newhead->clear();
    */
    return 0;
}
