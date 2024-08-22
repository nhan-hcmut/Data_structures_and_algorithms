#include<iostream>
#include<utility>
#include<queue>
#include<stack>
using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};

void longestPathSumRecur(BTNode* temp, int& sum, int& len) {
    if (!temp) {
        sum = len = 0;
        return;
    }
    int sumLeft = 0, lenLeft = 0, sumRight = 0, lenRight = 0;
    longestPathSumRecur(temp->left, sumLeft, lenLeft);
    longestPathSumRecur(temp->right, sumRight, lenRight);
    if (lenLeft > lenRight) {
        sum = sumLeft + temp->val;
        len = lenLeft + 1;
    }
    else if (lenLeft < lenRight) {
        sum = sumRight + temp->val;
        len = lenRight + 1;
    }
    else {
        sum = max(sumLeft, sumRight) + temp->val;
        len = lenLeft + 1;
    }
}

int longestPathSum(BTNode* root) {
    int sum = 0, len = 0;
    longestPathSumRecur(root, sum, len);
    return sum;
}

int main() {
    // test 1
    int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
    int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), value);
    cout << longestPathSum(root); // result: 18

    /* test 2
    int arr[] = {-1,0,1,0,1,4,5,3,7,3};
    int value[] = {6,12,23,20,20,20,3,9,13,15};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << longestPathSum(root); // result: 61
    */
    return 0;
}