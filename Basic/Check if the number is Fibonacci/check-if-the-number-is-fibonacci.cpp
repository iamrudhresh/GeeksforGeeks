//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string checkFibonacci(int N){
        // code here 
                float x=5*N*N*1.0;
        return sqrt(x+4)==int(sqrt(x+4))||sqrt(x-4)==int(sqrt(x-4))?"Yes":"No";
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkFibonacci(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends