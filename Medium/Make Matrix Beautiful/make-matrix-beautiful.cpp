//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int>diff(n);
        int need = 0;
        //we can only inc. so,take diff and try to adjust row while adjust the row the column is also get affect
        // the sum of diff. in row and sum of diff. in col is equal ->by observation
        for(int i=0;i < matrix.size();i++)
        {
            int row_sum  = 0;
            int col_sum = 0;
            for(int j=0;j < matrix[0].size();j++)
            {
                row_sum += matrix[j][i];
                col_sum += matrix[i][j];
            }
            need = max({need,row_sum,col_sum});
            diff[i] = row_sum;
        }
        int ans = 0;
        for(auto curr:diff)
        {
            ans += need - curr;
        }
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends