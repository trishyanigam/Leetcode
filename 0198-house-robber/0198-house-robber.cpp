class Solution {
public:
    int helper(int i,vector<int>& nums,int n,vector<int>& dp)
    {
        if(i==0)
        {
            return nums[0];
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int notTake = helper(i-1,nums,n,dp);
        int take = 0;
        take = nums[i]+helper(i-2,nums,n,dp);
        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return helper(n-1,nums,n,dp);
    }
};