class Solution {
public:
    int helper(int i,int amount, vector<int>& coins,vector<vector<int>>& dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(i>=coins.size())
        {
            return 0;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int notTake = helper(i+1,amount,coins,dp);
        int take = 0;
        if(coins[i]<=amount)
        {
            take = helper(i,amount-coins[i],coins,dp);
        }
        dp[i][amount] = take+notTake;
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);
    }
};