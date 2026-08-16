class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char,int>mp;
        int l = 0;
        int ans = 0;
        for(int r=0;r<s.size();r++)
        {
            mp[s[r]]++;
            while(mp[s[r]]==k)
            {
                mp[s[l]]--;
                l++;
            }
            ans+=l;
        }
        return ans;
    }
};