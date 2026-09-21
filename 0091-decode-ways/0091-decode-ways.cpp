class Solution {
public:
    int helper(int i,int n,string& s,vector<int>& dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int way = helper(i+1,n,s,dp);
        if(i+1<n)
        {
            int num = (s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26)
            {
                way+=helper(i+2,n,s,dp);
            }
        }
        return dp[i] = way;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return helper(0,n,s,dp);
    }
};