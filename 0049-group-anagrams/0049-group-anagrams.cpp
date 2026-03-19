class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>mp;
        for(string s:strs)
        {
            vector<int>freq(26,0);
            for(char c:s)
            {
                freq[c-'a']++;
            }
            string key="";
            for(int el:freq)
            {
                key+=to_string(el)+'#';
            }
            mp[key].push_back(s);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};