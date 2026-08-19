class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Only seats 2 to 9 matter
            if (s >= 2 && s <= 9) {
                rows[row] |= (1 << s);
            }
        }

        // Initially every row can accommodate 2 families
        long long ans = 2LL * n;

        for (auto &[row, mask] : rows) {

            // Check left block: 2,3,4,5
            bool left = true;
            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << s)) {
                    left = false;
                    break;
                }
            }

            // Check right block: 6,7,8,9
            bool right = true;
            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << s)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                // Still 2 families
                continue;
            }

            // Check middle block: 4,5,6,7
            bool middle = true;
            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << s)) {
                    middle = false;
                    break;
                }
            }

            // This row can accommodate at most 1 family
            if (left || middle || right) {
                ans--;
            }
            else {
                // Cannot accommodate any family
                ans -= 2;
            }
        }

        return ans;
    }
};