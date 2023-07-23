//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void speedBreaker(double a, int b){
        // code here
        cout<<fixed<<setprecision(b)<<a<<endl;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        double a;
        cin >> a;
        int b;
        cin >> b;
        Solution ob;
        ob.speedBreaker(a,b);
    }
    return 0;
}

// } Driver Code Ends