//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
            vector<int>ans;
        for(int start=0;start<arr.size();start++)
         {
             int currsum=0;
             for(int end=start;end<arr.size();end++)
              {
                  currsum+=arr[end];
                  if(currsum==target)
                   {
                       ans.push_back(start+1);
                       ans.push_back(end+1);
                       return ans;
                   }
              }
         }
         ans.push_back(-1);
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends