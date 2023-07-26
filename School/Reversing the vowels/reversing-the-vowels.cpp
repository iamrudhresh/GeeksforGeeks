//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        string modify (string s)
        {
            int i=0;
            int j=s.length()-1;
            
            
            while(j>i){
                
                if((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'  || s[i]=='u') && ((s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o'  || s[j]=='u'))){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                else if(!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'  || s[i]=='u') ){
                    i++;
                }
                else if(!(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o'  || s[j]=='u') ){
                    j--;
                }
            }
            
            return s;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends