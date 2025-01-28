//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void substrings(string &s,vector<string>&ans,int index)
    {
        int n=s.size();
        if(index>=n)//base condn
        {
            ans.push_back(s);
            return;
        }
        unordered_set<char> used;
        for(int i=index;i<n;i++)
        {
            if(used.find(s[i])!=used.end())
                continue; //if not used np insert it if not take the next index
            used.insert(s[i]);
            swap(s[i],s[index]);
            substrings(s,ans,index+1);
            swap(s[i],s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string>ans;
        int index=0;
        substrings(s,ans,0);
        return ans;        // Code here there
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends