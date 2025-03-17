//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String input_line[] = read.readLine().trim().split("\\s+");
            int N = input_line.length;
            int arr[] = new int[N];
            for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(input_line[i]);
            int sum = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            if (ob.isSubsetSum(arr, sum))
                System.out.println("true");
            else
                System.out.println("false");

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {

       private static Boolean fun(int n,int arr[],int sum,int dp[][]){
        if(sum==0)
            return true;
        if(n==0){
            if(arr[0]==sum)
                return true;
            else
                return false;
        }
        if(dp[n][sum]!=-1)
            return dp[n][sum]==1;
        Boolean notTake=fun(n-1,arr,sum,dp);
        Boolean take=false;
        if(arr[n]<=sum)
            take=fun(n-1,arr,sum-arr[n],dp);
        dp[n][sum]=(notTake || take)?1:0;
        return take || notTake;
    } 
    static Boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n=arr.length;
        int dp[][]=new int[n][sum+1];
        for(int r[]:dp)
            Arrays.fill(r,-1);
        return fun(n-1,arr,sum,dp);
        
    }
}