class Solution {
public:
    int helper(int r,int c,int m,int n,vector<vector<int>>& dp)
    {
        if(r<0 || r>=m || c<0 || c>=n)
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
        int up = helper(r-1,c,m,n,dp);
        int left = helper(r,c-1,m,n,dp);
        return dp[r][c] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,m,n,dp);
    }
};