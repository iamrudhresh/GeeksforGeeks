//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
int equilibriumPoint(long long a[], int n) {
    
        if(n==1)
        return 1;
        
        long long s1=a[0];
        long long s2=a[n-1];
        int i=1;
        int j=n-2;
        while(i<=j)
        {
            if(s1==s2 && i==j)
            return i+1;
            else
            {
                if(s1<s2)
                {
                s1+=a[i];
                i++;
                }
                else if(s1>s2)
                {
                s2+=a[j];
                j--;
                }
                else
                {
                s1+=a[i];
                s2+=a[j];
                i++;
                j--;
                }
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends