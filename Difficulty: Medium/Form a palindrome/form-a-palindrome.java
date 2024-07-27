//{ Driver Code Starts
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String str = read.readLine();

            Solution ob = new Solution();
            
            System.out.println(ob.countMin(str));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
static int countMin(String str) {
        int n = str.length();
        int[][] dp = new int[n][n];

        for (int gap = 1; gap < n; gap++) {
            for (int l = 0, h = gap; h < n; l++, h++) {
                if (str.charAt(l) == str.charAt(h)) {
                    dp[l][h] = dp[l + 1][h - 1];
                } else {
                    dp[l][h] = Math.min(dp[l][h - 1], dp[l + 1][h]) + 1;
                }
            }
        }
        return dp[0][n - 1];
}
}