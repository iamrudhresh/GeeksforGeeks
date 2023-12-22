//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<N;i++) {
            v.push_back({{F[i],S[i]},i+1});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        int end = v[0].first.first;
        ans.push_back(v[0].second);
        for(int i=1;i<N;i++) {
            if(v[i].first.second>end) {
                end = v[i].first.first;
                ans.push_back(v[i].second);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends