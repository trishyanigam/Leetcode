class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2 && vis[i][j]==-1)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int ans = 0;

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            ans = max(ans,t);

            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==-1)
                {
                    q.push({{nr,nc},t+1});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==-1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};