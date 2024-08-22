#include<iostream>
#include<string>
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
        for (int i = 0; i < l - 1; i++) {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    int countTwoChildrenNodeRecur(Node* temp) const;
    int countTwoChildrenNode();
    // STUDENT ANSWER END
};
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
template<class K, class V>
int BinaryTree<K, V>::countTwoChildrenNodeRecur(Node* temp) const {
    if (!temp) return 0;
    int count = 0;
    if (temp->pLeft && temp->pRight) count++;
    count += this->countTwoChildrenNodeRecur(temp->pLeft);
    count += this->countTwoChildrenNodeRecur(temp->pRight);
    return count;
}

template<class K, class V>
int BinaryTree<K, V>::countTwoChildrenNode() {
    return this->countTwoChildrenNodeRecur(this->root);
}
// STUDENT ANSWER END

int main() {
    
    // test 1
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",2, 4); // Add to root
    binaryTree.addNode("L",3, 6); // Add to root's left node
    binaryTree.addNode("R",5, 9); // Add to root's right node
    cout << binaryTree.countTwoChildrenNode(); // result: 1

    /* test 2
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",2, 4);
    binaryTree.addNode("L",3, 6);
    binaryTree.addNode("R",5, 9);
    binaryTree.addNode("LL",4, 10);
    binaryTree.addNode("LR",6, 2);
    cout << binaryTree.countTwoChildrenNode(); // result: 2
    */
    return 0;
}