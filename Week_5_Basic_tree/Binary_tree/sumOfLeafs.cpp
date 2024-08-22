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
    //Helping functions
    int sumOfLeafsRecur(Node*) const;
    int sumOfLeafs();
};

//Helping functions
template<class K, class V>
int BinaryTree<K, V>::sumOfLeafsRecur(Node* temp) const {
    if (!temp) return 0;
    
    if (!temp->pLeft && !temp->pRight) return temp->value;
    
    return sumOfLeafsRecur(temp->pLeft) + sumOfLeafsRecur(temp->pRight);
}

template<class K, class V>
int BinaryTree<K, V>::sumOfLeafs() {
    //TODO
    return this->sumOfLeafsRecur(this->root);
}

int main() {

    // test 1
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);
    cout << binaryTree.sumOfLeafs(); // result: 4
    
    /* test 2
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4);
    binaryTree.addNode("L", 3, 6);
    binaryTree.addNode("R", 5, 9);
    cout << binaryTree.sumOfLeafs(); // result: 15
    */
    return 0;
}
