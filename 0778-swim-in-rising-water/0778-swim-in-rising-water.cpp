class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0],0,0});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!pq.empty())
        {
            int time = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];

            pq.pop();

            if(vis[r][c]) continue;
            vis[r][c] = 1;
            if(r==n-1 && c==n-1)
            return time;
            for(int i=0;i<4;i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc])
                {
                    pq.push({max(time,grid[nr][nc]),nr,nc});
                }
            }
        }
        return -1;
    }
};