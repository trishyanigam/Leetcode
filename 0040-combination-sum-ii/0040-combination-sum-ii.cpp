class Solution {
public:
    void helper(int st,vector<int>& arr,int tar,vector<int>& curr,vector<vector<int>>& ans)
    {
        if(tar==0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=st;i<arr.size();i++)
        {
            if(i>st && arr[i]==arr[i-1])
            continue;

            if(arr[i]>tar)
            break;

            curr.push_back(arr[i]);
            helper(i+1,arr,tar-arr[i],curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,candidates,target,curr,ans);
        return ans;
    }
};