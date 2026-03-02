class Solution {
public:
    int helper(int i,vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            return 1e9;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int notTake = 0+helper(i-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[i]<=amount)
        {
            take = 1+helper(i,coins,amount-coins[i],dp);
        }
        dp[i][amount]=min(take,notTake);
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(n-1,coins,amount,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};