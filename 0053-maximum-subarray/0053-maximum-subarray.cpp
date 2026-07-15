class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int ans=0;
        for(int x:nums)
        {
            sum+=x;
            ans=max(ans,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return ans;
    }
};