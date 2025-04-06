//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
          
        // first we convert given edges into adjecent
        vector<int> adj[V];
        for(auto it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        
        // now we calculate in-degree of the nodes
        int inDegree[V] = {0};
        for(int i=0; i<V; i++) {
            for(auto it: adj[i])
                inDegree[it]++;
        }
        
        // then we push the node in queue who have in-degree value = 0
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        // now we approach through BFS
        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it: adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        return res;
    
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends