class Solution {
public:
int findmax(vector <int>&v)
{
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        maxi=max(maxi,v[i]);
    }
    return maxi;
}
long long calculate(vector <int >&v,long long hourly)
{
    long long totalH=0;
    for(int i=0;i<v.size();i++)
    {
        totalH+=ceil((double)v[i]/(double)hourly);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findmax(piles);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long totalH=calculate(piles,mid);
            if(totalH<=h)
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