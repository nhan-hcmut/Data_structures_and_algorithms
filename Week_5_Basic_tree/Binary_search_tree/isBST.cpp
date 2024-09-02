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
    bool isBSTRecur(Node*) const;
    // End helping functions

    bool isBST() const;
    // STUDENT ANSWER END
};

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
template<class K, class V>
bool BinaryTree<K, V>::isBSTRecur(Node* ptr) const {
    if (!ptr) return true;
    if ((ptr->pLeft && ptr->pLeft->value > ptr->value) || (ptr->pRight && ptr->pRight->value < ptr->value)) return false;
    if (isBSTRecur(ptr->pLeft) && isBSTRecur(ptr->pRight)) return true;
    return false;
}
// End helping functions

template<class K, class V>
bool BinaryTree<K, V>::isBST() const {
    // TODO: return true if a tree is a BST; otherwise, return false.
    return this->isBSTRecur(this->root);
}
// STUDENT ANSWER END

int main() {

    // test 1
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 2); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node
    cout << binaryTree.isBST(); // result: 1
    
    /* test 2
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);
    cout << binaryTree.isBST(); // result: 1
    */
    return 0;
}