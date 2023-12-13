//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            long ans = new Solution().countStrings(n);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public static final long mod=(long)1e9+7;
    public long countStrings(int n1) {
        long prev0=1L;
        long prev1=1L;
        long curr0=0L;
        long curr1=0L;
        for(int n=1;n<=n1;n++){
            for(int prev=0;prev<2;prev++){
                if(prev==1) curr1=prev0%mod;
                else curr0=prev1%mod+prev0%mod;
            }
            prev0=curr0;
            prev1=curr1;
        }
        return curr0%mod;
    }
}