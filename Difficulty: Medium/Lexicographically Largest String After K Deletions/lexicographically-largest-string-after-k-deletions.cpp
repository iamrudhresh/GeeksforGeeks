class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
          // code here
        stack<char>st;
        int n=s.size();
        int si=n-k;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<s[i] && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        
        string ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans.substr(0,si);
        
    }
};
