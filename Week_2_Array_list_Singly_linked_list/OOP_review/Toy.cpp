#include <bits/stdc++.h>
using namespace std;

enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        /*
         * STUDENT ANSWER
        */
        this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        /*
         * STUDENT ANSWER
        */
        this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero numberOfItems and nullptr toyBox
        */
        this->numberOfItems = 0;
        *toyBox = nullptr;
    }
    
    int addItem(const CarToy& carToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Car toy to the box.
                 If successfully added, the function returns the current number of toys in the box.
                 If the box is full, return -1.
        */
        if (this->numberOfItems < 5) {
            this->toyBox[numberOfItems] = new CarToy(carToy.price, carToy.color);
            this->numberOfItems++;
            return this->numberOfItems;
        }
        return -1;
    }
    
    int addItem(const PuzzleToy& puzzleToy)
    {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Puzzle toy to the box.
                 If successfully added, the function returns the current number of toys in the box.
                 If the box is full, return -1.
        */
        if (this->numberOfItems < 5) {
            this->toyBox[numberOfItems] = new PuzzleToy(puzzleToy.price, puzzleToy.size);
            this->numberOfItems++;
            return this->numberOfItems;
        }
        return -1;
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};

int main() {

    //Test 1
    CarToy car(20000,red);
    PuzzleToy puzzle(30000,small);
    car.printType(); // Result: This is a car toy
    puzzle.printType(); // Result: This is a puzzle toy
    
    /* Test 2
    CarToy car(20000,red);
    PuzzleToy puzzle(30000,small);

    ToyBox box;
    box.addItem(car);
    box.addItem(puzzle);
    box.printBox(); // Result: This is a car toy
    // Result: This is a puzzle toy
    */

    /* Test 3
    Toy* toy = new CarToy(30000,red);
    toy->printType(); // Result: This is a car toy
    */
    
    return 0;
}
