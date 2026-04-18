class Solution {
public:
    void helper(int st,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans)
    {
        ans.push_back(path);
        for(int i=st;i<nums.size();i++)
        {
            if(i>st && nums[i]==nums[i-1])
            {
                continue;
            }
            path.push_back(nums[i]);
            helper(i+1,nums,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       vector<int> path;
       helper(0,nums,path,ans); 
       return ans;
    }
};