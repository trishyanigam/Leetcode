class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return {0};
        }
        vector<int>ans;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==1)
            {
                q.push(i);
            }
        }
        int rem=n;
        while(rem>2)
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int node=q.front();
                q.pop();
                for(int neigh:adj[node])
                {
                    indeg[neigh]--;
                    if(indeg[neigh]==1)
                    {
                        q.push(neigh);
                    }
                }
            }
            rem-=s;
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};