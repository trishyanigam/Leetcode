class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0;
        int ans = 0;
        while(r<n-1)
        {
            int maxReach = 0;
            for(int i=l;i<=r;i++)
            {
                maxReach = max(maxReach,i+nums[i]);
            }
            l=r+1;
            r=maxReach;
            ans++;
        }
        return ans;
    }
};