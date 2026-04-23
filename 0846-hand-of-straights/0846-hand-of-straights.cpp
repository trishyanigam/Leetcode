class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)
        {
            return false;
        }
        map<int,int>mp;
        for(int num:hand)
        {
            mp[num]++;
        }
        for(auto it:mp)
        {
            int el=it.first;
            int cnt=it.second;
            if(cnt>0)
            {
                for(int i=0;i<groupSize;i++)
                {
                    if(mp[el+i]<cnt)
                    {
                        return false;
                    }
                    mp[el+i]-=cnt;
                }
            }
        }
        return true;
    }
};