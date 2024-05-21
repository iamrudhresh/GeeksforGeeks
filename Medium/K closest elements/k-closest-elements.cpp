//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
int findCrossOver(vector<int> arr, int low, int high, int x) {
    // If x is greater than all elements, return the last index
    if (arr[high] <= x) {
        return high;
    }
    // If x is smaller than all elements, return the first index
    if (arr[low] > x) {
        return low;
    }
  
    int mid = (low + high) / 2;
    
    // Check if mid is the crossover point
    if (arr[mid] <= x && arr[mid + 1] > x) {
        return mid;
    } 
    // If x is greater than arr[mid], then crossover point is on the right side
    else if (arr[mid] < x) {
        return findCrossOver(arr, mid + 1, high, x);
    }
    // Otherwise, crossover point is on the left side
    return findCrossOver(arr, low, mid - 1, x);
}


vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
   
    int id1 = findCrossOver(arr, 0, n - 1, x);
    // Set the second pointer just after the crossover point
    int id2 = id1 + 1;

    // If x is present in the array, move id1 one step back
    if (id1 >= 0 && arr[id1] == x) {
        id1--;
    }

    vector<int> ans; 

    
    for (int i = 0; i < k; i++) {
        // Both pointers are within bounds of the array
        if (id1 >= 0 && id2 < n) {
            int val1 = x - arr[id1]; 
            int val2 = arr[id2] - x; 

            // Compare the distances and prioritize the closer element
            if (val1 < val2) {
                ans.push_back(arr[id1]);
                id1--;
            } else if (val1 > val2) {
                ans.push_back(arr[id2]);
                id2++;
            } else {
                // If distances are equal, prioritize the greater element
                if (arr[id1] > arr[id2]) {
                    ans.push_back(arr[id1]);
                    id1--; // Move left pointer one step back
                } else {
                    ans.push_back(arr[id2]);
                    id2++; // Move right pointer one step forward
                }
            }
        } 
        
        else if (id1 >= 0) {
            ans.push_back(arr[id1]);
            id1--;
        } 
       
        else if (id2 < n) {
            ans.push_back(arr[id2]);
            id2++;
        }
    }

    return ans; 
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends