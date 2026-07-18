class Solution {
public:
    int cntSub(vector<int>& nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int odd = 0;
        int ans = 0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]%2!=0)
            {
                odd++;
            }
            while(odd>k)
            {
                if(nums[l]%2!=0)
                {
                    odd--;
                }
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cntSub(nums,k)-cntSub(nums,k-1);
    }
};