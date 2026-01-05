class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum=0;
        for(int itr =0;itr<k;itr++){
            sum+=arr[itr];
        }
        int maxi = sum;
        for(int itr=k,i=0;itr<arr.size();itr++,i++){
            sum+=arr[itr];
            sum-=arr[i];
            maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};

