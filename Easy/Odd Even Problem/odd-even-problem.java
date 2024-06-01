//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String s;
            s = br.readLine();

            Solution obj = new Solution();
            String res = obj.oddEven(s);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static String oddEven(String s) {
        // code here
            int[] evens = new int[26];
        int[] odds = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int alphaPos = c - (int)'a' + 1;
            // System.out.println(c + " " + alphaPos + " " + (alphaPos % 2 == 0));
            if (alphaPos % 2 == 0) evens[alphaPos - 1]++;
            else odds[alphaPos - 1]++;
        }
        
        int x = (int)Arrays.stream(evens).filter(i -> (i > 0) && (i % 2 == 0)).count();
        int y = (int)Arrays.stream(odds).filter(i -> (i > 0) && (i % 2 != 0)).count();
        // System.out.println(x + " " + y);
        
        if ((x + y) % 2 == 0) return "EVEN";
        return "ODD";
    }
}
