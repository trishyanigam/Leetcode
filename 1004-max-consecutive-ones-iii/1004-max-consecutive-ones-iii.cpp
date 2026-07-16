class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int zeroes = 0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                zeroes++;
            }
            while(zeroes>k)
            {
                if(nums[l]==0)
                {
                    zeroes--;
                }
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};