class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        for(int n:nums)
        {
            res^=n;
        }
        return res;
    }
};