class Solution {
public:
    int helper(int i,int newTar,int n,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i>=n)
        {
            if(newTar==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][newTar]!=-1)
        {
            return dp[i][newTar];
        }
        int notTake = helper(i+1,newTar,n,nums,dp);
        int take = 0;
        if(nums[i]<=newTar)
        {
            take = helper(i+1,newTar-nums[i],n,nums,dp);
        }
        dp[i][newTar] = take+notTake;
        return dp[i][newTar];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum=0;
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
        return helper(0,newTar,n,nums,dp);
    }
};