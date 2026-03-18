class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int el = nums[i];
            int more = target-el;
            if(mp.find(more)!=mp.end())
            {
                return {mp[more],i};
            }
            mp[el]=i;
        }
        return {-1,-1};
    }
};