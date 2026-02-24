class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int V=isConnected.size();
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};