class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n1 = s.size();
        int n2 = p.size();
        vector<int>f1(26,0);
        for(char ch:p)
        {
            f1[ch-'a']++;
        }
        vector<int>f2(26,0);
        for(int i=0;i<n1;i++)
        {
            f2[s[i]-'a']++;
            if(i>=n2)
            {
                f2[s[i-n2]-'a']--;
            }
            if(f1==f2)
            {
                ans.push_back(i-n2+1);
            }
        }
        return ans;
    }
};