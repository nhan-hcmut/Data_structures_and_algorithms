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

int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) return 0;
    if (root->val < lo) return rangeCount(root->right, lo, hi);
    if (root->val > hi) return rangeCount(root->left, lo, hi);
    return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right, lo, hi);
}

int main() {

    // test 1
    int value[] = {3, 2, 9, 7, 12, 4, 8};
    int lo = 5, hi = 10;
    BTNode* root = BTNode::createBSTree(value, value + sizeof(value) / sizeof(int));
    cout << rangeCount(root, lo, hi); // result: 3

    /* test 2
    int value[] = {1167, 2381, 577, 2568, 124, 1519, 234, 1679, 2696, 2359};
    int lo = 500, hi = 2000;
    BTNode* root = BTNode::createBSTree(value, value + sizeof(value) / sizeof(int));
    cout << rangeCount(root, lo, hi); // result: 4
    */

    return 0;
}