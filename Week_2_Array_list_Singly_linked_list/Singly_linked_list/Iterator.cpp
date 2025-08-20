#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class SLinkedList {

public:
    class Iterator; //forward declaration
    class Node;     //forward declaration

protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0) {};
    ~SLinkedList(); // Helping methods

    void add(const T &e); // Helping methods
    void add(int index, const T &e);

    T removeAt(int index); // Helping methods
    bool removeItem(const T &removeItem);

    bool empty();
    int size();
    void clear(); // Helping methods

    T get(int index);
    void set(int index, const T &e);

    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();

    SLinkedList(const SLinkedList &list)
    {
        if (this->head != NULL) this->clear();

        this->head = this->tail = NULL;
        this->count = 0;
        
        for (Node* temp = list.head; temp != NULL; temp = temp->next) this->add(temp->data);
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator() : pList(NULL), current(NULL), index(-1) {}; // Helping methods
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        
        void remove();
        void set(const T &e);
        
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

// Helping methods
template <class T>
void SLinkedList<T>::add(const T &e) {
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

template <class T>
T SLinkedList<T>::removeAt(int index) {
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

template <class T>
SLinkedList<T>::~SLinkedList() {this->clear();}

template <class T>
void SLinkedList<T>::clear() {while (this->head != NULL) this->removeAt(0);}
// End helping methods


/* TODO */
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
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

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
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

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for the current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    this->current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in the current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator) {
    /*
        Operator not equal
        * Returns false if both iterators point to the same node and have the same index
    */
    return !(this->current == iterator.current && this->index == iterator.index);
}

// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++() {
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
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int) {
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
/* END TODO */

int main() {
    // Test 1
    SLinkedList<int> list;
    
    int size = 10;
    
    for (int idx = 0; idx < size; idx++) {
        list.add(idx);
    }
    
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    
    for (it = list.begin(); it != list.end(); it++) {
        assert(*it == expvalue);
        expvalue += 1;
    }
    
    /* Test 2
    SLinkedList<int> list;
        
    int size = 10;
    
    for (int idx = 0; idx < size; idx++) {
        list.add(idx);
    }
            
    SLinkedList<int>::Iterator it;
    
    int expvalue = 0;
    
    for (it = list.begin(); it != list.end(); ++it) {
        assert(*it == expvalue);
        expvalue += 1;
    }
    */
    
    return 0;
}
