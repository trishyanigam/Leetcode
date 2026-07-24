class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
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