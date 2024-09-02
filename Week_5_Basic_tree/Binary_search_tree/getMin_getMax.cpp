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
        Node *pLeft, *pRight;
        friend class BinarySearchTree<T>;

        public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value);

    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    T getMinRecur(Node*) const;
    T getMaxRecur(Node*) const;
    // End helping functions
    
    T getMin();
    T getMax();
    // STUDENT ANSWER END
};

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
template<class T>
T BinarySearchTree<T>::getMinRecur(Node* ptr) const {
    if (!ptr->pLeft) return ptr->value;
    return this->getMinRecur(ptr->pLeft);
}

template<class T>
T BinarySearchTree<T>::getMaxRecur(Node* ptr) const {
    if (!ptr->pRight) return ptr->value;
    return this->getMaxRecur(ptr->pRight);
}
// End helping functions

template<class T>
T BinarySearchTree<T>::getMin() {
    //TODO: return the minimum values of nodes in the tree.
    return this->getMinRecur(this->root);
}

template<class T>
T BinarySearchTree<T>::getMax() {
    //TODO: return the maximum values of nodes in the tree.
    return this->getMaxRecur(this->root);
}
// STUDENT ANSWER END

int main() {
    
    // Test 1
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(i);
    }
    cout << bst.getMin() << endl; // result: 0
    cout << bst.getMax() << endl; // result: 9

    /* test 2
    int values[] = {66, 60, 84, 67, 21, 45, 62, 1, 80, 35};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 1
    cout << bst.getMax() << endl; // result: 84
    */

    /* test 3
    int values[] = {38, 0, 98, 38, 99, 67, 19, 70, 55, 6};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 0
    cout << bst.getMax() << endl; // result: 99
    */

    /* test 4
    int values[] = {34, 81, 73, 48, 66, 91, 19, 84, 78, 79};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 19
    cout << bst.getMax() << endl; // result: 91
    */

    /* test 5
    int values[] = {94, 61, 75, 36, 34, 58, 62, 74, 54, 90};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 34
    cout << bst.getMax() << endl; // result: 94
    */

    /* test 6
    int values[] = {32, 0, 2, 84, 34, 78, 70, 60, 95, 71, 26, 62, 0, 22, 95};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 0
    cout << bst.getMax() << endl; // result: 95
    */

    /* test 7
    int values[] = {53, 24, 32, 40, 80, 47, 81, 88, 42, 29, 31, 91, 77, 73, 90};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 24
    cout << bst.getMax() << endl; // result: 91
    */

    /* test 8
    int values[] = {32, 19, 23, 33, 76, 1, 37, 53, 18, 89, 28, 1, 77, 52, 17};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 1
    cout << bst.getMax() << endl; // result: 89
    */

    /* test 9
    int values[] = {25, 29, 57, 30, 62, 56, 60, 55, 88, 56, 70, 83, 56, 75, 17};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 17
    cout << bst.getMax() << endl;; // result: 88
    */

    /* test 10
    int values[] = {75, 13, 83, 83, 30, 40, 10, 86, 17, 21, 45, 22, 22, 72, 63};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.getMin() << endl; // result: 10
    cout << bst.getMax() << endl; // result: 86
    */

    return 0;
}
