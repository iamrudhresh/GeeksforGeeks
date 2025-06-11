class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
       int n=color.size();
        stack<int>c,r;
        for(int i=0;i<n;i++){
            if(!c.empty() && !r.empty() && c.top()==color[i] && r.top()==radius[i]){
                c.pop();
                r.pop();
            }
            else{
            c.push(color[i]);
            r.push(radius[i]);
            }

        }
        return c.size();
    }
};