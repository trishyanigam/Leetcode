class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> count;

        for(int i = 0; i <= n - k; i++)
        {
            set<int> st;

            // Current subarray of size k
            for(int j = i; j < i + k; j++)
            {
                st.insert(nums[j]);
            }

            // Each number counted once for this subarray
            for(int x : st)
            {
                count[x]++;
            }
        }

        int ans = -1;

        for(auto it : count)
        {
            if(it.second == 1)
            {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};