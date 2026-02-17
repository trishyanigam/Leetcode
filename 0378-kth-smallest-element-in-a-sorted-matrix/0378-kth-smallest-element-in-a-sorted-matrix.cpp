class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],i,0});
        }
        while(--k)
        {
            auto [val,r,c] = pq.top();
            pq.pop();
            if(c+1<n)
            {
                pq.push({matrix[r][c+1],r,c+1});
            }
        }
        return get<0>(pq.top());
    }
};