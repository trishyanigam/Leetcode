class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(char c:moves)
        {
            if(c=='U')
            {
                x=x-1;
            }
            else if(c=='D')
            {
                x=x+1;
            }
            else if(c=='L')
            {
                y=y-1;
            }
            else
            {
                y=y+1;
            }
        }
        if(x==0 && y==0)
        {
            return true;
        }
        return false;
    }
};