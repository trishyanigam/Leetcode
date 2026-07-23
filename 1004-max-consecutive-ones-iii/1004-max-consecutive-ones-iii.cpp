class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int cntZero = 0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==0)
            {
                cntZero++;
            }
            while(cntZero>k)
            {
                if(nums[l]==0)
                {
                    cntZero--;
                }
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};