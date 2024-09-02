#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
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

vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    vector<int> result;
    if (!root) return result;

    // use a queue for breadth-first traversal
    queue<BSTNode*> nodeQueue;
    nodeQueue.push(root);
    bool leftToRight = true; // a boolean variable determines the direction of traversal

    while (!nodeQueue.empty()) {
        int levelBreadth = nodeQueue.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelBreadth; i++) {
            BSTNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (leftToRight) currentLevel.push_back(currentNode->val);
            else currentLevel.insert(currentLevel.begin(), currentNode->val);

            if (currentNode->left) nodeQueue.push(currentNode->left);
            if (currentNode->right) nodeQueue.push(currentNode->right);
        }

        // push values of the current level to vector result
        result.insert(result.end(), currentLevel.begin(), currentLevel.end());

        // reverse the direction of traversal of the next level
        leftToRight = !leftToRight;
    }
    return result;
}

int main() {

    // Test
    int arr[] = {0, 3, 5, 1, 2, 4};
    BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
    printVector(levelAlterTraverse(root)); // Result: [0, 3, 1, 5, 4, 2]
    BSTNode::deleteTree(root);
    
    return 0;
}