class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b)
        {
            return a[1]<b[1];
        });
        int cnt=0;
        int last=INT_MIN;
        for(auto &it:pairs)
        {
            if(it[0]>last)
            {
                cnt++;
                last=it[1];
            }
        }
        return cnt;
    }
};