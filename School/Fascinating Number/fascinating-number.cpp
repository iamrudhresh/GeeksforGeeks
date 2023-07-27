//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	bool fascinating(int n) {
	    // code here
	             string s1=to_string(n);

         string s2=to_string(n*2);

         string s3=to_string(n*3);

        string s4=s1+s2+s3;

        int i=0;

        for (int j=i+1;j<s4.length();j++){

                if(s4[i]=='0' || s4[j]=='0'){

                     return  0;

                     break;

               }

               if(s4[i]==s4[j]){

                   return  0;

                   break;

              }

              if(j==s4.length()-1 && i<s4.length()-1){

                  i=i+1;

                  j=i;

             }

        }

        return  1;

}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans) {
            cout << "Fascinating\n";
        } else {
            cout << "Not Fascinating\n";
        }
    }
    return 0;
}
// } Driver Code Ends