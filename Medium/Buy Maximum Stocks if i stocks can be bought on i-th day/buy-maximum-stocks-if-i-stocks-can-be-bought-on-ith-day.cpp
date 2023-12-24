//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int buyMaximumProducts(int N, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i=0;i<N;i++)
            v.push_back({price[i],i+1}); // vector of pairs containing {number of stocks, with their quantity}
        
        sort(v.begin(), v.end());       // Sort according to the price of stcko
        
        int count=0;
        for(int i=0;i<N;i++)
        {
            int p= v[i].first;    // Price of stock
            int s= v[i].second;   // Number of stocks available for purchase
            int m= k/p;           // Number of that i can purchase with available money
            
            if(m>= s)  // Purchase all stocks
            {
                count+= s;
                k-= p*s;
                continue;
            }
            else      // Can purchase stocks less than available stock
            {
                count+= m;
                k-= m*p;
                break;
            }
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends