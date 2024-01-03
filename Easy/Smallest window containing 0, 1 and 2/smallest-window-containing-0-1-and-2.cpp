//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int ans=INT_MAX;
        int i=0,j=0,n=S.size();
        int a[3]={0};
        int cnt=0;
        while(j<n){
            a[S[j]-'0']++;
            if(a[(S[j]-'0')]==1) cnt++;
            if(cnt==3){
                ans=min(ans,j-i+1);
                while(cnt==3){
                    a[(S[i]-'0')]--;
                    if(a[(S[i]-'0')]==0) cnt--;
                    i++;
                    if(cnt==3) ans=min(ans,j-i+1);
                }
            }
            j++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends