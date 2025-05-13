//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
         if(r>n) return 0;
        if(r==0 || r==n) return 1;
        
        int r2=n-r,minr=min(r,r2),maxr=max(r,r2);
        long long  ans=1 ;int idx=2, rem=1;
        for(int i=n;i>maxr;i--)
        {
            ans*=i;
            if(rem!=1 && ans%rem==0) {ans/=rem; rem=1;}
            
            if(idx>minr) continue;
            else if(ans%idx==0) ans/=idx++;
            else rem*=idx++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends