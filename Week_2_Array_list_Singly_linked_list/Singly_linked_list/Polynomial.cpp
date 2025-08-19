// #include "Iterator.h"
#include <iostream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Iterator; // Forward declaration
    class Node;     // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {};
    ~SLinkedList() {this->clear();}
    void add(const T &e) {
        Node* pNew = new Node(e, NULL);
        if (this->head == NULL) {
            this->head = pNew;
            this->tail = pNew;
        }
        else {
            this->tail->next = pNew;
            this->tail = pNew;
        }
        this->count++;
    }
    void add(int index, const T &e) {
        /* Insert an element into the list at given index. */
        if (index < 0 || this->count < index) throw std::out_of_range("Index is out of range!");
        if (this->count == 0) this->head = this->tail = new Node(e, nullptr);
        else if (index == 0) {
            Node* pNew = new Node(e, this->head);
            this->head = pNew;
        }
        else if (index == this->count) {
            this->tail->next = new Node(e, nullptr);
            this->tail = this->tail->next;
        }
        else {
            Node *pNew = new Node(e, nullptr), *pre = this->head;
            for (short i = 0; i < index-1; i++) pre = pre->next;
            pNew->next = pre->next;
            pre->next = pNew;
        }
        this->count++;
    }
    T removeAt(int index) {
        if (index < 0 || this->count <= index) throw std::out_of_range("Index is out of range!");
        T value;
        if (this->count == 1) {
            value = this->head->data;
            delete this->head;
            this->head = this->tail = NULL;
        }
        else if (index == 0) {
            value = this->head->data;
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        else if (index == this->count - 1) {
            value = this->tail->data;
            Node* pre = this->head;
            while (pre->next != this->tail) pre = pre->next;
            delete this->tail;
            this->tail = pre;
            this->tail->next = NULL;
        }
        else {
            Node* pre = this->head;
            for (int i = 0; i < index - 1; i++) pre = pre->next;
            Node* cur = pre->next;
            value = cur->data;
            pre->next = cur->next;
            delete cur;
        }
        this->count--;
        return value;
    }
    bool removeItem(const T &Item);
    bool empty();
    int size();
    void clear() {while (this->head != NULL) this->removeAt(0);}
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list) {
        if (this->head != NULL) this->clear();
        this->head = this->tail = NULL;
        this->count = 0;
        for (Node* temp = list.head; temp != NULL; temp = temp->next) this->add(temp->data);
    }
    Iterator begin() {return Iterator(this, true);}
    Iterator end() {return Iterator(this, false);}
