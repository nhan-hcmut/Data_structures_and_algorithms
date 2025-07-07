# Recommended order:

1. `class Point` in Point.cpp

2. `class Circle` in Circle.cpp

3. `containsPoint(...)` and `containsTriangle(...)` in containsPoint_containsTriangle.cpp

4. Operators `=`, `==` and `>>` in Circle_overload_operators.cpp

5. `class Character` in Character.cpp

6. Operators `=`, `<` and `()` in Character_overload_operators.cpp

7. `class Player` in Player.cpp

8. `class Book` in Book.cpp

9. `friend bool checkAuthor(...)` in checkAuthor.cpp

10. `class Printer` in Printer.cpp

11. `class CarToy` -> `class PuzzleToy` -> `class ToyBox` in Toy.cpp

---
# class Book

Hoang is a K19 student studying at Bach Khoa University. He plans to write a book management software for the library. In the class design, Hoang has designed the `class Book` as follows:
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
Your task in this exercise is to implement the functions marked with `/* STUDENT ANSWER */`.

**<ins>Note</ins>:** `<bits/stdc++.h>` header and the `std` namespace are already included.

**<ins>For example</ins>:**
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
# class Character

In a game, we have `class Character` that stores the data of individual characters. The `class Character` is declared as follows:
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
Your task is to define the constructors and member methods of the `Character` class.

**<ins>Note</ins>:** In this task, the `<iostream>` library and the `std` namespace are already included. **<ins>No</ins>** additional libraries are allowed.

**<ins>For example</ins>:**
+ Test 1:
```cpp
Character ch1(100, 3, 6);
cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY() << endl; // Result: 100 3 6
```
<br/>

+ Test 2:
```cpp
Character ch2;
cout << ch2.getHp() << " " << ch2.getX() << " " << ch2.getY() << endl; // Result: 0 0 0
```
<br/>

+ Test 3:
```cpp
Character* ch31 = new Character(100, 1, 2);
Character* ch32 = new Character(100, -3, 4);
cout << ch31->getManhattanDistTo(ch32) << endl; // Result: 6
delete ch31;
delete ch32;
```
<br/>

+ Test 4:
```cpp
Character ch4;
ch4.setX(4);
cout << ch4.getX() << endl; // Result: 4
```
<br/>

+ Test 5:
```cpp
Character ch5;
ch5.setY(5);
cout << ch5.getY() << endl; // Result: 5
```
<br/>

+ Test 6:
```cpp
Character ch6;
ch6.setHp(6);
cout << ch6.getHp() << endl; // Result: 6
```

---
# Overload 3 operators in the Character class

