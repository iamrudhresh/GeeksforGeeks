//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User functiom template for C++

class Solution {
  public:
    int BasicDataType(string s) {
        if(!isdigit(s[0]) and s[0] != '.')
            return sizeof(char);
        else if(s.find('.') == string::npos)
            return sizeof(int);
        else
            return (s.length() - s.find('.') - 1 ) < 6 ? sizeof(float) : sizeof(double);
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
        cout << ob.BasicDataType(S) << endl;
    }
}
// } Driver Code Ends