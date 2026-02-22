class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
        {
            return 0;
        }
        int n=nums.size();
        int cnt=0;
        int pro=1;
        int left=0;
        for(int r=0;r<n;r++)
        {
            pro*=nums[r];
            while(pro>=k)
            {
                pro/=nums[left];
                left++;
            }
            cnt+=r-left+1;
        }
        return cnt;
    }
};