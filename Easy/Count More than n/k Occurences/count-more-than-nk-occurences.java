//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Driverclass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            int k = sc.nextInt();

            System.out.println(new Solution().countOccurence(arr, n, k));
        }
    }
}

// } Driver Code Ends


class Solution 
{
    public int countOccurence(int[] arr, int n, int k) 
    {
        int ans=0;
       HashMap <Integer,Integer> h= new HashMap<>();
       for(int a:arr) h.put(a,h.getOrDefault(a,0)+1);
       for(int i:h.values()) if(i>(n/k))ans++;
       return ans;
    }
}


