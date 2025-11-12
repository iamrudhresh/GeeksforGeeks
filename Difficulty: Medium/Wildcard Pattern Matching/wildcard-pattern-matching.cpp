class Solution {
  private:    
    bool solve(int i,int j,string &pat,string &txt,vector<vector<int>> &dp){
        //base case
        
        if(i==0 && j==0){
            return true;
        }
        if(i==0 && j>0){
            return false;
        }
        if(j==0 && i>0){
            for(int ind=1; ind<=i; ind++){
                if(pat[ind-1] != '*'){
                    return false;
                }
            }
            
            return true;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(pat[i-1]==txt[j - 1] || pat[i-1]=='?'){
            return dp[i][j] = solve(i-1,j-1,pat,txt,dp);
        } 
        else if(pat[i-1]=='*'){
            return dp[i][j] =solve(i,j-1,pat,txt,dp) || solve(i-1,j,pat,txt,dp) || solve(i-1,j-1,pat,txt,dp);
        } 
        else{
            return dp[i][j]=false;
        }
    }     
  public:
    bool wildCard(string &txt, string &pat) {
       // code here
       //1. Memoization
        // int n=pat.size();
        // int m=txt.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        // return solve(n,m,pat,txt,dp);
        
        
        
        //2.Tabulation
        
        // int n=pat.length();
        // int m=txt.length();
        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // dp[0][0]=true;
        
        // for(int ind2=1;ind2<=m;ind2++){
        //     dp[0][ind2]=false;
        // }
        
        // for(int ind1=1;ind1<=n;ind1++){
        //     bool flag=true;
        //     for(int i=1;i<ind1;i++){
        //         if(pat[i-1]!='*'){
        //             flag=false;
        //             break;
        //         }
        //     }
        //     dp[ind1][0]=flag;
            
        //     for(int ind2=1;ind2<=m;ind2++){
        //         if(pat[ind1-1]==txt[ind2-1] || pat[ind1-1]=='?'){
        //             dp[ind1][ind2]=dp[ind1-1][ind2-1];
        //         }
        //         else if(pat[ind1-1]=='*'){
        //             dp[ind1][ind2]=dp[ind1-1][ind2] || dp[ind1][ind2-1] || dp[ind1-1][ind2-1];
        //         }
        //         else{
        //             dp[ind1][ind2]=false;
        //         }
        //     }
        // }
        
        // return dp[n][m];
        
        
        //3.Space Optimised
        int n=pat.size();
        int m=txt.size();

        vector<bool> prev(m+1,false),curr(m+1,false);

        // Base case: empty pattern matches empty text
        prev[0]=true;

        for (int i=1; i<=n;i++) {
            // Check if all previous pattern chars are '*'
            bool allStars=true;
            for (int k = 1; k <= i; k++) {
                if (pat[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }
            curr[0] =allStars;

            for (int j=1; j<= m;j++) {
                if (pat[i-1]==txt[j-1] || pat[i-1]=='?'){
                    curr[j]=prev[j-1];
                } 
                else if (pat[i - 1] == '*') {
                    curr[j]=prev[j] || curr[j-1] || prev[j-1];
                } 
                else {
                    curr[j]=false;
                }
            }

            prev=curr;
        }

        return prev[m];
   
    }
};