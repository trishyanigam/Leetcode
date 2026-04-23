class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Step 1: group indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // Step 2: process each group
        for(auto &it : mp) {
            vector<int> &v = it.second;
            int sz = v.size();

            // total sum of indices
            long long totalSum = 0;
            for(int x : v) totalSum += x;

            long long prefixSum = 0;

            for(int k = 0; k < sz; k++) {
                int idx = v[k];

                // left contribution
                long long left = (long long)k * idx - prefixSum;

                // right contribution
                long long right = (totalSum - prefixSum - idx) 
                                  - (long long)(sz - k - 1) * idx;

                ans[idx] = left + right;

                prefixSum += idx;
            }
        }

        return ans;
    }
};