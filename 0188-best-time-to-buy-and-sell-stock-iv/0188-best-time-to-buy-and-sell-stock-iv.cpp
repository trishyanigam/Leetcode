class Solution {
public:
    int helper(int i,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i==n || cap==0)
        {
            return 0;
        }
        if(dp[i][buy][cap]!=-1)
        {
            return dp[i][buy][cap];
        }
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i]+helper(i+1,0,cap,n,prices,dp),helper(i+1,1,cap,n,prices,dp));
        }
        else
        {
            profit = max(prices[i]+helper(i+1,1,cap-1,n,prices,dp),helper(i+1,0,cap,n,prices,dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,n,prices,dp);
    }
};