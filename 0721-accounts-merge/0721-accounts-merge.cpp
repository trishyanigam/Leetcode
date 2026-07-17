class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py)
            parent[px] = py;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        unordered_map<string, int> emailToId; // email -> account index that first owned it
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string &email = accounts[i][j];
                if (emailToId.find(email) != emailToId.end()) {
                    unite(i, emailToId[email]);
                } else {
                    emailToId[email] = i;
                }
            }
        }
        
        // Group emails by root parent
        unordered_map<int, set<string>> groups;
        for (auto &p : emailToId) {
            int root = find(p.second);
            groups[root].insert(p.first);
        }
        
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> account;
            account.push_back(accounts[g.first][0]); // name
            for (auto &email : g.second) // already sorted (set)
                account.push_back(email);
            result.push_back(account);
        }
        
        return result;
    }
};