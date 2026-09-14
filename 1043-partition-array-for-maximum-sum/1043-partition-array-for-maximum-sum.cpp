class Solution {
public:
    int helper(int i,int n,vector<int>& arr,int k,vector<int>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int maxi = 0;
        int ans = 0;
        for(int j=i;j<min(n,i+k);j++)
        {
            maxi = max(maxi,arr[j]);
            int len = j-i+1;
            int sum = maxi*len+helper(j+1,n,arr,k,dp);
            ans = max(ans,sum);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return helper(0,n,arr,k,dp);
    }
};