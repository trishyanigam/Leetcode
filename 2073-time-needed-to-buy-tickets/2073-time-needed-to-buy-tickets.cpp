class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++)
        {
            q.push({tickets[i],i});
        }
        int time = 0;
        while(!q.empty())
        {
            auto[t,idx] = q.front();
            q.pop();

            t--;
            time++;

            if(t==0&&idx==k)
            {
                return time;
            }
            if(t>0)
            {
                q.push({t,idx});
            }
        }
        return time;
    }
};