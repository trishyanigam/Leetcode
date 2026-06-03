class Solution {
public:
    long long solve(vector<int>& startA, vector<int>& durA,
                    vector<int>& startB, vector<int>& durB) {

        vector<long long> ends;
        for (int i = 0; i < startA.size(); i++) {
            ends.push_back(1LL * startA[i] + durA[i]);
        }

        sort(ends.begin(), ends.end());

        long long ans = LLONG_MAX;

        for (int j = 0; j < startB.size(); j++) {
            long long s = startB[j];

            auto it = upper_bound(ends.begin(), ends.end(), s);

            long long startSecond;

            if (it == ends.begin()) {
                // all end times > s
                startSecond = *it;
            } else {
                // some end time <= s
                startSecond = s;
            }

            ans = min(ans, startSecond + durB[j]);
        }

        return ans;
    }

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long landFirst =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long waterFirst =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(landFirst, waterFirst);
    }
};