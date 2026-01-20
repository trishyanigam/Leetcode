class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int x : nums) {
            // If x is even, it's impossible
            if ((x & 1) == 0) {
                ans.push_back(-1);
                continue;
            }
            
            // Count trailing ones
            int cnt = 0;
            int temp = x;
            while (temp & 1) {
                cnt++;
                temp >>= 1;
            }
            
            // Minimum possible value
            ans.push_back(x - (1 << (cnt - 1)));
        }
        
        return ans;
    }
};
