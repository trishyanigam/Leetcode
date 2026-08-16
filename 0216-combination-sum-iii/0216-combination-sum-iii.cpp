class Solution {
public:
    void helper(int i,int s,int k,int n,vector<int>& arr,vector<int>& path,vector<vector<int>>& ans)
    {
        if(i==s)
        {
            if(n==0 && k==0)
            {
                ans.push_back(path);
            }
            return;
        }
        if(arr[i]<=n)
        {
            path.push_back(arr[i]);
            helper(i+1,s,k-1,n-arr[i],arr,path,ans);
            path.pop_back();
        }
        helper(i+1,s,k,n,arr,path,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> path;
        helper(0,9,k,n,arr,path,ans);
        return ans;
    }
};