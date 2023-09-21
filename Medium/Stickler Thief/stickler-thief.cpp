//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int help(vector<int> &dp, int arr[], int n, int index)
    {
        if(index>n) return 0;
        if(index == n) return arr[n];
        if(dp[index] != -1) return dp[index];
        int include = help(dp, arr, n, index+2) + arr[index];
        int exclude = help(dp, arr, n, index+1) + 0;
        return dp[index] = max(include, exclude);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, -1);
        return help(dp, arr, n-1, 0);
    }


};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends