class Solution {
public:
    int helper(int i,int prev,vector<int>& nums,int n,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int notTake = helper(i+1,prev,nums,n,dp);
        int take = 0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            take = 1+helper(i+1,i,nums,n,dp);    
        }
        dp[i][prev+1] = max(take,notTake);
        return dp[i][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,n,dp);
    }
};