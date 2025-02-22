//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int maxLength(string& s) {
        // code here
        int n=s.length();
        int op=0, cl=0, maxi=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='(') op++;
            else cl++;
            
            if(op==cl){
                maxi=max(maxi, 2*min(op, cl));
            }else if(cl>op){
                cl=op=0;
            }
        }
        op=cl=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]==')') cl++;
            else op++;
            
            if(op==cl){
                maxi=max(maxi, 2*min(op, cl));
            }else if(op>cl){
                op=cl=0;
            }
        }
        
        return maxi;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends