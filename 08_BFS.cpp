#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Simple BFS function that traverses a graph represented by adjacency matrix
void BFS(vector<vector<int>> graph, int start) {
    int V = graph.size();  // Number of vertices
    vector<bool> visited(V, false);  // Track visited nodes
    queue<int> q;  // Queue for BFS

    // Start with the first node
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";  // Print current node
        q.pop();
        
        // Check all adjacent vertices
        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    // Create a simple graph using adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 0},  // Node 0 is connected to 1 and 2
        {1, 0, 0, 1},  // Node 1 is connected to 0 and 3
        {1, 0, 0, 1},  // Node 2 is connected to 0 and 3
        {0, 1, 1, 0}   // Node 3 is connected to 1 and 2
    };

    cout << "BFS starting from vertex 0: ";
    BFS(graph, 0);
    
    return 0;
}
