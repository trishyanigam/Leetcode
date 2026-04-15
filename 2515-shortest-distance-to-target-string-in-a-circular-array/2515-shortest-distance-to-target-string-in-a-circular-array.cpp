class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                int dis = abs(i-startIndex);
                ans=min(ans,min(dis,n-dis));
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};