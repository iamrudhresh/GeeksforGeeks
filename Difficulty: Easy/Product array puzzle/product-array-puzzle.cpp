//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
               // code here
        int n = arr.size(), left = 1;
        vector<int> ans(n), suff(n + 1);
        suff[n] = 1;
        
        for (int i = n-1; i >= 0; i--) {
            suff[i] = arr[i] * suff[i + 1];
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = left * suff[i + 1];
            left *= arr[i];
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends