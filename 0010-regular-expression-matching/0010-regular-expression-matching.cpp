class Solution {
public:
    bool helper(int i,int j,string &s,string &p,int n,int m,vector<vector<int>>& dp)
    {
        if(j==m)
        {
            return i==n;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool match = (i<s.size() && (s[i]==p[j] || p[j]=='.'));
        bool ans;
        if(j+1<p.size() && p[j+1]=='*')
        {
            ans = helper(i,j+2,s,p,n,m,dp) || (match && helper(i+1,j,s,p,n,m,dp));
        }
        else
        {
            ans = match && helper(i+1,j+1,s,p,n,m,dp);
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s,p,n,m,dp);
    }
};