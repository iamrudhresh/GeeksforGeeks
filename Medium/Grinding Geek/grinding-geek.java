//{ Driver Code Starts
import java.util.*;
import java.io.*;

public class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0)
        {
            int n = scanner.nextInt();
            int total = scanner.nextInt();
            int[] cost = new int[n];
            for (int i = 0; i < n; i++) {
                cost[i] = scanner.nextInt();
            }
            Solution solution = new Solution();
            int result = solution.max_courses(n, total, cost);
            System.out.println(result);
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
       public static int rec(int i, int total, int[] cost, int[][] dp) {
        if (i >= cost.length || total <= 0) return 0;
        if (dp[i][total] != -1) return dp[i][total];
        int take = 0;
        int dontTake = 0;
        if (total >= cost[i]) take = 1 + rec(i + 1, total - cost[i] + (int) Math.floor(0.9 * cost[i]), cost, dp);
        dontTake = rec(i + 1, total, cost, dp);
        return dp[i][total] = Math.max(take, dontTake);
    }

    public static int max_courses(int n, int total, int[] cost) {
        int dp[][] = new int[n + 1][total + 1];
        for (int[] arr : dp) {
            Arrays.fill(arr, -1);
        }
        return rec(0, total, cost, dp);
    }
}

