class Solution {
public:
    bool isGood(int num)
    {
        bool change=false;
        while(num>0)
        {
            int d=num%10;
            if(d==3||d==4||d==7)
            {
                return false;
            }
            if(d==2||d==5||d==6||d==9)
            {
                change=true;
            }
            num/=10;
        }
        return change;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(isGood(i))
            {
                cnt++;
            }
        }
        return cnt;
    }
};