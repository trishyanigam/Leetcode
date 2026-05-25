class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int>minDis(n,INT_MAX);
        vector<bool>vis(n,false);
        minDis[0] = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int u = -1;
            for(int j=0;j<n;j++)
            {
                if(!vis[j] && (u==-1 || minDis[j]<minDis[u]))
                {
                    u=j;
                }
            }
            vis[u] = true;
            ans+=minDis[u];

            for(int v=0;v<n;v++)
            {
                if(!vis[v])
                {
                    int cost = abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    minDis[v] = min(minDis[v],cost);
                }
            }
        }
        return ans;
    }
};