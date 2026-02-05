class Solution {
    public int maxOnes(int arr[], int k) {
        int l=0,zeroes=0,maxlen=0,n=arr.length;
        for(int r=0;r<n;r++) {
            if(arr[r]==0) zeroes++;
            while(zeroes>k) {
                if(arr[l]==0) zeroes--;
                l++;
            }
            maxlen=Math.max(maxlen,r-l+1);
        }
        return maxlen;
    }
}