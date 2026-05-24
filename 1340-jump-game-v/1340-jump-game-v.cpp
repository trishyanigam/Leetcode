class Solution {
public:
    int n;

    int dfs(int idx, vector<int>& arr, int d, vector<int>& dp) {
        
        // If already computed, return stored answer
        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1; // count current index

        // Explore LEFT
        for (int j = idx - 1; j >= max(0, idx - d); j--) {

            // Cannot jump over greater/equal element
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        // Explore RIGHT
        for (int j = idx + 1; j <= min(n - 1, idx + d); j++) {

            // Cannot jump over greater/equal element
            if (arr[j] >= arr[idx])
                break;

            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }

        return dp[idx] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();

        vector<int> dp(n, -1);

        int result = 1;

        // Try starting from every index
        for (int i = 0; i < n; i++) {
            result = max(result, dfs(i, arr, d, dp));
        }

        return result;
    }
};