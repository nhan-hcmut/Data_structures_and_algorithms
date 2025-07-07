#include <iostream>
using namespace std;

class Character {

private:
    int x;
    int y;

protected:
    int hp;

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
    if (this->hp <= other.hp) return true;
    return false;
}

// Print data of the instance with format: hp-x-y
void Character::operator()() {
    // STUDENT ANSWER
    cout << this->hp << "-" << this->x << "-" << this->y;
}

/*
Declare and define the derived class Player that satisfies:

    - Methods of base class Character cannot be accessed outside Player class using Player instances.
        Ex: Player pl; pl.setX(); will raise errors when compiled.

    - Player class has these methods and constructors:
        + Constructor Player(): acts just like Character()
        + Constructor Player(int hp, int x, int y): acts just like Character(hp, x, y)
        + Method void printPlayerData(): print data of the instance with format: hp-x-y
        + Method void moveTo(int x, int y): set the values of x, y to new values
        
    - The mentioned constructors and methods can be accessed outside Player class
*/

class Player : private Character {
    public:
        Player() {
            this->hp = 0;
            this->setX(0);
            this->setY(0);
        }
        Player(int hp, int x, int y) {
            this->hp = hp;
            this->setX(x);
            this->setY(y);
        }
        void printPlayerData() {
            cout << this->hp << "-" << this->getX() << "-" << this->getY();
        }
        void moveTo(int x, int y) {
            this->setX(x);
            this->setY(y);
        }
};

int main() {
    // Test 1
    Player pl1(100, 3, 6);
    pl1.printPlayerData(); // Result: 100-3-6
    cout << endl;

    // Test 2
    Player pl2;
    pl2.printPlayerData(); // Result: 0-0-0
    cout << endl;

    // Test 3
    Player pl3(300, 1, 2);
    pl3.moveTo(3, 4);
    pl3.printPlayerData(); // Result: 300-3-4
    cout << endl;

    // Test 4
    Player pl4(300, 1, 2);
    pl4.printPlayerData(); // Result: 300-1-2
    cout << endl;
    pl4.moveTo(2, 1);
    pl4.printPlayerData(); // Result: 300-2-1
    cout << endl;

    // Test 5
    Player pl5(300, 1, 2);
    pl5.moveTo(9, 7);
    pl5.printPlayerData(); // Result: 300-9-7
    cout << endl;

    // Test 6
    Player pl;
    //pl.setX(); // Result: Compile-time error

    return 0;
}