class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If number of 0-mod-3 stones is even,
        // Alice wins when both types exist and
        // neither side dominates too much.
        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        }

        // If number of 0-mod-3 stones is odd,
        // one side must have at least 3 more stones
        // than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};