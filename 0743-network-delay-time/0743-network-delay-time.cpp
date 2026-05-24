class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto[d,node] = pq.top();
            pq.pop();
            if(d>dis[node])
                continue;
            for(auto &[neigh,wt]:adj[node])
            {
                if(dis[node]+wt<dis[neigh])
                {
                    dis[neigh] = dis[node]+wt;
                    pq.push({dis[neigh],neigh});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
            {
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};