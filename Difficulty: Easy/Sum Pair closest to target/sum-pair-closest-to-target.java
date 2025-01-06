//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String line = br.readLine();
            String[] tokens = line.split(" ");

            ArrayList<Integer> array = new ArrayList<>();

            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            int target = Integer.parseInt(br.readLine());

            Solution ob = new Solution();
            List<Integer> res = ob.sumClosest(arr, target);
            if (res.isEmpty()) {
                System.out.print("[]");
            } else {
                for (Integer num : res) {
                    System.out.print(num + " ");
                }
            }
            System.out.println();
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        // code here
            
       if(arr.length < 2) return new ArrayList<>();   
       
       Arrays.sort(arr);
       
       List<Integer> list = new ArrayList<>();
       
       int max = Integer.MAX_VALUE, i = 0, j = arr.length - 1;
       
       while(i < j){
           
           int add = arr[i] + arr[j];
           int sum = Math.abs(target - add);
           
           if(sum < max){
               max = sum;
               list = List.of(arr[i], arr[j]);
           }
           else if(sum == max && Math.abs(arr[j] - arr[i]) > (list.get(1) - list.get(0))){
               list = List.of(arr[i], arr[j]);
           }
           
           if(add > target){
               j--;
           }else if(add < target){
               i++;
           }else{
               break;
           }
       }
       
       return list;
    }
}