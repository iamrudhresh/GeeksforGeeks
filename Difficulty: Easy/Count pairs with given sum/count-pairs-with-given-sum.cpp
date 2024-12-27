//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
           // Hash map to store the frequency of elements encountered
        unordered_map<int, int> mp;  
        int cnt = 0; // Counter to keep track of pair count

        // Traverse the array
        for (int i = 0; i < arr.size(); ++i) {
            // Required value to form a pair with arr[i]
            int req = target - arr[i];

            // Check if the required value exists in the map
            if (mp.find(req) != mp.end()) {
                cnt += mp[req]; // Add the frequency of the required value
            }

            // Increment the frequency of the current value in the map
            mp[arr[i]]++;
        }

        return cnt; // Return the total number of pairs
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends