#include<iostream>
#include<queue>
#include<stack>
#include<utility>

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

// helping function
void sumDigitPathRecur(BTNode* temp, int currentSum, int& totalSum) {
    if (!temp) return;
    
    currentSum = (currentSum * 10 + temp->val) % 27022001;
    
    if (!temp->left && !temp->right) {
        totalSum = (totalSum + currentSum) % 27022001;
        return;
    }
    sumDigitPathRecur(temp->left, currentSum, totalSum);
    sumDigitPathRecur(temp->right, currentSum, totalSum);
}
// End helping function

int sumDigitPath(BTNode* root) {
    int totalSum = 0;
    sumDigitPathRecur(root, 0, totalSum);
    return totalSum;
}

int main() {

    // test 1
    int arr[] = {-1,0,0,2,2};
    int value[] = {3,5,2,1,4};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << sumDigitPath(root); // result: 680

    /* test 2
    int arr[] = {-1,0,0};
    int value[] = {1,2,3};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << sumDigitPath(root); // result: 25
    */
    return 0;
}
