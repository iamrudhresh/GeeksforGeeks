class Solution {
      public int uniquePaths(int[][] grid) {
        // code here
        int dp[][]=new int[grid.length][grid[0].length];
        for(int[] d:dp) Arrays.fill(d,-1);
        return rec(0,0,grid,dp);
    }
    private int rec(int i,int j,int grid[][],int dp[][]){
        if(i==grid.length || j==grid[0].length || grid[i][j]==1) return 0;
        if(i==grid.length-1 && j==grid[0].length-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int count=0;
        count+=rec(i+1,j,grid,dp);
        count+=rec(i,j+1,grid,dp);
        return dp[i][j]=count;
    }
};