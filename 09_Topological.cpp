#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    vector<int> topoOrder;
    queue<int> q;

    // Calculate in-degrees of all vertices
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Add all vertices with zero in-degree to the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process each vertex in the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check for cycles (if topoOrder does not contain all vertices)
    if (topoOrder.size() != V) {
        cout << "The graph contains a cycle." << endl;
        return {};
    }

    return topoOrder;
}

int main() {
    int V = 6;
    vector<vector<int>> adj = {
        {2, 3},
        {3, 4},
        {},
        {5},
        {5},
        {}
    };

    vector<int> topoOrder = topologicalSortKahn(V, adj);

    if (!topoOrder.empty()) {
        cout << "Topological Order (BFS): ";
        for (int v : topoOrder) {
            cout << v << " ";
        }
    }

    return 0;
}
