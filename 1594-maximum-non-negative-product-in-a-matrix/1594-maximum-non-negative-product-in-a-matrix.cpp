class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        const long long MOD = 1e9 + 7;

        vector<vector<long long>> maxDp(m, vector<long long>(n));
        vector<vector<long long>> minDp(m, vector<long long>(n));

        maxDp[0][0] = minDp[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            maxDp[0][j] = minDp[0][j] = maxDp[0][j-1] * grid[0][j];
        }

        // first column
        for (int i = 1; i < m; i++) {
            maxDp[i][0] = minDp[i][0] = maxDp[i-1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];

                long long mx = max({
                    val * maxDp[i-1][j],
                    val * minDp[i-1][j],
                    val * maxDp[i][j-1],
                    val * minDp[i][j-1]
                });

                long long mn = min({
                    val * maxDp[i-1][j],
                    val * minDp[i-1][j],
                    val * maxDp[i][j-1],
                    val * minDp[i][j-1]
                });

                maxDp[i][j] = mx;
                minDp[i][j] = mn;
            }
        }

        long long ans = maxDp[m-1][n-1];

        if (ans < 0) return -1;
        return ans % MOD;
    }
};