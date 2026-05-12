class Solution {
public:
    int helper(int i,int j,string& s, string& t,int n,int m,vector<vector<int>>& dp)
    {
        if(j==m)
        {
            return 1;
        }
        if(i==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if(s[i]==t[j])
        {
            int take = helper(i+1,j+1,s,t,n,m,dp);
            int notTake = helper(i+1,j,s,t,n,m,dp);
            ans = take+notTake;
        }
        else
        {
            ans = helper(i+1,j,s,t,n,m,dp);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s,t,n,m,dp);
    }
};