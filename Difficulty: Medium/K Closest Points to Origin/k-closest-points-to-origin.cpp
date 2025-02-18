//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int,int>> pq; //max-heap
        
        int n=points.size();
        
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int d = x*x + y*y;
            
            pq.push({d,i});
            
            if(pq.size()>k)
            pq.pop();
        }
        
        vector<vector<int>> res;
        
        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            res.push_back({points[i][0],points[i][1]});
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends