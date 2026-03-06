class Solution {
public:
    int helper(int k,int n,vector<vector<int>>&dp)
    {
        if(k==1)
        {
            return n;
        }
        if(n==0 || n==1)
        {
            return n;
        }
        if(dp[k][n]!=-1)
        {
            return dp[k][n];
        }
        int low=1,high=n;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int breakCase = helper(k-1,mid-1,dp);
            int notBreak = helper(k,n-mid,dp);
            int temp = 1+max(breakCase,notBreak);
            if(breakCase>notBreak)
            {
                high=mid-1;
                ans=min(ans,temp);
            }
            else
            {
                low=mid+1;
                ans=min(ans,temp);
            }
        }
        dp[k][n] = ans;
        return dp[k][n];
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return helper(k,n,dp);
    }
};