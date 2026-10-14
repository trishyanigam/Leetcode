class Solution {
public:
    bool isValid(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                if(isValid(s,l+1,r) || isValid(s,l,r-1))
                {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};