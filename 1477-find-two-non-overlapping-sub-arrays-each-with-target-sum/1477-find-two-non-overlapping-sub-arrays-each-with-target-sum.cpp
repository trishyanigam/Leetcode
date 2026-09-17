class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside indices [0 ... i]
        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;
        int minLen = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            // Found a subarray [left ... right]
            if (sum == target) {
                int len = right - left + 1;

                // If there was a previous valid subarray
                // ending before 'left', combine them
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                minLen = min(minLen, len);
            }

            // Best valid subarray ending anywhere up to right
            if (right == 0)
                best[right] = minLen;
            else
                best[right] = min(best[right - 1], minLen);
        }

        return ans == INF ? -1 : ans;
    }
};