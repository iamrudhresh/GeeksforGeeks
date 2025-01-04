//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
         int ans = 0,n = arr.size();
        for(int i = 0;i<n-2;i++){
            int left = i+1,right = n-1;
            while(left<right){
                int sum = arr[i] + arr[left] + arr[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    int e1 = arr[left],e2 = arr[right],c1 = 0,c2 = 0;
                    while(left<=right && arr[left]==e1){
                        c1++;
                        left++;
                    }
                    while(left<=right && arr[right]==e2){
                    c2++;
                    right--;
                    }
                    if(e1 == e2) ans += (c1*(c1-1))/2;
                    else ans += c1*c2;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends