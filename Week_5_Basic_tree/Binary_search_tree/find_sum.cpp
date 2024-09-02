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
    // You can define other functions here to help you.
    bool findRecur(Node*, T);
    T sumRecur(Node*, T, T);
    // End helping functions

    bool find(T);
    T sum(T, T);
    // STUDENT ANSWER END
};

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
template<class T>
bool BinarySearchTree<T>::findRecur(Node* ptr, T i) {
    if (!ptr) return false;
    if (ptr->value == i) return true;
    if (ptr->value > i) return findRecur(ptr->pLeft, i);
    return findRecur(ptr->pRight, i);
}

template<class T>
T BinarySearchTree<T>::sumRecur(Node* ptr, T l, T r) {
    if (!ptr) return 0;
    if (ptr->value < l) return sumRecur(ptr->pRight, l, r);
    if (ptr->value > r) return sumRecur(ptr->pLeft, l, r);
    return ptr->value + sumRecur(ptr->pLeft, l, r) + sumRecur(ptr->pRight, l, r);
}
// End helping functions

template<class T>
bool BinarySearchTree<T>::find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return this->findRecur(this->root, i);
}

template<class T>
T BinarySearchTree<T>::sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return this->sumRecur(this->root, l, r);
}
// STUDENT ANSWER END

int main() {

    // test 1
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(i);
    }
    cout << bst.find(7) << endl; // result: 1
    cout << bst.sum(0, 4) << endl; // result: 10
    
    /* test 2
    int values[] = {66, 60, 84, 67, 21, 45, 62, 1, 80, 35};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(5) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 56
    */

    /* test 3
    int values[] = {38, 0, 98, 38, 99, 67, 19, 70, 55, 6};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(5) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 95
    */

    /* test 4
    int values[] = {34, 81, 73, 48, 66, 91, 19, 84, 78, 79};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(5) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 53
    */

    /* test 5
    int values[] = {94, 61, 75, 36, 34, 58, 62, 74, 54, 90};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 1
    cout << bst.sum(10, 40); // result: 70
    */

    /* test 6
    int values[] = {32, 0, 2, 84, 34, 78, 70, 60, 95, 71, 26, 62, 0, 22, 95};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 1
    cout << bst.sum(10, 40); // result: 114
    */

    /* test 7
    int values[] = {53, 24, 32, 40, 80, 47, 81, 88, 42, 29, 31, 91, 77, 73, 90};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 156
    */

    /* test 8
    int values[] = {32, 19, 23, 33, 76, 1, 37, 53, 18, 89, 28, 1, 77, 52, 17};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 207
    */

    /* test 9
    int values[] = {25, 29, 57, 30, 62, 56, 60, 55, 88, 56, 70, 83, 56, 75, 17};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 101
    */

    /* test 10
    int values[] = {75, 13, 83, 83, 30, 40, 10, 86, 17, 21, 45, 22, 22, 72, 63};
    BinarySearchTree<int> bst;
    for (int i = 0; i < 15; ++i) {
        bst.add(values[i]);
    }
    cout << bst.find(34) << endl; // result: 0
    cout << bst.sum(10, 40); // result: 175
    */

    return 0;
}