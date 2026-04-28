class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for (auto &row : grid) {
            for (int num : row) {
                arr.push_back(num);
            }
        }

        sort(arr.begin(), arr.end());

        int median = arr[arr.size() / 2];
        int ops = 0;

        for (int num : arr) {
            if (abs(num - median) % x != 0)
                return -1;

            ops += abs(num - median) / x;
        }

        return ops;
    }
};