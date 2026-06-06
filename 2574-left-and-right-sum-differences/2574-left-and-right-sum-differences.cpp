class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n,0);
        vector<int> rs(n,0);
        int leftSum=0;
        int rightSum=0;
        for(int i=0;i<n;i++)
        {
            ls[i] = leftSum;
            leftSum+=nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            rs[i] = rightSum;
            rightSum+=nums[i];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i] = abs(ls[i]-rs[i]);
        }
        return ans;
    }
};