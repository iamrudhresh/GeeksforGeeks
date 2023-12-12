//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String inline[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(inline[0]);
            int m = Integer.parseInt(inline[1]);
            String inline1[] = in.readLine().trim().split("\\s+");
            int M[][] = new int[n][m];
            for(int i = 0;i < n*m;i++){
                M[i/m][i%m] = Integer.parseInt(inline1[i]);
            }
            
            Solution ob = new Solution();
            System.out.println(ob.maxGold(n, m, M));
        }
    }
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int maxGold(int n, int m, int M[][]){
        int dp[][] = new int[n][m];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], -1);
        }
        
        return solve_dp( n, m, M);
    }
    
   
    
    static int solve_dp(int n, int m, int arr[][]){
        
        int dp[][] = new int[n][m];
        
        for(int j = m - 1; j >= 0; j--){
            for(int i = 0; i < n; i++){
                
                int d_up = (i - 1 >= 0 && j + 1 < m) ? dp[i - 1][j + 1] : 0;
                int right = (j + 1 < m) ? dp[i][j + 1] : 0;
                int d_down = (i + 1 < n && j + 1 < m) ? dp[i + 1][j + 1] : 0;
                
                dp[i][j] = arr[i][j] + Math.max(right, Math.max(d_up, d_down));
                
            }
        }
        
        int max = Integer.MIN_VALUE;
        
        for(int i = 0; i < n; i++){
            max = Math.max(max, dp[i][0]);
        }
        
        return max;
    }
}
