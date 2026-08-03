class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                el=nums[i];
                cnt++;
            }
            else if(nums[i]==el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int tar = n/2;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el)
            {
                cnt2++;
            }
        }
        if(cnt2>tar)
        {
            return el;
        }
        return -1;
    }
};