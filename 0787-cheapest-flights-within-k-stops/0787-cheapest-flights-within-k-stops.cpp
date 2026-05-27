class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &f:flights)
        {
            int u = f[0];
            int v = f[1];
            int c = f[2];
            adj[u].push_back({v,c});
        }
        vector<int>stops(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        while(!pq.empty())
        {
            int cost = pq.top()[0];
            int node = pq.top()[1];
            int stop = pq.top()[2];

            pq.pop();

            if(node==dst)
            {
                return cost;
            }

            if(stop>k ||stop>stops[node])
            {
                continue;
            }

            stops[node] = stop;

            for(auto &it:adj[node])
            {
                int nextNode = it.first;
                int price = it.second;
                pq.push({cost+price,nextNode,stop+1});
            }
        }
        return -1;
    }
};