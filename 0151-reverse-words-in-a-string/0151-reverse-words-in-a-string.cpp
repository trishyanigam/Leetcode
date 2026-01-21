class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word,res;
        while(ss>>word)
        {
            res = word+" "+res;
        }
        if(!res.empty())
        {
            res.pop_back();
        }
        return res;
    }
};