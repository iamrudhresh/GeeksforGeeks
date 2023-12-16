//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
  
        
        int t = Integer.parseInt(br.readLine().trim()); 

        while(t > 0){
        	long n = Integer.parseInt(br.readLine().trim()); 
            Solution ob = new Solution();
            System.out.println(ob.countStr(n)); 
            t--;
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java
class Solution {
    static long countStr(long n) {
        // Initialize variables to count different combinations
        long countA = 1, countB = n, countC = n;
        long countAB = n * (n - 1); // Strings with 'a' and 'b'
        long countAC = countAB / 2; // Strings with 'a' and 'c'
        long countBC = countAC * (n - 2); // Strings with 'b' and 'c'

        // Sum up all the counts
        long total = countA + countB + countC + countAB + countAC + countBC;
        
        return total;
    }
}