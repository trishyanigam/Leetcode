class Solution {
public:
    int helper(int i,vector<int>& nums, int tar,int n,vector<vector<int>>& dp)
    {
        if(i>=n)
        {
            if(tar==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        int notTake = helper(i+1,nums,tar,n,dp);
        int take = 0;
        if(nums[i]<=tar)
        {
            take = helper(i+1,nums,tar-nums[i],n,dp);
        }
        dp[i][tar] = take+notTake;
        return dp[i][tar];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int n:nums)
        {
            totSum+=n;
        }
        int newTar = (target+totSum)/2;
        if(abs(target)>totSum || (target+totSum)%2!=0)
        {
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(newTar+1,-1));
        return helper(0,nums,newTar,n,dp);
    }
};