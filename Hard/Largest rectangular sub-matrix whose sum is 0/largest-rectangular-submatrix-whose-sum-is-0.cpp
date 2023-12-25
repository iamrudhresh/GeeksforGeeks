//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
   pair<int,int> kadne(vector<int>& v)
    {
        int sum=0;
        int maxi=-1e9;
        int l=0;
        int r=-1;
        
        int s=0;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum>maxi)
            {
                maxi=sum;
                l=s;
                r=i;
            }
            
            if(sum<0)
            {
                sum=0;
                s=i+1;
            }
        }
        
        return {l,r};
    }
   vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
   {
      int m = a.size();
      int n = a[0].size();
      
      int left, right, up, down;
      left = right = up = down = 0;
      
      for(int i=0; i<n; i++){
          vector<int> arr(m, 0);
          
          for(int j=i; j<n; j++){
              for(int k=0; k<m; k++){
                  arr[k] += a[k][j];
              }
              
              
            // pair<int,int> ans=kadne(arr);
            // int l=ans.first;
            // int r=ans.second;
              unordered_map<long long, int> map;
              map[0] = -1;
              
              int l=0, r=0;
              long long sum = 0;
              
              for(int k=0; k<m; k++){
                  sum += arr[k];
                  
                  if(map.count(sum)){
                      if((k-map[sum]) > (r-l)){
                          l = map[sum]+1;
                          r = k+1;
                      }
                  }
                  else{
                      map[sum] = k;
                  }
              }
              
              if((j-i+1)*(r-l) > (right-left)*(down-up)){
                  up = l;
                  down = r;
                  left = i;
                  right = j+1;
              }
          }
      }
      
      vector<vector<int>> result;
      
      for(int i=up; i<down; i++){
          vector<int> arr;
          
          for(int j=left; j<right; j++){
              arr.push_back(a[i][j]);
          }
          
          result.push_back(arr);
      }
      
      return result;
  }
};

//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends