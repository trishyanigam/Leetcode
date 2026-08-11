class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>& dp,int n,int m)
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
            int cost = grid[row][col]+moveCost[grid[row][col]][nc]+helper(row+1,nc,grid,moveCost,dp,n,m);
            ans = min(ans,cost);
        }
        return dp[row][col] = ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = INT_MAX;
        for(int col=0;col<m;col++)
        {
            ans = min(ans,helper(0,col,grid,moveCost,dp,n,m));
        }
        return ans;
    }
};