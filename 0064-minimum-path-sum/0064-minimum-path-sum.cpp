class Solution {
public:
    int helper(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(r>=n || c>=m)
        {
            return INT_MAX;
        }
        if(r==n-1 && c==m-1)
        {
            return grid[r][c];
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        int right = helper(r,c+1,n,m,grid,dp);
        int bottom = helper(r+1,c,n,m,grid,dp);
        return dp[r][c] = grid[r][c]+min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,grid,dp);
    }
};