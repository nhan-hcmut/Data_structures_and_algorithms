#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
    public:
    int x, y;
    int dir;
    node(int i, int j) {
        x = i;
        y = j;
        // Initially direction set to 0
        dir = 0;
    }
};

bool canEatFood(int maze[5][5], int fx, int fy) {
    /*TODO*/
    bool visited[5][5] = {false};
    stack<node> record;
    node rat(0, 0);
    record.push(rat);

    while (!record.empty()) {
        node current = record.top();
        int curDir = current.dir, i = current.x, j = current.y;
        current.dir++;
        record.pop();
        record.push(current);
        if (i == fx && j == fy) return true;
        
        if (curDir == 0) {
            if (i > 0 && maze[i-1][j] && !visited[i-1][j]) {
                node next(i-1, j);
                visited[i-1][j] = true;
                record.push(next);
            }
        }
        else if (curDir == 1) {
            if (j > 0 && maze[i][j-1] && !visited[i][j-1]) {
                node next(i, j-1);
                visited[i][j-1] = true;
                record.push(next);
            }
        }
        else if (curDir == 2) {
            if (i < 4 && maze[i+1][j] && !visited[i+1][j]) {
                node next(i+1, j);
                visited[i+1][j] = true;
                record.push(next);
            }
        }
        else if (curDir == 3) {
            if (j < 4 && maze[i][j+1] && !visited[i][j+1]) {
                node next(i, j+1);
                visited[i][j+1] = true;
                record.push(next);
            }
        }
        else {
            visited[i][j] = true;
            record.pop();
        }
    }
    return false;
}

int main() {
    
    // test 1
    // Maze matrix
    int maze[5][5] = {
    { 1, 0, 1, 1, 0 },
    { 1, 1, 1, 0, 1 },
    { 0, 1, 0, 1, 1 },
    { 1, 1, 1, 1, 0 },
    { 1, 0, 0, 1, 0 }
    };

    // Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy); // result: 1
    
    /* test 2
    // Maze matrix
    int maze[5][5] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 0 },
        { 0, 1, 0, 1, 1 },
        { 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 0 }
    };

    // Food coordinates
    int fx = 2, fy = 3;

    cout << canEatFood(maze, fx, fy); // result: 1
    */
    return 0;
}
