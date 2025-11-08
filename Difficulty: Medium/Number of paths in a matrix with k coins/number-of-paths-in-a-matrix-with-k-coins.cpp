class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        vector<vector<map<int,int>>>vec(mat.size() , vector<map<int,int>>(mat[0].size()));
        vec[0][0][mat[0][0]]++;
        int count =0;
        for(int i=0;i<mat.size() ;i++){
            for(int j=0;j<mat[0].size() ;j++){
                if(i==0 && j==0)continue;
                if(i!=0){
                    for(auto [t,y]: vec[i-1][j]){
                        if(mat[i][j] +t <=k)vec[i][j][mat[i][j] +t]+=y;
                    }
                }
                if(j!=0){
                    for(auto [t,y]: vec[i][j-1]){
                        if(mat[i][j] +t <=k)vec[i][j][mat[i][j] +t]+=y;
                    }
                }
            }
        }
        return vec[mat.size()-1][mat[0].size()-1][k];
    }
};