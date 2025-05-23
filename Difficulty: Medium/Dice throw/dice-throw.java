class Solution {
    static int noOfWays(int m, int n, int x) {
        // code here
           // code here
        int[] dp = new int[x+1];
        dp[0] = 1;
        
        for(int dice = 1; dice <= n; dice++){
            int[] next = new int[x+1];
            for(int sum = 1; sum <= x; sum++){
                for(int face = 1; face <= m; face++){
                    if(sum - face >= 0){
                        next[sum] += dp[sum-face];
                    }
                }
            }
            dp = next;
        }
        return dp[x];
    }
};