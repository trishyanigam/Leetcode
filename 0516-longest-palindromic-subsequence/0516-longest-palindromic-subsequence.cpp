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
            if(s[l]==s[r])
            {
                return 1;
            }
            return 0;
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
            return dp[l][r] = max(helper(l+1,r,s,dp),helper(l,r-1,s,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,n-1,s,dp);
    }
};