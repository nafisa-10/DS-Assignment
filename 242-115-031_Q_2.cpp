#include <iostream>
using namespace std;
int main() {
    const int MAX = 100;  // maximum number of vertices
    int v,e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    int adjMatrix[MAX][MAX] = {0};  // adjacency matrix initialized to 0
    int adjList[MAX][MAX];           // adjacency list storage
    int degree[MAX] = {0};           // count of neighbors for each vertex

    cout << "Enter edges(u w): \n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;

        // Basic input validation
        if (u < 0 || u >= v || w < 0 || w >= v) {
            cout << "Invalid input " << v-1 << endl;
            i--;  // repeat this iteration
            continue;
        }
        // Update adjacency matrix (undirected graph)
        adjMatrix[u][w] = 1;
        adjMatrix[w][u] = 1;

        // Update adjacency list
        adjList[u][degree[u]] = w;
        degree[u]++;
        adjList[w][degree[w]] = u;
        degree[w]++;
    }
    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < v; i++) {
        cout << i << ": ";
        for (int j = 0; j < degree[i]; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
