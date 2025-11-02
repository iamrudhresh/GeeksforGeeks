class Solution {
  public:
    int maxEdgesToAdd(int v, vector<vector<int>>& edges) {
        // code here
        return (v*(v-1))/2 - edges.size();
    }
};