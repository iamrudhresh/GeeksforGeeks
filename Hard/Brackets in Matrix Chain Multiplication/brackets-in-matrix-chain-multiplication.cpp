//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
private:
    vector<vector<int>> dp, val;
    int n;
public:
    int MCM(int i, int j, int arr[]){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int tmp = arr[i-1] * arr[k] * arr[j] + MCM(i, k, arr) + MCM(k+1, j, arr);
            if(tmp < ans) ans = tmp, val[i][j] = k; 
        }
        return dp[i][j] = ans;
    }
    void construct_string(int i, int j, string &ans){
        if(i > j) return; 
        if(i == j){
            ans.push_back('A' + i - 1);
            return;
        }
        ans.push_back('('); 
        construct_string(i, val[i][j], ans); 
        construct_string(val[i][j] + 1, j, ans);
        ans.push_back(')'); 
        return;
    }
    string matrixChainOrder(int p[], int N){ 
        n = N, dp.resize(n, vector<int>(n, -1)), val.resize(n, vector<int>(n, -1));
        MCM(1, n-1, p);
        string ans = ""; 
        construct_string(1, n-1, ans);  
        return ans;
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends