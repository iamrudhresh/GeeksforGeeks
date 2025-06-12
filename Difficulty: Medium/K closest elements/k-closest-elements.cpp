class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
          vector<int> ans;
        int j = (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        int i = j-1;
        if(arr[j] == x) j++;
        while(k > 0 && i >= 0 && j < arr.size()){
            if(x-arr[i] >= arr[j]-x)    ans.push_back(arr[j++]);
            else    ans.push_back(arr[i--]);
            k--;
        }
        while(k > 0 && i >= 0){
            ans.push_back(arr[i--]);
            k--;
        }
        while(k > 0 && j < arr.size()){
            ans.push_back(arr[j++]);
            k--;
        }
        return ans;
    }
};