class Solution {
public:
    void helper(int st,int sum,vector<int>& candidates,int tar,int n,vector<int>& path,vector<vector<int>>& ans)
    {
            if(sum==tar)
            {
                ans.push_back(path);
                return;
            }
        for(int i=st;i<n;i++)
        {
            if(i>st && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(sum>tar)
            {
                break;
            }
            path.push_back(candidates[i]);
            helper(i+1,sum+candidates[i],candidates,tar,n,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(0,0,candidates,target,n,path,ans);
        return ans;
    }
};