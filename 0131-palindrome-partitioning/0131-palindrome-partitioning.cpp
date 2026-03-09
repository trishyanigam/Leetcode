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
    void helper(int i,string& s,vector<string>&path,vector<vector<string>>& ans)
    {
        if(i==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(i,j,s))
            {
                path.push_back(s.substr(i,j-i+1));
                helper(j+1,s,path,ans);
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