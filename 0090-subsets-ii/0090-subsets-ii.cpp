class Solution {
public:
    void helper(int st,int n,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans)
    {
        ans.push_back(path);
        
        for(int i=st;i<n;i++)
        {
            if(i>st && nums[i]==nums[i-1])
            {
                continue;
            }
            path.push_back(nums[i]);
            helper(i+1,n,nums,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        helper(0,n,nums,path,ans);
        return ans;
    }
};