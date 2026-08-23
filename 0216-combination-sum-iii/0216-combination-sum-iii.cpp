class Solution {
public:
    void helper(int i,int n,int k,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans)
    {
        if(k==0 && n==0)
        {
            ans.push_back(path);
            return;
        }
        if(i==9)
        {
            return;
        }
        if(nums[i]<=n)
        {
            path.push_back(nums[i]);
            helper(i+1,n-nums[i],k-1,nums,path,ans);
            path.pop_back();
        }
        helper(i+1,n,k,nums,path,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int> path;
        vector<vector<int>> ans;
        helper(0,n,k,nums,path,ans);
        return ans;
    }
};