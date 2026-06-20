class Solution {
public:
    int helper(int r,int c,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(r==n-1)
        {
            return triangle[r][c];
        }
        if(dp[r][c]!=INT_MAX)
        {
            return dp[r][c];
        }
        int down = triangle[r][c]+helper(r+1,c,n,triangle,dp);
        int dia = triangle[r][c]+helper(r+1,c+1,n,triangle,dp);
        return dp[r][c] = min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        return helper(0,0,n,triangle,dp);
    }
};