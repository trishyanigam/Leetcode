class Solution {
public:
    int helper(int l,int r,string& s,vector<vector<int>>& dp)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return 1;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        if(s[l]==s[r])
        {
            return dp[l][r] = 2+helper(l+1,r-1,s,dp);
        }
        else
        {
            int op1 = helper(l+1,r,s,dp);
            int op2 = helper(l,r-1,s,dp);
            return dp[l][r] = max(op1,op2);
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,n-1,s,dp);
    }
};