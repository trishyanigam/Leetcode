class Solution {
public:
    int helper(int i,vector<int>& nums,int tar,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(tar==0 && nums[0]==0)
            {
                return 2;
            }
            if(tar==0 || nums[0]==tar)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        int notTake = helper(i-1,nums,tar,dp);
        int take = 0;
        if(nums[i]<=tar)
        {
            take = helper(i-1,nums,tar-nums[i],dp);
        }
        return dp[i][tar] = take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int x:nums)
        {
            totSum+=x;
        }
        if(totSum<abs(target) || (target+totSum)%2!=0)
        {
            return 0;
        }
        int newTar = (target+totSum)/2;
        vector<vector<int>>dp(n,vector<int>(newTar+1,-1));
        return helper(n-1,nums,newTar,dp);
    }
};