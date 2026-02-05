class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        int idx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                int move=0;
                int j=i;
                while(move<nums[i])
                {
                    move++;
                    j++;
                    if(j==n)
                    {
                        j=j%n;
                    }
                }
                res[idx++]=nums[j];
            }
            else if(nums[i]<0)
            {
                int move=0;
                int j=i;
                while(move<abs(nums[i]))
                {
                    move++;
                    j--;
                    if(j<0)
                    {
                        j=n-1;
                    }
                }
                res[idx++]=nums[j];
            }
            else
            {
                res[idx++]=nums[i];
            }
        }
        return res;
    }
};