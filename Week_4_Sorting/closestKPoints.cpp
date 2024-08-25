#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
    public:
    int x, y;
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void display() {
        cout << "(" << this->x << ", " << this->y << ")";
    }
};

/* Your helping functions go here */
// Calculate Euclidean distance between two points
double calculateDistance(const Point &point1, const Point &point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
/* End helping functions */

void closestKPoints(Point points[], int n, Point &des_point, int k) {
    //TODO

    // selection sort
    for (short i = 0; i < n - 1; i++) {
        double minDistance = calculateDistance(des_point, points[i]);
        short idxOfMin = i;
        
        for (short j = i + 1; j < n; j++) {
            if (calculateDistance(des_point, points[j]) < minDistance) {
                minDistance = calculateDistance(des_point, points[j]);
                idxOfMin = j;
            }
        }
        int tempX = points[i].x, tempY = points[i].y;
        
        points[i].x = points[idxOfMin].x;
        points[i].y = points[idxOfMin].y;
        
        points[idxOfMin].x = tempX;
        points[idxOfMin].y = tempY;
    }
    // End selection sort
    
    for (short i = 0; i < k && i < n; i++) {
        points[i].display();
        cout << endl;
    }
}

int main() {
    
    // Test 1
    Point points[] = {{3, 3}, {5, -1}, {-2, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    int k = 2;
    Point des_point = {0, 2};
    closestKPoints(points, n, des_point, k);

    /* Result:
    (-2, 4)
    (3, 3)
    */

    /* Test 2
    Point points[] = {{3, 3}, {5, -1}, {-2, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    int k = 3;
    Point des_point = {0, 2};
    closestKPoints(points, n, des_point, k);
    
    Result:
    (-2, 4)
    (3, 3)
    (5, -1)
    */
    return 0;
}
