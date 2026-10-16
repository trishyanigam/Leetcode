class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        unordered_map<char,int>mp;
        for(char c:t)
        {
            mp[c]++;
        }
        int cnt = 0;
        int l = 0;
        int ans = INT_MAX;
        int st = 0;
        for(int r=0;r<n1;r++)
        {
            if(mp[s[r]]>0)
            {
                cnt++;
            }
            mp[s[r]]--;
            while(cnt==t.size())
            {
                if(r-l+1<ans)
                {
                    ans=r-l+1;
                    st=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0)
                {
                    cnt--;
                }
                l++;
            }
        }
        if(ans==INT_MAX)
        {
            return "";
        }
        return s.substr(st,ans);
    }
};