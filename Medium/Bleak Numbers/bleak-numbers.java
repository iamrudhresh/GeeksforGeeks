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
            int ans = ob.is_bleak(n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
public int is_bleak(int n)
    {
        // Code here
        int maxBits = (int) (Math.log(n) / Math.log(2)) + 1;
        int limit = Math.min(n, maxBits * 2);
        for (int x = n - limit; x < n; x++) {
        if (x + Integer.bitCount(x) == n) {
            return 0;
        }
    }
    
    return 1;
     
    }
}