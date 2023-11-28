//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N, M, x, y;
            String S[] = read.readLine().split(" ");
            N = Integer.parseInt(S[0]);
            M = Integer.parseInt(S[1]);
            ArrayList<ArrayList<Integer>> adj =
                new ArrayList<ArrayList<Integer>>(N);
            for (int i = 0; i < N; i++) adj.add(new ArrayList<Integer>());
            String S1[] = read.readLine().split(" ");
            for (int i = 0; i < 2 * M; i += 2) {
                x = Integer.parseInt(S1[i]);
                y = Integer.parseInt(S1[i + 1]);
                adj.get(x).add(y);
            }
            Solution ob = new Solution();
            System.out.println(ob.sumOfDependencies(adj, N));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int sumOfDependencies(ArrayList<ArrayList<Integer>> adj, int v) {
        int sum = 0;
        for (ArrayList<Integer> list: adj) sum += list.size();
        
        return sum;
    }
};