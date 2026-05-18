class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& vis2,stack<int>& st,vector<int> adj[])
    {
        vis[node] = 1;
        vis2[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,vis2,st,adj))
                {
                    return true;
                }
            }
            else if(vis2[it])
            {
                return true;
            }
        }
        st.push(node);
        vis2[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> adj[numCourses];
        for(auto it:prerequisites)
        {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int>vis(numCourses,0);
        vector<int>vis2(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,vis2,st,adj))
                {
                    return {};
                }
            }
        }
        while(!st.empty())
        {
            int el = st.top();
            st.pop();
            ans.push_back(el);
        }
        return ans;
    }
};