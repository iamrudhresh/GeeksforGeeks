//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int count = 0;
        int t = N;
        
        while(N>0)
        {
            
            if( N%10 !=0 && t % (N%10) == 0 )
            {
                // cout<<N << " " << N%10 << " " << N % (N%10) <<endl;
                count++;
            }
            N/=10;
        }
        return count;
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends