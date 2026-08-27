class Solution {
public:
    int helper(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==n-1)
        {
            return triangle[i][j];
        }
        if(i<0 || j<0)
        {
            return INT_MAX;
        }
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }
        int down = helper(i+1,j,n,triangle,dp);
        int dia = helper(i+1,j+1,n,triangle,dp);
        return dp[i][j] = triangle[i][j]+min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        return helper(0,0,n,triangle,dp);
    }
};