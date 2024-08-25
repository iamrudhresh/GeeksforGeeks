//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        vector<double> a(arr.size()), b(brr.size());
        
        for(int i = 0; i<arr.size(); i++)
            a[i] = (double)log(arr[i]) / (double)arr[i];
        for(int i = 0; i<brr.size(); i++)   
            b[i] = (double)log(brr[i]) / (double)brr[i];
            
        sort(a.begin(), a.end(), greater<double>());
        sort(b.begin(), b.end(), greater<double>());
        int i = 0, j = 0, n = a.size(), m = b.size();
        long long x = 0;
        while(i<n && j < m)
        {
            if(a[i] > b[j])
            {
                x += (m-j);
                i++;
            }
            else
                j++;
        }
        return x;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends