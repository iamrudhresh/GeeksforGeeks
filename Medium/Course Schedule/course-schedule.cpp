//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n], indegree(n), topo;
        for(auto i: prerequisites) 
            adj[i[1]].push_back(i[0]);
            
        for(int i = 0; i < n; i++) 
        {
            for(auto j: adj[i])
                indegree[j]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
                
        while(!q.empty()) 
        {
            auto p = q.front();
            q.pop();
            
            topo.push_back(p);
            for(auto v: adj[p]) 
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        
        return topo.size() != n ? vector<int>() : topo;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends