//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        int res=0,count=0;
        vector<int>v(26,0);
        
        for(char c:tasks){
            v[c-'A']++;
            res=max(res,v[c-'A']);
        }
        
        for(int i:v){
            if(i==res){
                count++;
            }
        }
        
        return max(N,res + (res- 1)*K + count - 1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends