//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            List<Integer> nums = new ArrayList<>();
            for (String part : parts) {
                nums.add(Integer.parseInt(part));
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
// } Driver Code Ends


class Solution {
    // Function to find the majority elements in the array
  public List<Integer> findMajority(List<Integer> nums) {
        int one_third=0;
        if(nums.size()>5){
        one_third=nums.size()/3;
        }
        else if(nums.size()>2){
            one_third=1;
        }
        else{
            one_third=0;
        }
        List<Integer> l=new ArrayList<>();
        HashMap<Integer,Integer> hm=new HashMap<>();
        for(int i=0;i<nums.size();i++){
            if(hm.containsKey(nums.get(i))){
                hm.put(nums.get(i),hm.get(nums.get(i))+1);
            }
            else{
                hm.put(nums.get(i),1);
            }
        }
        for(Map.Entry<Integer,Integer> entry:hm.entrySet()){
            if(entry.getValue()>one_third){
                l.add(entry.getKey());
            }
        }
        if(l.size()>=1){
        return l;
        }
        else{
            l.add(-1);
        }
        return l;
    }
}
