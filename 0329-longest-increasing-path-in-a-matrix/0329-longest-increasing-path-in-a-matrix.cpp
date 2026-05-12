class Solution {
public:
    int helper(int i,int j,int n,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int ans = 1;
        for(int k=0;k<4;k++)
        {
            int nr = i+dr[k];
            int nc = j+dc[k];

            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[i][j])
            {
                ans = max(ans,1+helper(nr,nc,n,m,matrix,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans,helper(i,j,n,m,matrix,dp));
            }
        }
        return ans;
    }
};