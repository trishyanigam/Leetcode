class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cntFive = 0;
        int cntTen = 0;
        int cntTwenty = 0;
        for(int bill:bills)
        {
            if(bill==5)
            {
                cntFive++;
            }
            else if(bill==10)
            {
                cntTen++;
                if(cntFive==0)
                {
                    return false;
                }
                cntFive--;
            }
            else
            {
                cntTwenty++;
                if(cntTen>=1 && cntFive>=1)
                {
                    cntFive--;
                    cntTen--;
                }
                else if(cntFive>=3)
                {
                    cntFive-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};