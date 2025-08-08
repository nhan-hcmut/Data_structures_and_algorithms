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
    this->hp = this->x = this->y = 0;
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
    
    int xDifference = (this->x > other->x) ? (this->x - other->x) : (other->x - this->x);
    int yDifference = (this->y > other->y) ? (this->y - other->y) : (other->y - this->y);
    
    return xDifference + yDifference;
}

int main() {
    
    // test 1
    Character ch1(100, 3, 6);
    cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY() << endl; // Result: 100 3 6

    /* test 2
    Character ch2;
    cout << ch2.getHp() << " " << ch2.getX() << " " << ch2.getY() << endl; // Result: 0 0 0
    */

    /* test 3
    Character* ch31 = new Character(100, 1, 2);
    Character* ch32 = new Character(100, -3, 4);
    cout << ch31->getManhattanDistTo(ch32) << endl;
    delete ch31;
    delete ch32; // Result: 6
    */
    
    /* test 4
    Character ch4;
    ch4.setX(4);
    cout << ch4.getX() << endl; // Result: 4
    */

    /* test 5
    Character ch5;
    ch5.setY(5);
    cout << ch5.getY() << endl; // Result: 5
    */

    /* test 6
    Character ch6;
    ch6.setHp(6);
    cout << ch6.getHp() << endl; // Result: 6
    */ 
    return 0;
}
