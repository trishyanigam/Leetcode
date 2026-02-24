class Solution {
public:
    void dfs(int i,int j,int n,int m, vector<vector<int>>&vis,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || vis[i][j])
        {
            return;
        }
        vis[i][j]=true;
        dfs(i-1,j,n,m,vis,grid);
        dfs(i+1,j,n,m,vis,grid);
        dfs(i,j-1,n,m,vis,grid);
        dfs(i,j+1,n,m,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(i,j,n,m,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};