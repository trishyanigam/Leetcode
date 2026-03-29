class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())
        {
            return "";
        }
        string ans="";
        auto &find = mp[key];
        int low=0;
        int high=find.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(find[mid].first<=timestamp)
            {
                ans=find[mid].second;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }

        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */