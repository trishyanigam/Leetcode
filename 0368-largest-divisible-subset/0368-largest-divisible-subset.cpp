class Solution {
public:
    int helper(int i,int prev,int n,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int notTake = helper(i+1,prev,n,nums,dp);
        int take = 0;
        if(prev==-1 || nums[i]%nums[prev]==0)
        {
            take = 1+helper(i+1,i,n,nums,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(nums.begin(),nums.end());
        helper(0,-1,n,nums,dp);
        int i=0;
        int prev=-1;
        while(i<n)
        {
            int notTake = helper(i+1,prev,n,nums,dp);
            int take = 0;
            if(prev==-1 || nums[i]%nums[prev]==0)
            {
                take = 1+helper(i+1,i,n,nums,dp);
            }
            if(take>=notTake && (prev==-1 || nums[i]%nums[prev]==0))
            {
                ans.push_back(nums[i]);
                prev=i;
            }
            i++;
        }
        return ans;
    }
};