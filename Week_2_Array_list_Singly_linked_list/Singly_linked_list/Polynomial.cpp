#include<iostream>
using namespace std;

class Polynomial; //forward declaration

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
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
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
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() const {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};

//SLinkedList has been done with the following attributes and methods:
class SLinkedList : IList<T> {
    public:
    class Iterator; //forward declaration
    class Node;     //forward declaration

    protected:
    Node* head;
    Node* tail;
    int count;

    public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {};
    virtual ~SLinkedList();
    virtual void add(const T& e);
    virtual void add(int index, const T& e);
    virtual T removeAt(int index);
    virtual bool removeItem(const T& removeItem);
    virtual bool empty();
    virtual int size();
    virtual void clear();
    virtual T get(int index);
    virtual void set(int index, const T& e);
    virtual int indexOf(const T& item);
    virtual bool contains(const T& item);
};

void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if (term.coeff == 0) return;
    SLinkedList<Term>::Iterator it;
    int idx = 0;
    for (it = this->terms->begin(); it != this->terms->end(); it++, idx++) {
        if ((*it).exp < term.exp) {
            this->terms->add(idx, term);
            return;
        }
        else if ((*it).exp == term.exp) {
            (*it).coeff += term.coeff;
            if ((*it).coeff == 0) {
                this->terms->removeAt(idx);
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
    /* Result
    [
    Term: (10 5)
    Term: (4 3)
    Term: (6 2)
    Term: (-1 0)
    ]
    */

    /* Test 2
    int n = 5;
    int coeff[] = { 1, 2, 3, 4, 5 };
    int exp[] = { 1, 2, 3, 4, 5 };

    Polynomial p1;
    for (int i = 0; i < n; ++i)
        p1.insertTerm(coeff[i], exp[i]);

    p1.print();
    // Result
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
