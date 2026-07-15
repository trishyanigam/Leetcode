class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(!pq.empty())
        {
            int f = pq.top().first;
            char ch = pq.top().second;
            while(f--)
            {
                ans+=ch;
            }
            pq.pop();
        }
        return ans;
    }
};