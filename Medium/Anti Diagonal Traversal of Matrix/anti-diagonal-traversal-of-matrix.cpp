//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void traverse(vector<vector<int>> matrix,int row,int col,vector<int>& ans){
        
        int n = matrix.size();
        while(row < n and col >= 0){
            ans.push_back(matrix[row][col]);
            row++;
            col--;
        }
    }
  
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> ans;
        int n = matrix.size();
        int row = 0;
        int col = 0;
        while( row < n and col < n){
            traverse(matrix,row,col,ans);
            if(col < n-1) col++;
            else row++;
        }
        
        return ans;
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends