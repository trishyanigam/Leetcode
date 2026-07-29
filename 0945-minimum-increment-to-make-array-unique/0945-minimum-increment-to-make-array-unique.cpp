class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1])
            {
                int req = nums[i-1]+1;
                moves+=req-nums[i];
                nums[i] = req;
            }
        }
        return moves;
    }
};