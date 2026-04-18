class Solution {
public:
    void helper(int open,int close,int n,string path,vector<string>& ans)
    {
        if(path.size()==2*n)
        {
            ans.push_back(path);
            return;
        }
        if(open<n)
        {
            path.push_back('(');
            helper(open+1,close,n,path,ans);
            path.pop_back();
        }
        if(close<open)
        {
            path.push_back(')');
            helper(open,close+1,n,path,ans);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path = "";
        helper(0,0,n,path,ans);
        return ans;
    }
};