#include<iostream>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) {}
};

// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first test case example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) { // should complete this function first
    ListNode* newHead;
    
    if (a->val < b->val) {
        newHead = a;
        a = a->next;
    }
    else {
        newHead = b;
        b = b->next;
    }
    newHead->next = nullptr;

    ListNode* temp = newHead;
    while (a && b) {
        if (a->val < b->val) {
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        else {
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
        temp->next = nullptr;
    }
    if (a) temp->next = a;
    if (b) temp->next = b;
    return newHead;
}

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *tortoise = head, *hare = head->next;

    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    ListNode* middle = tortoise->next;
    tortoise->next = nullptr;

    ListNode* first = mergeSortList(head);
    ListNode* second = mergeSortList(middle);

    return mergeLists(first, second);
}

// helping functions
ListNode* init(int arr[], int size, unordered_map<ListNode*, int>& nodeAddr) {
    if (size == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    nodeAddr[head] = arr[0];
    
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
        nodeAddr[temp] = arr[i];
    }
    return head;
}

void printList(ListNode* head, unordered_map<ListNode*, int>& nodeAddr) {
    int count = 0;
    while (head) {
        cout << head->val;
        count++;
        head = head->next;
        if (head) cout << " ";
        if (count > 1000) throw "ERROR: Too many nodes!";
    }
    cout << endl;
}

void freeMem(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
// End helping functions

int main() {

    // test 1
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};

    unordered_map<ListNode*, int> nodeAddr;

    ListNode* a = init(arr1, sizeof(arr1) / 4, nodeAddr);
    ListNode* b = init(arr2, sizeof(arr2) / 4, nodeAddr);
    ListNode* merged = mergeLists(a, b);
    
    try {
        printList(merged, nodeAddr); // result: 1 2 3 4 5 6 7 8 9
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(merged);

    /* test 2
    int size;
    cin >> size; // input: 9
    int* array = new int[size];
    for(int i = 0; i < size; i++) cin >> array[i]; // input: 9 3 8 2 1 6 7 4 5
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* head = init(array, size, nodeAddr);
    ListNode* sorted = mergeSortList(head);
    try {
        printList(sorted, nodeAddr); // result: 1 2 3 4 5 6 7 8 9
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(sorted);
    delete[] array;
    */
    
    /* test 3
    int size;
    cin >> size; // input: 20
    int* array = new int[size];
    for(int i = 0; i < size; i++) cin >> array[i]; // input: 360924 716925 459489 389399 824308 777676 806187 986180 936828 433111 449243 141749 250782 270849 955511 281354 960612 456616 752793 292654
    
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* head = init(array, size, nodeAddr);
    ListNode* sorted = mergeSortList(head);
    try {
        printList(sorted, nodeAddr); // result: 141749 250782 270849 281354 292654 360924 389399 433111 449243 456616 459489 716925 752793 777676 806187 824308 936828 955511 960612 986180
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(sorted);
    delete[] array;
    */

    return 0;
}