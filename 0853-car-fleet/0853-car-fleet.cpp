class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>>cars;
        for(int i=0;i<n;i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int ans=0;
        double curr=0;
        for(auto &car:cars)
        {
            if(curr<car.second)
            {
                ans++;
                curr=car.second;
            }
        }
        return ans;
    }
};