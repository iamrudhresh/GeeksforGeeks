class Solution {
  public:
    int dp[46];
    int solve(int n){
        if(n==1)  return 1;
        if(n==2)  return 2;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= solve(n-1)+solve(n-2); 
    }
    int numberOfWays(int n) {
        // --brute-Force-- 
        // memset(dp,-1,sizeof(dp));
        // return solve(n);
        // --Optimised-- 
        if(n==1) return 1;
        int a=1;
        int b=2;
        for(int i=3;i<=n;i++){
            int curr=a+b;
            a=b;
            b=curr;
        }
        return b;
    }
};
// 1 2 3 5 