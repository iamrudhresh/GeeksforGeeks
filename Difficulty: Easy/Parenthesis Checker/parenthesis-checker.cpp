//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isleft(char lhs)
    {
        return lhs == '[' || lhs == '{' || lhs == '(';
    }
    
    bool isBalanced(string& s) {
        stack<char> st{};
        for(auto& i : s)
        {
            if ( isleft(i) )
                st.push(i);
            else if( st.empty())
                return false;
            else
            {
                if( i == ')')
                {
                    if( st.top() != '(')
                        return false;
                }
                else if( i == ']')
                 {
                     if( st.top() != '[')
                        return false;
                 }
                else if( i == '}')
                 {
                     if( st.top() != '{')
                        return false;
                 }
                st.pop();
            }
        }
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends