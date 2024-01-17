//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> process;
    vector<vector<int>> ans;
    void permut(vector<int>&arr,vector<bool>&visited,vector<int>&process){
        if(process.size() == arr.size()){
            ans.push_back(process);
            return;
        }
        for(int i = 0;i<arr.size();i++){
            if(visited[i]) continue;
            if(i-1>=0 && arr[i-1]==arr[i]&&!visited[i-1]) continue;
            visited[i] = true;
            process.push_back(arr[i]);
            permut(arr,visited,process);
            process.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        vector<bool> visited(n,false);
        permut(arr,visited,process);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends