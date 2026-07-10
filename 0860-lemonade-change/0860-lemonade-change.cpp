class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0,ten= 0,twenty= 0;
        for(int bill:bills)
        {
            if(bill==5)
            {
                five++;
            }
            else if(bill==10)
            {
                if(five==0)
                {
                    return false;
                }
                ten++;
                five--;
            }
            else
            {
                twenty++;
                if(ten>=1 && five>=1)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five-=3;
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