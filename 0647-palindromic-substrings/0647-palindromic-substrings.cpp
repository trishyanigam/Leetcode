class Solution {
public:
    int expand(int l,int r,int n,string& s)
    {
        int cnt=0;
        while(l>=0 && r<n && s[l]==s[r])
        {
            cnt++;

            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=expand(i,i,n,s);
            ans+=expand(i,i+1,n,s);
        }
        return ans;
    }
};