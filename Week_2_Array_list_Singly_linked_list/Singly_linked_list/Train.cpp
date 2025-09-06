#include <iostream>
using namespace std;

class Train {
public:
    class TrainCar;
private:
    TrainCar* head;
    TrainCar* tail;
    int size;
public:
    class TrainCar {
    private:
        int remainingSpace;
        TrainCar* next;
        friend class Train;
    public:
        TrainCar() {this->next = NULL;}
        TrainCar(int remainingSpace, TrainCar* next = NULL) {
            this->remainingSpace = remainingSpace;
            this->next = next;
        }
    };
    Train() {
        this->head = new TrainCar(0);
        this->tail = this->head;
        this->size = 1;
    }
    ~Train(); // Helping methods
    void add(int); // Helping methods

    int allocate(int containerSize); /* TODO */
    int totalRemainingSpace(); /* TODO */
};

// Helping methods
Train::~Train() {
    while (this->head != NULL) {
        TrainCar* temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->size--;
    }
    this->tail = NULL;
}

void Train::add(int remainingSpace) {
    this->tail->next = new TrainCar(remainingSpace);
    this->tail = this->tail->next;
    this->size++;
}

/* TODO */
int Train::allocate(int containerSize) {
    int index = -1;
    TrainCar *curr = this->head->next, *temp = NULL;

    for (int j = 1; j < this->size; j++) {
        if (curr->remainingSpace >= containerSize && (temp == NULL || curr->remainingSpace < temp->remainingSpace)) {
            temp = curr;
            index = j;
        }
        curr = curr->next;
    }
    if (index > 0) temp->remainingSpace -= containerSize;
    return index;
}

int Train::totalRemainingSpace() {
    int result = 0;
    TrainCar* temp = this->head->next;

    while (temp != NULL) {
        result += temp->remainingSpace;
        temp = temp->next;
    }
    return result;
}

int main() {

    // Test
    Train* t = new Train();
    t->add(200); t->add(400); t->add(300); ; t->add(600); t->add(500); t->add(100);

    cout << t->allocate(390) << "\n"; // Result: 2
    cout << t->allocate(590) << "\n"; // Result: 4
    cout << t->totalRemainingSpace() << "\n"; // Result: 1120
    cout << t->allocate(510) << "\n"; // Result: -1
    cout << t->allocate(10) << "\n"; // Result: 2
    
    return 0;
}