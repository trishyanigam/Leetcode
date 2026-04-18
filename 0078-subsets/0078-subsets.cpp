class Solution {
public:
    vector<vector<int>>ans;
    void helper(int st,vector<int>& nums,vector<int>& path)
    {
        ans.push_back(path);
        for(int i=st;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            helper(i+1,nums,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        helper(0,nums,path);
        return ans;
    }
};