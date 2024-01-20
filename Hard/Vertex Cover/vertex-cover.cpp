//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <utility>

using namespace std;

class Solution {
private:
    vector<vector<int>> adj;

    bool isPossible(int n, int m, int mid) {
        int set = (1 << mid) - 1;
        int limit = (1 << n);

        while (set < limit) {
            bool vis[n + 1][n + 1] = {0};
            int edgeCovered = 0;

            for (int j = 1, u = 1; j < limit; j = j << 1, u++) {
                if (set & j) {
                    for (int v = 1; v <= n; v++) {
                        if (adj[u][v] && !vis[u][v]) {
                            edgeCovered++;
                            vis[u][v] = 1;
                            vis[v][u] = 1;
                        }
                    }
                }
            }

            if (edgeCovered == m)
                return true;

            int rightMostSetBit = set & -set;
            int val = set + rightMostSetBit;
            set = (((val ^ set) >> 2) / rightMostSetBit) | val;
        }
        return false;
    }

public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        int m = edges.size();
        adj.resize(n + 1, vector<int>(n + 1));

        for (auto v : edges) {
            adj[v.first][v.second] = 1;
            adj[v.second][v.first] = 1;
        }

        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (isPossible(n, m, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends