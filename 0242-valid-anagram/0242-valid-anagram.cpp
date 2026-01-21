class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        int alt[26] = {0};
        for(char c:s)
        {
            alt[c-'a']++;
        }
        for(char c:t)
        {
            alt[c-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(alt[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};