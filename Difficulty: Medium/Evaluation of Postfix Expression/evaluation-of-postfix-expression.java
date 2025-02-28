//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;


// } Driver Code Ends


class Solution {
    public int evaluate(String[] arr) {
        // code here
          Deque<Integer> operands = new ArrayDeque<>();
        int num1 = 0, num2 = 0;
        for(String el : arr){
            if(el.equals("+") || el.equals("-") || el.equals("*") || el.equals("/")){
                num2 = operands.pop();
                num1 = operands.pop();
            }
            if(el.equals("+")){
                operands.push(num1 + num2);
            }else if(el.equals("-")){
                operands.push(num1 - num2);
            }else if(el.equals("*")){
                operands.push(num1 * num2);
            }else if(el.equals("/")){
                operands.push(num1 / num2);
            }else{
                operands.push(Integer.parseInt(el));
            }
        }
        
        return operands.peek();
    }
}


//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int t = Integer.parseInt(line);
        while (t-- > 0) {
            line = reader.readLine();
            String[] arr = line.split(" ");
            Solution solution = new Solution();
            System.out.println(solution.evaluate(arr));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends