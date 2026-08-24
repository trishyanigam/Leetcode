class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& vis2)
    {
        vis[node]=1;
        vis2[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,vis2))
                {
                    return true;
                }
            }
            else if(vis2[it])
            {
                return true;
            }
        }
        vis2[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int>vis(numCourses,0);
        vector<int>vis2(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,vis2))
                {
                    return false;
                }
            }
        }
        return true;
    }
};