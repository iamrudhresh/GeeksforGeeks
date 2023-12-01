//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            
            Solution ob = new Solution();
            System.out.println(ob.isRepresentingBST(arr, N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
 static int isRepresentingBST(int arr[], int N){
       if(N == 0){
            return 1;
       }
        for(int i = 0; i <= N - 2;i++){
            if(arr[i] > arr[i+1]){
                return 0;
            }
        }
        return 1;
 }
}