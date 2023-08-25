//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
int longestKSubstr(string s, int k) {
        int N = s.size();
        int maxlen = -1 , unique = 0;
        vector<int> hash(26,0);
        for(int L=0,R=0;R<N;R++){
            unique += (++hash[s[R]-'a'] == 1);
            while(unique > k) unique -= (--hash[s[L++]-'a'] == 0);
            if(unique == k && L <= R) maxlen = max(maxlen,R-L+1);
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends