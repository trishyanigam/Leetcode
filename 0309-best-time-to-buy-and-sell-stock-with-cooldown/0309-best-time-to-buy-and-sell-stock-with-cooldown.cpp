class Solution {
public:
    int helper(int i,int buy,vector<int>& prices,vector<vector<int>>& dp,int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i]+helper(i+1,0,prices,dp,n),0+helper(i+1,1,prices,dp,n));
        }
        else
        {
            profit = max(prices[i]+helper(i+2,1,prices,dp,n),0+helper(i+1,0,prices,dp,n));
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp,n);
    }
};