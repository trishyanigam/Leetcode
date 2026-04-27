class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // directions: up, down, left, right
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        // allowed directions for each street type
        vector<vector<int>> allowed = {
            {},             // dummy (0 unused)
            {2,3},          // type 1 -> left,right
            {0,1},          // type 2 -> up,down
            {2,1},          // type 3 -> left,down
            {3,1},          // type 4 -> right,down
            {2,0},          // type 5 -> left,up
            {3,0}           // type 6 -> right,up
        };

        // opposite directions
        vector<int> opp = {1,0,3,2};

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) return true;

            int type = grid[x][y];

            for(int d : allowed[type]){
                int nx = x + dir[d].first;
                int ny = y + dir[d].second;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(vis[nx][ny]) continue;

                int nextType = grid[nx][ny];

                // check if neighbor connects back
                bool ok = false;
                for(int nd : allowed[nextType]){
                    if(nd == opp[d]){
                        ok = true;
                        break;
                    }
                }

                if(ok){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};