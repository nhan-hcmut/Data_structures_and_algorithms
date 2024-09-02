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
    Node *root;

    public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}

    // helping functions
    void inorder(Node*& ptr) const {
        if (!ptr) return;
        this->inorder(ptr->pLeft);
        cout << ptr->data << " ";
        this->inorder(ptr->pRight);
    }
    Node* searchBST(Node*& ptr, T target) const {
        if (!ptr) return nullptr;
        if (target < ptr->data) return searchBST(ptr->pLeft, target);
        if (target < ptr->data) return searchBST(ptr->pRight, target);
        return ptr;
    }
    // End helping functions

    void printInorder() {
        //TODO
        this->inorder(this->root);
    }

    bool search(const T& value) {
        //TODO
        Node* foundNode = searchBST(this->root, value);
        if (!foundNode) return false;
        return true;
    }

    class Node {
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

        public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

int main() {

    // test
    AVLTree<int> avl;
    int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63, 99, 100};
    for (int i = 0; i < 12; i++) avl.insert(arr[i]);
    avl.printInorder(); // result: 10 13 32 40 42 52 63 68 92 98 99 100
    cout << endl << avl.search(10); // result: 1

    return 0;
}
