//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minX(int a, int b, int c, long int k){
        //complete the function here
                for(int i=0 ;i<k;i++){
            if(a*(pow(i,2))+b*i+c>=k){
                return i;
            }
        }
    }
    
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        long k;
        
        cin >> a >> b >> c >> k;
        Solution ob;
        cout << ob.minX(a, b, c, k) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends