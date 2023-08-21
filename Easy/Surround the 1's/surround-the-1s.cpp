//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   int Count(vector<vector<int> >& matrix) {
        // Code here
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    count=0;
                    for(int p=i-1; p<i+2; p++){
                        for(int q=j-1; q<j+2; q++){
                            if(p>=0 && p<m && q>=0 && q<n && matrix[p][q]==0){
                                count++;
                            }
                        }
                    }
                    if(count>0 && count%2==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends