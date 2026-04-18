class Solution {
public:
    void helper(int st,vector<int>& arr,int tar,vector<int>& path,vector<vector<int>>& ans)
    {
        int n = arr.size();
        if(tar==0)
        {
            ans.push_back(path);
            return;
        }
        for(int i=st;i<n;i++)
        {
            if(i>st && arr[i]==arr[i-1])
            {
                continue;
            }
            if(arr[i]<=tar)
            {
                path.push_back(arr[i]);
                helper(i+1,arr,tar-arr[i],path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        helper(0,candidates,target,path,ans);
        return ans;
    }
};