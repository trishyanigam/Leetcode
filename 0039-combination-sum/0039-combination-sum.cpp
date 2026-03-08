class Solution {
public:
    void helper(int i,vector<int>&curr,vector<vector<int>>&ans,vector<int>&candidates,int target)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[i]<=target)
        {
            curr.push_back(candidates[i]);
            helper(i,curr,ans,candidates,target-candidates[i]);
            curr.pop_back();
        }
        helper(i+1,curr,ans,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr;
        helper(0,curr,ans,candidates,target);
        return ans;
    }
};