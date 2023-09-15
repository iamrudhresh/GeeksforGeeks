//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool helper(int arr[],int ind,int target,vector<vector<int>>&dp)
    {
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool take = false;
        
        if(arr[ind] <= target)
        take = helper(arr,ind-1,target-arr[ind],dp);
        
        bool nottake = false;
        nottake = helper(arr,ind-1,target,dp);
        return dp[ind][target] = (take or nottake);
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++) sum += arr[i];
        if(sum%2) return 0;
        int target = sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return helper(arr,N-1,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends