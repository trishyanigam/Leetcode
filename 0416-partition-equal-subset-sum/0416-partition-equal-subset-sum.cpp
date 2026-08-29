class Solution {
public:
    bool helper(int i,vector<int>& nums,int tar,vector<vector<int>>& dp)
    {
        if(tar==0)
        {
            return true;
        }
        if(i==0)
        {
            if(nums[0]==tar)
            {
                return true;
            }
            return false;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        bool notTake = helper(i-1,nums,tar,dp);
        bool take = false;
        if(nums[i]<=tar)
        {
            take = helper(i-1,nums,tar-nums[i],dp);
        }
        return dp[i][tar] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int x:nums)
        {
            totSum+=x;
        }
        if(totSum%2!=0)
        {
            return false;
        }
        int tar = totSum/2;
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return helper(n-1,nums,tar,dp);
    }
};