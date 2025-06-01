class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
            // code here
        int n=mat1.size();
        vector<int>mt1;
        vector<int>mt2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mt1.push_back(mat1[i][j]);
                mt2.push_back(mat2[i][j]);
            }
        }
        int p=mt1.size();
        int m=mt2.size();
        int count=0; 
        int left=0;
        int right=p-1;
        set<pair<int,int>>sp;
        while(left<p&&right>=0){
            if(mt1[left]+mt2[right]==x){
                count++;
               
                right--;
                left++;
               
            }
            else if(mt1[left] + mt2[right] < x){
              left++;
                
            }
            else{
               right--;
               
            }
        }
        return count;
    }
};