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
            BinarySearchTree&ltint&gt bst;<br/>
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
            BinarySearchTree&ltint&gt bst;<br/>
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
# find_sum

Given class BinarySearchTree, you need to finish method find(i) to check whether value i is in the tree or not; method sum(l,r) to calculate sum of all elements in the tree that has value greater than or equal to l and less than or equal to r.
```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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

    class Node {
        private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

        public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value);
    // STUDENT ANSWER BEGIN
 
    // STUDENT ANSWER END
};
```
**For example:**

<table>
    <tr>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>
            BinarySearchTree&ltint&gt bst;<br/>
            for (int i = 0; i < 10; ++i) bst.add(i);<br/>
            cout << bst.find(7) << endl;<br/>
            cout << bst.sum(0, 4) << endl;
        </td>
        <td>
            1<br/>
            10
        </td>
    </tr>
</table>

---
# getMin_getMax

Given class BinarySearchTree, you need to finish 2 methods getMin() and getMax().
```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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

    class Node {
        private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

        public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value);
    // STUDENT ANSWER BEGIN

    // STUDENT ANSWER END
};
```

**For example:**

<table>
    <tr>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>
            BinarySearchTree&ltint&gt bst;<br/>
            for (int i = 0; i < 10; ++i) bst.add(i);<br/>
            cout << bst.getMin() << endl;<br/>
            cout << bst.getMax() << endl;
        </td>
        <td>
            0<br/>
            9
        </td>
    </tr>
</table>

---
# isBST

Given class BinaryTree, you need to finish method isBST() to determine if a binary tree is a binary search tree (BST) or not.
```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree {
    public:
    class Node;
    
    private:
    Node* root;
    
    public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node {
        private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;
        
        public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value) {
        if (posFromRoot == "") {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        
        for (int i = 0; i < l - 1; i++) {
            if (!walker) return;
            if (posFromRoot[i] == 'L') walker = walker->pLeft;
            if (posFromRoot[i] == 'R') walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L') walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R') walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.

    bool isBST() const;
    // STUDENT ANSWER END
};
```
**Example:**

<table>
    <tr>
        <td>No.</td>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>1</td>
        <td>
            BinaryTree&ltint, int&gt binaryTree;<br/>
            binaryTree.addNode("", 2, 4); // Add to root<br/>
            binaryTree.addNode("L", 3, 2); // Add to root's left node<br/>
            binaryTree.addNode("R", 5, 9); // Add to root's right node<br/>
            cout << binaryTree.isBST();
        </td>
        <td>1</td>
    </tr>
    <tr>
        <td>2</td>
        <td>
            BinaryTree&ltint, int&gt binaryTree;<br/>
            binaryTree.addNode("", 2, 4);<br/>
            cout << binaryTree.isBST();
        </td>
        <td>1</td>
    </tr>
</table>

---
# kthSmallest

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

Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position.

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
int kthSmallest(BSTNode* root, int k);
```
Where root is the root node of given binary search tree (this tree has n elements) and k satisfy: 1 <= k <= n <= 100000. This function returns the k-th smallest value in the tree.

**Example:**

Given a binary search tree in 'kthSmallest.png'. With k = 2, the result should be 1.

**Note:** In this exercise, the libraries \<iostream\>, \<vector\>, \<stack\>, \<queue\>, \<algorithm\>, \<climits\> and using namespace std are used. You can write helper functions; however, you are **NOT** allowed to use other libraries.

**For example:**

<table>
    <tr>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>
            int arr[] = {6, 9, 2, 13, 0, 20};<br/>
            int k = 2;<br/>
            BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));<br/>
            cout << kthSmallest(root, k);<br/>
            BSTNode::deleteTree(root);
        </td>
        <td>2</td>
    </tr>
</table>

---
# levelAlterTraverse

Class **BSTNode** is used to store a node in binary search tree, described on the following:
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

Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position.

For example:
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
vector<int> levelAlterTraverse(BSTNode* root);
```
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the values of the nodes in each level, alternating from going left-to-right and right-to-left.

**Example:**

Given a binary search tree in 'levelAlter.png'.

In the first level, we should traverse from left to right (node: 3) and in the second level, we traverse from right to left (node: 4, 0). After traversing all the nodes, the result should be [3, 4, 0, 2, 1].

**Note:** In this exercise, the libraries \<iostream\>, \<vector\>, \<stack\>, \<queue\>, \<algorithm\> and using namespace std are used. You can write helper functions; however, you are **NOT** allowed to use other libraries.

**For example:**

<table>
    <tr>
        <td>Test</td>
        <td>Result</td>
    </tr>
    <tr>
        <td>
            int arr[] = {0, 3, 5, 1, 2, 4};<br/>
            BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));<br/>
            printVector(levelAlterTraverse(root));<br/>
            BSTNode::deleteTree(root);
        </td>
        <td>[0, 3, 1, 5, 4, 2]</td>
    </tr>
</table>

---
# rangeCount

Class **BTNode** is used to store a node in binary search tree, described on the following:
```cpp
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
```
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.

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
int rangeCount(BTNode* root, int lo, int hi);
```
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), lo and hi are 2 positive integers and lo ≤ hi. This function returns the number of all nodes whose values are between [lo, hi] in this binary search tree.

**More information:** If a node has val which is equal to its ancestor's, it is in the right subtree of its ancestor.

**Example:**

Given a binary search tree in 'RangeCount.png', with lo=5, hi=10, all the nodes satisfied are node 9, 7, 8; there fore, the result is 3.

**Note:** In this exercise, the libraries \<iostream\>, \<stack\>, \<queue\>, \<utility\> and using namespace std are used. You can write helper functions; however, you are **NOT** allowed to use other libraries.

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
            int value[] = {3, 2, 9, 7, 12, 4, 8};<br/>
            int lo = 5, hi = 10;<br/>
            BTNode* root = BTNode::createBSTree(value, value + sizeof(value) / sizeof(int));<br/>
            cout << rangeCount(root, lo, hi);
        </td>
        <td>3</td>
    </tr>
    <tr>
        <td>2</td>
        <td>
            int value[] = {1167, 2381, 577, 2568, 124, 1519, 234, 1679, 2696, 2359};<br/>
            int lo = 500, hi = 2000;<br/>
            BTNode* root = BTNode::createBSTree(value, value + sizeof(value) / sizeof(int));<br/>
            cout << rangeCount(root, lo, hi);
        </td>
        <td>4</td>
    </tr>
</table>

---
# singleChild

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

Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
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
int singleChild(BSTNode* root);
```
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the number of single children in the tree.

**More information:** A node is called a single child if its parent has only one child.

**Example:**

Given a binary search tree in 'singleChild.png'. There are 2 single children: node 2 and node 3.

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
            BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));<br/>
            cout << singleChild(root);<br/>
            BSTNode::deleteTree(root);
        </td>
        <td>3</td>
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
