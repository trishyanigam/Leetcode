class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l = 0;
        int ans = 0;
        for(int r=0;r<s.size();r++)
        {
            while(st.find(s[r])!=st.end())
            {
                st.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            st.insert(s[r]);
        }
        return ans;
    }
};