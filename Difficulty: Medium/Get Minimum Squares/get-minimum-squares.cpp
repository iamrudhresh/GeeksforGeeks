class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n+1, INT_MAX);       // dp[i] denoting min num of perfect squares to make sum i
        dp[0] = 0;
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=i; j++) {
                dp[i] = min(dp[i], dp[i-(j*j)]+1);      // checking already calculated perfect squares less than i
            }
        }
        
        return dp[n];
    }
};