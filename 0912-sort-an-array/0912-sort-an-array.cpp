class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums)
        {
            mp[n]++;
        }
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int i=0;
        for(int range=mini;range<=maxi;range++)
        {
            while(mp[range]>0)
            {
                nums[i]=range;
                i++;
                mp[range]--;
            }
        }
        return nums;
    }
};