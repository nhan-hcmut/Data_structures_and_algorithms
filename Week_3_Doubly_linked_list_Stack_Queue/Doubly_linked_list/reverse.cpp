#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    if (a == b) return head;

    ListNode* tempA = head;
    ListNode* tempB = head;
    int range = b-a+1;
    for (int i = 0; i < a - 1; i++) tempA = tempA->right;    
    for (int i = 0; i < b - 1; i++) tempB = tempB->right;
    
    for (int i = 0; i < range / 2; i++) {
        ListNode* tempAl = tempA->left;
        ListNode* tempAr = tempA->right;
        ListNode* tempBl = tempB->left;
        ListNode* tempBr = tempB->right;
        
        if (tempAl) tempAl->right = tempB;
        if (tempBr) tempBr->left = tempA;
        tempB->left = tempAl;
        tempA->right = tempBr;
        
        if (tempAr == tempB) {
            tempA->left = tempB;
            tempB->right = tempA;
        }
        else if (tempAr == tempBl) {
            tempAr->left = tempB;
            tempAr->right = tempA;
            tempB->right = tempAr;
            tempA->left = tempAr;
        }
        else {
            tempAr->left = tempB;
            tempB->right = tempAr;
            tempBl->right = tempA;
            tempA->left = tempBl;
        }
        if (!tempAl) head = tempB;
        
        ListNode* ptr = tempA;
        tempA = tempB;
        tempB = ptr;
        tempB = tempB->left;
        tempA = tempA->right;
    }
    return head;
}

int main() {

    // Test 1
    int size;
    cin >> size; // 5
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i]; // 3 4 5 6 7
    }
    int a, b;
    cin >> a >> b; // 2 4
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue); // result: 3 6 5 4 7
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;

    /* Test 2
    int size;
    cin >> size; // 3
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i]; // 8 9 10
    }
    int a, b;
    cin >> a >> b; // 1 3
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue); // 10 9 8
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
    */
    
    /* test 3
    int size;
    cin >> size; // 20
    int* list = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> list[i]; // 2158 2398 300 2268 3655 765 3792 4038 1761 4762 1292 3200 3882 962 488 1938 3757 3122 302 640
    }
    int a, b;
    cin >> a >> b; // 9 12
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue); // 2158 2398 300 2268 3655 765 3792 4038 3200 1292 4762 1761 3882 962 488 1938 3757 3122 302 640
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(head);
    delete[] list;
    */
    return 0;
}