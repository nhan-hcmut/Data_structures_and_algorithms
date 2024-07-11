#include<iostream>
using namespace std;

template<class T>
class ArrayList {
    protected:
    T* data; // dynamic array to store the list's items
    int capacity; // size of the dynamic array
    int count; // number of items stored in the array

    public:
    ArrayList() {this->capacity = 5; this->count = 0; this->data = new T[5];}
    ~ArrayList() {delete[] this->data;}    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
    string toString();
};

template<class T>
T ArrayList<T>::removeAt(int index) {
    /*
    Remove element at index and return removed value
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index < 0 || this->count <= index) throw std::out_of_range("index is out of range");
    T value = this->data[index];
    for (short i = index; i < this->count-1; i++) this->data[i] = this->data[i+1];
    this->count--;
    return value;
}

template<class T>
bool ArrayList<T>::removeItem(T item) {
     /* Remove the first apperance of item in array and return true, otherwise return false */
    if (this->count == 0) return false;
    for (short i = 0; i < this->count; i++) {
        if (this->data[i] == item) {
            this->removeAt(i);
            return true;
        }
    }
    return false;
}

template<class T>
void ArrayList<T>::clear() {
    /*
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (this->data) delete this->data;
    this->data = new T[5];
    this->capacity = 5;
    this->count = 0;
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

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.removeAt(0);

    cout << arr.toString() << '\n'; // result: [1, 2, 3, 4, 5, 6, 7, 8, 9]
    cout << arr.size(); // result: 9
    
    /* test 2
    ArrayList<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.removeAt(9);

    cout << arr.toString() << '\n'; // result: [0, 1, 2, 3, 4, 5, 6, 7, 8]
    cout << arr.size(); // result: 9
    */

    /* test 3
    ArrayList<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.removeAt(5);

    cout << arr.toString() << '\n'; // result: [0, 1, 2, 3, 4, 6, 7, 8, 9]
    cout << arr.size(); // result: 9
    */

    return 0;
}
