class Solution {
public:
    bool dfs(int r,int c,int pr,int pc,int n,int m,vector<vector<bool>>&vis,vector<vector<char>>& grid)
    {
        vis[r][c]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==grid[r][c])
            {
                if(!vis[nr][nc])
                {
                    if(dfs(nr,nc,r,c,n,m,vis,grid))
                    {
                        return true;
                    }
                }
                else if(pr!=nr || pc!=nc)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    if(dfs(i,j,-1,-1,n,m,vis,grid))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};