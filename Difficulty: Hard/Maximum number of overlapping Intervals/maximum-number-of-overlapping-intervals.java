class Solution {
    public static int overlapInt(int[][] arr) {
        // code here
          int n =  arr.length;
          TreeMap<Integer,Integer>map =  new TreeMap<>();
          for(int []interval : arr){
               map.put(interval[0],map.getOrDefault(interval[0],0)+1);
               map.put(interval[1]+1,map.getOrDefault(interval[1]+1,0)-1);
          }
          int count = 0, ans = 0;
          for(int  chnage : map.values()){
              count+=chnage;
              ans = Math.max(ans,count);
          }
          return ans;
    }
}

