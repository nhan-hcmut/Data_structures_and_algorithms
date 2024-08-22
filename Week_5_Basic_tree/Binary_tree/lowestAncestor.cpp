#include<iostream>
#include<stack>
#include<queue>
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

int lowestAncestor(BTNode* root, int a, int b) {
    if (!root) return -1;
    
    // If either of the two nodes is the root node, return the root node.
    if (root->val == a || root->val == b) return root->val;
    
    // Recursively search for the two nodes in the left and right subtrees of the root node.
    int left = lowestAncestor(root->left, a, b);
    int right = lowestAncestor(root->right, a, b);
    
    // If both nodes are found in different subtrees of the root node, return the root node as the lowest common ancestor.
    if (left != -1 && right != -1) return root->val;
    
    // If both nodes are found in the same subtree of the root node, recursively search for the lowest common ancestor in that subtree.
    if (left != -1) return left;
    return right;
}

int main() {
    
    // Test 1
    int arr[] = {-1,0,0,2,2,3,3};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
    cout << lowestAncestor(root, 4, 5); // Result: 2

    /* test 2
    int arr[] = {-1,0,1,1,0,4,4,2,5,6};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
    cout << lowestAncestor(root, 4, 9); // result: 4
    */
    return 0;
}
