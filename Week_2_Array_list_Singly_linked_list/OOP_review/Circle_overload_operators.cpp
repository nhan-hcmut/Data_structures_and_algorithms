#include <bits/stdc++.h>
using namespace std;

class Point {

private:
    double x, y;

public:
    Point()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero x-y coordinate
        */
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        /*
         * STUDENT ANSWER
        */
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        /*
         * STUDENT ANSWER
        */
        this->x = x;
    }

    void setY(double y)
    {
        /*
         * STUDENT ANSWER
        */
        this->y = y;
    }

    double getX() const
    {
        /*
         * STUDENT ANSWER
        */
        return this->x;
    }

    double getY() const
    {
        /*
         * STUDENT ANSWER
        */
        return this->y;
    }

    double distanceToPoint(const Point& pointA)
    {
        /*
         * STUDENT ANSWER
         * TODO: calculate the distance from this point to point A in the coordinate plane
        */
        return sqrt(pow(this->x - pointA.x, 2) + pow(this->y - pointA.y, 2));
    }
};


class Circle {

private:
    Point center;
    double radius;

public:
   Circle()
    {
        /*
         * STUDENT ANSWER
        */
        this->center.setX(0);
        this->center.setY(0);
        
        this->radius = 0;
    }

    Circle(Point center, double radius)
    {
        /*
         * STUDENT ANSWER
        */
        this->center = center;
        this->radius = radius;
    }
    
    double getRadius() const { return this->radius; }
    
    void setRadius(double radius) { this->radius = radius; }
    
    Point getCenter() const {
        return this->center;
    }
    
    void setCenter(Point &point) {
        this->center = point;
    }
    
    void operator=(const Circle &circle)
    {
        /*
         * STUDENT ANSWER
        */
        this->center = circle.center;
        this->radius = circle.radius;
    }

    bool operator==(const Circle &circle)
    {
        /*
         * STUDENT ANSWER
        */
        if (this->radius != circle.radius) return false;
         
        if (this->center.getX() != circle.center.getX()) return false;
         
        if (this->center.getY() != circle.center.getY()) return false;
         
        return true;
    }

    friend istream& operator >> (istream &in, Circle &circle);

    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

istream& operator >> (istream &in, Circle &circle) {
    /*
    * STUDENT ANSWER
    */
    double x, y;

    in >> x >> y >> circle.radius;

    circle.center.setX(x);

    circle.center.setY(y);

    return in;
}

int main() {

    // Test 1
    Point pointO(0, 0);
    Circle A = Circle(pointO, 3);
    Circle B;
    B = A;
    cout << (B == A) << endl; // Result: 1
    
    // Test 2
    // Circle A;
    // cin >> A; // Input: 2 3.5 2
    // A.printCircle(); // Result: Center: {2.00, 3.50} and Radius 2.00

    return 0;
}