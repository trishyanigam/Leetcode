class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& vis2)
    {
        vis[i]=1;
        vis2[i]=1;
        for(auto it:adj[i])
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
        vis2[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
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