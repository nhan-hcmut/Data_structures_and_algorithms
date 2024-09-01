#include<iostream>
using namespace std;

class BSTNode {
    public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};

int singleChild(BSTNode* root) {
    // STUDENT ANSWER
    if (!root) return 0;

    int count = 0;
    if ((root->left && !root->right) || (!root->left && root->right)) count = 1;
    count += singleChild(root->left) + singleChild(root->right);

    return count;
}

int main() {

    // Test
    int arr[] = {0, 3, 5, 1, 2, 4};
    BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
    cout << singleChild(root); // Result: 3
    BSTNode::deleteTree(root);

    return 0;
}