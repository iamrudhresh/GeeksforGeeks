class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> oddIndices;  //stores all odd element indices.
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2)
                oddIndices.push_back(i);
        }
        int i=0;
        int j=k-1;
        int ans=0;
        while(j<oddIndices.size()){
            int a, b;
            if(i==0)
                a=oddIndices[i]+1;
            else
                a = oddIndices[i]-oddIndices[i-1];
            if(j==oddIndices.size()-1)
                b=arr.size()-oddIndices[j];
            else
                b = oddIndices[j+1]-oddIndices[j];
            ans+=a*b;
            i++;
            j++;
        }
        return ans;
    }
};