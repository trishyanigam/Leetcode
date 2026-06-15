class Solution {
public:
    int helper(int i,vector<int>& dp)
    {
        if(i==1 || i==2)
        {
            return i;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        dp[i] = helper(i-1,dp)+helper(i-2,dp);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};