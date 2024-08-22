# BFS

Given a Binary tree, the task is to traverse all the nodes of the tree using Breadth First Search algorithm and print the order of visited nodes (has no blank space at the end)

```cpp
#include<iostream>
#include<string>
#include<queue>
using namespace std;

template<class K, class V>
class BinaryTree {
    public:
    class Node;

    private:
    Node *root;

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
        if(posFromRoot == "") {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++) {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    void BFS();
    // STUDENT ANSWER END
};

template<class K, class V>
void BinaryTree<K, V>::BFS() {}
```
**For example:**

+ Test:
```cpp
BinaryTree<int, int> binaryTree;
binaryTree.addNode("",2, 4); // Add to root
binaryTree.addNode("L",3, 6); // Add to root's left node
binaryTree.addNode("R",5, 9); // Add to root's right node
binaryTree.BFS();
```
+ Result: 4 6 9

---
# getHeight_preOrder_inOrder_postOrder

Given class BinaryTree, you need to finish methods getHeight(), preOrder(), inOrder(), postOrder().
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
        Node* pLeft, * pRight;
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
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    int getHeight();
    string preOrder();
    string inOrder();
    string postOrder();
    // STUDENT ANSWER END
};

template<class K, class V>
int BinaryTree<K, V>::getHeight() {
    // TODO: return height of the binary tree.
}

template<class K, class V>
string BinaryTree<K, V>::preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
}

template<class K, class V>
string BinaryTree<K, V>::inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
}

template<class K, class V>
string BinaryTree<K, V>::postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
}
```

**For example:**

+ Test 1:
```cpp
BinaryTree<int, int> binaryTree;
binaryTree.addNode("", 2, 4); // Add to root
binaryTree.addNode("L", 3, 6); // Add to root's left node
binaryTree.addNode("R", 5, 9); // Add to root's right node

cout << binaryTree.getHeight() << endl;
cout << binaryTree.preOrder() << endl;
cout << binaryTree.inOrder() << endl;
cout << binaryTree.postOrder() << endl;
```
+ Result 1:
<br/>
2
<br/>
4 6 9
<br/>
6 4 9
<br/>
6 9 4
<br/>
<br/>

+ Test 2:
```cpp
BinaryTree<int, int> binaryTree;
binaryTree.addNode("", 2, 4);

cout << binaryTree.getHeight() << endl;
cout << binaryTree.preOrder() << endl;
cout << binaryTree.inOrder() << endl;
cout << binaryTree.postOrder() << endl;
```
+ Result 2:
<br/>
1
<br/>
4
<br/>
4
<br/>
4

---
# longestPathSum

Class BTNode is used to store a node in binary tree, described on the following:
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

**Request:** Implement function
```cpp
int longestPathSum(BTNode* root);
```
Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.

**Example:**

Given a binary tree in the image 'longestPathSum.png':

The longest path from the root node to the leaf node is 1-4-7-4-2, so return the sum of this path, is 18.


**Explanation of function createTree:** The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.

**Example:**
```cpp
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
```
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.

**Note:** In this exercise, the libraries \<iostream\>, \<utility\>, \<queue\>, \<stack\> and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

**For example:**

+ Test 1:
```cpp
int arr[] = {-1,0,0,2,2,3,3,5};
int value[] = {1,5,4,7,12,4,8,2};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << longestPathSum(root);
```
+ Result 1: 18

+ Test 2:
```cpp
int arr[] = {-1,0,1,0,1,4,5,3,7,3};
int value[] = {6,12,23,20,20,20,3,9,13,15};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << longestPathSum(root);
```
+ Result 2: 61

---
# lowestAncestor

Class BTNode is used to store a node in binary tree, described on the following:
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

**Request:** Implement function:
```cpp
int lowestAncestor(BTNode* root, int a, int b);
```
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the lowest ancestor node's val of node a and node b in this binary tree (assume a and b always exist in the given binary tree).

**More information:**

- A node is called as the lowest ancestor node of node a and node b if node a and node b are its descendants.

- A node is also the descendant of itself.

- On the given binary tree, each node's val is distinguish from the others' val

**Example:**

Given a binary tree in the image 'LowestAncestor.png':

- The lowest ancestor of node 4 and node 5 is node 2.

**Explanation of function createTree:** The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.

**Example:**
```cpp
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
```
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.

**Note:** In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

**For example:**

+ Test 1:
```cpp
int arr[] = {-1,0,0,2,2,3,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 5);
```
+ Result 1: 2

+ Test 2:
```cpp
int arr[] = {-1,0,1,1,0,4,4,2,5,6};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), NULL);
cout << lowestAncestor(root, 4, 9);
```
+ Result 2: 4

---
# sumDigitPath

Class BTNode is used to store a node in binary tree, described on the following:
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
Where val is the value of node (integer, in segment [0,9]), left and right are the pointers to the left node and right node of it, respectively.

**Request:** Implement function:
```cpp
int sumDigitPath(BTNode* root);
```
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).

**More information:**

- A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.

- Each digit path represents a number in order, each node's val of this path is a digit of this number, while root's val is the first digit.

**Example:**

Given a binary tree in the image 'SumDigitPath.png':

All of the digit paths are 3-5, 3-2-1, 3-2-4; and the number reprensted by them are 35, 321, 324, respectively. The sum of them (after mod 27022001) is 680.

**Explanation of function createTree:** The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.

**Example:**
```cpp
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
```
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.

Note that whichever Node appears first in the arr sequence will be the left Node, and the test cases always ensure that the resulting tree is a binary tree.

**Note:** In this exercise, the libraries iostream, queue, stack, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

**For example:**

+ Test 1:
```cpp
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << sumDigitPath(root);
```
+ Result 1: 680

+ Test 2:
```cpp
int arr[] = {-1,0,0};
int value[] = {1,2,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << sumDigitPath(root);
```
+ Result 2: 25

---
