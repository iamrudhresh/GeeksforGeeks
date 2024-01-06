//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            long a;
            a = Long.parseLong(br.readLine().trim());
            
            
            long b;
            b = Long.parseLong(br.readLine().trim());
            
            Solution obj = new Solution();
            long res = obj.sumOfPowers(a, b);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends



class Solution {
public static long sumOfPowers(long a, long b) {
        long sum = 0;
        for(long i = a; i<=b; i++){
            sum+=findPrime(i, 0);
        }
        return sum;
    }

    public static long findPrime(long a, long temp){
        long i = 2;
        while (i*i<=a && a>1) {
            if(a%i==0){
                a=a/i;
                temp++;
            }
            if(a%i!=0){
                i++;
            }
        }
        if(a!=1){
            temp++;
        }
        return temp;
    }
}
        
