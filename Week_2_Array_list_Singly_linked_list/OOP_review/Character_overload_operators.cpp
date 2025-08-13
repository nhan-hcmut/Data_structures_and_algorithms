#include <iostream>
using namespace std;

class Character {

protected:
    int hp;
    int x;
    int y;

public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp() const;
    void setHp(int hp);

    // Set and get x
    int getX() const;
    void setX(int x);
    
    // Set and get y
    int getY() const;
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);

    /* TO DO */

    // Operator =: copy all data from Character other
    void operator=(const Character& other);

    // Operator <: Character a < Character b when a's hp is less than or equal b's hp
    bool operator<(const Character& other);

    // Operator () with zero parameters: print data of the instance with format: hp-x-y
    void operator()();
};

Character::Character() {
    // STUDENT ANSWER
    this->x = 0;
    this->y = 0;
    this->hp = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;
}

int Character::getHp() const {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() const {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() const {
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    
    int xDifference = (this->x > other->getX()) ? this->x - other->getX() : other->getX() - this->x;
    int yDifference = (this->y > other->getY()) ? this->y - other->getY() : other->getY() - this->y;
    
    return xDifference + yDifference;
}

// Copy all data from Character other
void Character::operator=(const Character& other) {
    // STUDENT ANSWER
    this->hp = other.hp;
    this->x = other.x;
    this->y = other.y;
}

// Character a < Character b when a's hp is less than or equal b's hp
bool Character::operator<(const Character& other) {
    // STUDENT ANSWER
    return (this->hp <= other.hp);
}

// Print data of the instance with format: hp-x-y
void Character::operator()() {
    // STUDENT ANSWER
    cout << this->hp << "-" << this->x << "-" << this->y;
}

int main() {
    // Test 1
    Character ch1(100, 3, 6);
    ch1(); // Result: 100-3-6
    cout << endl;

    // Test 2
    Character ch21(10, 20, 30);
    Character ch22(5, 5, 6);
    cout << ((ch21 < ch22) ? "true\n" : "false\n"); // Result: "false"

    // Test 3
    Character ch31;
    Character ch32;
    cout << ((ch31 < ch32) ? "true\n" : "false\n"); // Result: "true"
    
    // Test 4
    Character ch4;
    ch4(); // Result: 0-0-0
    cout << endl;
    ch4 = Character(5, 10, 20);
    ch4(); // Result: 5-10-20
    cout << endl;

    // Test 5
    Character(3, 4, 5)(); // Result: 3-4-5
    cout << endl << ((Character(3, 4, 5) < Character(3, 4, 5)) ? "true\n" : "false\n"); // Result: true
    
    return 0;

}
