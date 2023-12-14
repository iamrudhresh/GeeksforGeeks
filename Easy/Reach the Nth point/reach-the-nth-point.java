//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.nthPoint(n);
            System.out.println(ans);            
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
     public int nthPoint(int n)
    {
        // Code here
        int MOD = 1000000007; 
        if(n==1 || n==2 || n==3) return n;
        int a = 2, b=3, c=0;
        for(int i=4; i<=n; i++){
            c = (a+b)%MOD;
            a=b;
            b = c;
        }
        return b%MOD;
    }
}