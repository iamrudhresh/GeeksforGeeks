//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long findNthNumber(int n, int k) {
        long long low = 0, high = 1e18;
        dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(65, vector<long long>(65, -1)));
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long count = find(mid, k);
            if(count >= n)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    long long find(long long n, int k){
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }

    long long dpf(string s, int n, int tight, int k){
        if(k < 0)
            return 0;
        if(n == 0){
            return 1;
        }
        if(dp[tight][k][n] != -1)
            return dp[tight][k][n];
        int ub = (tight == 1 ? (int)(s[s.length() - n] - '0') : 1);
        long long ans = 0;
        for(int dig = 0; dig <= ub; dig++){
            if(dig == ub)
                ans += dpf(s, n - 1, tight, k - dig);
            else
                ans += dpf(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = ans;
    }

    void reset(){
        for(int i = 0; i < 65; i++){
            for(int j = 0; j < 65; j++){
                dp[0][i][j] = dp[1][i][j] = -1;
            }
        }
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends