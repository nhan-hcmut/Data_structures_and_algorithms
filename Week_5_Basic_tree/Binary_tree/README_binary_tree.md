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
