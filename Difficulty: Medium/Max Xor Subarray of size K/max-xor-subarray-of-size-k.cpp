class Solution {
  public:
   int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int maxXor = INT_MIN;
        int currentXor = arr[0];
        
        int l = 0, r = 1;
        while(l<=n-k){
            if(r-l+1 > k){
                maxXor = max(maxXor, currentXor);
                currentXor ^= arr[l];
                l++;
            }
            currentXor ^= arr[r];
            r+=1;
        }
        if(maxXor == INT_MIN){
            return currentXor;
        }
        return maxXor;
    }
};