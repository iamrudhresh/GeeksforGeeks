//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   vector<int> abc(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> x(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                x[i] = st.top();
            }

            st.push(i);
        }

        return x;
    }

    
    vector<int> xyz(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> y(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                y[i] = st.top();
            }

            st.push(i);
        }

        return y;
    }

    
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();  

        vector<int> x = abc(arr, n);    // x is prevSmaller
        vector<int> y = xyz(arr, n);    // y is nextsmaller
        vector<int> ans(n, 0);

        
        for (int i = 0; i < n; i++) {
            int len = y[i] - x[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }

        
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends