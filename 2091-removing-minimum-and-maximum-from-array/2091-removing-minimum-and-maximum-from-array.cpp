class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // 1. Both removed from left
        int option1 = right + 1;

        // 2. Both removed from right
        int option2 = n - left;

        // 3. One from left, one from right
        int option3 = left + 1 + (n - right);

        return min({option1, option2, option3});
    }
};