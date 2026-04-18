class Solution {
public:
    void helper(int i,vector<int>& arr,int tar,vector<int>& path,vector<vector<int>>& ans)
    {
        int n=arr.size();
            if(tar==0)
            {
                ans.push_back(path);
                return;
            }

        for(int j=i;j<n;j++)
        {
            if(j>i && arr[j]==arr[j-1])
            {
                continue;
            }
            if(arr[j]>tar)
            {
                break;
            }
            path.push_back(arr[j]);
            helper(j+1,arr,tar-arr[j],path,ans);
            path.pop_back();
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