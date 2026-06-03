class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int>& dp)
    {
        if(idx<0)
        {
            return 0;
        }
        if(idx==0)
        {
            return nums[0];
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int notTake = helper(idx-1,nums,dp);
        int take = nums[idx]+helper(idx-2,nums,dp);
        int ans = max(take,notTake);
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return helper(n-1,nums,dp);
    }
};