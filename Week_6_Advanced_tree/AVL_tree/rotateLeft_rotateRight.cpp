#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue {LH = -1, EH = 0, RH = 1};

void printNSpace(int n) {for (int i = 0; i < n - 1; i++) cout << " ";}
void printInteger(int& n) {cout << n << " ";}

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

    int getHeight() {return this->getHeightRec(this->root);}
    
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
        if(!subroot) return 0;
        return getHeightRec(subroot->pLeft) - getHeightRec(subroot->pRight);
    }
    
    Node* rotateLeft(Node* subroot) {
        //TODO: Rotate and return new root after rotate
        Node* temp = subroot->pRight;
        subroot->pRight = temp->pLeft;
        temp->pLeft = subroot;
        subroot = temp;
        return subroot;
    }
    
    Node* rotateRight(Node* subroot) {
        //TODO: Rotate and return new root after rotate
        Node* temp = subroot->pLeft;
        subroot->pLeft = temp->pRight;
        temp->pRight = subroot;
        subroot = temp;
        return subroot;
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

int main() {
    
    // Test rotateLeft
    AVLTree<int> avl;
    avl.insert(0);
    avl.insert(1);
    cout << "After inserting 0, 1. Tree:\n";
    avl.printTreeStructure();
    avl.insert(2);
    cout << endl << "After inserting 2, perform 'rotateLeft'. Tree:\n";
    avl.printTreeStructure();
    
    /* result:
    After inserting 0, 1. Tree:
    0
     1

    After inserting 2, perform 'rotateLeft'. Tree:
     1
    0 2
    */
    
    /* Test rotateRight
    AVLTree<int> avl;
    avl.insert(10);
    avl.insert(9);
    cout << "After inserting 10, 9. Tree:" << endl; 
    avl.printTreeStructure();
    avl.insert(8);
    cout << endl << "After inserting 8, perform 'rotateRight'. Tree:" << endl;
    avl.printTreeStructure();
    
    result:
    After inserting 10, 9. Tree:
     10
    9

    After inserting 8, perform 'rotateRight'. Tree:
     9
    8 10
    */
    return 0;
}