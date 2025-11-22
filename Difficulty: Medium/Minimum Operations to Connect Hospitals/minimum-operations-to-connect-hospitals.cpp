class Solution {
  public:
    vector<vector<int>> g;
    vector<int> vis;
    
    void dfs(int node, int cnt) {
        vis[node] = cnt;
    
        for(auto &x : g[node]) {
            if(!vis[x]) {
                dfs(x, cnt);
            }
        }
    }
    
    int minConnect(int V, vector<vector<int>>& edges) {
        if(edges.size() < V - 1) 
            return -1;
        
        g.resize(V);
        vis.resize(V, 0);

        for(auto &x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        int cnt = 0;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
               dfs(i, ++cnt);
            }
        }
        
        return cnt - 1;
    }
};