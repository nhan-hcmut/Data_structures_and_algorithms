# Book

Hoang is a K19 student studying at Bach Khoa University. He plans to write a book management software for the library. In the class design, Hoang has designed the class Book as follows:
```cpp
class Book
{
private:
    char* title; 
    char* authors; 
    int publishingYear; 
public: 
   // some method
};
```
Your task in this exercise is to implement functions marked with /* STUDENT ANSWER */.

**Note:** We have #include \<bits/stdc++.h\> and using namespace std;

For example:
+ Test 1:
```cpp
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
book1.printBook();
```
+ Result:
<br/>
Giai tich 1
<br/>
Nguyen Dinh Huy
<br/>
2000
<br/><br/>

+ Test 2:
```cpp
Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
Book book2 = book1;
book2.printBook();
```
+ Result:
<br/>
Giai tich 1
<br/>
Nguyen Dinh Huy
<br/>
2000

---
# Character

In a game, we have class Character to store characters' data.
The class Character is declared as below:
```cpp
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
```
Your task is to define constructors and methods of the class.

**Note:** In this task, \<iostream\> library has been included and namespace std is used. No other libraries are allowed.

**For example:**
+ Test 1:
```cpp
Character ch1(100, 3, 6);
cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();
```
+ Result: 100 3 6
<br/>

+ Test 2:
```cpp
Character ch2;
cout << ch2.getHp() << " " << ch2.getX() << " " << ch2.getY();
```
+ Result: 0 0 0
<br/>

+ Test 3:
```cpp
Character* ch31 = new Character(100, 1, 2);
Character* ch32 = new Character(100, -3, 4);
cout << ch31->getManhattanDistTo(ch32);
delete ch31;
delete ch32;
```
+ Result: 6
<br/>

+ Test 4:
```cpp
Character ch4;
ch4.setX(4);
cout << ch4.getX();
```
+ Result: 4
<br/>

+ Test 5:
```cpp
Character ch5;
ch5.setY(5);
cout << ch5.getY();
```
+ Result: 5
<br/>

+ Test 6:
```cpp
Character ch6;
ch6.setHp(6);
cout << ch6.getHp();
```
+ Result: 6

---
# Circle

In the coordinate plane, a circle is defined by center and radius.

Your task in this exercise is to implement functions marked with /*  * STUDENT ANSWER   */.

**Note:** you can use implemented class Point in previous question

**For example:**
+ Test:
```cpp
Circle A;
A.printCircle();
```
+ Result: Center: {0.00, 0.00} and Radius 0.00

---
# Point

We have class Point to store a point in the coordinate plane with its x-y coordinate.

Your task in this exercise is to implement functions marked with /*  * STUDENT ANSWER   */.

**Note:** We have #include \<bits/stdc++.h\> and using namespace std;

**For example:**

+ Test 1:
```cpp
Point A(2, 3);
cout << A.getX() << " " << A.getY();
```
+ Result: 2 3
<br/>

+ Test 2:
```cpp
Point A(2, 3);
Point B(1, 1);
cout << pow(A.distanceToPoint(B), 2);
```
+ Result: 5

---
# Toy

1. In the toy store, all toy has a price. Car toy has a price and color, Puzzle toy has a price and size. We have to implement class CarToy and class PuzzleToy which inherit from class Toy.
2. Class ToyBox has a  pointer array to store a list of toys (up to 5 items including car and puzzle) and number of items in the box.

Your task is to implement two function addItem(…) in class ToyBox. If successfully added, the function returns the current number of toys in the box. If the box is full, return -1.

**For example:**

+ Test 1:
```cpp
CarToy car(20000,red);
PuzzleToy puzzle(30000,small);
car.printType();
puzzle.printType();
```
+ Result:
<br/>
This is a car toy
<br/>
This is a puzzle toy
<br/><br/>

+ Test 2:
```cpp
CarToy car(20000,red);
PuzzleToy puzzle(30000,small);

ToyBox box;
box.addItem(car);
box.addItem(puzzle);
box.printBox();
```
+ Result:
<br/>
This is a car toy
<br/>
This is a puzzle toy
<br/><br/>

+ Test 3:
```cpp
Toy* toy = new CarToy(30000,red);
toy->printType();
```
+ Result: This is a car toy
