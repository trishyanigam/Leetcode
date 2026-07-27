class Solution {
public:
    string expand(int l,int r,int n,string s)
    {
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        for(int i=0;i<n;i++)
        {
            string odd = expand(i,i,n,s);
            if(odd.length()>ans.length())
            {
                ans = odd;
            }
            string even = expand(i,i+1,n,s);
            if(even.length()>ans.length())
            {
                ans = even;
            }
        }
        return ans;
    }
};