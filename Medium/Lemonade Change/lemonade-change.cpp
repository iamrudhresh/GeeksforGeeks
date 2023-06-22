//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        unordered_map<int,int>mp;
        for(auto x: bills)
        {
            int req = x - 5;
            
            while(req/10 > 0 && mp[10]>0)
            {
                mp[10]--;
                req = req - 10;
            }
            while(req/5 > 0 && mp[5]>0)
            {
                mp[5]--;
                req = req - 5;
            }
            mp[x]++;
            if(req > 0) return false; 
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends