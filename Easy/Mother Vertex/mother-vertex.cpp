//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i,set<int>&v2,vector<int>&vis,vector<int>adj[]){
        vis[i] = 1;
        v2.insert(i);
        for(auto adjNode : adj[i]){
            if(v2.find(adjNode)==v2.end()) dfs(adjNode,v2,vis,adj);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        set<int>v2;
	        if(!vis[i]){
	            dfs(i,v2,vis,adj);
	        }
	        if(v2.size()==V) return i;
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends