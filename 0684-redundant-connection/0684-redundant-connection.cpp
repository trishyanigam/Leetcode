class Solution {
public:

    int findParent(int node,vector<int>& parent)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findParent(parent[node],parent);
    }
    bool Union(int u,int v,vector<int>& parent,vector<int>& rank)
    {
        u = findParent(u,parent);
        v = findParent(v,parent);
        if(u==v)
        {
            return false;
        }
        if(rank[u]<rank[v])
        {
            parent[u] = v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1,0);
        vector<int>rank(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
        for(auto &e:edges)
        {
            int u = e[0];
            int v = e[1];
            if(!Union(u,v,parent,rank))
            {
                return e;
            }
        }
        return {};
    }
};