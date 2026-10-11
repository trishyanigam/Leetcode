class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int x:nums)
        {
            totSum+=x;
        }
        int ls=0;
        for(int i=0;i<n;i++)
        {
            int rs = totSum-ls-nums[i];
            if(ls==rs)
            {
                return i;
            }
            ls+=nums[i];
        }
        return -1;
    }
};