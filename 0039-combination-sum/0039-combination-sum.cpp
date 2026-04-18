class Solution {
public:
    void helper(int i,vector<int>& arr,int tar,vector<int>& path,vector<vector<int>>& ans)
    {
        int n = arr.size();
        if(i==n)
        {
            if(tar==0)
            {
                ans.push_back(path);
            }
            return;
        }

        if(arr[i]<=tar)
        {
            path.push_back(arr[i]);
            helper(i,arr,tar-arr[i],path,ans);
            path.pop_back();
        }
        helper(i+1,arr,tar,path,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(0,candidates,target,path,ans);
        return ans;
    }
};