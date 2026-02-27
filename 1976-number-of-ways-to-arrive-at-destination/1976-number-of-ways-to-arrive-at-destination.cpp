class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long INF = LLONG_MAX;
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,long long>>>adj(n);
        vector<long long>dist(n,INF);
        vector<int>ways(n);
        for(auto &r:roads)
        {
            int u=r[0];
            int v=r[1];
            int w=r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto [time,node]=pq.top();
            pq.pop();
            if(time>dist[node])
            {
                continue;
            }
            for(auto [nextNode,wt]:adj[node])
            {
                if(dist[nextNode]>time+wt)
                {
                    dist[nextNode]=time+wt;
                    ways[nextNode]=ways[node];
                    pq.push({dist[nextNode],nextNode});
                }
                else if(dist[nextNode]==time+wt)
                {
                    ways[nextNode]=(ways[nextNode]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};