In a game, we have `class Character` that stores the data of individual characters. The `class Character` is declared as follows:
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

    // Operator =: copy all data from Character other
    void operator=(const Character& other);

    // Operator <: Character a < Character b when a's hp is less than or equal b's hp
    bool operator<(const Character& other);

    // Operator () with zero parameters: print data of the instance with format: hp-x-y
    void operator()();
};
```
In this exercise, your task is to overload these 3 operators =, < and () of the Character class in the file "Character_overload_operators.cpp". Their functions are described above.

**<ins>Note</ins>:** In this task, the `<iostream>` library and the `std` namespace are already included. **<ins>No</ins>** additional libraries are allowed.

**<ins>For example</ins>:**
+ Test 1:
```cpp
Character ch1(100, 3, 6);
ch1(); // Result: 100-3-6
cout << endl;
```
+ Test 2:
```cpp
Character ch21(10, 20, 30);
Character ch22(5, 5, 6);
cout << ((ch21 < ch22) ? "true\n" : "false\n"); // Result: "false"
```
+ Test 3;
```cpp
Character ch31;
Character ch32;
cout << ((ch31 < ch32) ? "true\n" : "false\n"); // Result: "true"
```
+ Test 4:
```cpp
Character ch4;
ch4(); // Result: 0-0-0
cout << endl;
ch4 = Character(5, 10, 20);
ch4(); // Result: 5-10-20
cout << endl;
```
+ Test 5:
```cpp
Character(3, 4, 5)(); // Result: 3-4-5
cout << endl << ((Character(3, 4, 5) < Character(3, 4, 5)) ? "true\n" : "false\n"); // Result: false
```

---
# class Circle

In the coordinate plane, a circle is defined by its center and radius.

Your task in this exercise is to implement the functions marked with `/*  * STUDENT ANSWER   */`.

**<ins>Note</ins>:** you can use the `Point` class implemented in the previous question.

**<ins>For example</ins>:**
+ Test:
```cpp
Circle A;
A.printCircle();
```
+ Result: Center: {0.00, 0.00} and Radius 0.00

---
# Overload 3 operators in the Circle class

In this exercise, your task is to overload 3 operators =, == and >> of the Circle class in the file Circle_overload_operators.cpp:

1. Overload operator = (assignment operator): `void operator=(const Circle &circle);`

2. Overload operator == (Two circles are equal if they have the same center and radius): `bool operator==(const Circle &circle);`

3. Overload operator >> (stdin center.x, center.y, radius in order): `friend istream& operator >> (istream &in, Circle &circle);`

**<ins>For example</ins>:**
+ Test 1:
```cpp
Point pointO(0, 0);
Circle A = Circle(pointO, 3);
Circle B;
B = A;
cout << (B == A) << endl; // Result: 1
```
+ Test 2:
```cpp
Circle A;
cin >> A; // Input: 2 3.5 2
A.printCircle(); // Result: Center: {2.00, 3.50} and Radius 2.00
```

---
# class Player

In a game, we have `class Character` that stores the data of individual characters. The `class Character` is declared as follows:
```cpp
class Character {
private:
    int x;
    int y;
protected:
    int hp;
public:
    Character();
    Character(int hp, int x, int y);
    int getHp();
    void setHp(int hp);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getManhattanDistTo(Character* other);
    void operator()();
};
```
Your task is to define a new `class Player` which is a derived class of `class Character`. The requirements of the new class are listed below:

+ Methods of base `class Character` cannot be accessed outside `class Player` using `Player` instances. **<ins>Example</ins>:** `Player pl; pl.setX();` will raise errors when compiled.

+ `class Player` has these methods and constructors.
  + Constructor `Player()`: acts just like `Character()`
  + Constructor `Player(int hp, int x, int y)`: acts just like `Character(hp, x, y)`
  + Method `void printPlayerData()`: print data of the instance with format: hp-x-y
  + Method `void moveTo(int x, int y)`: set the values of x, y to new values
  + The constructors and methods mentioned above can be accessed outside `class Player`

**<ins>Note</ins>:** In this task, the `<iostream>` library and the `std` namespace are already included. **<ins>No</ins>** additional libraries are allowed.

**<ins>For example</ins>:**
+ Test 1:
```cpp
Player pl1(100, 3, 6);
pl1.printPlayerData(); // Result: 100-3-6
cout << endl;
```
+ Test 2:
```cpp
Player pl2;
pl2.printPlayerData(); // Result: 0-0-0
cout << endl;
```
+ Test 3:
```cpp
Player pl3(300, 1, 2);
pl3.moveTo(3, 4);
pl3.printPlayerData(); // Result: 300-3-4
cout << endl;
```
+ Test 4:
```cpp
Player pl4(300, 1, 2);
pl4.printPlayerData(); // Result: 300-1-2
cout << endl;
pl4.moveTo(2, 1);
pl4.printPlayerData(); // Result: 300-2-1
cout << endl;
```
+ Test 5:
```cpp
Player pl5(300, 1, 2);
pl5.moveTo(9, 7);
pl5.printPlayerData(); // Result: 300-9-7
cout << endl;
```
+ Test 6:
```cpp
Player pl;
//pl.setX(); // Result: Compile-time error
```

---
# class Point

In the coordinate plane, we have `class Point` to store a point with its x-y coordinate.

Your task in this exercise is to implement the functions marked with `/*  * STUDENT ANSWER   */`.

**<ins>Note</ins>:** The `<bits/stdc++.h>` header and the `std` namespace are already included.

**<ins>For example</ins>:**

+ Test 1:
```cpp
Point A(2, 3);
cout << A.getX() << " " << A.getY() << endl; // Result: 2 3
```
<br/>

+ Test 2:
```cpp
Point A(2, 3);
Point B(1, 1);
cout << pow(A.distanceToPoint(B), 2) << endl; // Result: 5
```

---
# Toy

1. In the toy store, all toys have a price. The car toy has a price and a color. The puzzle toy has a price and a size. We have to implement the `CarToy` and `PuzzleToy` classes which inherit from the `Toy` class.
2. The `ToyBox` class has a pointer array to store a list of toys (up to 5 items, including cars and puzzles) and a variable for the number of items in the box.

Your task is to implement two addItem(…) functions in the `ToyBox` class. If an item is successfully added, the function returns the current number of toys in the box. If the box is full, it returns -1.

The `<bits/stdc++.h>` header and the `std` namespace are already included.

**<ins>For example</ins>:**

+ Test 1:
```cpp
CarToy car(20000,red);
PuzzleToy puzzle(30000,small);
car.printType();
puzzle.printType();
// Result:
// This is a car toy
// This is a puzzle toy
```

+ Test 2:
```cpp
CarToy car(20000,red);
PuzzleToy puzzle(30000,small);

ToyBox box;
box.addItem(car);
box.addItem(puzzle);
box.printBox();
// Result:
// This is a car toy
// This is a puzzle toy
```

+ Test 3:
```cpp
Toy* toy = new CarToy(30000,red);
toy->printType(); // Result: This is a car toy
```

---
# `bool containsPoint(...);` and `bool containsTriangle(...);`

In this exercise, your task is to implement these 2 methods of the Circle class in the file containsPoint_containsTriangle.cpp

1. Implement method `bool containsPoint(const Point point);` to check if a given point is entirely within the circle or not (points on the circle do not count). If it is contained, return true.

2. Implement method `bool containsTriangle(const Point pointA, const Point pointB, const Point pointC);` to check if a given triangle ABC (where points A, B and C are not collinear) lies entirely within the circle or not (points on the circle do not count). If it is contained, return true.

**<ins>For example</ins>:**

+ Test 1:
```cpp
Point pointO(0, 2);
Point point1(1, 2);
Circle A = Circle(pointO, 2);
cout << A.containsPoint(point1) << endl; // Result: 1
```
+ Test 2:
```cpp
Point pointO(0, 0);
Point point1(1, 0), point2(-1, 0), point3(0, 3);
Circle A = Circle(pointO, 3);
cout << A.containsTriangle(point1, point2, point3) << endl; // Result: 0
```
