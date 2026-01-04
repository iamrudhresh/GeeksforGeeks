class Solution {
    public void sort012(int[] arr) {
        // code here
        int l =0 , m=0 , e = arr.length -1;
        
        while(m<=e){
            if(arr[m]==0){
                arr[m] = arr[l];
                arr[l] = 0;
                l++; m++;
            }
            else if(arr[m] == 1){
                m++;
            }
            else{
                arr[m] = arr[e];
                arr[e] = 2;
                e--;
            }
        }
    }
}