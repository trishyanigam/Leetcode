class Solution {
public:
    int maximum(vector<int>& piles)
    {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    int calculate(vector<int>& piles,long long val)
    {
        int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=ceil((double)piles[i]/(double)val);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maximum(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long tot = calculate(piles,mid);
            if(tot<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};