//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.numberOfConsecutiveOnes(N));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static int numberOfConsecutiveOnes(int n) {
        // code here
            if(n == 2) return 1;
        int a = 0, b = 1;
        int ans = 1;
        int mod = 1_000_000_007;
        for(int i=3; i<=n; i++){
            int c = (a+b)%mod;
            a = b;
            b = c;
            ans = ((ans*2)%mod + c)%mod;
        }
        return ans;
    }
}
