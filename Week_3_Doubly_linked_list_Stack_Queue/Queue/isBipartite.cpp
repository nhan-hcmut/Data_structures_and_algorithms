#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int numberOfVertices = graph.size();
    enum Color {RED, GREEN, BLUE};
    vector<Color> colorVtr(numberOfVertices, RED);
    
    colorVtr[0] = GREEN;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int walker = q.front(), outDegree = graph[walker].size();
        q.pop();
        
        for (int a = 0; a < outDegree; a++) {
            int adjacentVertex = graph[walker][a];
            
            if (colorVtr[adjacentVertex] == RED) {
                colorVtr[adjacentVertex] = (colorVtr[walker] == GREEN) ? BLUE : GREEN;
                q.push(adjacentVertex);
            }
            else if (colorVtr[adjacentVertex] == colorVtr[walker]) return false;
        }
    }
    return true;
}

int main() {

    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G[i][j]) graph[i].push_back(j);
            }
        }
    isBipartite(graph) ? cout << "Yes" : cout << "No"; // result: Yes
    return 0;
}