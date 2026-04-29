class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto&a,auto&b){
            return a[1]<b[1];
        });
        int rem=0;
        int end=intervals[0][1];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<end)
            {
                rem++;
            }
            else
            {
                end=intervals[i][1];
            }
        }
        return rem;
    }
};