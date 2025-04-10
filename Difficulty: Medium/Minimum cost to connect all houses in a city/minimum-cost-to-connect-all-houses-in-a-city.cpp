//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
           // code here
        int n = houses.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> vis(n, 0);
        pq.push({0, 0});
        int sum =0; 
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int wt = node.first;
            int ind = node.second;
            if (vis[ind]) continue;
    
            vis[ind] = 1;
            sum += wt;
    
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int newWt = abs(houses[ind][0] - houses[i][0]) + abs(houses[ind][1] - houses[i][1]);
                    pq.push({newWt, i});
                }
            }
        }
        
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends