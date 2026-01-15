class Solution {
    public int minCandy(int arr[]) {
        // code here
        int n = arr.length;
        
        int[] nums=new int[n];
        
        Arrays.fill(nums,1);
         
        for(int i =1;i<n;i++){
            if(arr[i]>arr[i-1])
                nums[i]=nums[i-1]+1;
        }
        
        for(int i =n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
                nums[i]=Math.max(nums[i],nums[i+1]+1);
        }
        
        int candysum =0;
        
        for(int x:nums){
            candysum +=x;
        }
        
        return candysum;
    }
}