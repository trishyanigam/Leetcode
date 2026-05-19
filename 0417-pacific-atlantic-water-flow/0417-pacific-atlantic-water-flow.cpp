class Solution {
public:
    void dfs(int r,int c,int n,int m,vector<vector<int>>& heights,vector<vector<int>>& vis)
    {
        vis[r][c] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[r][c])
            {
                dfs(nr,nc,n,m,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            dfs(0,j,n,m,heights,pacific);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,0,n,m,heights,pacific);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,m-1,n,m,heights,atlantic);
        }
        for(int j=0;j<m;j++)
        {
            dfs(n-1,j,n,m,heights,atlantic);
        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};