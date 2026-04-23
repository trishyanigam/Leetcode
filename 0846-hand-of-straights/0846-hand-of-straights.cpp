class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> freq;

        for(int num : hand) {
            freq[num]++;
        }

        for(auto &it : freq) {
            int start = it.first;
            int count = it.second;

            if(count > 0) {
                // try to form group starting at 'start'
                for(int i = 0; i < groupSize; i++) {
                    int curr = start + i;

                    if(freq[curr] < count) {
                        return false;
                    }

                    freq[curr] -= count;
                }
            }
        }

        return true;
    }
};