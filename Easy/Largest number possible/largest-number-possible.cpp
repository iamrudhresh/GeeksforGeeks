//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        vector<int> v(N,9);
        int size = v.size()-1;
        int large = N*9;
        if(S>large || (S==0 && N>1)){
            return "-1";
        }
        while(large!=S){
            int val = large - S;
            if(val >= 9){
                v[size] = 0;
                size--;
                large = large - 9;
            }
            else{
                v[size] = v[size] - val;
                large = large - val;
            }
        }
        string ans = "";
        for(auto i:v){
            ans += to_string(i);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends