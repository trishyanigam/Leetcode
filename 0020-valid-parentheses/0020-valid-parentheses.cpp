class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                char ch2 = st.top();
                st.pop();
                if((ch2=='(' && ch==')') || (ch2=='[' && ch==']') || (ch2=='{' && ch=='}'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};