//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

long long int maxi(long long int a, long long int b){
    if(a>b) return a;
    return b;
}

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int surplus[n];
        surplus[n-1] = 0;
        for(long long int i=n-2; i>=0; i--){
            surplus[i] = maxi(0,a[i+1] + surplus[i+1]);
        }
        long long sum[n], ans=0;
        sum[0] = a[0];
        for(long long int i=0; i<n; i++){
            if(i==0) sum[0] = a[0];
            else sum[i] = a[i] + sum[i-1];
            if(i == k-1){
                ans = sum[k-1] + surplus[k-1];
            }
            else if(i >= k){
                ans = maxi(ans,sum[i] - sum[i-k] +surplus[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends