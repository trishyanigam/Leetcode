class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char ch:tasks)
        {
            freq[ch-'A']++;
        }
        int maxFreq = *max_element(freq.begin(),freq.end());
        int maxCnt = 0;
        for(int f:freq)
        {
            if(f==maxFreq)
            {
                maxCnt++;
            }
        }
        int ans = (maxFreq-1)*(n+1)+maxCnt;
        return max((int)tasks.size(),ans);
    }
};