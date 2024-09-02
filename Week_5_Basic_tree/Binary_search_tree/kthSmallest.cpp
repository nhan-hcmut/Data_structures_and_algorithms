#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
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

int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    int count = 0;
    int result = -1;
    stack<BSTNode*> stk;

    BSTNode* currentNode = root;

    while (currentNode || !stk.empty()) {
        while (currentNode) {
            stk.push(currentNode);
            currentNode = currentNode->left;
        }
        currentNode = stk.top();
        stk.pop();

        count++;
        if (count == k) {
            result = currentNode->val;
            break;
        }
        currentNode = currentNode->right;
    }
    return result;
}

int main() {

    // test
    int arr[] = {6, 9, 2, 13, 0, 20};
    int k = 2;
    BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
    cout << kthSmallest(root, k); // result: 2
    BSTNode::deleteTree(root);

    return 0;
}