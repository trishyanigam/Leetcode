class Solution {
public:
    void helper(int st,string& digits,vector<string>& mapping,string &path,vector<string>& ans)
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
            helper(st+1,digits,mapping,path,ans);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string path = "";
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(0,digits,mapping,path,ans);
        return ans; 
    }
};