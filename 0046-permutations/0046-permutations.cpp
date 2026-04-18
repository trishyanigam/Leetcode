class Solution {
public:
    void helper(vector<int>& nums,vector<int>& path,vector<bool>&used,vector<vector<int>>& ans)
    {
        int n = nums.size();
        if(path.size()==n)
        {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i]=true;
            path.push_back(nums[i]);
            helper(nums,path,used,ans);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        helper(nums,path,used,ans);
        return ans;
    }
};