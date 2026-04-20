class Solution {
public:
    void helper(int st,string &path,vector<string> mapping,string digits,vector<string> &ans)
    {
        if(st==digits.size())
        {
            ans.push_back(path);
            return;
        }
        string letter = mapping[digits[st]-'0'];
        for(char ch:letter)
        {
            path.push_back(ch);
            helper(st+1,path,mapping,digits,ans);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mapping = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        string path = "";
        helper(0,path,mapping,digits,ans);
        return ans;
    }
};