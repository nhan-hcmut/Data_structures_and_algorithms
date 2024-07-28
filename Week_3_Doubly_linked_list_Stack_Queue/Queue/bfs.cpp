#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int start) {
    int numberOfVertices = graph.size();
    bool* visited = new bool[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) visited[i] = false;

    queue<int> q;
    bool firstMeet = true;
    visited[start] = true;
    q.push(start);
    
    int walker;
    while(!q.empty()) {
        walker = q.front();
        
        if (firstMeet) {
            cout << walker;
            firstMeet = false;
        }
        else cout << " " << walker;
        q.pop();

        int outDegree = graph[walker].size();
        for (int i = 0; i < outDegree; i++) {
            int adjacentVertex = graph[walker][i];
            
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
    delete[] visited;
}

int main() {

	int init_graph[10][10] = { {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());

	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (init_graph[i][j]) graph[i].push_back(j);
        }
    }
    bfs(graph, 0); // result: 0 1 2 4 6 8 3 7 5 9
    return 0;
}
