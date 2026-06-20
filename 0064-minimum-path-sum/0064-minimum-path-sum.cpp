class Solution {
public:
    int helper(int r,int c,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(r==0 && c==0)
        {
            return grid[r][c];
        }
        if(r<0 || c<0 || r>=n || c>=m)
        {
            return 1e9;
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        int up = grid[r][c]+helper(r-1,c,n,m,grid,dp);
        int left = grid[r][c]+helper(r,c-1,n,m,grid,dp);
        dp[r][c] = min(up,left);
        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,n,m,grid,dp);
    }
};