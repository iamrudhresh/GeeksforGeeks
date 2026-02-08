class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = arr[0];
        int prevmini = 1,prevmaxi = 1,currmaxi = arr[0],currmini = arr[0];
        for(int i = 1;i<n;i++)
        {
           prevmini = currmini;
           prevmaxi = currmaxi;
           currmaxi = max({arr[i],arr[i]*prevmaxi,arr[i]*prevmini});
           currmini = min({arr[i],arr[i]*prevmaxi,arr[i]*prevmini});
           ans = max(ans,currmaxi);        
            
        }
      
        return ans;
    }
};