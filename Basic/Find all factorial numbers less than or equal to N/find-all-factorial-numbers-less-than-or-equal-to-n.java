//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            long N=sc.nextLong();
			
            Solution ob = new Solution();
            ArrayList<Long> ans = ob.factorialNumbers(N);
            for(long num : ans){
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    static ArrayList<Long> factorialNumbers(long N){
        ArrayList<Long> list = new ArrayList();
        for(long i=1; i<=N; i++){
            long factorial = factorial(i);
            if(factorial <= N){
                list.add(factorial);
            }else{
                break;
            }
        }
        return list;
    }
    
    static long factorial(long n){
        long fact = 1;
        for(long i=1; i<=n; i++){
            fact = fact * i;
        }
        return fact;
    }
}