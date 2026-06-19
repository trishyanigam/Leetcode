class Solution {
public:
    bool helper(int i,vector<int>& arr, int tar,vector<vector<int>>& dp)
    {
        if(tar==0)
        {
            return true;
        }
        if(i==0)
        {
            if(arr[0]==tar)
            {
                return true;
            }
            return false;
        }
        if(dp[i][tar]!=-1)
        {
            return dp[i][tar];
        }
        bool notTake = helper(i-1,arr,tar,dp);
        bool take = false;
        if(arr[i]<=tar)
        {
            take = helper(i-1,arr,tar-arr[i],dp);
        }
        dp[i][tar] = take||notTake;
        return dp[i][tar];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int n:nums)
        {
            totSum+=n;
        }
        if(totSum%2!=0)
        {
            return false;
        }
        int tar = totSum/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return helper(n-1,nums,tar,dp);
    }
};