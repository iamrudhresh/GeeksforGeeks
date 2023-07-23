//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int countWays(int N){ 
        // code here
        int c=0,z=0; 
       for(int i=1; i<N; i++){
           for(int j=i; j<N; j++){
               for(int k=j; k<N; k++){
                   for(int l=k; l<N; l++){
                       if(i+j+k+l == N) c++;
                   }
               }
           }
       }
       return c;
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
        cin>>N;
        Solution ob;
        cout << ob.countWays(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends