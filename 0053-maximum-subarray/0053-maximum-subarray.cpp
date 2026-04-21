class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum=0;
        for(int n:nums)
        {
            sum+=n;
            ans = max(ans,sum);
            if(sum<0)
            {
                sum=0;
            }            
        }
        return ans;
    }
};