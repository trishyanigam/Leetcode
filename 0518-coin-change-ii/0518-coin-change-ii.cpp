class Solution {
public:
    int helper(int i,int amt,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(amt==0)
        {
            return 1;
        }
        if(i>=coins.size())
        {
            return 0;
        }
        if(dp[i][amt]!=-1)
        {
            return dp[i][amt];
        }
        int notTake = helper(i+1,amt,coins,dp);
        int take = 0;
        if(coins[i]<=amt)
        {
            take = helper(i,amt-coins[i],coins,dp);
        }
        dp[i][amt] = take+notTake;
        return dp[i][amt];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);
    }
};