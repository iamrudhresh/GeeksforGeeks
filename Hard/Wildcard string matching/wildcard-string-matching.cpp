//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
bool match(string wild, string pattern){
        int n = wild.length();
        int m = pattern.length();
        int i = 0, j = 0;
        for (;j<m;j++){
            if (wild[i] == '?'){
                i++;
                continue;
            }
            else if (wild[i] == '*'){
                i++;
                j++;
                while(i<n && (wild[i] == '*' || wild[i] == '?')){
                    i++;
                    j++;
                }
                while(j<m && wild[i]!=pattern[j])
                    j++;
                i++;
                continue;
            }
            else if (wild[i] != pattern[j]){
                //cout << i << " " << j << endl;
                return false;
            }
            i++;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends