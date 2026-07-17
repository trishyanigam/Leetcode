class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[v] = how many elements in nums equal v
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs (i, j) with gcd(nums[i], nums[j]) == g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            // count how many elements are multiples of g
            long long cnt = 0;
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            // total pairs whose gcd is a multiple of g (i.e. divides evenly by g)
            exact[g] = cnt * (cnt - 1) / 2;

            // subtract pairs whose gcd is a larger multiple of g
            // (inclusion-exclusion, processed g from high to low so exact[2g], exact[3g]... are ready)
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exact[g] -= exact[multiple];
        }

        // prefix[g] = number of pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        // answer each query via binary search on prefix (finds smallest g s.t. prefix[g] > q)
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            int lo = 1, hi = mx;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid] > q) hi = mid;
                else lo = mid + 1;
            }
            ans.push_back(lo);
        }

        return ans;
    }
};