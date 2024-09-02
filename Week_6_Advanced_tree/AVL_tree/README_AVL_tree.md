# rotateRight_rotateLeft

In this question, you have to perform rotate nodes on AVL tree. Note that:

- When adding a node which has the same value as parent node, add it in the right sub tree.

Your task is to implement function: rotateRight, rotateLeft. You could define one or more functions to achieve this task.
```cpp
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue {LH = -1, EH = 0, RH = 1};

void printNSpace(int n) {for (int i = 0; i < n - 1; i++) cout << " ";}

void printInteger(int &n) {cout << n << " ";}

template<class T>
class AVLTree {
    public:
    class Node;
    
    private:
    Node* root;
    
    protected:
    int getHeightRec(Node* node) {
        if (node == NULL) return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
    
    public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight() {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure() {
        int height = this->getHeight();
        if (this->root == NULL) {
            cout << "NULL\n";
            return;
        }
        queue<Node*> q;
        q.push(root);
        Node* temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == NULL) {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode) {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height) return;
        }
    }

    void insert(const T& value);
    int getBalance(Node* subroot) {
        if (!subroot) return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    }
    Node* rotateLeft(Node* subroot) {
        //TODO: Rotate and return new root after rotate
    };
    Node* rotateRight(Node* subroot) {
        //TODO: Rotate and return new root after rotate
    };

    class Node {
        private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

        public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
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
            // Test rotateLeft<br/>
            AVLTree<int> avl;<br/>
            avl.insert(0);<br/>
            avl.insert(1);<br/>
            cout << "After inserting 0, 1. Tree:" << endl;<br/>
            avl.printTreeStructure();<br/>
            avl.insert(2);<br/>
            cout << endl << "After inserting 2, perform 'rotateLeft'. Tree:" << endl;<br/>
            avl.printTreeStructure();
        </td>
        <td>
            After inserting 0, 1. Tree:<br/>
            0<br/>
            &nbsp1<br/>
            <br/>
            After inserting 2, perform 'rotateLeft'. Tree:<br/>
            &nbsp1<br/>
            0&nbsp2
        </td>
    </tr>
    <tr>
        <td>2</td>
        <td>
            // Test rotateRight<br/>
            AVLTree<int> avl;<br/>
            avl.insert(10);<br/>
            avl.insert(9);<br/>
            cout << "After inserting 10, 9. Tree:" << endl;<br/>
            avl.printTreeStructure();<br/>
            avl.insert(8);<br/>
            cout << endl << "After inserting 8, perform 'rotateRight'. Tree:" << endl;<br/>
            avl.printTreeStructure();
        </td>
        <td>
            After inserting 10, 9. Tree:<br/>
            &nbsp10<br/>
            9<br/>
            <br/>
            After inserting 8, perform 'rotateRight'. Tree:<br/>
            &nbsp9<br/>
            8&nbsp10
        </td>
    </tr>
</table>

---
# search_printInorder

In this exercise, you have to search and print inorder on AVL tree. You have to implement 2 methods: search() and printInorder() to complete the task. Note that:

- When the tree is null, don't print anything. 

- There's a whitespace at the end when print the tree inorder in case the tree is not null.

- When tree contains value, search return true.
```cpp
#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue {LH = -1, EH = 0, RH = 1};

template<class T>
class AVLTree {
    public:
    class Node;
    
    private:
    Node* root;
    
    public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}

    void printInorder() {
        //TODO
    }

    bool search(const T& value) {
        //TODO
    }

    class Node {
        private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

        public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
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
            AVLTree&ltint&gt avl;<br/>
            int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63, 99, 100};<br/>
            for (int i = 0; i < 12; i++) avl.insert(arr[i]);<br/>
            avl.printInorder();<br/>
            cout << endl << avl.search(10);
        </td>
        <td>
            10 13 32 40 42 52 63 68 92 98 99 100<br/>
            1
        </td>
    </tr>
</table>

---
