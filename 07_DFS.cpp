#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal recursively
void DFSUtil(vector<vector<int>>& adj, int v, vector<bool>& visited) {
    // Mark current vertex as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Visit all adjacent vertices
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(adj, i, visited);
        }
    }
}

// Function to perform DFS traversal starting from vertex v
void DFS(vector<vector<int>>& adj, int V, int start) {
    // Create visited array and mark all vertices as not visited
    vector<bool> visited(V, false);

    // Call recursive DFS utility function
    DFSUtil(adj, start, visited);
}

int main() {
    // Number of vertices
    int V = 4;

    // Create adjacency list representation of graph
    vector<vector<int>> adj(V);

    // Add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    DFS(adj, V, 2);
    cout << endl;

    return 0;
}
