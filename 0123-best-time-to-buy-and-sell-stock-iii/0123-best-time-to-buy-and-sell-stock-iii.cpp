class Solution {
public:
    int helper(int i,int buy,int k,int n,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i==n || k==0)
        {
            return 0;
        }
        if(dp[i][buy][k]!=-1)
        {
            return dp[i][buy][k];
        }
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i]+helper(i+1,0,k,n,prices,dp),helper(i+1,1,k,n,prices,dp));
        }
        else
        {
            profit = max(prices[i]+helper(i+1,1,k-1,n,prices,dp),helper(i+1,0,k,n,prices,dp));
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,1,2,n,prices,dp);
    }
};