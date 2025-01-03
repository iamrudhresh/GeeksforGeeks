//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code her
         vector<int> result{-1};

        for(int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == target)
                return vector<int> {i + 1, i + 1};        
            if(arr[i] < target)
            {
                int j = i + 1;
                int temp = arr[i] + arr[j];
                while( temp < target && ++j < arr.size() )
                {
                    temp += arr[j];
                }
                if( temp == target)
                {
                    result[0] = i+1;
                    result.push_back( j+1 );
                    break;
                }
            }
        }
        if(arr.back() == target)
            return vector<int> {arr.size(), arr.size()};
        return result;
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