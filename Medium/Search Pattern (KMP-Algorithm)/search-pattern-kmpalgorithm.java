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
            String s, patt;
            s = sc.next();
            patt = sc.next();
            
            Solution ob = new Solution();
            
            ArrayList<Integer> res = ob.search(patt, s);
            if(res.size()==0)
                System.out.print(-1);
            else {
                for(int i = 0;i<res.size();i++)
                    System.out.print(res.get(i) + " ");
            }
            System.out.println();    
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    
    ArrayList<Integer> search(String pat, String txt)
    {
        ArrayList<Integer> ans = new ArrayList<>();
        int len = txt.length()-pat.length();
        for(int i=0;i<=len;i++){
            if(txt.charAt(i)!=pat.charAt(0)){
                continue;
            }else{
                //check first and last character of the substring if it match then enter 
                //nested if condition.
                if(txt.charAt(i) == pat.charAt(0) && 
                        txt.charAt(i+pat.length()-1) == pat.charAt(pat.length()-1)){
                    if(txt.substring(i,i+pat.length()).equals(pat)){
                        ans.add(i+1);
                    }
                }
            }
        }
        if(ans==null){
            ans.add(-1);
        }
        return ans;
    }
}