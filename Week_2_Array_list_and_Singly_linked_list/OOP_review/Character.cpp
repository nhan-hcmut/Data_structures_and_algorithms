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
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
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

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
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

int main() {
    Character ch1(100, 3, 6);
    
    cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY(); // Result: 100 3 6

    return 0;
}
