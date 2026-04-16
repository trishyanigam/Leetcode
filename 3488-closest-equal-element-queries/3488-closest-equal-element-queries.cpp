class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        // Step 2: Process queries
        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            int m = vec.size();
            
            // Binary search
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int pos = it - vec.begin();
            
            int mini = INT_MAX;
            
            // Next occurrence (circular)
            int nextIdx = vec[(pos + 1) % m];
            int d1 = abs(nextIdx - q);
            mini = min(mini, min(d1, n - d1));
            
            // Previous occurrence (circular)
            int prevIdx = vec[(pos - 1 + m) % m];
            int d2 = abs(prevIdx - q);
            mini = min(mini, min(d2, n - d2));
            
            ans.push_back(mini);
        }
        
        return ans;
    }
};