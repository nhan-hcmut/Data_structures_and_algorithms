#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr) {}
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    int getData() const {return this->data;}
    void setData(int data) {this->data = data;}

    Node* getNext() const {return this->next;}
    void setNext(Node* next) {this->next = next;}
};

// Helping functions
void printList(Node* root) {
    cout << "HEAD -> ";
    while (root != nullptr) {
        cout << root->getData() << " -> ";
        root = root->getNext();
    }
    cout << "NULL";
}

void clear(Node* root) {
    while (root != nullptr) {
        Node* temp = root;
        root = root->getNext();
        delete temp;
    }
}
// End helping functions

/* TODO */
void reduceDuplicate(Node* root) {
    if (root == nullptr || root->getNext() == nullptr) return;

    Node* nxt = root->getNext();

    while (nxt != nullptr) {
        if (root->getData() == nxt->getData()) {
            nxt = nxt->getNext();
            delete root->getNext();
            root->setNext(nxt);
        }
        else {
            root = nxt;
            nxt = nxt->getNext();
        }
    }
}

int main() {
    
    // Test 1
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(1, node1);
    Node* node3 = new Node(0, node2);
    
    printList(node3); // result: HEAD -> 0 -> 1 -> 1 -> NULL
    cout << endl;
    
    reduceDuplicate(node3);
    printList(node3); // result: HEAD -> 0 -> 1 -> NULL
    clear(node3);
    
    /* Test 2
    Node* node1 = new Node(2, nullptr);
    Node* node2 = new Node(5, node1);
    Node* node3 = new Node(4, node2);
    Node* node4 = new Node(4, node3);
    Node* node5 = new Node(3, node4);
    Node* node6 = new Node(2, node5);
    Node* node7 = new Node(2, node6);
    Node* node8 = new Node(2, node7);
    Node* node9 = new Node(1, node8);
    
    printList(node9); // result: HEAD -> 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5 -> 2 -> NULL
    cout << endl;
    
    reduceDuplicate(node9);
    printList(node9); // result: HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> 2 -> NULL
    clear(node9);
    */
    
    /* Test 3
    Node* node1 = new Node(6, nullptr);

    printList(node1); // result: HEAD -> NULL
    cout << endl;
    
    reduceDuplicate(node1);
    printList(node1); // result: HEAD -> NULL
    clear(node1);
    */
    
    return 0;
}