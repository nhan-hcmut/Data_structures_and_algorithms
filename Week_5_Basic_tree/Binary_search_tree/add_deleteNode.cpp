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
    Node* addRecur(Node* temp, T value);
    //End helping functions

    void add(T value);
    
    //Helping functions
    Node* deleteRecur(Node* temp, T value);
    Node* minValueNode(Node* temp);
    //End helping functions

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
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::addRecur(BinarySearchTree<T>::Node* temp, T value) {
    if (!temp) temp = new Node(value);
    else if (value <= temp->value) temp->pLeft = addRecur(temp->pLeft, value);
    else temp->pRight = addRecur(temp->pRight, value);
    
    return temp;
}
//End helping functions

template<class T>
void BinarySearchTree<T>::add(T value) {
    //TODO
    this->root = this->addRecur(this->root, value);
}

//Helping functions
template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteRecur(BinarySearchTree<T>::Node* temp, T value) {
    if (!temp) return nullptr;
    if (value < temp->value) temp->pLeft = deleteRecur(temp->pLeft, value);
    else if (value > temp->value) temp->pRight = deleteRecur(temp->pRight, value);
    else {
        // Case 1: No child or one child
        if (!temp->pLeft) {
            Node* tempRight = temp->pRight;
            delete temp;
            return tempRight;
        }
        else if (!temp->pRight) {
            Node* tempLeft = temp->pLeft;
            delete temp;
            return tempLeft;
        }
        // Case 2: Two children
        Node* successor = minValueNode(temp->pRight);
        temp->value = successor->value;
        temp->pRight = deleteRecur(temp->pRight, successor->value);
    }
    return temp;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::minValueNode(BinarySearchTree<T>::Node* temp) {
    Node* current = temp;
    while (current->pLeft) {
        current = current->pLeft;
    }
    return current;
}
//End helping functions

template<class T>
void BinarySearchTree<T>::deleteNode(T value) {
    //TODO
    this->root = this->deleteRecur(this->root, value);
}

int main() {

    // test 1
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.deleteNode(9);
    cout << bst.inOrder(); // result: 2 10

    /* test 2
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.add(8);
    cout << bst.inOrder()<<endl; // result: 2 8 9 10
    bst.add(11);
    bst.deleteNode(9);
    cout << bst.inOrder(); // result: 2 8 10 11
    */
    return 0;
}
