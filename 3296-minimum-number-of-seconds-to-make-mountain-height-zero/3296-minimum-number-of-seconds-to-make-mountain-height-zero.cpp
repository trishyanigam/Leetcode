class Solution {
public:

    bool can(long long T, int H, vector<int>& workerTimes){
        long long total = 0;

        for(int w : workerTimes){
            long long left = 0, right = 1e6;

            while(left <= right){
                long long mid = (left + right) / 2;

                long long time = (long long)w * mid * (mid + 1) / 2;

                if(time <= T){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            total += right;

            if(total >= H) return true;
        }

        return total >= H;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left = 0, right = 1e18;
        long long ans = right;

        while(left <= right){
            long long mid = (left + right) / 2;

            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};