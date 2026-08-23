class Solution {
public:
    void helper(int st,int n,string digits,vector<string>& mapping,string &path,vector<string>& ans)
    {
        if(st==n)
        {
            ans.push_back(path);
            return;
        }
        string letter = mapping[digits[st]-'0'];
        for(char ch:letter)
        {
            path.push_back(ch);
            helper(st+1,n,digits,mapping,path,ans);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string path = "";
        vector<string> ans;
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(0,n,digits,mapping,path,ans);
        return ans;
    }
};