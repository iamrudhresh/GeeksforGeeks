class Solution {
  public:
    
    bool check(vector<int>& arr, int k, int threshold)
    {
        int cnt=0;
        
        for(int i=0;i<arr.size();i++)
        {
            cnt+=ceil(arr[i]/(double)threshold);
        }
        
        return cnt<=k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int maxValue=*max_element(arr.begin(),arr.end());
        
        int low=1,high=maxValue;
        int res=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(check(arr,k,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
        
    }
};
