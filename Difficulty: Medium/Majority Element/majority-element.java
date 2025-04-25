//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().majorityElement(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int majorityElement(int arr[]) {
        // code here
          Arrays.sort(arr);
        int len = arr.length;
        if(len == 1)
        {
            return arr[0];
        }
        int max = 1;
        int majority = arr[0];
        int count =1;
        for(int i=1;i<len;i++)
        {
            if(arr[i]==arr[i-1])
            {
                count+=1;
            }
            else
            {
                count=1;
            }
            if(count>max)
            {
                max=count;
                majority=arr[i];
            }
        }
        if(max>len/2 )
        {
            return majority;
        }
        else
        {
            return -1;
        }
    }
}