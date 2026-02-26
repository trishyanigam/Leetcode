class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis1,vector<int>&vis2,stack<int>&st)
    {
        vis1[node]=1;
        vis2[node]=1;
        for(int neigh:adj[node])
        {
            if(vis1[neigh]==0)
            {
                if(dfs(neigh,adj,vis1,vis2,st))
                {
                    return true;
                }
            }
            else if(vis2[neigh])
            {
                return true;
            }
        }
        vis2[node]=0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>>adj(numCourses);
        for(auto &p:prerequisites)
        {
            int u=p[0];
            int v=p[1];
            adj[v].push_back(u);
        }
        vector<int>vis1(numCourses,0);
        vector<int>vis2(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++)
        {
            if(vis1[i]==0)
            {
                if(dfs(i,adj,vis1,vis2,st))
                {
                    return {};
                }
            }
        }

        while(!st.empty())
        {
            int el=st.top();
            st.pop();
            ans.push_back(el);
        }
        return ans;
    }
};