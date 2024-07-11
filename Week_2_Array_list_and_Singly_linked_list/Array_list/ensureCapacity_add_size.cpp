#include<iostream>
using namespace std;

template<class T>
class ArrayList {
    protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
    
    public:
    ArrayList() {this->capacity = 5; this->count = 0; this->data = new T[5];}
    ~ArrayList(){delete[] this->data;}
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
    string toString();
};

template<class T>
void ArrayList<T>::ensureCapacity(int cap) {
    /*
        if cap == capacity:
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap >= this->capacity) {
        int newCapacity = this->capacity*3/2 + 1;
        T* newData = new T[newCapacity];
        for (short i = 0; i < this->count; i++) newData[i] = this->data[i];
        delete this->data;
        this->data = newData;
        this->capacity = newCapacity;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    this->ensureCapacity(this->count+1);
    this->data[this->count] = e;
    this->count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    /*
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */
    if (index < 0 || this->count < index) throw std::out_of_range("the input index is out of range!");
    this->ensureCapacity(this->count+1);
    for (short i = this->count; i > index; i--) this->data[i] = this->data[i-1];
    this->data[index] = e;
    this->count++;
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */
    return this->count;
}

template<class T>
string ArrayList<T>::toString() {
    string str = "[";
    for (short i = 0; i < this->count; i++) {
        str += to_string(this->data[i]);
        if (i < this->count-1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

int main() {

    // test 1
    ArrayList<int> arr;
    int size = 10;
    for (int index = 0; index < size; index++) {
        arr.add(index);
    }
    cout << arr.toString() << '\n'; // result: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    cout << arr.size(); // result: 10
    
    /* test 2
    ArrayList<int> arr;
    int size = 20;
    for (int index = 0; index < size; index++){
        arr.add(0, index);
    }
    cout << arr.toString() << '\n'; // result: [19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    cout << arr.size() << '\n'; // result: 20
    arr.ensureCapacity(5);
    */

    return 0;
}
