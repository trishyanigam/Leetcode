class Solution {
public:
    int helper(int i,string s,int n,vector<int>&dp)
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
        int takeOne = helper(i+1,s,n,dp);
        int takeTwo = 0;
        if(i+1<n)
        {
            int num = (s[i]-'0')*10+(s[i+1]-'0');
            if(num>=10 && num<=26)
            {
                takeTwo = helper(i+2,s,n,dp);
            }
        }
        dp[i]=takeOne+takeTwo;
        return dp[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return helper(0,s,n,dp);
    }
};