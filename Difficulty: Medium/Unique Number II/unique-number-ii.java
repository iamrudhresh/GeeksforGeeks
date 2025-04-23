//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.HashMap;


// } Driver Code Ends

class Solution {
    public int[] singleNum(int[] arr) {
        // Code here
         int xor = 0;
        for(int ele:arr){
            xor^=ele;
        }
        int shiftBit = 0;
        while(xor > 0){
            if((xor&1) > 0)break;
            shiftBit += 1;
            xor >>= 1;
        }
        int ele1 = 0;
        int ele2 = 0;
        for(int ele:arr){
            int bit = ((ele >> shiftBit)&1);
            if(bit==1){
                ele1^=ele;
            }
            else{
                ele2^=ele;
            }
        }
        int[] ans = new int[2];
        ans[0] = Math.min(ele1,ele2);
        ans[1] = Math.max(ele1,ele2);
        return ans;
    }
}


//{ Driver Code Starts.
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            // int k = Integer.parseInt(br.readLine());
            // Create Solution object and find closest sum
            Solution ob = new Solution();
            int[] ans = ob.singleNum(arr);

            // Print the result as a space-separated string
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println(); // New line after printing the results
            System.out.println("~");
        }
    }
}

// } Driver Code Ends