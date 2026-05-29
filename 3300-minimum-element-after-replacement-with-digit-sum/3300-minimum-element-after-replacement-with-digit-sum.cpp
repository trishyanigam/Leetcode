class Solution {
public:
    int sumOfElement(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int ans = INT_MAX;
    int minElement(vector<int>& nums) {
        for(int num:nums)
        {
            int s = sumOfElement(num);
            ans=min(ans,s);
        }
        return ans;
    }
};