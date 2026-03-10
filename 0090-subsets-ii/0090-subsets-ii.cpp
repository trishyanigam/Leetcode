class Solution {
public:
    void helper(int i,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        ans.push_back(temp);

        for(int j=i;j<n;j++)
        {
            if(j>i && nums[j]==nums[j-1])
            {
                continue;
            }
            temp.push_back(nums[j]);
            helper(j+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        helper(0,n,nums,temp,ans);
        return ans;
    }
};