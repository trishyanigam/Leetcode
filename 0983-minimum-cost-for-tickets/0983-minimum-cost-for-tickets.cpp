class Solution {
public:
    int helper(int i,vector<int>& days, vector<int>& costs,vector<int>&dp,int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int op1=costs[0]+helper(i+1,days,costs,dp,n);

        int idx;
        for(idx=i;idx<n && days[idx]<days[i]+7;idx++);
        int op2=costs[1]+helper(idx,days,costs,dp,n);

        for(idx=i;idx<n && days[idx]<days[i]+30;idx++);
        int op3=costs[2]+helper(idx,days,costs,dp,n);

        dp[i]=min(op1,min(op2,op3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return helper(0,days,costs,dp,n);
    }
};