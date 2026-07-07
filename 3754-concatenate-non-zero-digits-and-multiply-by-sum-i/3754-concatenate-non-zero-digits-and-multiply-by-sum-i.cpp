class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> changed;
        while(n>0)
        {
            if(n%10!=0)
            {
                changed.push_back(n%10);
            }
            n/=10;
        }
        reverse(changed.begin(),changed.end());
        int sum=0;
        for(int x:changed)
        {
            sum+=x;
        }
        long long ans = 0;
        for(int x:changed)
        {
            ans=ans*10+x;
        }
        return ans*sum;
    }
};