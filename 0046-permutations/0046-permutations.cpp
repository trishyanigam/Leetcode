class Solution {
public:
    void helper(vector<int>& nums,int n,vector<int>& path,vector<bool>& used,vector<vector<int>>& ans)
    {
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
            helper(nums,n,path,used,ans);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(n,false);
        helper(nums,n,path,used,ans);
        return ans;
    }
};