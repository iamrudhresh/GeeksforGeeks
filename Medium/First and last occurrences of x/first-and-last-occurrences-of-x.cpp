//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
void helper(int arr[],int left, int right, int x, vector<int> &ans){
        if(left > right)
            return;
            
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == x){
            if(ans[0] == -1 && ans[1] == -1){
                ans[0] = mid;
                ans[1] = mid;
            }else{
                ans[0] = min(ans[0], mid);
                ans[1] = max(ans[1], mid);
            }
            
            helper(arr, left, mid - 1, x, ans);
            helper(arr, mid + 1, right, x, ans);
        }
        else if(arr[mid] < x)
            helper(arr, mid + 1, right, x, ans);
        else
            helper(arr, left, mid - 1, x, ans);
    }
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2,-1);
        helper(arr, 0, n-1, x, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends