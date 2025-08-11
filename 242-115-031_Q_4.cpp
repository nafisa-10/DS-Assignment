#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    vector<bool> visited(vertices, false);
    stack<int> s;

    s.push(start);

    cout << "DFS traversal order: ";

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (!visited[curr]) {
            cout << curr << " ";
            visited[curr] = true;

            // Push neighbors in reverse order for consistent traversal order
            for (int i = (int)adjList[curr].size() - 1; i >= 0; i--) {
                int neighbor = adjList[curr][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    cout << endl;
    return 0;
}
