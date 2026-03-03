class Solution {
public:
    int ans=0;
    int helper(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        helper(i-1,j,nums1,nums2,dp);
        helper(i,j-1,nums1,nums2,dp);
        if(nums1[i]==nums2[j])
        {
            dp[i][j]=1+helper(i-1,j-1,nums1,nums2,dp);
            ans=max(ans,dp[i][j]);
        }
        else
        {
            dp[i][j]=0;
        }
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(n-1,m-1,nums1,nums2,dp);
        return ans;
    }
};