class Solution {
  public:
   int n;
    int dp[51][51][51];
    
    int solve(int i1, int j1, int i2, vector<vector<int>>& mat) {
        int j2 = i1 + j1 - i2;
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n ||
            mat[i1][j1] == -1 || mat[i2][j2] == -1)
            return INT_MIN;

        if (i1 == n - 1 && j1 == n - 1)
            return mat[i1][j1];

        if (dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];

        int chocolates = 0;
        if (i1 == i2 && j1 == j2)
            chocolates += mat[i1][j1];
        else
            chocolates += mat[i1][j1] + mat[i2][j2];

        int bestNext = max({
            solve(i1 + 1, j1, i2 + 1, mat),
            solve(i1, j1 + 1, i2, mat),
            solve(i1 + 1, j1, i2, mat),
            solve(i1, j1 + 1, i2 + 1, mat)
        });

        chocolates += bestNext;
        return dp[i1][j1][i2] = chocolates;
    }

    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, mat);
        return ans<=0?0:ans;
    }
};