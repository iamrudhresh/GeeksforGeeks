//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
        {
            // your code here
            vector< vector< vector<int> >  >dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
            function<int(int,int,int)>f=[&](int i,int j,int k)->int{
              
              if(i<0||j<0||k<0)
              return 0;
              
              
              
              if(dp[i][j][k]!=-1)
              return dp[i][j][k];
              int res=0;
              if(a[i]==b[j] && b[j]==c[k])
              {
                  res=1+f(i-1,j-1,k-1);
              }
              else if(a[i]==b[j])
              {
                  res=max(res,f(i,j,k-1));
              }
              else if(a[i]==c[k])
              {
                  res=max(res,f(i,j-1,k));
              }
              else if(b[j]==c[k])
              {
                  res=max(res,f(i-1,j,k));
              }
              int x=f(i,j-1,k-1);
              int y=f(i-1,j,k-1);
              int z=f(i-1,j-1,k);
              
              res=max({x,y,z,res});
              
              
            return dp[i][j][k]=res;
            };
            
            
            return f(n1-1,n2-1,n3-1);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends