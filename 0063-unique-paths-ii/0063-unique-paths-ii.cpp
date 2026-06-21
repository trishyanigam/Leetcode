class Solution {
public:
    int helper(int r,int c,int m,int n,vector<vector<int>> &grid,vector<vector<int>>& dp)
    {
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==1)
        {
            return 0;
        }
        if(r==0 && c==0)
        {
            return 1;
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        int up = helper(r-1,c,m,n,grid,dp);
        int left = helper(r,c-1,m,n,grid,dp);
        return dp[r][c] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,m,n,obstacleGrid,dp);
    }
};