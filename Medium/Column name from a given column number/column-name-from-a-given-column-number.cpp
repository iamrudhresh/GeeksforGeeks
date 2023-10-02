//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string help = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",ans = "";
        while(n){
            int p = n % 26;
            if(p == 0){
                ans += help[25];
                n /= 26;
                n--;
            }
            else{
                ans += help[p-1];
                n /= 26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends