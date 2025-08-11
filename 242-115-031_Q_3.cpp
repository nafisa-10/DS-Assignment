#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Create adjacency list
    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Assuming undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    vector<bool> visited(vertices, false);
    queue<int> q;

    // Start BFS from  start
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal order: ";

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        // Explore all neighbors
        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
    return 0;
}
