class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        for(char ch:s)
        {
            f1[ch-'a']++;
        }
        for(char ch:t)
        {
            f2[ch-'a']++;
        }
        if(f1==f2)
        {
            return true;
        }
        return false;
    }
};