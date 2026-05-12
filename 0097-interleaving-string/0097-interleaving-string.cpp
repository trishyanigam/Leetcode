class Solution {
public:
    bool helper(int i,int j,string& s1, string& s2, string& s3,int a,int b,int c,vector<vector<int>>& dp)
    {
        if(i>=a && j>=b)
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool ans=false;
        int k = i+j;
        if(i<a && s1[i]==s3[k])
        {
            ans = ans || helper(i+1,j,s1,s2,s3,a,b,c,dp);
        }
        if(j<b && s2[j]==s3[k])
        {
            ans = ans || helper(i,j+1,s1,s2,s3,a,b,c,dp);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        if(a+b!=c)
        {
            return false;
        }
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        return helper(0,0,s1,s2,s3,a,b,c,dp);
    }
};