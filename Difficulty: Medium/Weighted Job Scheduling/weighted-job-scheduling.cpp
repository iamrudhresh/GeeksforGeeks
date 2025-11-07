class Solution {
  public:
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
        int n = jobs.size();
        sort(jobs.begin(), jobs.end());
        
        vector<int> start(n);
        for (int i=0; i<n; i++) start[i] = jobs[i][0];
        
        vector<int> next(n);
        for (int i=0; i<n; i++) {
            int et = jobs[i][1];
            auto it = lower_bound(start.begin()+i+1, start.end(), et);
            if (it != start.end()) {
                next[i] = (int)(it-start.begin());
            }
            else next[i] = n;
        }
        
        vector<int> dp(n+1);
        
        dp[n] = 0;      // when no segment is selected
        
        // selecting segment in reverse order
        for (int i=n-1; i>=0; i--) {
            dp[i] = max(dp[i+1], jobs[i][2] + dp[next[i]]);
        }
        
        return dp[0];
    }
};