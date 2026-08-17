class Solution {
public:
    int helper(int i, int j, vector<int>& stoneValue,
               vector<vector<int>>& dp,
               vector<int>& prefix) {

        if(i == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for(int k = i; k < j; k++) {

            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if(leftSum < rightSum) {
                ans = max(ans,
                          leftSum + helper(i, k, stoneValue, dp, prefix));
            }
            else if(leftSum > rightSum) {
                ans = max(ans,
                          rightSum + helper(k + 1, j, stoneValue, dp, prefix));
            }
            else {
                ans = max(ans,
                          max(leftSum + helper(i, k, stoneValue, dp, prefix),
                              rightSum + helper(k + 1, j, stoneValue, dp, prefix)));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, n - 1, stoneValue, dp, prefix);
    }
};