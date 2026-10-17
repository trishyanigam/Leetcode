class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty())
        {
            char ch = pq.top().second;
            int freq = pq.top().first;
            while(freq--)
            {
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};