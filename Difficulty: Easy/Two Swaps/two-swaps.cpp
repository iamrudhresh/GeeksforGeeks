//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
     int n=arr.size();
        int swap_count=0,i=0;
        while(i<n){
            if(arr[i]-1!=i){
                  swap_count++;
                  int temp=arr[arr[i]-1];
                  arr[arr[i]-1]=arr[i];
                  arr[i]=temp;
                  continue;
            }
            
            if(swap_count>2)
                return false;
            i++;
        }
        if(swap_count==2||swap_count==0)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends