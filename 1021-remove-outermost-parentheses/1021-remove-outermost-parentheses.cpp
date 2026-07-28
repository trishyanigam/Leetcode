class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        int dep = 0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                if(dep>0)
                {
                    ans+=ch;
                }
                dep++;
            }
            else
            {
                dep--;
                if(dep>0)
                {
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};