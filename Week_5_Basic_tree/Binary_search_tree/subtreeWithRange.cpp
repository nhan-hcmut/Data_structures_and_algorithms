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

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    if (!root) return nullptr;
    
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    
    if (root->val < lo) {
       BSTNode* rChild = root->right;
       delete root;
       return rChild;
    }
    if (root->val > hi) {
       BSTNode* lChild = root->left;
       delete root;
       return lChild;
    }
    return root;
}

int main() {

    // Test
    int arr[] = {0, 3, 5, 1, 2, 4};
    int lo = 1, hi = 3;
    BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
    root = subtreeWithRange(root, lo, hi);
    BSTNode::printPreorder(root); // Result: 3 1 2
    BSTNode::deleteTree(root);
    
    return 0;
}