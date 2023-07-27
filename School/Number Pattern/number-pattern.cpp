//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<string> numberPattern(int N)
    {
        // Write Your Code here
        vector<string> result(N);
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=i; j++)
                result[i-1] += to_string(j);
            for(int j=i-1; j>=1; j--)
                result[i-1] += to_string(j);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
       
        Solution ob;
        vector<string> res = ob.numberPattern(N);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    
    }
    return 0;
}
// } Driver Code Ends