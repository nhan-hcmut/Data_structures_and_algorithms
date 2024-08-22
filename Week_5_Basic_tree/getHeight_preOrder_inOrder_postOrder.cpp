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
    int getHeightRecur(Node* temp) const;
    int getHeight();

    string preOrderRecur(Node* temp) const;
    string preOrder();

    string inOrderRecur(Node* temp) const;
    string inOrder();

    string postOrderRecur(Node* temp) const;
    string postOrder();
    // STUDENT ANSWER END
};

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
template<class K, class V>
int BinaryTree<K, V>::getHeightRecur(Node* temp) const {
    if (!temp) return 0;
    if (this->getHeightRecur(temp->pLeft) > this->getHeightRecur(temp->pRight)) return this->getHeightRecur(temp->pLeft) + 1;
    return this->getHeightRecur(temp->pRight) + 1;
}

template<class K, class V>
int BinaryTree<K, V>::getHeight() {
    // TODO: return height of the binary tree.
    return this->getHeightRecur(this->root);
}

template<class K, class V>
string BinaryTree<K, V>::preOrderRecur(Node* temp) const {
    if (!temp) return "";
    stringstream ss;
    ss << temp->value << " ";
    ss << this->preOrderRecur(temp->pLeft);
    ss << this->preOrderRecur(temp->pRight);
    return ss.str();
}

template<class K, class V>
string BinaryTree<K, V>::preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    return this->preOrderRecur(this->root);
}

template<class K, class V>
string BinaryTree<K, V>::inOrderRecur(Node* temp) const {
    if (!temp) return "";
    stringstream ss;
    ss << this->inOrderRecur(temp->pLeft);
    ss << temp->value << " ";
    ss << this->inOrderRecur(temp->pRight);
    return ss.str();
}

template<class K, class V>
string BinaryTree<K, V>::inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    return this->inOrderRecur(this->root);
}

template<class K, class V>
string BinaryTree<K, V>::postOrderRecur(Node* temp) const {
    if (!temp) return "";
    stringstream ss;
    ss << this->postOrderRecur(temp->pLeft);
    ss << this->postOrderRecur(temp->pRight);
    ss << temp->value << " ";
    return ss.str();
}

template<class K, class V>
string BinaryTree<K, V>::postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    return this->postOrderRecur(this->root);
}

// STUDENT ANSWER END

int main() {

    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
    
    /* result:
    2
    4 6 9
    6 4 9
    6 9 4
    */
    return 0;
}
