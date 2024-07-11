# Character.cpp

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
+ Test:
```cpp
Character ch1(100, 3, 6);
cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();
```
+ Result: 100 3 6

---
# Circle.cpp

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
# Point.cpp

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
