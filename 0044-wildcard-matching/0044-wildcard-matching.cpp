class Solution {
public:
    bool helper(int i,int j,string& s, string& p,vector<vector<int>>& dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int a=0;a<=j;a++)
            {
                if(p[a]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(p[j]=='?' || s[i]==p[j])
        {
            return dp[i][j] = helper(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*')
        {
            return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,s,p,dp);
    }
};