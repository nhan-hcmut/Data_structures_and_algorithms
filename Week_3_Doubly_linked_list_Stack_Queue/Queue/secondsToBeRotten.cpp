#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Hint: use breadth-first search

int secondsToBeRotten(vector<vector<int>>& grid) {
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n = grid.size(), m = grid[0].size(), freshApples = 0;
    queue<pair<int, int>> RottenApples;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 2) {
                RottenApples.push({r, c});
            }
            else if (grid[r][c] == 1) {
                freshApples++;
            }
        }
    }
    int time = 0;
    
    while (!RottenApples.empty()) {
        if (freshApples < 1) return time;
        int size = RottenApples.size();
        
        for (int rot = 0; rot < size; rot++) {
            pair<int, int> rottenApple = RottenApples.front();
            RottenApples.pop();

            for (int dir = 0; dir < 4; dir++) {
                int r = rottenApple.first + directions[dir][0], c = rottenApple.second + directions[dir][1];
                
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    freshApples--;
                    RottenApples.push({r, c});
                }
            }
        }
        if (!RottenApples.empty()) time++;
    }
    return (freshApples > 0) ? -1 : time;
}

int main() {

    // test 1
    int rows, cols;
    cin >> rows >> cols; // input: 1 4
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j]; // input: {2 2 0 1}
    }
    cout << secondsToBeRotten(grid); // result: -1
    
    /* test 2
    int rows, cols;
    cin >> rows >> cols; // input: 3 3
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j]; // input: {0 1 2} {0 1 2} {2 1 1}
    }
    cout << secondsToBeRotten(grid); // result: 1
    */
    return 0;
}
