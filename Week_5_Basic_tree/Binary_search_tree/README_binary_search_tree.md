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
