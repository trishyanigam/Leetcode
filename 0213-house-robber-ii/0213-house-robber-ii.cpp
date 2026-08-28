class Solution {
public:
    int helper(int i,vector<int>& nums,vector<int>& dp)
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
        int notTake = helper(i-1,nums,dp);
        int take = nums[i]+helper(i-2,nums,dp);
        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int>nums1;
        vector<int>nums2;
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                nums1.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                nums2.push_back(nums[i]);
            }
        }
        int ans1 = helper(n-2,nums1,dp1);
        int ans2 = helper(n-2,nums2,dp2);
        return max(ans1,ans2);
    }
};