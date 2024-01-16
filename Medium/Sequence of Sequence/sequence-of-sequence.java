//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line[] = read.readLine().trim().split("\\s+");
            int m = Integer.parseInt(input_line[0]);
            int n = Integer.parseInt(input_line[1]);
            
            Solution ob = new Solution();
            System.out.println(ob.numberSequence(m, n));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution{
    public int numberSequence(int m, int n)
    {
        // code here
        /*
        states keep track of if index and last number in special sequence
        want dp(0,1)
        if we get to the end and last number is at most n, then we are good
        for the last number in the sequence we need to try all [2*last up to m]
        cache states
        */
        int[][] memo = new int[m+1][n+1];
        for (int i = 0; i <= m; i++){
            Arrays.fill(memo[i],-1);
        }
        
        int ways = 0;
        for (int i = 1; i <= m; i++){
            ways += dp(1,i,m,n,memo);
        }
        return ways;
    }
    public int dp(int i, int last_num, int m, int n, int[][] memo){
        if (i >= n){
            if (last_num <= m){
                return 1;
            }
            return 0;
        }
        
        if (last_num > m){
            return 0;
        }
        
        if (memo[last_num][i] != -1){
            return memo[last_num][i];
        }
        
        int ways = 0;
        for (int next_num = 2*last_num; next_num <= m; next_num++){
            ways += dp(i+1,next_num,m,n,memo);
        }
        memo[last_num][i] = ways;
        return ways;
    }
}