class Solution {
public:
    bool isPalindrome(int i,int j,string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(int st, string s,vector<string> &path,vector<vector<string>> &ans)
    {
        if(st==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=st;i<s.size();i++)
        {
            if(isPalindrome(st,i,s))
            {
                path.push_back(s.substr(st,i-st+1));
                helper(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,path,ans);
        return ans;
    }
};