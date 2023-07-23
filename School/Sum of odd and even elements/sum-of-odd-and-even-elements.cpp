//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
		vector<int> find_sum(int n)
		{
		    // Code here
		    int even=0;
		    int odd=0;
		    for(int i=0;i<=n;i++){
		        if(i%2==0){
		            even+=i;
		        }
		    }
		    for(int i=0;i<=n;i++){
		        if(i%2!=0){
		            odd+=i;
		        }
		    }
		    return {odd, even};
		    

		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	vector<int> ans = ob.find_sum(n);
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"\n";
    }
	return 0;
}
// } Driver Code Ends