class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxVal=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>minHeap;
        for(int i=0;i<nums.size();i++)
        {
            maxVal=max(maxVal,nums[i][0]);
            minHeap.push({nums[i][0],i,0});
        }
        int st=0;
        int end=maxVal;
        while(true)
        {
            auto curr=minHeap.top();
            minHeap.pop();
            int val=curr[0];
            int r=curr[1];
            int c=curr[2];

            if(end-st>maxVal-val)
            {
                st=val;
                end=maxVal;
            }
                if(c<nums[r].size()-1)
                {
                    minHeap.push({nums[r][c+1],r,c+1});
                    maxVal = max(maxVal,nums[r][c+1]);
                }
                else
                {
                    break;
                }
        }
        return {st,end};
    }
};