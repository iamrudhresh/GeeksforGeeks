//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int kthElement(vector<int>& a, vector<int>& b, int k) 
    {
        // code here
        int na = a.size();
        int nb = b.size();
        int ans, flag=0;
            
        int i=0, j=0;
        while(i<na && j<nb)
        {
            if(a[i]<b[j])
            {
                ans = a[i];
                flag++;
                i++;
            }
            else if(a[i]>b[j])
            {
                ans = b[j];
                flag++;
                j++;
            }
            else
            {
                ans = a[i];
                flag+=2;
                i++;
                j++;
            }
            if(flag>=k )
                return ans;
        }
        while(i<na)
        {
            ans = a[i];
            i++;
            flag++;
            if(flag==k)
                return ans;
        }
        
        while(j<nb)
        {
            ans = b[j];
            flag++;    
            j++;
            if(flag==k)
                return ans;
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends