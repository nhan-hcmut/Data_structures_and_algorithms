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

    bool containsPoint(const Point point)
    {
        /*
         * STUDENT ANSWER
         * TODO: check if a given point is entirely within the circle (points on the circle do not count).
            If it is contained, return true.
        */
        
        if (this->center.distanceToPoint(point) < this->radius) return true;
        
        return false;
    }

    bool containsTriangle(const Point pointA, const Point pointB, const Point pointC)
    {
        /*
         * STUDENT ANSWER
         * TODO: check if a given triangle ABC (where points A, B and C are not collinear) lies entirely within the circle (points on the circle do not count).
             If it is contained, return true.
        */
        if (this->center.distanceToPoint(pointA) >= this->radius) return false;
        
        if (this->center.distanceToPoint(pointB) >= this->radius) return false;
        
        if (this->center.distanceToPoint(pointC) >= this->radius) return false;
        
        return true;
    }
};

int main() {

    // Test 1
    Point pointO(0, 2);
    Point point1(1, 2);
    Circle A = Circle(pointO, 2);
    cout << A.containsPoint(point1) << endl; // Result: 1
    
    // Test 2
    // Point pointO(0, 0);
    // Point point1(1, 0), point2(-1, 0), point3(0, 3);
    // Circle A = Circle(pointO, 3);
    // cout << A.containsTriangle(point1, point2, point3) << endl; // Result: 0

    return 0;
}
