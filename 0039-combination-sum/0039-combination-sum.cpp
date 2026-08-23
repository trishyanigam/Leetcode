class Solution {
public:
    void helper(int i,int n,vector<int>& arr,int tar,vector<int>& path,vector<vector<int>>& ans)
    {
        if(tar==0)
        {
            ans.push_back(path);
            return;
        }
        if(i==n)
        {
            return;
        }
        if(arr[i]<=tar)
        {
            path.push_back(arr[i]);
            helper(i,n,arr,tar-arr[i],path,ans);
            path.pop_back();
        }

        helper(i+1,n,arr,tar,path,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> path;
        vector<vector<int>> ans;
        helper(0,n,candidates,target,path,ans);
        return ans;
    }
};