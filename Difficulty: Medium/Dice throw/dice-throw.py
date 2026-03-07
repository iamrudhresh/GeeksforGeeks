class Solution:
    def noOfWays(self, m, n, x):
        dp = [[0 for _ in range(x+1)] for _ in range(n+1)]
        
        dp[0][0] = 1
        
        for i in range(1, n+1): 
            for j in range(1, x+1):  
                for k in range(1, m+1):
                    if j >= k:
                        dp[i][j] += dp[i-1][j-k]
        
        return dp[n][x]