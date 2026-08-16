class Solution {
public:
    void helper(int i,int sum,vector<int>& candidates, int target,vector<int>& path,vector<vector<int>>& ans)
    {
        if(i==candidates.size())
        {
            if(sum==target)
            {
                ans.push_back(path);
            }
            return;
        }
        if(sum>target)
        {
            return;
        }
        path.push_back(candidates[i]);
        helper(i,sum+candidates[i],candidates,target,path,ans);
        path.pop_back();

        helper(i+1,sum,candidates,target,path,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        helper(0,0,candidates,target,path,ans);
        return ans;
    }
};