//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007

class Solution
{
    public:
    
    int countWays(int n){
        vector<int> totalSteps(n+1, 0);
        totalSteps[0] = 1;
        for(int i{}; i<n; i++){
            for(int j{1}; j<=3; j++)
            if(i+j <= n){
                totalSteps[i+j] = (totalSteps[i] + totalSteps[i+j]) % MOD;
            }
        }
        
        return totalSteps[n];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends