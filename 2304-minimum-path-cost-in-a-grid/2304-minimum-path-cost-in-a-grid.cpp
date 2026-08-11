class Solution {
public:
    int helper(int row,int col,int n,int m,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>& dp)
    {
        if(row==n-1)
        {
            return grid[row][col];
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int ans = INT_MAX;
        for(int nc=0;nc<m;nc++)
        {
            int cost = grid[row][col]+moveCost[grid[row][col]][nc]+helper(row+1,nc,n,m,grid,moveCost,dp);
            ans=min(ans,cost);
        }
        return dp[row][col]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int col=0;col<m;col++)
        {
            ans = min(ans,helper(0,col,n,m,grid,moveCost,dp));
        }
        return ans;
    }
};