class Solution {
public:
    int helper(int i,vector<int>& arr,vector<int>& dp)
    {
        if(i==0)
        {
            return arr[0];
        }
        if(i==-1)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int take = arr[i]+helper(i-2,arr,dp);
        int notTake = 0+helper(i-1,arr,dp);
        dp[i] = max(take,notTake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        vector<int> t1;
        vector<int> t2;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                t1.push_back(nums[i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                t2.push_back(nums[i]);
            }
        }

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        int ans1 = helper(n-2,t1,dp1);
        int ans2 = helper(n-2,t2,dp2);

        return max(ans1,ans2);
    }
};