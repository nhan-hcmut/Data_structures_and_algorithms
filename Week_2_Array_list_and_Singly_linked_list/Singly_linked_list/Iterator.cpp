#include<iostream>
#include<cassert>
using namespace std;

template<class T>
class SLinkedList {
    public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
    
    protected:
    Node *head;
    Node *tail;
    int count;
    
    public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list) {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
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
        Node(Node *next) {this->next = next;}
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

template<class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true:
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false:
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    if (begin) {
        if (pList && pList->head) {
            current = pList->head;
            index = 0;
        }
        else {
            current = nullptr;
            index = -1;
        }
    }
    else {
        current = nullptr;
        if (pList) index = pList->size();
        else index = 0;
    }
}

template<class T>
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

template<class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    if (!current || !pList || !pList->head) throw std::out_of_range("Segmentation fault!");

    if (current == pList->head) {
        pList->head = pList->head->next;
        if (!pList->head) { // list is now empty
            pList->tail = nullptr;
        }
        current = nullptr;
        index = -1;
    }
    else {
        Node* temp = pList->head;
        while (temp && temp->next != current) {
            temp = temp->next;
        }
        if (temp) {
            temp->next = current->next;
            if (temp->next == nullptr) { // last element was removed
                pList->tail = temp;
            }
            current = temp;
            index--;
        }
    }
    pList->count--; // decrease size of list
}

template<class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (!current) throw std::out_of_range("Segmentation fault!");
    current->data = e;
}

template<class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (!current) throw std::out_of_range("Segmentation fault!");
    return current->data;
}

template<class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
    return (this->current != iterator.current || this->index != iterator.index);
}
// Prefix ++ overload
template<class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (!current && index == -1) throw std::out_of_range("Segmentation fault!");

    if (current) {
        current = current->next;
        index++;
    }
    else if (index == -1) {
        current = pList->head;
        index = 0;
    }
    return *this;
}
// Postfix ++ overload
template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (!current && index == -1) throw std::out_of_range("Segmentation fault!");

    Iterator previous = *this;

    if (current) {
        current = current->next;
        index++;
    }
    else if (index == -1) {
        current = pList->head;
        index = 0;
    }
    return previous;
}

int main() {

    // test 1
    SLinkedList<int> list;
    
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
            
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for(it = list.begin(); it != list.end(); it++){
        assert(*it == expvalue);
        expvalue += 1;
    }

    /* test 2
    SLinkedList<int> list;
        
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
            
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for(it = list.begin(); it != list.end(); ++it){
        assert(*it == expvalue);
        expvalue += 1;
    }
    */

    return 0;
}
