# add_deleteNode

In this question, you have to perform add and delete on binary search tree. Note that:

- When deleting a node which still have 2 children, take the inorder successor (smallest node of the right sub tree of that node) to replace it.

- When adding a node which has the same value as parent node, add it in the left sub tree.

Your task is to implement two functions: add and deleteNode. You could define one or more functions to achieve this task.
```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define SEPARATOR "#<ab@17943918#@>#"

template<class T>
class BinarySearchTree {
    public:
    class Node;
    
    private:
    Node* root;
    
    public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    //Helping functions

    void add(T value);
    void deleteNode(T value);

    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder() {
        return inOrderRec(this->root);
    }
    
    class Node {
        private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
        
        public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};

//Helping functions

template<class T>
void BinarySearchTree<T>::add(T value) {
    //TODO
}

template<class T>
void BinarySearchTree<T>::deleteNode(T value) {
    //TODO
}
```
**For example:**

<table>
    <tr>
        <td>No.</td>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>1</td>
        <td>
            BinarySearchTree<int> bst;<br/>
            bst.add(9);<br/>
            bst.add(2);<br/>
            bst.add(10);<br/>
            bst.deleteNode(9);<br/>
            cout << bst.inOrder();
        </td>
        <td>2 10</td>
    </tr>
    <tr>
        <td>2</td>
        <td>
            BinarySearchTree<int> bst;<br/>
            bst.add(9);<br/>
            bst.add(2);<br/>
            bst.add(10);<br/>
            bst.add(8);<br/>
            cout << bst.inOrder() << endl;<br/>
            bst.add(11);<br/>
            bst.deleteNode(9);<br/>
            cout << bst.inOrder();
        </td>
        <td>
            2 8 9 10<br/>
            2 8 10 11
        </td>
    </tr>
</table>

---
# subtreeWithRange

Class BSTNode is used to store a node in binary search tree, described on the following:
```cpp
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
```
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.

Also, a static method named **createBSTree** is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position.

**For example:**
```cpp
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
```
is equivalent to
```cpp
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
```
**Request:** Implement function
```cpp
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi);
```
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the binary search tree after deleting all nodes whose values are outside the range [lo, hi] (inclusive).

**Example:**

Given a binary search tree in 'subtree.png', with lo = 7 and hi = 10, the result will be in 'subtreeres.png'.

**Note:** In this exercise, the libraries \<iostream\> and using namespace std are used. You can write helper functions; however, you are NOT allowed to use other libraries.

**For example:**

<table>
    <tr>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>
            int arr[] = {0, 3, 5, 1, 2, 4};<br/>
            int lo = 1, hi = 3;<br/>
            BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));<br/>
            root = subtreeWithRange(root, lo, hi);<br/>
            BSTNode::printPreorder(root);<br/>
            BSTNode::deleteTree(root);
        </td>
        <td>3 1 2</td>
    </tr>
</table>
