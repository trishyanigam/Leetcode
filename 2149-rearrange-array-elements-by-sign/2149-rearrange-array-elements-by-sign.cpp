class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        vector<int>ans(n);
        int idx=0;
        for(int i=0;i<n/2;i++)
        {
            ans[idx]=pos[i];
            idx+=2;
        }
        int idx2=1;
        for(int i=0;i<n/2;i++)
        {
            ans[idx2]=neg[i];
            idx2+=2;
        }
        return ans;
    }
};