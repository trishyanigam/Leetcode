class Solution {
public:
    long long dp[101][101];

    long long solve(int i, int j, vector<int>& robots, vector<vector<int>>& factories) {
        // all robots assigned
        if(i == robots.size()) return 0;

        // no factories left but robots remain
        if(j == factories.size()) return 1e18;

        if(dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j+1, robots, factories); // skip current factory

        long long dist = 0;
        int capacity = factories[j][1];

        // try assigning k robots to this factory
        for(int k = 0; k < capacity && i + k < robots.size(); k++) {
            dist += abs(robots[i + k] - factories[j][0]);
            ans = min(ans, dist + solve(i + k + 1, j + 1, robots, factories));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, robots, factories);
    }
};