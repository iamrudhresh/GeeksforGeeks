//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

   bool kPangram(string str, int k) {
        vector<int>arr(26);
        for (char ch: str){
            if (ch == ' ') continue;
            arr[ch - 'a']+=1; 
        }
        int nhi_hai = 0;
        int space_for_alpha = 0; // matlab eesa character jo phele bhi aa chuka hai or uski jagah apan eesa characters likhe jo phele nhi aaya
        for (int i=0; i< 26; i++){
            if (arr[i] > 1) space_for_alpha += (arr[i]-1);
            if (!arr[i]) nhi_hai+=1; // sentance me eesa characters jo 26 characters me se nhi aaya
        }
        
        return nhi_hai <= space_for_alpha && nhi_hai <= k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends