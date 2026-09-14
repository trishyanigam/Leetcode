class Solution {
public:
    bool isPalin(int l,int r,string& s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(int st,int n,string& s,vector<string>& path,vector<vector<string>>& ans)
    {
        if(st==n)
        {
            ans.push_back(path);
            return;
        }
        for(int i=st;i<n;i++)
        {
            if(isPalin(st,i,s))
            {
                path.push_back(s.substr(st,i-st+1));
                helper(i+1,n,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> path;
        helper(0,n,s,path,ans);
        return ans;
    }
};