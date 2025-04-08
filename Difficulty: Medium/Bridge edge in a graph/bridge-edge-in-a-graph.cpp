//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
              // Build the adjacency list
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Arrays for discovery time, low time, and visited state
        vector<int> discovery(V, -1);  // Discovery time
        vector<int> low(V, -1);        // Low time
        vector<bool> visited(V, false);
        int time = 0; // Time counter for DFS

        bool isBridgeEdge = false;

        // Helper function for DFS traversal
        function<void(int, int)> dfs = [&](int u, int parent) {
            visited[u] = true;
            discovery[u] = low[u] = time++;  // Set discovery time and low time for u

            for (int v : adj[u]) {
                if (!visited[v]) {
                    // If v is not visited, do DFS on v
                    dfs(v, u);
                    // After recursion, update the low[u] considering the back edge
                    low[u] = min(low[u], low[v]);

                    // Check if the edge (u, v) is a bridge
                    if (low[v] > discovery[u] && ((u == c && v == d) || (u == d && v == c))) {
                        isBridgeEdge = true; // This edge is a bridge
                    }
                } else if (v != parent) {
                    // If v is already visited and is not the parent of u, update low[u]
                    low[u] = min(low[u], discovery[v]);
                }
            }
        };

        // Run DFS for all unvisited nodes, as the graph may be disconnected
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1); // DFS starting from vertex i
            }
        }

        return isBridgeEdge;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends