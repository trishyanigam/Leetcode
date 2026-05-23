class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        // Count breaking points
        for(int i = 0; i < n; i++)
        {
            // Compare current element with next element
            if(nums[i] > nums[(i + 1) % n])
            {
                count++;
            }
        }

        // Valid only if at most one drop exists
        return count <= 1;
    }
};