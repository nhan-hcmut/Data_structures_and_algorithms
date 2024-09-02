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
