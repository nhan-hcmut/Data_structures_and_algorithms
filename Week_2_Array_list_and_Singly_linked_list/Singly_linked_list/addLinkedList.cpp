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
    static LLNode* createWithIterators(int*, int*);
    static void printList(LLNode*);
    void clear();
};

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
    LLNode *sum = new LLNode(0, nullptr), *cur = sum;
    vector<int> result;
    int plus = 0, remainder = 0;
    while (l0 && l1) {
        plus = l0->val + l1->val + remainder;
        result.push_back(plus % 10);
        if (plus >= 10) remainder = 1;
        else remainder = 0;
        l0 = l0->next;
        l1 = l1->next;
    }
    while (l0) {
        plus = l0->val + remainder;
        result.push_back(plus % 10);
        if (plus >= 10) remainder = 1;
        else remainder = 0;
        l0 = l0->next;
    }
    while (l1) {
        plus = l1->val + remainder;
        result.push_back(plus % 10);
        if (plus >= 10) remainder = 1;
        else remainder = 0;
        l1 = l1->next;
    }
    if (remainder) result.push_back(1);
    for (unsigned long long i = 0; i < (unsigned long long)result.size(); i++) {
        cur->next = new LLNode(result.at(i), nullptr);
        cur = cur->next;
    }
    cur = sum;
    sum = sum->next;
    delete cur;
    return sum;
}

LLNode* LLNode::createWithIterators(int* start, int* end) {
    LLNode *head = nullptr, *temp = nullptr;
    return head;
}
void LLNode::printList(LLNode* head) {}
void LLNode::clear() {}

int main() {
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead); //result: [2, 4, 1]
    head1->clear();
    head2->clear();
    newhead->clear();
    return 0;
}