public:
    class Node {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node() {next = 0;}
        Node(T data, Node *next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator() : pList(NULL), current(NULL), index(-1) {};
        Iterator(SLinkedList<T> *pList, bool begin) {
            /*
                Constructor of iterator
                * Set pList to pList
                * if begin = true:
                * * Set current (index = 0) to pList's head if pList is not NULL
                * * Otherwise set to NULL (index = -1)
                * if begin = false:
                * * Always set current to NULL
                * * Set index to pList's size if pList is not NULL, otherwise 0
            */
            this->pList = pList;
            if (begin) {
                if (pList != NULL) {
                    this->current = pList->head;
                    this->index = 0;
                }
                else { /* pList == NULL */
                    this->current = NULL;
                    this->index = -1;
                }
            }
            else { /* begin == false */
                this->current = NULL;
                if (pList != NULL) {
                    this->index = pList->count;
                }
                else { /* pList == NULL */
                    this->index = 0;
                }
            }
        }
        Iterator &operator=(const Iterator &iterator) {
            /*
                Assignment operator
                * Set this current, index, pList to iterator corresponding elements.
            */
            this->current = iterator.current;
            this->index = iterator.index;
            this->pList = iterator.pList;
            return *this;
        }
        void remove() {
            /*
                Remove a node which is pointed by current
                * After removing, current points to the previous node of the current position (the node with index - 1)
                * If removing at the front, current points to previous "node" of head (current = NULL, index = -1)
                * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
            */
            if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
            if (this->index == 0) {
                this->pList->removeAt(0);
                this->current = NULL;
                this->index = -1;
            }
            else { /* this->index > 0 */
                Node* pre = this->pList->head;
                while (pre->next != this->current) pre = pre->next;
                this->pList->removeAt(this->index);
                this->index--;
                this->current = pre;
            }
        }
        void set(const T &e) {
            /*
                Set the new value for the current node
                * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
            */
            if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
            this->current->data = e;
        }
        T &operator*() {
            /*
                Get data stored in the current node
                * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
            */
            if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
            return this->current->data;
        }
        bool operator!=(const Iterator &iterator) {
            /*
                Operator not equal
                * Returns false if both iterators point to the same node and have the same index
            */
            return !(this->current == iterator.current && this->index == iterator.index);
        }
        
        // Prefix ++ overload
        Iterator &operator++() {
            /*
                Prefix ++ overload
                * Set current to the next node
                * If iterator corresponds to the previous "node" of head, set it to head
                * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
            */
            if (this->index == this->pList->count) throw std::out_of_range("Segmentation fault!");
            if (this->index == -1) {
                if (this->pList != NULL) this->current = this->pList->head;
                else this->current = NULL;
                this->index = 0;
            }
            else { /* this->index > -1 */
                this->current = this->current->next;
                this->index++;
            }
            return *this;
        }
        
        // Postfix ++ overload
        Iterator operator++(int) {
            /*
                Postfix ++ overload
                * Set current to the next node
                * If iterator corresponds to the previous "node" of head, set it to head
                * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
            */
            if (this->index == this->pList->count) throw std::out_of_range("Segmentation fault!");
            Iterator curIt = *this;
            if (this->index == -1) {
                if (this->pList != NULL) this->current = this->pList->head;
                else this->current = NULL;
                this->index = 0;
            }
            else { /* this->index > -1 */
                this->current = this->current->next;
                this->index++;
            }
            return curIt;
        }
    };
};
// End #include "Iterator.h"

/* Initialized frame */
class Polynomial; // Forward declaration

class Term {
private:
    double coeff;
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << "\nTerm: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};

class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
        if (this->terms != NULL) delete this->terms;
    }
    void insertTerm(const Term& term); /* TODO */
    void insertTerm(double coeff, int exp); /* TODO */
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << "\n]";
    }
};
/* End initialized frame */

/* TODO */
void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if (term.coeff == 0) return;

    if (this->terms == NULL) this->terms = new SLinkedList<Term>();
    
    int position = 0;
    for (SLinkedList<Term>::Iterator it = this->terms->begin(); it != this->terms->end(); it++, position++) {
        // The storage allocation for each term in the polynomial must be done in descending order of their exponent.
        if ((*it).exp < term.exp) {
            this->terms->add(position, term);
            return;
        }
        if ((*it).exp == term.exp) {
            (*it).coeff += term.coeff;
            
            if ((*it).coeff == 0) {
                this->terms->removeAt(position);
            }
            return;
        }
    }
    this->terms->add(term);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    this->insertTerm(Term(coeff, exp));
}
/* END TODO */

int main() {
    
    // Test 1
    Polynomial *poly = new Polynomial();
    
    poly->insertTerm(6.0, 2);
    poly->insertTerm(4.0, 5);
    poly->insertTerm(4.0, 3);
    poly->insertTerm(6.0, 5);
    poly->insertTerm(-1.0, 0);
    poly->insertTerm(-6.0, 6);
    poly->insertTerm(6.0, 6);
    
    poly->print();
    cout << endl << endl;
    
    /* Result:
    [
    Term: (10 5)
    Term: (4 3)
    Term: (6 2)
    Term: (-1 0)
    ]
    */
    
    // Test 2
    int n = 5;
    int coeff[] = { 1, 2, 3, 4, 5 };
    int exp[] = { 1, 2, 3, 4, 5 };

    Polynomial p1;
    for (int i = 0; i < n; ++i) {
        p1.insertTerm(coeff[i], exp[i]);
    }
    p1.print();

    /* Result:
    [
    Term: (5 5)
    Term: (4 4)
    Term: (3 3)
    Term: (2 2)
    Term: (1 1)
    ]
    */

    return 0;
}
