class Solution {
public:
    int helper(int i,vector<int>& coins,int amt,vector<vector<int>>& dp)
    {
        if(amt==0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][amt]!=-1)
        {
            return dp[i][amt];
        }
        int notTake = helper(i-1,coins,amt,dp);
        int take = 0;
        if(coins[i]<=amt)
        {
            take = helper(i,coins,amt-coins[i],dp);
        }
        return dp[i][amt] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,coins,amount,dp);
    }
};