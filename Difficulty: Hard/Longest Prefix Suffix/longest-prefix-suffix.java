//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {

            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.lps(s));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
  int lps(String str) {
        int[] A = new int[str.length()];
        int j = 0, i = 1;
        while (i < str.length()) {
            if (str.charAt(i) == str.charAt(j)) {
                A[i] = j + 1;
                j++;
                i++;
            } else {
                if (j == 0)
                    i++;
                else
                    j = A[j - 1];
            }
        }

        return A[str.length() - 1];
    }
}