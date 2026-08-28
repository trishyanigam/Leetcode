class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
        {
            return INT_MAX;
        }
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up = helper(i-1,j,grid,dp);
        int left = helper(i,j-1,grid,dp);
        return dp[i][j] = grid[i][j]+min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,grid,dp);
    }
};