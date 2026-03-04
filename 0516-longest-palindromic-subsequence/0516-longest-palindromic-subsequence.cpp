class Solution {
public:
    int helper(int i,int j,string& s,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            dp[i][j]=2+helper(i+1,j-1,s,dp);
        }
        else
        {
            int left = helper(i+1,j,s,dp);
            int right = helper(i,j-1,s,dp);
            dp[i][j] = max(left,right);
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};