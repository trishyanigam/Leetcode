class Solution {
public:
    bool isNonDecreasing(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int op=0;
        while(!isNonDecreasing(nums))
        {
            int minSum=INT_MAX;
            int idx;
            int n=nums.size();
            int sum=0;
            for(int i=0;i+1<n;i++)
            {
                sum=nums[i]+nums[i+1];
                if(sum<minSum)
                {
                    minSum=sum;
                    idx=i;
                }
            }
            nums[idx]=minSum;
            nums.erase(nums.begin()+idx+1);
            op++;
        }
        return op;
        
    }
};