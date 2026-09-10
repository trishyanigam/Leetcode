class Solution {
public:
    bool check(string& a,string& b)
    {
        int n = a.size();
        int m = b.size();
        if(m!=n+1)
        {
            return false;
        }
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return (i==n);
    }
    int helper(int i,int prev,int n,vector<string>& words,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int notTake = helper(i+1,prev,n,words,dp);
        int take = 0;
        if(prev==-1 || check(words[prev],words[i]))
        {
            take = 1+helper(i+1,i,n,words,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(words.begin(),words.end(),[](auto a,auto b){
            return a.size()<b.size();
        });
        return helper(0,-1,n,words,dp);
    }
};