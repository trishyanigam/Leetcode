class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(colors[i]!=colors[n-1])
            {
                ans=max(ans,n-i-1);
                break;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(colors[i]!=colors[0])
            {
                ans=max(ans,i);
                break;
            }
        }
        return ans;
    }
};