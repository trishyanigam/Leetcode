class Solution {
public:
    string expand(int l,int r,string& s)
    {
        while(l>=0 && r<s.length() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            string odd = expand(i,i,s);
            if(odd.length()>ans.length())
            {
                ans=odd;
            }

            string even = expand(i,i+1,s);
            if(even.length()>ans.length())
            {
                ans=even;
            }
        }

        return ans;
    }
};