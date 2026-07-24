class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int dep = 0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                dep++;
                ans = max(ans,dep);
            }
            else if(ch==')')
            {
                dep--;
            }
        }
        return ans;
    }
};