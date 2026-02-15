class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        // your code here
        Collections.sort(arr);
        int min=Integer.MAX_VALUE;
        for(int i=0;i<arr.size()&& (m-1+i)<arr.size();i++){
            int t1 = arr.get(i);
            int t2= arr.get(m-1+i);
            int diff = t2-t1;
            if(diff<min){
                min= diff;
            }
        }
        return min;
        
        
    }
}