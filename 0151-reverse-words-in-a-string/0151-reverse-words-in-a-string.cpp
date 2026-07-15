class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stringstream ss(s);
        string word;
        while(ss>>word)
        {
            ans=word+' '+ans;
        }
        if(!ans.empty())
        {
            ans.pop_back();
        }
        return ans;
    }
};