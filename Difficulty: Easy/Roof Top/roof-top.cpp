//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
  int maxStep(vector<int>& arr) {
        
        int ans=1;
        int res=1;
        for(int i=0;i<arr.size()-1;i++){
            
            if(arr[i]<arr[i+1])
            res++;
            else{
                ans=max(ans,res);
                res=1;
            }
        }
        ans=max(ans,res);
        return ans-1;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends