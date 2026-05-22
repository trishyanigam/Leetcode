class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        for(int i=0;i<points.size();i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            double dist = sqrt(x1*x1+y1*y1);
            pq.push({dist,i});
        }
        for(int i=0;i<k;i++)
        {
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};