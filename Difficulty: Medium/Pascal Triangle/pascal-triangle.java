//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            ArrayList<Integer> ans = new Solution().nthRowOfPascalTriangle(n);
            printAns(ans);

            System.out.println("~");
        }
    }

    public static void printAns(ArrayList<Integer> ans) {
        for (Integer x : ans) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {

    ArrayList<Integer> nthRowOfPascalTriangle(int n) {
        // code here
         ArrayList<Integer> a = null;
        ArrayList<Integer> prev = null;
        for(int x=1;x<=n;x++){
            a = new ArrayList<>();
            for(int y=0;y<x;y++){
                if(y==0 || y==x-1){
                    a.add(1);
                }else{
                    a.add(prev.get(y-1) + prev.get(y));
                }
            }
            prev = a;
        }
        return a;
    }
}