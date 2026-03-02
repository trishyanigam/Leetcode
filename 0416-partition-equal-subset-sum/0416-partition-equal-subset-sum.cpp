class Solution {
public:
    bool helper(int i,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            return false;
        }
        if(target==0)
        {
            return true;
        }
        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }
        bool notTake=helper(i+1,target,nums,dp);
        bool take=false;
        if(nums[i]<=target)
        {
            take=helper(i+1,target-nums[i],nums,dp);
        }
        return dp[i][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int n:nums)
        {
            sum+=n;
        }
        if(sum%2!=0)
        {
            return false;
        }
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(0,target,nums,dp);
    }
};