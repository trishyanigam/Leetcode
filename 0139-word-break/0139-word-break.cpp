class Solution {
public:
    bool helper(int i,string s,int n,unordered_set<string>& st,vector<int>& dp)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int j=i;j<n;j++)
        {
            string word = s.substr(i,j-i+1);
            if(st.count(word))
            {
                if(helper(j+1,s,n,st,dp))
                {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        return helper(0,s,n,st,dp);
    }
};