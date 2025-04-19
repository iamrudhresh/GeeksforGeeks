//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine();
            String[] S = s.split(" ");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maxXor(arr));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int maxXor(int[] arr) {
        // code here
           int mask=0, max=0;
        for(int i=31;i>=0;i--){
            mask=mask | (1<<i);
            Set<Integer> set= new HashSet<>();
            for(int n:arr)
                set.add(mask & n);
               
            int tmp = max | (1<< i);
            for(int prefix : set){
                if(set.contains(tmp ^ prefix)){
                    max = tmp;
                    break ;
                }
            }
        }
        return max;
    }
}