class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        
        // Prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1]
                             - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        int left = 1, right = min(m, n), ans = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            bool found = false;
            
            for (int i = mid; i <= m && !found; i++) {
                for (int j = mid; j <= n; j++) {
                    int sum = prefix[i][j]
                            - prefix[i - mid][j]
                            - prefix[i][j - mid]
                            + prefix[i - mid][j - mid];
                    
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
            }
            
            if (found) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};
