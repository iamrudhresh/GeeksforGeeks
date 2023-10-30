//{ Driver Code Starts
//Initial Template for Java

//Initial Template for Java

//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;


class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		
		// looping through all testcases
		while(testcases-- > 0){
		    String line = br.readLine();
		    String[] element = line.trim().split("\\s+");
		    int sizeOfArray = Integer.parseInt(element[0]);
		    
		    int arr [] = new int[sizeOfArray];
		    
		    line = br.readLine();
		    String[] elements = line.trim().split("\\s+");
		    for(int i = 0;i<sizeOfArray;i++){
		        arr[i] = Integer.parseInt(elements[i]);
		    }
		    
		    
		    Solution obj = new Solution();
		    long res = obj.sumXOR(arr, sizeOfArray);
		    System.out.println(res);
		}
	}
}



// } Driver Code Ends


//User function Template for Java

class Solution{
   
    // Function for finding maximum and value pair
    public long sumXOR (int arr[], int n) {
    // Create an array to store the counts for each bit position (31 bits)
    long[] v = new long[31];
    long ans = 0; // Initialize the answer variable

    for (int i = 0; i < n; i++) {
        long x = arr[i]; // Get the current element from the array
        for (int j = 0; j < 31; j++) {
            // Check if the current bit is set (1)
            if ((x & 1) == 1) {
                // Calculate 'a' as the difference between the current index 'i' and the count 'v[j]' for this bit
                long a = i - v[j];

                // Calculate 'res' as 'a' multiplied by 2^j (1 << j)
                long res = a * (1 << j);

                // Add 'res' to the answer
                ans += res;

                // Increment the count for this bit position
                v[j]++;
            } else {
                // If the current bit is not set, calculate 'a' as the count 'v[j]' for this bit
                long a = v[j];

                // Calculate 'res' as 'a' multiplied by 2^j (1 << j)
                long res = a * (1 << j);

                // Add 'res' to the answer
                ans += res;
            }
            // Right-shift 'x' to check the next bit position
            x >>= 1;
        }
    }
    return ans; // Return the final answer
    }
}


    
    



