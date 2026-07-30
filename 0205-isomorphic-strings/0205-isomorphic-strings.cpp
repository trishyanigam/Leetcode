class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m)
        {
            return false;
        }
        vector<int>freq1(256,-1);
        vector<int>freq2(256,-1);
        for(int i=0;i<n;i++)
        {
            if(freq1[s[i]]==-1 && freq2[t[i]]==-1)
            {
                freq1[s[i]] = t[i];
                freq2[t[i]] = s[i];
            }
            else
            {
                if(freq1[s[i]]!=t[i] || freq2[t[i]]!=s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};