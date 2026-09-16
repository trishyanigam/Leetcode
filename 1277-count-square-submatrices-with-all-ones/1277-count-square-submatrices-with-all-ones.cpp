class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(matrix[i][j]==0)
        {
            return 0;
        }
        int top = helper(i-1,j,matrix,dp);
        int left = helper(i,j-1,matrix,dp);
        int dia = helper(i-1,j-1,matrix,dp);
        return dp[i][j] = 1+min({top,left,dia});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans+=helper(i,j,matrix,dp);
            }
        }
        return ans;
    }
};