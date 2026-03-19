class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> ps(n, vector<int>(m, 0));
        vector<vector<int>> px(n, vector<int>(m, 0));

        // Build prefix sums
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                ps[i][j] = val;
                px[i][j] = (grid[i][j] == 'X');

                if(i > 0) {
                    ps[i][j] += ps[i-1][j];
                    px[i][j] += px[i-1][j];
                }
                if(j > 0) {
                    ps[i][j] += ps[i][j-1];
                    px[i][j] += px[i][j-1];
                }
                if(i > 0 && j > 0) {
                    ps[i][j] -= ps[i-1][j-1];
                    px[i][j] -= px[i-1][j-1];
                }
            }
        }

        int count = 0;

        // Count valid submatrices
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ps[i][j] == 0 && px[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};