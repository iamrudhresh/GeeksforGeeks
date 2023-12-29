//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
int kSubstrConcat (int n, string s, int k)
    {
        
        
        if(n%k) return 0;
        map<string,int>mp;
        string temp = "";
        temp += s[0];
        for(int i=1;i<n;i++) {
            if(i%k==0){
                mp[temp]++;
                temp = "";
            }
            temp += s[i];
        }
        mp[temp]++;
        if(mp.size()>2) return 0;
        else{
            int count=0;
            for(auto it:mp) {
                if(it.second>1) {
                    count++;
                }
            }
            if(count>1) return 0;
        }
            return 1;
    }


};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends