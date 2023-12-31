//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N;
            N = Integer.parseInt(br.readLine());
            
            
            int[] coins = IntArray.input(br, N);
            
            Solution obj = new Solution();
            boolean res = obj.isPossible(N, coins);
            
            int _result_val = (res) ? 1 : 0;
            System.out.println(_result_val);
        }
    }
}

// } Driver Code Ends



class Solution {
    static Boolean[][] memo;

    static boolean find(int[] coins, int n, int accumulated) {
        if (n < 0) {
            return false;
        }

        if (memo[n][accumulated] != null) {
            return memo[n][accumulated];
        }

        int take = coins[n] + accumulated;
        int not = accumulated;

        if (take % 24 == 0 || take % 20 == 0 || take == 2024) {
            memo[n][accumulated] = true;
            return true;
        }

        memo[n][accumulated] = find(coins, n - 1, take) || find(coins, n - 1, not);
        return memo[n][accumulated];
    }

    public static boolean isPossible(int N, int[] coins) {
        memo = new Boolean[N][2025];
        
        // code here
        return find(coins, N - 1, 0);
    }
}
        
