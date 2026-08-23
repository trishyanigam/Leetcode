class Solution {
public:
    void helper(int st,int n,vector<int>& arr,int tar,vector<int> &path,vector<vector<int>>& ans)
    {
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
                helper(i+1,n,arr,tar-arr[i],path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        vector<vector<int>>ans;
        helper(0,n,candidates,target,path,ans);
        return ans;
    }
};