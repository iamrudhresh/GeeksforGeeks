//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int smithNum(int n) {
        // code here
              if(n==1)
        return 0;
        int m =n;
        int sum1=0;
        int sum2=0;
        int i=2;
        while(i<=n/2)
        {
            if(m%i==0)
            {
                if(i<10)
                sum1+=i;
                else
                {
                int j=i;
                while(j>0)
                {
                    sum1+=(j%10);
                    j=j/10;
                }
                }
                m=m/i;
            }
            else
            i++;
        }
        while(n>0)
        {
            sum2=sum2+(n%10);
            n=n/10;
        }
        if(sum1==0)
        return 0;
        if(sum1==sum2)
        return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends